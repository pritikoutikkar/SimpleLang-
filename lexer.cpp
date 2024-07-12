#include <iostream>
#include <vector>
#include <string>

struct ASTNode {
    std::string type;
    std::vector<ASTNode> children;
    std::string value;
};

ASTNode parse(const std::vector<Token>& tokens) {
    ASTNode root;
    root.type = "Program";
    size_t i = 0;
    while (i < tokens.size()) {
        if (tokens[i].type == KEYWORD && tokens[i].value == "var") {
            ASTNode varDecl;
            varDecl.type = "VarDecl";
            varDecl.value = tokens[i+1].value; 
            varDecl.children.push_back({"Literal", {}, tokens[i+3].value}); 
            root.children.push_back(varDecl);
            i += 4; 
        } else {
            i++;
        }
    }
    return root;
}
