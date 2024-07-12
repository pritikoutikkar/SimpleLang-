#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "lexer.h"
#include "parser.h"
#include "code_generator.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file.sl>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file " << argv[1] << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::vector<Token> tokens = tokenize(code);
    
    ASTNode ast = parse(tokens);

    std::string assemblyCode = generateAssembly(ast);

    std::ofstream outputFile("generated_code.asm");
    if (!outputFile) {
        std::cerr << "Error: Cannot open output file generated_code.asm" << std::endl;
        return 1;
    }
    outputFile << assemblyCode;
    outputFile.close();

    std::cout << "Compilation successful. Assembly code written to generated_code.asm" << std::endl;
    return 0;
}
