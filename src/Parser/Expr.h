#include <string>
#include <iostream>
#include <vector>

#include "Token.h"
#include "Ast.h"


class Expr{
    ~Expr() = 0;
};

class Equality: public Expr{};
class Comparison: public Equality{};
class Addition: public Comparison{};
class Multiplication: public Addition{};
class Unary: public Multiplication{};
class Primary: public Unary{};


