#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

//prototipos de funcion
char** provisionar_matriz(int);
void imprimir_matriz(char**,int);
void liberar_matriz(char**,int);
void crear_tablero(char**,int );
void jugar(char**,int );
bool pieza_valida(char**,int,int ,char );

int main(){
        int size=11;
        char**matriz=NULL;
        //menu con fin centinela
        //mientras no se seleccione la opcion de salida el menu continua
        char opcion;
        do{
                cout<<"\ningrese una opcion\n1.comenzar\n2.salir\n\n?:";cin>>opcion;
                //la opcion es procesada en una estructura de casos
                switch(opcion){
                        case '1':
                                
                                matriz=provisionar_matriz(size);
                                //crear el tablero
                                crear_tablero(matriz,size);
                                //imprimir matriz
                                imprimir_matriz(matriz,size);
                                
                                //comienza el juego
                                
                                //no olvidemos liberar memoria dinamica
                                liberar_matriz(matriz,size);
                                break;
                        
                        case '2':
                                cout<<"\nhasta luego"<<endl;
                                break;

                        default:cout<<"\nno ingreso una opcion correcta/intente de nuevo"<<endl;
                }
        }while(opcion!='2');
        
        
        
        
}

//definicion de funciones
char** provisionar_matriz(int size){
	char**matriz=NULL;

	matriz=new char*[size];//reservando memoria lara las filas

	for(int i=0;i<size;i++){
		matriz[i]=new char[size];//reservando memoria para las columnas
	}

	return matriz;
}
void imprimir_matriz(char** matriz,int size){
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}
void liberar_matriz(char** matriz,int size){
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

void crear_tablero(char**matriz,int size){
        //se crea una matriz de 11*11
       
	//llenar con espacios vacios
        
        for(int x=0;x<size;x++){
                for(int y=0;y<size;y++){
                        matriz[x][y]=' ';
                        
                }
                
        }
        
        //recorremos la matriz y vamos a ir poniendo piezas segun sea el caso
        for(int x=0;x<size;x++){
                for(int y=0;y<size;y++){
                        if(y==0||y==size-1){
				matriz[size/2][y]='n';
				matriz[(size/2)+1][y]='n';
				matriz[(size/2)-1][y]='n';
			}
                        
                        if(x==0||x==size-1){
				matriz[x][size/2]='n';
				matriz[x][(size/2)+1]='n';
				matriz[x][(size/2)-1]='n';
			}
			
			if(y==1||y==size-2){
				//matriz[size/2][y]='n';
				matriz[(size/2)+1][y]='n';
				matriz[(size/2)-1][y]='n';
			}
                        
                        if(x==1||x==size-2){
				//matriz[x][size/2]='n';
				matriz[x][(size/2)+1]='n';
				matriz[x][(size/2)-1]='n';
			}
			
			if(y==2||y==size-3){
				matriz[size/2][y]='n';
				//matriz[(size/2)+1][y]='n';
				//matriz[(size/2)-1][y]='n';
			}
                        
                        if(x==2||x==size-3){
				matriz[x][size/2]='n';
				//matriz[x][(size/2)+1]='n';
				//matriz[x][(size/2)-1]='n';
			}
			
			if(y==3||y==size-4){
				matriz[size/2][y]='b';
				//matriz[(size/2)+1][y]='n';
				//matriz[(size/2)-1][y]='n';
			}
                        
                        if(x==3||x==size-4){
				matriz[x][size/2]='b';
				//matriz[x][(size/2)+1]='n';
				//matriz[x][(size/2)-1]='n';
			}
			
			if(y==4||y==size-5){
				matriz[size/2][y]='b';
				matriz[(size/2)+1][y]='b';
				matriz[(size/2)-1][y]='b';
			}
                        
                        if(x==4||x==size-5){
				matriz[x][size/2]='b';
				matriz[x][(size/2)+1]='b';
				matriz[x][(size/2)-1]='b';
			}
			
			if(x==size/2&&y==size/2){
				matriz[x][y]='w';
			}
			
			//marcar las ezquinas
			
			if(x==0&&y==0){
                                matriz[x][y]='x';
                                
                        }
                        
                        if(x==0&&y==size-1){
                                matriz[x][y]='x';
                                
                        }
                        if(x==size-1&&y==0){
                                matriz[x][y]='x';
                                
                        }
                        if(x==size-1&&y==size-1){
                                matriz[x][y]='x';
                                
                        }
                        
                }
                
        }
        
}

void jugar(char**matriz,int size){
        //la matriz esta lista para el juego
        string entrada;
        cout<<"turno n - ingrese coordena en formato especificado ejmp:[A-0] ";
        cin>>entrada;
                
        //suponiendo validacion de entrada
        
        //turno piezas negras
        while(!pieza_valida(matriz,4,0,'n')){
                cout<<" pieza invalida -> turno n - ingrese coordena en formato especificado ejmp:[A-0] ";
                cin>>entrada;
                //suponiendo validacion de entrada
                
        }

                
}

bool pieza_valida(char** matriz,int x,int y,char pieza){
        if(matriz[x][y]==pieza){
                return true;
                
        }else{
                return false;
                
        }
        
}
