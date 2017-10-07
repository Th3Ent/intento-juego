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
        char estela = ' ';
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
        
        char get_estela();
        void set_estela(char estela_);
};