#include "ciudad.hpp"

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"

int main(){
    for(int i = 0; i < 100; i++)
        cout<<endl;
    system("clear");
    
    int n_filas, n_columnas, n_obstaculos = 1, opc;
    
    cout << "\nIntroduzca número de filas: ";
    cin >> n_filas;
    cout << "\nIntroduzca número de columnas: ";
    cin >> n_columnas;
    
    int x_ini = 1, x_fin = 1, y_ini = 1, y_fin = 1;
    do{
        
    do{
    cout << "\nIntroducir inicio.\n X: ";
    cin >> x_ini;
    cout <<" Y: ";
    cin >> y_ini;
    if(x_ini > n_filas || x_ini > n_columnas)
        cout<<"\nValores imposibles, estan fuera de rango ";
    }while(x_ini > n_filas || y_ini > n_columnas);//Comprueba que esten en rango
    
    
    do{
    cout << "\nIntroducir fin. \n X: ";
    cin >> x_fin;
    cout << "Y: ";
    cin >> y_fin;
    if(x_fin > n_filas || x_fin > n_columnas)
        cout<<"\nValores imposibles, estan fuera de rango ";
    }while(x_fin > n_filas || y_fin > n_columnas);//Comprueba que esten en rango
    
    }while(x_fin == y_fin && x_ini == x_fin); //Compueba que el final y el principio no esten en el mismo cuadrante
    
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1);
    
    cout << "\nDecida como quiere los obstáculos:\n1.Aleatorio\n2.Manual(porcentaje)\n3.Manual(cantidad): ";
    do{
        cin >> opc;
        switch(opc){
            case 1:  
                    do{
                        cout <<"\nNumero de obstaculos: ";
                        cin>> n_obstaculos;
                        if(n_obstaculos > n_filas*n_columnas - 2)
                            cout<<"\n Demasiados obstaculos, el maximo son "<<n_filas*n_columnas;
                    }while(n_obstaculos > n_filas*n_columnas - 2);
                    citi.aleatorio(n_obstaculos);
                    break;
            case 2: cout << "\nIntroduce porcentaje: ";
                    int porcentaje;
                    while(porcentaje > 100){
                    cin >> porcentaje;
                    if(porcentaje > 100)
                        cout<<"\n El porcentaje maximo es 100% no "<<porcentaje;
                    }
                    n_obstaculos = (n_columnas*n_filas*porcentaje)/100;
                    citi.aleatorio(n_obstaculos);
                    break;
            case 3: cout << "\nNúmero de obstáculos: ";
                    cin >> n_obstaculos;
                    citi.manu_alea(n_obstaculos);
                    break;
            default: cout << "\nOpción incorrecta, escoja otra" << endl;
        }
    }while(opc > 3 || opc < 1);
    
    for(int i = 0; i < 10; i++)
        cout<<endl;
       
       
    char mov; 
    bool fin;
    do{
    system("clear");
    citi.pintar_ciudad();
    
    cout<<"\n :- ";
    cin>>mov;
    if(mov != 'q')
    fin = citi.mover_carro(mov);
    }while(!(fin || mov == 'q'));
    
    return 0;
    
}