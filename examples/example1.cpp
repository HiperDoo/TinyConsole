#include "TinyConsole.h"

void hello() {
	std::cout << "> User: Hola Mundo!\n";
}

void say(const std::string& text) {
	std::cout << "> User: Puedo mandar un mensaje => " << text << '\n';
}

void say2(int num, const std::string& text) {
	std::cout << "> User: Puedo enviar un numero => " << num << " y un mensaje => " << text << '\n';
}

void say3(int num1, const std::string& text, int num2) {
	std::cout << "> User: Puedo enviar un numero => " << num1 << ", un mensaje => " << text << " y otro numero => " << num2 << '\n';
}

void say4(int num1, const std::string& text1, int num2, const std::string& text2) {
	std::cout << "> User: Puedo enviar mas de dos strings y numeros, nums[" << num1 << ", " << num2 << "] textos" << text1 << ", " << text2 << '\n';
}

void sum(float a, float b, float c) {
	std::cout << "> User: Puedo hacer sumas! " << a << " + " << b << " + " << c << " = " << a + b + c << '\n';
}

void res(float a, float b) {
	std::cout << "> User: Puedo hacer restas! " << a << " - " << b << " = " << a - b << '\n';
}

void clear() {
	system("cls");
}

int main() {
	hd::TinyConsole cmd('/');

	std::cout << "> Utiliza las funciones de tu consola para llamar comandos en tiempo de ejecucion!\n   Ejemplos:\n\n";

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
	"/say4 12345 [Hola a todos] 67890 [Como estan?]",
        "/sum 4002.342 2414.13 -1341.02",
        "/res 4134.133 -41311.003"
    };
	for (int i = 0; i < num; i++) {
		std::cout << "Comando: " << test[i] << "\n   ";
		cmd.run(test[i]);
		std::cout << '\n';
	}

	std::cout << "\n> Intentalo tu o preciona Enter para terminar el programa...\n";

    std::string text;
    while (true) {
        std::getline(std::cin, text);
        if (text[0] == '/') {
		cmd.run(text);
        } else if (text == "") {
		break;
        } else {
		std::cout << "> Default: " << text << '\n';
	}
    }

	return 0;
}
