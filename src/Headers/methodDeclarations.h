#ifndef DECAF_COMPILER_METHOD_DECLARATIONS_H
#define DECAF_COMPILER_METHOD_DECLARATIONS_H

#include "block.h"


class MethodDeclarations: public ASTnode {
private:
    vector<class MethodDeclaration*> methodsVector;

public:
    MethodDeclarations() = default;

    void addMethodDecl(class MethodDeclaration *methodDecl);    

    virtual void accept(ASTvisitor &v) {
        v.visit(*this);
    }
};

class MethodDeclaration: public ASTnode {
private:
    // method return type (int/boolean/void)
    string type;

    // method name
    string methodName;

    // Args for the method
    class MethodArgs *methodArgs;

    // Method block
    class Block *block;

public:
    MethodDeclaration(string type, string methodName, class MethodArgs *methodArgs, class Block *block);

    virtual void accept(ASTvisitor &v) {
        v.visit(*this);
    }
};

class MethodArgs: public ASTnode {
private:
    vector<class MethodArg*> methodArgsVector;

public:
    MethodArgs() = default;

    void addMethodArg(class MethodArg *methodArg);

    virtual void accept(ASTvisitor &v) {
        v.visit(*this);
    }
};

class MethodArg: public ASTnode {
private:
    // DataType of the arg
    string type;

    // identifier of the arg
    string name;

public:
    MethodArg(string type, string name);

    virtual void accept(ASTvisitor &v) {
        v.visit(*this);
    }
};

#endif // !DECAF_COMPILER_METHOD_DECLARATIONS_H