#include <iostream>
#include <vector>
#include <string>

std::string generateAssembly(const ASTNode& ast) {
    std::string assemblyCode;
    for (const auto& node : ast.children) {
        if (node.type == "VarDecl") {
            assemblyCode += "LOAD R1, " + node.children[0].value + "\n"; // LOAD initial value
            assemblyCode += "STORE R1, " + node.value + "\n"; // STORE to variable
        }
    }
    assemblyCode += "HALT\n";
    return assemblyCode;
}
