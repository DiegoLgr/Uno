ast = "Ast.cpp"

terminals = {
    'Number': (('float', 'v'),),
    'String': (('std::string', 'v'),),
    'Bool': (('bool', 'v'),),
    'Nil': tuple(tuple()),
}

nonterminals = {
    'Equ': (('Expr', 'e1'), ('Expr', 'e2')),
    'Comp': (('Expr', 'e1'), ('Expr', 'e2')),
    'Add': (('Expr', 'e1'), ('Expr', 'e2')),
    'Mult': (('Expr', 'e1'), ('Expr', 'e2')),
    'Unary': (('Expr', 'e1'),),
    'Group': (('Expr', 'e1'),),
}

expressions = { **nonterminals, **terminals}

indent = 4 * " "


def write_file():
    with open( ast, "w+") as f:
        f.write("#include <string>\n\n")
        # Base classes and typedefs
        f.write("typedef struct Expr Expr;\n")
        for expr in expressions:
            f.write("typedef struct {0} {0};\n".format(expr))
        f.write("\n")

        f.write( visitor())

        f.write("struct Expr {\n virtual void accept( Visitor &v) const = 0;\n };\n")
        f.write("\n")

        for expr in nonterminals:
            f.write( class_expresion( expr, False))

        for expr in terminals:
            f.write( class_expresion( expr, True))


def visitor():
    visitor = "struct Visitor {\n"
    for expr in expressions:
        visitor += indent
        visitor += "virtual void visit( const {0} &e) = 0;\n".format( expr)
    visitor += "};\n\n"
    return visitor

def class_expresion( expr, is_terminal):
    """ Example of a non terminal and a terminal expresions.
    struct Mult: Expr{
        Mult( Expr &e1, Expr &e2):
            e1(e1),
            e2(e2)
        {}

        void accept( Visitor &v) const { v.visit( *this); }

        const Expr &e1;
        const Expr &e2;
    };

    struct Number: Expr {
        Number( float v): v(v){}

        void accept( Visitor &v){ v.visit( *this); }

        float v;
    };

    """
    declaration = "struct {0}: public Expr ".format(expr) + "{\n"

    # Constructor
    constructor = indent + "{0}( ".format(expr)
    if is_terminal:
        if expressions[expr]:
            for member in expressions[expr]:
                constructor += "const {0} {1}, ".format( member[0], member[1])
        else:
             constructor += "  " # If expr doesn't have members, it doesn't
                                 # get in, so it doesnt get the 2 extra char.
    else:
        for member in expressions[expr]:
            constructor += "const {0} &{1}, ".format( member[0], member[1])
    constructor = constructor[:-2] + "):" # Remove 2 extra char: ', '.
    for member in expressions[expr]:
        constructor += "\n"
        constructor += 2*indent + "{0}({0}),".format( member[1])
    constructor = constructor[:-1]
    constructor += "\n" + indent + "{}\n\n"

    # Accept function
    accept = indent + "void accept( Visitor &v) const { v.visit( *this); }\n\n"

    # Class members
    members = ""
    if is_terminal:
        for member in expressions[expr]:
           members += indent + "const {0} {1};\n".format( member[0], member[1])
    else:
        for member in expressions[expr]:
           members += indent + "const {0}& {1};\n".format( member[0], member[1])
    return  declaration + constructor + accept + members + "};\n\n"



if __name__ == '__main__':
    write_file()
