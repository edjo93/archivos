#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
string token(string , string , int );
void agregar();
void listar();
int main(){
	/*
	string c="laurate,unitec;ceutec,tgu,proceres";
	cout<<token(token(c,",",2),";",2)<<endl;//token de token para obtener ceutec
	*/
	char opcion;
	do{
		cout<<"\na-agregar\nb-listar\nc-salir\n?:";
		cin>>opcion;
		switch(opcion){
			case'a':
				agregar();
				break;
			case'b':
				listar();
				break;
			case'c':
				cout<<"\nhasta luego\n"	;
				break;
			default:
				cout<<"\nno ingreso una opcion correcta\n";
		}
	}while(opcion!='c');
	
	return 0;
}

string token(string cadena, string divisor, int pos){
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}
void agregar(){
	string c,n,e;
	cout<<"codigo: ";cin>>c;
	cout<<"nombre: ";cin>>n;
	cout<<"edad: " ;cin>>e;
	ofstream escribir;
	escribir.open("./prueba.txt",ios::app);
	escribir<<c<<";"<<n<<";"<<e<<endl;
	escribir.close();
}
void listar(){
	fstream leer;
	string linea;
	leer.open("./prueba.txt");
	while(!leer.eof()){
		getline(leer,linea);
		if(linea.size()>0){
			cout<<token(linea,";",1)+" "
			+token(linea,";",2)+" "
			+token(linea,";",3)+" "<<endl;
		}
		
	}
		
}

