#pragma once

#include "obstaculo.hpp"

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"
#define KSRED "\x1B[91m"

typedef struct{
    int pos_x;
    int pos_y;
    char car = '^';
} coche;

class ciudad{

  private:
    vector<vector<obstaculo> > city;
    int pos_x;
    int pos_y;
    coche carro;
    
  public:
    
    ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin);
    ~ciudad();
    
    void pintar_ciudad(void);
    void manu_alea(int n);
    void aleatorio(int n);
    bool mover_carro(char mov);
    
};








// \xe2\x95\x91 borde lateral
// \xe2\x95\x90 borde superior
// \xe2\x95\x94 esi
// \xe2\x95\x9a eii
// \xe2\x95\x9d eid
// \xe2\x95\x97 esd