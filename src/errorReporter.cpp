#include "errorReporter.h"
#include "string"

extern int yylineno;

ErrorReporter::ErrorReporter(std::ostream &error_stream) : err(error_stream) {}

// void ErrorReporter::error(const std::string &msg) {
//  err << "Error: " << msg << std::endl;
//}

void ErrorReporter::error(ErrorType type, const std::string &ast, int line) {
  std::string error_msg = "Error type " + std::to_string((int)type)  + " at line " + std::to_string(line) + " ";
  switch (type) {
  case ErrorType::VarUnknown:
    error_msg += "Use Undefined Variable";
    err << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::VarDuplicated:
    error_msg += "Redefined Variable";
    err << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncUnknown:
    error_msg += "Use Undefined Function";
    err << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncDuplicated:
    error_msg += "Redefined Function";
    err << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncParamsNotMatch:
    error_msg += "Can not Match Function Parameters";
    err << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncReturnTypeNotMatch:
    error_msg += "Func return type not match.";
    err << error_msg << std::endl;
    break;
  case ErrorType::ArrayIndexNotInt:
    error_msg += "Array";
    err << error_msg + " \"" + ast + "\" index not int." << std::endl;
    break;
  case ErrorType::BreakNotInLoop:
    error_msg += "Break not in loop.";
    err << error_msg << std::endl;
    break;
  case ErrorType::ContinueNotInLoop:
    error_msg += "Continue not in loop.";
    err << error_msg << std::endl;
    break;
  case ErrorType::VisitVariableError:
    error_msg += "Visit non-array variable in the form of subscript variables.";
    err << error_msg << std::endl;
    break;
  case ErrorType::DifferentTypeForOperands:
    error_msg += "Type mismatched for operands."+ ast;
    err << error_msg <<std::endl;
    break;
  // case ErrorType::ReturnNotInFunc:
  //   error_msg += "Return not in function";
  //   err << error_msg << std::endl;
  //   break;
  default:
    break;
  }
}
