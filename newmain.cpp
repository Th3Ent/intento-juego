#include "ciudad.hpp"

//JIAQI ES GUAPO 

int primer_nivel(){
    for(int i = 0; i < 100; i++)
        cout<<endl;
        
    system("clear");
    
    int n_filas = 15, n_columnas = 15, porcentaje = 20;
    int x_ini = 1, x_fin = 15, y_ini = 1, y_fin = 15;
    
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1, 72, 1);
    citi.aleatorio((n_columnas*n_filas*porcentaje)/100);
    char mov = 's'; 
    bool fin=false;
    citi.set_mon(10);
    system("clear");
    citi.pintar_ciudad();
    int tiempo;
    do{
    
    usleep(41667);
    
    initscr();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	echo();
	
    mov = getch();
    refresh();
    endwin();
    
    tiempo++;
    tiempo = citi.contr_mon(tiempo);
    
    if(mov == 'p' &&  mov!= ERR)
        citi.realeatorio((n_columnas*n_filas*porcentaje)/100);
    else if(mov == 'P' &&  mov!= ERR)
            citi.realeatorio((n_columnas*n_filas*porcentaje)/100, x_ini-1, y_ini-1);
         else if(mov == 'o' &&  mov!= ERR)
                citi.set_obstac();
             else if(mov == 'l' &&  mov!= ERR)
                    citi.elim_obstac();
                 else if(mov != 'q' &&  mov!= ERR){
                        fin = citi.mover_carro(mov);
                        for(int i = 0; i < 100; i++)
                            cout<<endl;
                        system("clear");
                        citi.pintar_ciudad();
                     }
    }while(!(fin || mov == 'q'));
    if(fin)
        cout<<"\nPasando a la fase 2\n\n";
        usleep(1000000);
    return citi.puntuacion;
}


int segundo_nivel(int pun){
    for(int i = 0; i < 100; i++)
        cout<<endl;
    system("clear");
    int n_filas = 20, n_columnas = 20, porcentaje = 25;
    int x_ini = 1, x_fin = 20, y_ini = 1, y_fin = 20;
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1, 96, 2);
    citi.aleatorio((n_columnas*n_filas*porcentaje)/100);
    citi.puntuacion = pun;
    char mov = 's'; 
    bool fin=false;
    citi.set_mon(20);
    system("clear");
    citi.pintar_ciudad();
    int tiempo;
    do{
    
    usleep(41667);
    
    initscr();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	echo();
	
    mov = getch();
    refresh();
    endwin();
    
    tiempo++;
    tiempo = citi.contr_mon(tiempo);
    
    if(mov == 'p' &&  mov!= ERR)
        citi.realeatorio((n_columnas*n_filas*porcentaje)/100);
    else if(mov == 'P' &&  mov!= ERR)
            citi.realeatorio((n_columnas*n_filas*porcentaje)/100, x_ini-1, y_ini-1);
         else if(mov == 'o' &&  mov!= ERR)
                citi.set_obstac();
             else if(mov == 'l' &&  mov!= ERR)
                    citi.elim_obstac();
                 else if(mov != 'q' &&  mov!= ERR){
                        fin = citi.mover_carro(mov);
                        for(int i = 0; i < 100; i++)
                            cout<<endl;
                        system("clear");
                        citi.pintar_ciudad();
                     }
    }while(!(fin || mov == 'q'));
    if(fin)
        cout<<"\nPasando a la fase 3\n\n";
        usleep(1000000);
    return citi.puntuacion;
    
}

int tercer_nivel(int pun){
    for(int i = 0; i < 100; i++)
        cout<<endl;
    system("clear");
    int n_filas = 25, n_columnas = 25, porcentaje = 30;
    int x_ini = 1, x_fin = 25, y_ini = 1, y_fin = 25;
    ciudad citi(n_filas, n_columnas, x_ini-1, x_fin-1, y_ini-1, y_fin-1, 120, 3);
    citi.aleatorio((n_columnas*n_filas*porcentaje)/100);
    citi.puntuacion = pun;
    char mov = 's'; 
    bool fin = false;
    citi.set_mon(30);
    system("clear");
    citi.pintar_ciudad();
    int tiempo;
    do{
    
    usleep(41667);
    
    initscr();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	echo();
	
    mov = getch();
    refresh();
    endwin();
    
    tiempo++;
    tiempo = citi.contr_mon(tiempo);
    
    if(mov == 'p' &&  mov!= ERR)
        citi.realeatorio((n_columnas*n_filas*porcentaje)/100);
    else if(mov == 'P' &&  mov!= ERR)
            citi.realeatorio((n_columnas*n_filas*porcentaje)/100, x_ini-1, y_ini-1);
         else if(mov == 'o' &&  mov!= ERR)
                citi.set_obstac();
             else if(mov == 'l' &&  mov!= ERR)
                    citi.elim_obstac();
                 else if(mov != 'q' &&  mov!= ERR){
                        fin = citi.mover_carro(mov);
                        for(int i = 0; i < 100; i++)
                            cout<<endl;
                        system("clear");
                        citi.pintar_ciudad();
                     }
    }while(!(fin || mov == 'q'));
    
        usleep(1000000);
        cout<<"\nFIN DEL JUEGO\n\n";
        usleep(1000000);
    return citi.puntuacion;
}
int main(){
    
    int punt = primer_nivel();
    punt = segundo_nivel(punt);
    punt = tercer_nivel(punt);
    cout<<"\nTU PUNTUACIÒN ES DE: "<<punt<<endl<<endl;;
    
    return 0;
    
}


//g++ -std=c++11 *.cpp -lncurses -fpermissive