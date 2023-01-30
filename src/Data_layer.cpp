//
// Created by Артём Гудзенко on 22.01.2023.
//

#include "../include/Data_layer.h"

Path::Path()
{
    path_files = ReadFromConfig(); // при сохдания побъекта заносим значения в поля
}

vector<string> Path::ReadFromConfig()
{ // ф-ия нужна для того, чтобы задать путь, где расположен файл .xml
    vector<string> res_vec_str(2);
    ifstream config_file; // открываем на чтение из файла конфига для пути
    string str;
    config_file.open("config_file.txt");

    if (!config_file) // проверка нахождения данного файла
    {
        cout << "\nФайл конфига пути не найден!!\n"
             << endl;
    }
    else
    {
        int cnt = 0;
        while (getline(config_file, str)) // получение строки из файла Config_way.txt
        {
            res_vec_str[cnt] = str.substr(str.find("/")); // чтение из файла входной и выходной путь с символа /
            cnt++;
        }
        config_file.close();
    }
    return res_vec_str;
}

string Path::getInp()
{
    return path_files[0];
}

string Path::getOutp()
{

    return path_files[1] + "/test.xml.001";
}