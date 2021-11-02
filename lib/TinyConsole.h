#ifndef TINYCONSOLE_H
#define TINYCONSOLE_H

#include <iostream>
#include <stdlib.h> 
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <typeinfo>
#include <tuple>

#include "ArgConvert.h"

namespace hd {
    class TinyConsole {
        //=*=*=*=>> Variables Privadas //=*=*=*=>>
        //Struct
        struct funcBox {
            std::function<void(const std::vector<std::string>&)> function;
            std::vector<int> paramTypes;
            int numParam = 0;
        };

        //Variables Estaticas
        static std::string mensagesES[11];
        static std::string menssagesEN[11];
        static std::string typeNames[14];

        //Variables
        std::map<std::string, funcBox> commandMap;
        char initCmd;
        bool verifyParam;

        //=*=*=*=>> Funciones Privadas //=*=*=*=>>
        bool isNumber(std::string arg);

        int numType(const std::string& arg);

        template<typename T>
        std::tuple<T> concArgs(const std::vector<std::string>& vecStr, uint8_t argPos) {
            std::string str = vecStr[argPos];
            return std::make_tuple(hd::ArgConvert<T>{}(str));
        }

        template<typename T, typename U, typename... Args>
        std::tuple<T, U, Args...> concArgs(const std::vector<std::string>& vecStr, uint8_t argPos) {
            std::string str = vecStr[argPos];
            argPos++;
            return std::tuple_cat(
                std::make_tuple(hd::ArgConvert<T>{}(str)),
                this->concArgs<U, Args...>(vecStr, argPos)
            );
        }

        template<typename... Args>
        void callFunc(const std::function<void(Args...)>& func, const std::vector<std::string>& vecStr) {
            std::tuple<typename std::remove_reference<Args>::type...> tuplCmd =
                this->concArgs<typename std::remove_reference<Args>::type...>(vecStr, 0);
            std::apply(func, tuplCmd);
        }

        template<>
        void callFunc<>(const std::function<void()>& func, const std::vector<std::string>& vecStr) {
            (void)vecStr;
            func();
        }

        template<typename T>
        void listArgs(const std::string& cmdName) {
            std::string argType = typeid(T).name();

            int numType = this->numType(argType);
            if (numType == -1) this->verifyParam = true;
            this->commandMap[cmdName].paramTypes.push_back(numType);
        }

        template<typename T, typename U, typename... Args>
        void listArgs(const std::string& cmdName) {
            std::string argType = typeid(T).name();

            int numType = this->numType(argType);
            if (numType == -1) this->verifyParam = true;
            this->commandMap[cmdName].paramTypes.push_back(numType);
            this->listArgs<U, Args...>(cmdName);
        }

        template<typename... FuncArgs>
        void subListArgs(const std::string& cmdName) {
            listArgs<FuncArgs...>(cmdName);
        }

        template<>
        void subListArgs<>(const std::string& cmdName) {}

    public:
        //=*=*=*=>> Constructor y Destructor //=*=*=*=>>
        TinyConsole(char initCmd);
        ~TinyConsole();

        //=*=*=*=>> Funciones Publicas //=*=*=*=>>
        template<typename... FuncArgs>
        void addCmd(const std::string& cmdName, void(*func)(FuncArgs...)) {
            subListArgs<FuncArgs...>(cmdName);
            this->commandMap[cmdName].function = std::bind(&TinyConsole::callFunc<FuncArgs...>, this, func, std::placeholders::_1);
            this->commandMap[cmdName].numParam = sizeof...(FuncArgs);
        }

        void run(std::string cmd);
    };
}

#endif