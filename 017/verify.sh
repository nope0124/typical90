#!/bin/bash

# コマンドライン引数の数を確認
if [ "$#" -ne 3 ]; then
    echo "Usage: bash verify.sh my_answer.cpp correct_answer.cpp input_file.txt"
    exit 1
fi

# コマンドライン引数を変数に代入
my_program=$1
correct_program=$2
input_file=$3

# 一時ファイル名
my_output="my_output.txt"
correct_output="correct_output.txt"

# コードをコンパイル
clang++ -std=c++17 -o my_program_exec $my_program
clang++ -std=c++17 -o correct_program_exec $correct_program

# コンパイルに失敗した場合のエラーハンドリング
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# プログラムを実行して出力を一時ファイルに保存
./my_program_exec < $input_file > $my_output
./correct_program_exec < $input_file > $correct_output

# 出力を比較
diff_result=$(diff -q $my_output $correct_output)

if [ "$diff_result" == "" ]; then
    echo "Output matches for input file: $input_file"
else
    echo "Output differs for input file: $input_file"
    echo "Expected output:"
    cat $correct_output
    echo "Your output:"
    cat $my_output
fi

# 一時ファイルと実行ファイルを削除
rm $my_output $correct_output my_program_exec correct_program_exec
