#include "TinyConsole.h"

//Variables Estaticas
std::string hd::TinyConsole::mensagesES[11] = {
    "ERROR::",
    "El comando debe ser llamado con el caracter '",
    "El comando ingresado no existe! Comando ingresado: ",
    "Se esperaba en el parametro numero ", " un numero! Parametro ingresado: ",
    " una cadena de texto! Parametro ingresado: ",
    "El parametro '", "' no es un numero!\n",
    "Se ha ingresado un parametro de mas!\n",
    "Se esperaban mas parametros.\n"
    "No se ha cerrado correctamente algun corchete \'[]\'\n"
};

std::string hd::TinyConsole::typeNames[14] = {
    "unsigned char", "char",
    "unsigned short", "short",
    "unsigned int", "int",
    "unsigned long int", "long int",
    "unsigned long long int", "long long int",
    "float", "double", "long double",
    "string"
};

//=*=*=*=>> Constructor y Destructor //=*=*=*=>>
hd::TinyConsole::TinyConsole(char initCmd) {
    this->initCmd = initCmd;
    this->verifyParam = false;
}

hd::TinyConsole::~TinyConsole() {}

//=*=*=*=>> Funciones Privadas //=*=*=*=>>
bool hd::TinyConsole::isNumber(std::string arg) {
    int char_pos = (arg[0] == '+' || arg[0] == '-');

    if (arg[char_pos] == '+' || arg[char_pos] == '-')
        return false;

    int n_nm, n_pt;
    for (n_nm = 0, n_pt = 0; std::isdigit(arg[char_pos]) || arg[char_pos] == '.'; ++char_pos) {
        arg[char_pos] == '.' ? ++n_pt : ++n_nm;
    }
    if (n_pt > 1 || n_nm < 1)
        return false;

    return char_pos == arg.size();
}

int hd::TinyConsole::numType(const std::string& arg) {
    if (arg == "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >") { return 13; };
    for (int i = 0; i < 13; i++)
        if (arg == typeNames[i]) return i;
    return -1;
}

//=*=*=*=>> Funciones Publicas //=*=*=*=>>
void hd::TinyConsole::run(std::string str) {
    if (str[0] != this->initCmd) {
        std::cout << mensagesES[0] << mensagesES[1] << this->initCmd << '\n';
        return;
    }
    std::string cmd = str.substr(1, str.find(" ") - 1);
    if (this->commandMap.count(cmd) != 1) {
        std::cout << mensagesES[0] << mensagesES[2] << cmd << '\n';
        return;
    }

    unsigned int currentParam = 0;
    unsigned int currPos = (cmd.size() + 1), endPos = str.length();
    unsigned int countStart = 0, countEnd = 0;
    std::size_t listStart = 0, listEnd = 0;
    std::vector<std::string> vecStr;

    while (listStart != std::string::npos) {
        listStart = str.find("[", listStart + 1);
        countStart++;
    }
    while (listEnd != std::string::npos) {
        listEnd = str.find("]", listEnd + 1);
        countEnd++;
    }

    int tempPos;
    if (countStart == countEnd) {
        while (currPos < endPos && vecStr.size() <= this->commandMap[cmd].numParam) {
            tempPos = currPos;
            if (str[currPos] == '[') {
                while (str[currPos] != ']' && currPos < endPos) currPos++;
                currPos++;

                vecStr.push_back(str.substr(tempPos, currPos - tempPos));

                if (this->commandMap[cmd].paramTypes[currentParam] != 13) {
                    std::cout << mensagesES[0] << mensagesES[3] << currentParam << mensagesES[4] << vecStr.back() << '\n';
                    return;
                }
                currentParam++;
            } else if (str[currPos] != ' ') {
                while (str[currPos] != ' ' && currPos < endPos) currPos++;
                vecStr.push_back(str.substr(tempPos, currPos - tempPos));

                if (this->commandMap[cmd].paramTypes[currentParam] == 13) {
                    std::cout << mensagesES[0] << mensagesES[3] << currentParam << mensagesES[5] << typeNames[13] << '\n';
                    return;
                } else if (!isNumber(vecStr.back())) {
                    std::cout << mensagesES[0] << mensagesES[6] << vecStr.back() << mensagesES[7];
                    return;
                }
                currentParam++;
            }
            currPos++;
        }
        if (vecStr.size() == this->commandMap[cmd].numParam) {
            this->commandMap[cmd].function(vecStr);
        } else if (vecStr.size() > this->commandMap[cmd].numParam) {
            std::cout << mensagesES[0] << mensagesES[8];
        } else {
            std::cout << mensagesES[0] << mensagesES[9];
        }
    } else {
        std::cout << mensagesES[0] << mensagesES[10];
    }
}