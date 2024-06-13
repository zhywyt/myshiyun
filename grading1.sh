#!/bin/bash

cd src

# make -s clean
make -s 

if [ ! -f "parser" ]; then
  echo "没有找到语法分析程序parser，请修改代码后，重新评测"
else

read -p '' case
chmod +x parser
./parser ../test_cases/case_$case.sy
fi 