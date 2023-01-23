//
// Created by Артём Гудзенко on 22.01.2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>



bool remove(char s1){
    return (s1 == '\"');
}
bool remo(char s1){
    return (s1 == '\"');

}

string editStr(string &str){
    auto pos = (remove_if(str.begin(), str.end(), remo));
    str.erase(pos, str.end());
    return str;
}

template <typename T>
T addcomma(T str, size_t &cnt, const int &size) {
    size_t pos = str.find_first_not_of(" ");
    str.erase(0, pos);
    cnt++;
    str = editStr(str);
    return (cnt == 0) ?  "{\"" +str + "\"," : (cnt == size)? "\"" +str + "\"}" : "\"" +str + "\"," ;
}

template <typename T>
    T change(T str) {
    vector<string> checks = { "date", "name", "hours-worked", "car-true"};
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

class ChangeFile{
public:

    string input = "/Users/artemgudzenko/Desktop/Less_1/c++/K-tech/K-tech/input_data/test.xml";
    string out = "/Users/artemgudzenko/Desktop/Less_1/c++/K-tech/K-tech/output_data/rez4.txt";


    string getInp(){
        return input;
    }
    string getOutp(){
        return  out;
    }
    bool file_edit2()
    {

        bool flag = false; //флаг проверки нахождения исходного файла
        ifstream file;     //на чтение (исходный каталог)
        file.open(input);
        string str;

        ifstream fin{input};
        int size = count(istream_iterator<char>(fin >> noskipws), {}, '\n');

        if (!file)
        {
            flag = true;
            cout << "\nФайл не найден!!!!!!!\n"
                 << endl;
        }

        else
        {
            ofstream mfile(out, ios::trunc | ios::out); //на запись (выходной каталог)
            size_t cnt = 0;

            while (getline(file, str))                                             //получение строки и ее изменение
            {
                if (cnt == 0) mfile<<"{";
//                str = editStr(str);    //обработка строки
//                cout << str<<endl;
                str = addcomma(str, cnt ,size);
                mfile << str<<endl;


//
//                mfile << str << endl; // запись в аутпут файл
//                mfile << TMshot_string;
            }
            file.close();
        }

        return flag;
    }


    bool file_edit()
    {

        bool flag = false; //флаг проверки нахождения исходного файла
        ifstream file;     //на чтение (исходный каталог)
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
            cout << "Кол-во строк: "<<size<<endl;
            ofstream mfile(out, ios::trunc | ios::out); //на запись (выходной каталог)m
            while (getline(file, str))                                             //получение строки и ее изменение
            {
//                str = editStr(str);    //обработка строки
//                cout << str<<endl;
                str = change(str);
                cout << str<<endl;
                mfile << str<<endl;
//
//                mfile << str << endl; // запись в аутпут файл
//                mfile << TMshot_string;
            }
            file.close();
        }

        return flag;
    }
};

