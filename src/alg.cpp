// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
const char* filename = "name.txt"

    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word = "";
    int count = 0;
// читаем содержимое файла посимвольно
    while(!file.eof())
    {
        char ch = file.get();
        if (ch >= 'a' && ch <= 'z') {
            if (ch >= 'A' && ch <= 'Z') ch += 32;
            word += ch;
            count++;
        }
    }
    if (count > 0) { add.tree(word); word = "";  count = 0;}
    
    file.close();
    return tree;
}
