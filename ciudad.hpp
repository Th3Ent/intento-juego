#pragma once

#include "camino.hpp"



typedef struct{
    int pos_x;
    int pos_y;
    char car = '^';
} coche;

class ciudad{
  
  public:
  
    vector<vector<camino*> > city;
    int pos_x;
    int pos_y;
    coche carro;
    

    
    ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin);
    ~ciudad();
    
    void pintar_ciudad(void);
    void manu_alea(int n);
    void aleatorio(int n);
    void realeatorio(int n);
    void realeatorio(int n, int x, int y);
    bool mover_carro(char mov);
    void set_obstac();
    
};








// \xe2\x95\x91 borde lateral
// \xe2\x95\x90 borde superior
// \xe2\x95\x94 esi
// \xe2\x95\x9a eii
// \xe2\x95\x9d eid
// \xe2\x95\x97 esd