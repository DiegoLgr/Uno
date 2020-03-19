ast = "../Parser/Ast.cpp"
"""
literals = {
    'Number': (('float', 'v'),),
    'String': (('std::string', 'v'),),
    'Bool': (('bool', 'v'),),
    'Nil': tuple(tuple()),
}
"""

nonterminals = {
    'Unary': (('Token', 't'), ('Expr', 'e1')),
    'Binary': (('Expr', 'e1'),('Token', 't'), ('Expr', 'e2')),
    'Group': (('Expr', 'e1'),),
    'Literal': (('Token', 't'),),
}

#expressions = { **nonterminals, **literals}
expressions = nonterminals

indent = 4 * " "


def write_file():
    with open( ast, "w+") as f:
        f.write("#include <string>\n\n")
        f.write("#include \"Token.h\"\n\n")
        # Base classes and typedefs
        f.write("typedef struct Expr Expr;\n")
        for expr in expressions:
            f.write("typedef struct {0} {0};\n".format(expr))
        f.write("\n")

        f.write( visitor())

        f.write("struct Expr {\n virtual void accept( Visitor &v) const = 0;\n };\n")
        f.write("\n")

        for expr in nonterminals:
            f.write( class_nonterminal( expr))

"""
        for expr in literals:
            f.write( class_literal( expr))
"""


def visitor():
    visitor = "struct Visitor {\n"
    visitor += indent + "virtual void visit( Expr &e) = 0;\n"
    for expr in expressions:
        visitor += indent
        visitor += "virtual void visit( const {0} &e) = 0;\n".format( expr)
    visitor += "};\n\n"
    return visitor

def class_literal( expr):
    declaration = "struct {0}: public Expr ".format(expr) + "{\n"

    # Constructor
    constructor = ""
    if expressions[expr]:
        constructor += indent + "{0}( const {0} {1}):".format(
            expressions[expr][0][0], expressions[expr][0][1])
        constructor += "\n"
        constructor += 2*indent + "{0}({0})\n".format( expressions[expr][0][1])
        constructor += indent + "{}\n\n"

    # Accept function
    accept = indent + "void accept( Visitor &v) const { v.visit( *this); }\n\n"

    # Class members
    member = ""
    if expressions[expr]:
        member += indent + "const {0} {1};\n".format( expressions[expr][0][0], expressions[expr][0][1])

    return  declaration + constructor + accept + member + "};\n\n"

def class_nonterminal( expr):
    declaration = "struct {0}: public Expr ".format(expr) + "{\n"

    # Constructor
    constructor = indent + "{0}( ".format(expr)
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
    for member in expressions[expr]:
       members += indent + "const {0}& {1};\n".format( member[0], member[1])
    return  declaration + constructor + accept + members + "};\n\n"


if __name__ == '__main__':
    write_file()
