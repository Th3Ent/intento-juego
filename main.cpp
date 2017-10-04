#include <iostream>

#include "ciudad.hpp"

using namespace std;

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"
// \xE2\x95\x94
int main(){
    system("clear");
    
    int n_filas, n_columnas, n_obstaculos, opc;
    
    cout << "\nIntroduzca número de filas: ";
    cin >> n_filas;
    cout << "\nIntroduzca número de columnas: ";
    cin >> n_columnas;
    
    int x_ini, x_fin, y_ini, y_fin;
    cout << "\nIntroducir inicio.\n X: ";
    cin >> x_ini;
    cout <<" Y: ";
    cin >> y_ini;
    
    cout << "\nIntroducir fin. \n X: ";
    cin >> x_fin;
    cout << "Y: ";
    cin >> y_fin;
    
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1);
    
    cout << "\nDecida como quiere los obstáculos:\n1.Aleatorio\n2.Manual(porcentaje)\n3.Manual(cantidad): ";
    do{
        cin >> opc;
        switch(opc){
            case 1: cout <<"\nNumero de obstaculos: "; 
                    cin>> n_obstaculos;
                    citi.aleatorio(n_obstaculos);
                    break;
            case 2: cout << "\nIntroduce porcentaje: ";
                    int porcentaje;
                    cin >> porcentaje;
                    n_obstaculos = (n_columnas*n_filas*porcentaje)/100;
                    break;
            case 3: cout << "\nNúmero de obstáculos: ";
                    cin >> n_obstaculos;
                    citi.manu_alea(n_obstaculos);
                    break;
            default: cout << "\nOpción incorrecta, escoja otra" << endl;
        }
    }while(opc > 3 || opc < 1);
    
    system("clear");
    citi.pintar_ciudad();
    
    return 0;
    
}