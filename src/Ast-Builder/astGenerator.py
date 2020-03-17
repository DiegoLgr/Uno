ast = "Ast.cpp"
terminals = {
    'Number': (('float', 'v'),),
}
nonterminals = {
    'Add': (('Expr', 'e1'), ('Expr', 'e2')),
    'Mult': (('Expr', 'e1'), ('Expr', 'e2')),
}
expressions = { **nonterminals, **terminals}

indent = 4 * " "


def write_file():
    with open( ast, "w+") as f:
        f.write("#include <iostream>\n\n\n")

        # Base classes and typedefs
        f.write("typedef struct Visitor Visitor;\n\n")
        f.write("struct Expr { virtual void accept( Visitor &v) = 0; };\n\n")

        for expr in expressions:
            f.write("typedef struct {0} {0};\n".format(expr))
        f.write("\n")

        f.write( visitor())

        for expr in nonterminals:
            f.write( class_expresion( expr, False))

        for expr in terminals:
            f.write( class_expresion( expr, True))


def visitor():
    declaration = "struct Visitor {\n"

    visit_methods = indent + "virtual void visit( Expr &e) = 0;\n"
    for expr in expressions:
        visit_methods += indent + "virtual void visit( {0} &e) = 0;\n".format(expr)

    return declaration + visit_methods + "};\n\n"


def class_expresion( expr, is_terminal):
    """ Example of a non terminal and a terminal expresions.
    struct Mult: Expr{
        Mult( Expr &e1, Expr &e2): e1(e1), e2(e2){}

        void accept( Visitor &v){ v.visit( *this); }

        Expr &e1;
        Expr &e2;
    };

    struct Number: Expr {
        Number( float v): v(v){}

        void accept( Visitor &v){ v.visit( *this); }

        float v;
    };

    """
    declaration = "struct {0}: Expr ".format(expr) + "{\n"

    # Constructor
    constructor = indent + "{0}( ".format(expr)
    if is_terminal:
        for member in expressions[expr]:
            constructor += "{0} {1}, ".format( member[0], member[1])
    else:
        for member in expressions[expr]:
            constructor += "{0} &{1}, ".format( member[0], member[1])
    constructor = constructor[:-2] + "): "
    for member in expressions[expr]:
        constructor += "{0}({0}), ".format( member[1])
    constructor = constructor[:-2] + "{}\n\n"

    # Accept function
    accept = indent + "void accept( Visitor &v){ v.visit( *this); }\n\n"

    # Class members
    members = ""
    if is_terminal:
        for member in expressions[expr]:
           members += indent + "{0} {1};\n".format( member[0], member[1])
    else:
        for member in expressions[expr]:
           members += indent + "{0}& {1};\n".format( member[0], member[1])
    return  declaration + constructor + accept + members + "};\n\n"



if __name__ == '__main__':
    write_file()
