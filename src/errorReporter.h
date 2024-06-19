#ifndef CARROTCOMPILER_ERRORREPORTER_H
#define CARROTCOMPILER_ERRORREPORTER_H

#include <iostream>

enum class ErrorType {
  VarUnknown = 1,                     //变量未声明
  VarDuplicated,                      //变量重复声明
  FuncUnknown,                        //函数在调用时未定义
  FuncDuplicated,                     //函数重复定义
  ImproperReferenceToFunctionName,    //把变量当做函数调用
  ImproperFunctionToReferenceName,    //对函数名的不当引用
  ArrayIndexNotInt,                   //对数组的不当引用
  VisitVariableError,                 //对非数组变量使用数组访问
  FuncParamsNotMatch,                 //函数调用时参数个数或类型不匹配
  FuncReturnTypeNotMatch,             //函数定义的返回类型不匹配
  DifferentTypeForOperands,           //操作数类型不匹配
  BreakNotInLoop,                     //break语句不在循环体内
  ContinueNotInLoop,                  //continue语句不在循环体内
};

/**
 * @brief 错误报告器
 *
 * @description: 用于报告编译器中的错误信息，包括错误类型和相关的语法节点。
 */
class ErrorReporter {
public:
  /**
   * 构造错误报告器
   * @param error_stream - 输出错误信息的流
   */
  explicit ErrorReporter(std::ostream &error_stream);

  // void error(const std::string &msg);
  /**
   * 报告特定类型的错误
   * @param type - 错误类型
   * @param ast - 相关的语法节点信息
   **/
  void error(ErrorType type, const std::string &ast, int line);

private:
  std::ostream &err;
};

#endif // CARROTCOMPILER_ERRORREPORTER_H
