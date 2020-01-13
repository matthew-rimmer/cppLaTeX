#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class LaTeXpackage {};

class LaTeXmacros {};

class LaTeXtext {
private:
    string content;

public:
    LaTeXtext(string content);

    string getContent();
};

class LaTeXdocument {
private:
    string fileName;
    vector<LaTeXpackage> packages;
    vector<LaTeXmacros> macros;
    vector<LaTeXtext> content;

    const string defaultHeader =
        "\\documentclass{article}"
        "\\usepackage[utf8]{inputenc}"
        "\\title{}"
        "\\author{}"
        "\\date{}"
        "\\begin{document}";

    const string defaultEnd = "\\end{document}";

public:
    LaTeXdocument();

    void addPackage(string packageName, string packageParameters);

    void addMacro(string name, string content);

    void addHeader(string header);

    void addSection(string text);

    void addParagraph(string text);

    void compile(string fileName);
};
