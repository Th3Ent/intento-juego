#include "ciudad.hpp"
#define TAM 50
#define POR 30
#define OBS 75
#define CHO 2

int main(){
    for(int i = 0; i < 100; i++)
        cout<<endl;
    system("clear");
    
    int n_filas = TAM, n_columnas = TAM, n_obstaculos = OBS, opc = CHO;
    int porcentaje = POR;
    cout << "\nIntroduzca número de filas: ";
  //  cin >> n_filas;
    cout << "\nIntroduzca número de columnas: ";
//    cin >> n_columnas;
    
    int x_ini = 1, x_fin = TAM, y_ini = 1, y_fin = TAM;
    do{
        
    do{
    cout << "\nIntroducir inicio.\n X: ";
  //  cin >> x_ini;
    cout <<" Y: ";
//    cin >> y_ini;
    if(x_ini > n_filas || x_ini > n_columnas)
        cout<<"\nValores imposibles, estan fuera de rango ";
    }while(x_ini > n_filas || y_ini > n_columnas);//Comprueba que esten en rango
    
    
    do{
    cout << "\nIntroducir fin. \n X: ";
 //   cin >> x_fin;
    cout << "Y: ";
  //  cin >> y_fin;
    if(x_fin > n_filas || x_fin > n_columnas)
        cout<<"\nValores imposibles, estan fuera de rango ";
    }while(x_fin > n_filas || y_fin > n_columnas);//Comprueba que esten en rango
    
    }while(x_fin == y_fin && x_ini == x_fin); //Compueba que el final y el principio no esten en el mismo cuadrante
    
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1);
    
    cout << "\nDecida como quiere los obstáculos:\n1.Aleatorio\n2.Manual(porcentaje)\n3.Manual(cantidad): ";
    do{
    //    cin >> opc;
        switch(opc){
            case 1:  
                    do{
                        cout <<"\nNumero de obstaculos: ";
      //                  cin>> n_obstaculos;
                        if(n_obstaculos > n_filas*n_columnas - 2)
                            cout<<"\n Demasiados obstaculos, el maximo son "<<n_filas*n_columnas;
                    }while(n_obstaculos > n_filas*n_columnas - 2);
                    citi.aleatorio(n_obstaculos);
                    break;
            case 2: cout << "\nIntroduce porcentaje: ";
                    
                    while(porcentaje > 101){
        //            cin >> porcentaje;
                    if(porcentaje > 101)
                        cout<<"\n El porcentaje maximo es 100% no "<<porcentaje;
                    }
                    n_obstaculos = (n_columnas*n_filas*porcentaje)/100;
                    if(n_obstaculos == n_columnas*n_filas)
                        n_obstaculos = n_obstaculos-2;
                    
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
    system("clear");
    citi.pintar_ciudad();
    
    do{
    
    usleep(50000);
    
    initscr();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	echo();
	
    mov = getch();
    refresh();
    endwin();
    
    if(mov == 'p' &&  mov!= ERR)
        citi.realeatorio(n_obstaculos);
    else if(mov == 'P' &&  mov!= ERR)
            citi.realeatorio(n_obstaculos, x_ini-1, y_ini-1);
         else if(mov == 'o' &&  mov!= ERR)
                citi.set_obstac();
             else if(mov == 'l' &&  mov!= ERR)
                    citi.elim_obstac();
                 else if(mov != 'q' &&  mov!= ERR){
                        fin = citi.mover_carro(mov);
                        system("clear");
                        citi.pintar_ciudad();
                     }
    }while(!(fin || mov == 'q'));
    if(fin)
        cout<<"\nFELICIDADES! LLEGASTE AL DESTINO\n\n";
    
    return 0;
    
}


//g++ -std=c++11 *.cpp -lncurses -fpermissive