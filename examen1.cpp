#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
        //menu con fin centinela
        //mientras no se seleccione la opcion de salida el menu continua
        char opcion;
        do{
                cout<<"\ningrese una opcion\n1.comenzar\n2.salir\n\n?:";cin>>opcion;
                //la opcion es procesada en una estructura de casos
                switch(opcion){
                        case '1':
                                
                                
                                break;
                        
                        case '2':
                                cout<<"\nhasta luego"<<endl;
                                break;

                        default:cout<<"\nno ingreso una opcion correcta/intente de nuevo"<<endl;
                }
        }while(opcion!='2');
        
        
        
        
}
