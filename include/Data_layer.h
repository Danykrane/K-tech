//
// Created by Артём Гудзенко on 22.01.2023.
//

#ifndef K_TECH_DATA_LAYER_H
#define K_TECH_DATA_LAYER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Path
{
    vector<string> path_files; // первая строка - путь аходного файла, вторая строка - путь выходного файла
public:
    Path();                          // путь к файлу конфига, где лежат пути для файлов
    vector<string> ReadFromConfig(); // для передачи данных с файла к полям

    string getInp();
    string getOutp();
    string getToDel(); //создание пути файла в папку to_delete
};

#endif // K_TECH_DATA_LAYER_H
