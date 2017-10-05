#pragma once

#include <iostream>
#include <vector>
//#include <unistd.h>
#include <stdlib.h>

using namespace std;

class obstaculo{
    private:
        bool obstac;
        bool inicio;
        bool fin;
    public:
        
        obstaculo();
        obstaculo(bool ob, bool inicio_, bool fin_);
        ~obstaculo();
        
        bool get_obstac();
        void set_obstac();
        
        bool get_inicio();
        void set_inicio();
        
        bool get_fin();
        void set_fin();
};