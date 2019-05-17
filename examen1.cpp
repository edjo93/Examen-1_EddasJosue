#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//prototipos de funcion
int** provisionar_matriz(int);
void imprimir_matriz(int**,int);
void liberar_matriz(int**,int);


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

//definicion de funciones
int** provisionar_matriz(int size){
	int**matriz=NULL;

	matriz=new int*[size];//reservando memoria lara las filas

	for(int i=0;i<size;i++){
		matriz[i]=new int[size];//reservando memoria para las columnas
	}

	return matriz;
}
void imprimir_matriz(int** matriz,int size){
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}
void liberar_matriz(int** matriz,int size){
	for(int i=0;i<size;i++){
		if(matriz[i]!=NULL){
			delete[] matriz[i];
			matriz[i]=NULL;

		}
	}	
	


	if(matriz!=NULL){
		delete[] matriz;
		matriz=NULL;
	}
}
