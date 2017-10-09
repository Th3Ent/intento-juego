#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>



using namespace std;

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"
#define KSRED "\x1B[91m"



class camino{
    
    public:
    
        char escr;
        
        camino();
        
      virtual int que_soy();
        
      virtual  ostream& print(ostream& os);
};

class obstaculo: public camino{
    
    public:
    
    obstaculo();
    
    ostream& print(ostream& os);
    
    int que_soy();

};

class inicio: public camino{
    
    public:
    
    inicio();
    
    ostream& print(ostream& os);
    
    int que_soy();
};

class fin: public camino{
    
    public:
    
    fin();
    
    ostream& print(ostream& os);
    
    int que_soy();
};


class estela: public camino{
    
    public:
    
    estela( char q);
    
    ostream& print(ostream& os);
    
    int que_soy();
};

class pipo: public camino{
    
    public:
     
    pipo();
    
    ostream& print(ostream& os);
    
    int que_soy();
    
};

