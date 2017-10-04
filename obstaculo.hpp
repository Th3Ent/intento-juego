#include <iostream>
using namespace std;

class obstaculo{
    private:
        bool obstac;
        bool inicio;
        bool fin;
    public:
        
        obstaculo(){
            obstac = false;
            inicio = false;
            fin = false;
        }
        
        obstaculo(bool ob, bool inicio_, bool fin_){
            obstac =  ob;
            inicio = inicio_;
            fin = fin_;
        }
        
        bool get_obstac(){
            return obstac;
        }
        void set_obstac(){
            obstac = true;
        }
        
        bool get_inicio(){
            return inicio;
        }
        void set_inicio(){
            inicio = true;
        }
        
        
        bool get_fin(){
            return fin;
        }
        void set_fin(){
            fin = true;
        }
};