//
// Created by Артём Гудзенко on 25.01.2023.
//


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

