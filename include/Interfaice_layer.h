//
// Created by Артём Гудзенко on 22.01.2023.
//

#ifndef K_TECH_INTERFAICE_LAYER_H
#define K_TECH_INTERFAICE_LAYER_H


//
// Created by Артём Гудзенко on 22.01.2023.
//

#ifndef K_TECH_APPLICATION_H
#define K_TECH_APPLICATION_H

#include "Data_layer.h"

class Application {
    string inputWay;
    string outWay;
    Folder fl;

public:
    Application(string inputWay = "", string outWay = 0): inputWay(inputWay), outWay(outWay){}
    void start();
};


#endif //K_TECH_APPLICATION_H


#endif //K_TECH_INTERFAICE_LAYER_H
