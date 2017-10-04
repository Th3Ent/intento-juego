#include "obstaculo.hpp"
#include <iostream>
#include <vector>
//#include <unistd.h>
#include <stdlib.h>

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"

typedef struct{
    int pos_x;
    int pos_y;
    char car = '^';
} coche;

class ciudad{
    
    vector<vector<obstaculo> > city;
    int pos_x;
    int pos_y;
    coche carro;
  public:
    
    ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin){
        city.resize(x);
        for(int i=0;i<x;i++){
            city[i].resize(y);
        }
        
        pos_x = x;
        pos_y = y;
        carro.pos_x = x;
        carro.pos_y = y;
        city[x_ini][y_ini].set_inicio();
        city[x_fin][y_fin].set_fin();
        
    }
   
   
  void pintar_ciudad(void){
      
      cout<<endl;
      
        for(int k = 0; k < pos_y ; k++)
            if(k != 0 || k!=pos_y-1)
                cout<< KGRN "-";
            else
                cout<<" ";
        cout<<endl;
      
      for(int i=0; i<pos_x;i++){
          
          cout<< KGRN "| ";
          for(int j=0 ; j<pos_y ; j++){
              
              if(carro.pos_x == i && carro.pos_y == j)
                  cout<<carro.car;
              else if(city[i][j].get_fin())
                  cout<< KYEL "O";
               else if(city[i][j].get_obstac())
                cout<< KCYN "#";
                else if(city[i][j].get_inicio())
                    cout << KRED "X";
               else
                cout<< " ";
          }
          
          cout<< KGRN " |"<<endl;
      }
      
        for(int k = 0; k < pos_y ; k++)
            if(k != 0 && k!=pos_y-1) 
                cout<< KGRN "-";
            else    
                cout<<" ";
        cout<<endl;
      
  }
  
  void manu_alea(int n){
      int x, y;
      for(int i = 0; i < n; i++){
          cout << "Introduce la posicion X del obstaculo: "<<i+1<<": ";
          cin >> x;
          cout << "Introduce la posicion Y del obstaculo: "<<i+1<<": ";
          cin >> y;
          
          city[x][y].set_obstac();
      }
  }
  
  void aleatorio(int n){
      srand(15);
      while(n > 0){  //para?
          int x, y;
          x = rand() % pos_x;
          y = rand() % pos_y;
          
          city[x][y].set_obstac();
          n--;
      }
  }
};