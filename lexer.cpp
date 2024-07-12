#include <iostream>
#include <string>
#include <vector>

enum TokenType { KEYWORD, OPERATOR, IDENTIFIER, LITERAL, UNKNOWN };

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& code) {
    // Lexer implementation here
}

int main() {
    std::string code = "var x = 10;";
    std::vector<Token> tokens = tokenize(code);
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.value << " Type: " << token.type << std::endl;
    }
    return 0;
}
