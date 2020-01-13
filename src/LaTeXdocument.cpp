#include "LaTeXdocument.h"
#include <iostream>
#include <vector>

using namespace std;

LaTeXtext::LaTeXtext(string content) {
    this->content = content;
}

void LaTeXdocument::addSection(string text) {
    LaTeXtext add = LaTeXtext("\\section{" + text + "}");
}

void LaTeXdocument::compile(string fileName) {
    ofstream myfile;
    myfile.open(fileName + ".tex");
    myfile << LaTeXdocument::defaultHeader;
    myfile << "nice";
    myfile << LaTeXdocument::defaultEnd;
    myfile.close();
    system(("pdflatex " + fileName + ".tex").c_str());
}

// void LaTeXdocument::addParagraph(string text) {}

LaTeXdocument::LaTeXdocument() {}

int main() {
    LaTeXdocument thing = LaTeXdocument();
    thing.compile("nice");
    return 0;
}
