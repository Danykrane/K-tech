//
// Created by Артём Гудзенко on 30.01.2023.
//

#include "../include/Function_layer.h"

using namespace std;

template <typename T>
T change(T str)
{
    const vector<string> checks = {"date", "name", "hours-worked", "car-true"};

    for (auto it : checks)
    {
        string begin = "<" + it + ">";
        string end = "</" + it + ">";

        if (str.find(begin) != string::npos && str.find(end) != string::npos)
        {
            return str.substr(str.find(begin) + begin.size(), str.find(end) - begin.size() - str.find(begin));
        }
    }
    return "";
}

vector<int> ChangeFile::file_edit()
{

    vector<int> pos;
    bool flag = false; // флаг проверки нахождения исходного файла
    ifstream file;     // на чтение (исходный каталог)
    file.open(input);
    string str;

    if (!file)
    {
        flag = true;
        cout << "\nФайл не найден!!!!!!!\n"
             << endl;
    }
    else
    {

        ifstream fin{input};
        int size = count(istream_iterator<char>(fin >> noskipws), {}, '\n');
        int cnt = 0;
        cout << "Кол-во строк: " << size << endl;
        cout << "Будем записывать в файл с расположением: " << out << endl;
        ofstream mfile(out, ios::trunc | ios::out); // на запись (выходной каталог)m
        while (getline(file, str))                  // получение строки и ее изменение
        {

            str = change(str);
            if (str.length() == 0)
                pos.push_back(cnt);

            cout << str << endl;
            mfile << str << endl;
            cnt++;
        }
        file.close();
    }

    for (auto it = pos.begin() + 3; it != pos.end(); it++)
    {
        if (*it + 1 == *(it + 1))
        {
            pos.erase(it);
        }
    }

    return pos;
}

void ChangeFile::emptyLine(vector<int> pos)
{
    string rez = "/Users/artemgudzenko/Desktop/Less_1/c++/K-tech/K-tech/output_data/out.txt";
    ifstream fin(out);
    ofstream fout(rez, ios::trunc | ios::out);

    string str;
    int cnt = 0;

    while (getline(fin, str))
    {
        if (find(pos.begin(), pos.end(), cnt) == pos.end())
            fout << str << endl;
        cnt++;
    }
    fin.close();
}
