#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum TokenType { KEYWORD, OPERATOR, IDENTIFIER, LITERAL, UNKNOWN };

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& code) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < code.size()) {
        if (std::isspace(code[i])) {
            i++;
            continue;
        }
        if (std::isalpha(code[i])) {
            size_t start = i;
            while (i < code.size() && std::isalnum(code[i])) i++;
            std::string word = code.substr(start, i - start);
            if (word == "var" || word == "if" || word == "else") {
                tokens.push_back({KEYWORD, word});
            } else {
                tokens.push_back({IDENTIFIER, word});
            }
        } else if (std::isdigit(code[i])) {
            size_t start = i;
            while (i < code.size() && std::isdigit(code[i])) i++;
            tokens.push_back({LITERAL, code.substr(start, i - start)});
        } else {
            char op = code[i++];
            tokens.push_back({OPERATOR, std::string(1, op)});
        }
    }
    return tokens;
}
