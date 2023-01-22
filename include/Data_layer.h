//
// Created by Артём Гудзенко on 22.01.2023.
//

#ifndef K_TECH_DATA_LAYER_H
#define K_TECH_DATA_LAYER_H
#include <string>

using namespace std;
class Data;

class Folder{
    Data *myfile;
public:
    void setPathToFile();

};

class Data{
protected:
    string wayToInpfile;
    string watToOutfile;

public:
    Data() = default;
    void setPath(string, string);
};

class MyFile:public Data{
    //File *file; //FILE - тип данных
public:
    void AnalyseData();
};
#endif //K_TECH_DATA_LAYER_H
