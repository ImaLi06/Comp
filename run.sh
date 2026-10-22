#!/bin/bash
# Compila ans.cpp con C++17 y lo ejecuta usando ans_input0.txt como entrada
cd "$(dirname "$0")" || exit 1

g++ -std=c++17 -O2 -w -o ans ans.cpp || exit 1
./ans < ans_input0.txt
