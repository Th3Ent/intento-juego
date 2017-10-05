#include "ciudad.hpp"
    
ciudad::ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin){
    city.resize(x);
    for(int i = 0; i < x; i++){
        city[i].resize(y);
    }
    
    pos_x = x;
    pos_y = y;
    carro.pos_x = x_ini;
    carro.pos_y = y_ini;
    city[x_ini][y_ini].set_inicio();
    city[x_fin][y_fin].set_fin();
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
            else if(city[i][j].get_fin())
                cout << KYEL " \xc2\xa4";
            else if(city[i][j].get_obstac())
                cout << KCYN " \xe2\x95\xac";
            else if(city[i][j].get_inicio()) //\xc2\xb1 es lo mas parecido a un coche
                cout << KRED " X";
            else
                cout<< "  ";
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
        city[x][y].set_obstac();
    }
}
  
void ciudad::aleatorio(int n){
    
    srand(time(NULL));
    while(n > 0){  
        int x, y;
        x = rand() % pos_x;
        y = rand() % pos_y;
        if(!(city[x][y].get_fin() || city[x][y].get_inicio() || city[x][y].get_obstac() )){
        city[x][y].set_obstac();
        n--;
        }
    }
}

bool ciudad::mover_carro(char mov){
    //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
    switch(mov){
        case 'a': if(!city[carro.pos_x][carro.pos_y-1].get_obstac() && (carro.pos_y-1 >= 0 ))
                  carro.pos_y--;
                  break;
        case 's': if( (carro.pos_x+1 < pos_x) && !city[carro.pos_x+1][carro.pos_y].get_obstac())
                  carro.pos_x++;
                  break;
        case 'd': if(!city[carro.pos_x][carro.pos_y+1].get_obstac() && (carro.pos_y+1 < pos_y))
                  carro.pos_y++;
                  break;
        case 'w': if((carro.pos_x-1 >= 0) && !city[carro.pos_x-1][carro.pos_y].get_obstac())
                  carro.pos_x--;
                  break;
        default: cout<<"\nMovimiento erroneo";
        
        
    }
    if(city[carro.pos_x][carro.pos_y].get_fin()){
        system("clear");
        pintar_ciudad();
        cout<<"\nFELICIDADES! LLEGASTE AL DESTINO\n\n";
            return true;
    }
        else
            return false;
    //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
}