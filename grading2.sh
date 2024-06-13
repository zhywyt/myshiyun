#!/bin/bash

#mkdir -p "ast"
cd src

#make -s clean
make -s

if [ ! -f "parser" ]; then
  echo "没有找到语法分析程序parser，请修改代码后，重新评测"
else
#读取键盘输入到typ中         
  read -p '' case
  chmod +x parser
  ./parser -ast ../test_cases/$case
fi 