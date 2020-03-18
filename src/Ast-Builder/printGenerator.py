printer = "Printer.cpp"

with open(printer, "w+") as f:
    source = "#include \Ast.cpp\"\n\n"
    source +="\
struct Printer: Visitor {\
std::string s {};\
\
void visit( const Expr &e) { e.accept( *this);}\
"
