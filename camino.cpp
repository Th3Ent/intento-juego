#include "camino.hpp"
        
    camino::camino(){
        escr = ' ';
    }
        
     int camino::que_soy(){
        return 0;
    }
        
    ostream& camino::print(ostream& os){
        os <<" "<<escr;
        return os;
    }

//·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~
    
    estela::estela( char q){
        escr = q;
    }
    
    ostream& estela::print(ostream& os){
    //    os <<KSRED" "<<escr;
        os <<KSRED"  ";
        return os;
    }
    
    int estela::que_soy(){
        return 1;
    }
    
//·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~    
    
    obstaculo::obstaculo(){
        escr = '#';
    }
    
    ostream& obstaculo::print(ostream& os){
        os <<KCYN " \xe2\x95\xac";
        return os;
    }
    
    int obstaculo::que_soy(){
        return 2;
    }

//·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~

    
    inicio::inicio(){
        escr = 'X';
    }
    
    ostream& inicio::print(ostream& os){
        os <<KRED" "<<escr;
        return os;
    }
    
    int inicio::que_soy(){
        return 3;
    }

//·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~
    
    fin::fin(){
        escr = 'O';
    }
    
    ostream& fin::print(ostream& os){
        os <<KYEL" \xc2\xa4";
        return os;
    }
    
    int fin::que_soy(){
        return 4;
    }

 //·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~   
    
    pipo::pipo(){
        escr = 'T';
    }
    
    ostream& pipo::print(ostream& os){
        os <<KYEL" \xc3\x9e";
        
    }
    
    int pipo::que_soy(){
        return 5;
    }
    
 //·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~   
    
    moneda::moneda(){
        escr = 'M';
    }
    
    ostream& moneda::print(ostream& os){
        os <<KBLACK" \xc3\x9f";
    }
    
    int moneda::que_soy(){
        return 6;
    }
    


