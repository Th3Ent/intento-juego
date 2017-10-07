#include "obstaculo.hpp"

obstaculo::obstaculo(){
    obstac = false;
    inicio = false;
    fin = false;
}

obstaculo::obstaculo(bool ob, bool inicio_, bool fin_){
    obstac =  ob;
    inicio = inicio_;
    fin = fin_;
}

obstaculo::~obstaculo(){}

bool obstaculo::get_obstac(){
    return obstac;
}
void obstaculo::set_obstac(){
    obstac = true;
}

bool obstaculo::get_inicio(){
    return inicio;
}
void obstaculo::set_inicio(){
    inicio = true;
}

bool obstaculo::get_fin(){
    return fin;
}
void obstaculo::set_fin(){
    fin = true;
}
char obstaculo::get_estela(){
    return estela;
}

void obstaculo::set_estela(char estela_){
    estela = estela_;
}