//
// Created by Артём Гудзенко on 30.01.2023.
//
#ifndef K_TECH_FUNCTION_LAYER_H
#define K_TECH_FUNCTION_LAYER_H

#include "Data_layer.h"

using namespace std;

template <typename T>
T change(T str); // прототип функции форматирования строки из xml документа

class ChangeFile
{
    Path file;
    string input = file.getInp();
    string out = file.getOutp();

public:
    vector<int> file_edit();
    void emptyLine(vector<int> pos);
};

#endif // K_TECH_FUNCTION_LAYER_H
