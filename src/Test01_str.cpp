//
// Created by Артём Гудзенко on 22.01.2023.
//
#include <iostream>


bool rem(char s1){
    return (s1 == '>' || s1 == '<' || s1 == '/');

}

string editSt(string &str){
    auto pos = (remove_if(str.begin(), str.end(), rem));
    str.erase(pos, str.end());
    return str;
}

class Test01{
public:

    string str1 = "<name>Алексеев Иван Петрович</name>";
    string str2 = "<date>1976-01-01</date>";



    void show(){
        cout <<str1<<endl;
        cout << str2<<endl;
    }

    void run(){
        editSt(str1);
        editSt(str2);
    }
};

