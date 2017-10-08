#include "ciudad.hpp"
    
ciudad::ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin){
    city.resize(x);
    for(int i = 0; i < x; i++){
        city[i].resize(y);
    }
    
    
    for(int i = 0; i< x; i++)
        for(int j = 0; j <y; j++)
            city[i][j] = new camino();

    pos_x = x;
    pos_y = y;
    carro.pos_x = x_ini;
    carro.pos_y = y_ini;
    city[x_ini][y_ini] = new inicio();
    city[x_fin][y_fin] = new fin();
}

ciudad::~ciudad(){}

void ciudad::pintar_ciudad(void){
        
    cout << endl << KGRN " \xe2\x95\x94";
    for(int k = 0; k < pos_y ; k++)
        if(k != 0 || k != pos_y-1)
            cout << KGRN "\xe2\x95\x90\xe2\x95\x90";
        else
            cout <<" ";
    cout << KGRN "\xe2\x95\x90\xe2\x95\x97" << endl;

    for(int i=0; i<pos_x;i++){
          
        cout<< KGRN " \xe2\x95\x91";
        for(int j=0 ; j<pos_y ; j++){
              
            if(carro.pos_x == i && carro.pos_y == j)
                cout <<RSD " "<<carro.car;
            else city[i][j]->print(cout);
        }
        cout<< KGRN " \xe2\x95\x91"<<endl;
    }
    cout << KGRN " \xe2\x95\x9a";
    for(int k = 0; k < pos_y ; k++)
        cout<< KGRN "\xe2\x95\x90\xe2\x95\x90";
    cout << KGRN "\xe2\x95\x90\xe2\x95\x9d" << endl;
}
  
void ciudad::manu_alea(int n){
    int x, y;
    for(int i = 0; i < n; i++){
        cout << "Introduce la posicion X del obstaculo: "<< i+1 <<": ";
        cin >> x;
        cout << "Introduce la posicion Y del obstaculo: "<< i+1 <<": ";
        cin >> y;
        city[x][y] = new obstaculo();
    }
}
  
void ciudad::aleatorio(int n){
    
    srand(time(NULL));
    while(n > 0){  
        int x, y;
        x = rand() % pos_x;
        y = rand() % pos_y;
        if(city[x][y]->que_soy() < 3){
        city[x][y] = new obstaculo();
        n--;
        }
    }
}

bool ciudad::mover_carro(char mov){
    //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
    switch(mov){
        case 'a': if( (carro.pos_y-1 >= 0 ) && (city[carro.pos_x][carro.pos_y-1]->que_soy() != 2  )){
                  carro.pos_y--;
                  carro.car = '<';
                  if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
                  city[carro.pos_x][carro.pos_y] = new estela('-');
                }
                  break;
        case 's': if( ((carro.pos_x+1 < pos_x) && city[carro.pos_x+1][carro.pos_y]->que_soy() != 2)){
                  carro.pos_x++;
                  carro.car = 'v';
                  if((city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 ))
                  city[carro.pos_x][carro.pos_y] = new estela('|');
                }
                  break;
        case 'd': if( (carro.pos_y+1 < pos_y) && (city[carro.pos_x][carro.pos_y+1]->que_soy() != 2  )){
                  carro.pos_y++;
                  carro.car = '>';
                  if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
                  city[carro.pos_x][carro.pos_y] = new estela('-');
                }
                  break;
        case 'w': if(((carro.pos_x-1 >= 0) && city[carro.pos_x-1][carro.pos_y]->que_soy() != 2)){
                  carro.pos_x--;
                  carro.car = '^';
                  if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
                  city[carro.pos_x][carro.pos_y]  = new estela('|');
                }
                  break;
        default: cout<<"\nMovimiento erroneo";
        
        
    }
    if(city[carro.pos_x][carro.pos_y]->que_soy() == 4){
            return true;
    }
        else
            return false;
    //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
}