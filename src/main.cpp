#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include "printer.h"
#include "ast.h"
#include "checker.h"

extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern void initFileName(char *);
extern void zhywyt_error(const char*);
extern FILE *yyin;
void preprocess(std::string srcFileName);
int main(int argc, char **argv) {
    // assert(argc >= 2);
    bool print_ast = true;
    if(argc>=2){
        char *filename;
        if(argc == 2) {
            filename = argv[1];
        }else if(argc == 3){
            print_ast = false;
            filename = argv[2];
        }
        yyin = fopen(filename, "r");
        if (yyin == nullptr) {
            std::cout << "yyin open " << filename << " failed" << std::endl;
            return -1;
        }
        std::string filename_out = strcpy(filename,strrchr(filename,'/')+1);

        initFileName(filename);
    }
    yyparse();

    //ofstream outfile;
    //outfile.open("../ast/" + filename_out + ".ast.txt", ios::out | ios::trunc);
    Printer printer;
    std::string info = printer.visit(*root);
    extern int error_num;
    if(print_ast)
        std::cout << info << std::endl;
    if(error_num)
        zhywyt_error((std::string("There is ")+std::to_string(error_num)+" Syntax Error!\n").c_str());
    else{
        printf("\033[1;32mCongratulate! There is not Syntax Error!\033[0m\n");
    }

    std::ostringstream oss;
    ErrorReporter errorReporter(oss);
    Checker checker(errorReporter);
    try{
        zhywyt_error("-------------------In Try!-------------------\n");
        checker.visit(*root);
    }
    catch(int ReturnCode){
        zhywyt_error("-------------------In Catch!-------------------\n");
        std::string info = oss.str();
        // zhywyt_error((std::string("There is ")+std::to_string(error_num)+" Syntax Error!\n").c_str());
        zhywyt_error((std::string("[Means Error!] : ")+info).c_str());
        return -1;
    }
    printf("\033[1;32mCongratulate! There is not YuYi Error!\033[0m\n");
    return 0;
}
