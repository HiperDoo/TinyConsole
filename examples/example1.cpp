#include "TinyConsole.h"

void hello() {
	std::cout << "> Console: Hello World!\n";
}

void say(const std::string& text) {
	std::cout << "> User: " << text << '\n';
}

void say2(int a, const std::string& text) {
	std::cout << "> User" << a << ": " << text << '\n';
}

void say3(int a, const std::string& text, int b) {
	std::cout << "> User" << a << ": " << text << " num: " << b << '\n';
}

void say4(int a, const std::string& b, const std::string& c, int d) {
	std::cout << "> User" << a << ": " << b << c << " num: " << d << '\n';
}

void sum(float a, float b, float c) {
	std::cout << "> Console: " << a << " + " << b << " + " << c << " = " << a + b + c << '\n';
}

void res(float a, float b) {
	std::cout << "> Console: " << a << " - " << b << " = " << a - b << '\n';
}

void clear() {
	system("cls");
}

int main() {
	hd::TinyConsole cmd('/');
	std::string text;

	cmd.addCmd("hello", hello);
	cmd.addCmd("say", say);
	cmd.addCmd("say2", say2);
	cmd.addCmd("say3", say3);
	cmd.addCmd("say4", say4);
	cmd.addCmd("sum", sum);
	cmd.addCmd("res", res);
	cmd.addCmd("clear", clear);

    const int num = 7;
    std::string test[num] = {
        "/hello",
        "/say [Hola a todos!]",
        "/say2 12345 [Hola a todos]",
        "/say3 12345 [Hola a todos] 67890",
		"/say4 12345 [Hola a todos] [Como estan?] 67890",
        "/sum 4002.342 2414.13 -1341.02",
        "/res 4134.133 -41311.003"
    };
    for (int i = 0; i < num - 1; i++) {
        cmd.run(test[i]);
    }

    while (true) {
        std::getline(std::cin, text);
        if (text[0] == '/') {
            cmd.run(text);
        } else {
            std::cout << "> HiperDoo: " << text << '\n';
        }
    }

	return 0;
}