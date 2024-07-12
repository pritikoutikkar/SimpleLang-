std::string generateAssembly(const ASTNode& ast) {
    // Assembly code generation implementation here
}

int main() {
    std::vector<Token> tokens = tokenize("var x = 10;");
    ASTNode ast = parse(tokens);
    std::string assemblyCode = generateAssembly(ast);
    std::cout << assemblyCode << std::endl;
    return 0;
}
