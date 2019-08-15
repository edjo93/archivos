#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;
string token(string , string , int );
void agregar();
void listar();
void eliminar();
void modificar();
int main(){
	/*
	string c="laurate,unitec;ceutec,tgu,proceres";
	cout<<token(token(c,",",2),";",2)<<endl;//token de token para obtener ceutec
	*/
	char opcion;
	do{
		cout<<"\na-agregar\nb-listar\nc-eliminar\nd-modificar\ne-salir\n?:";
		cin>>opcion;
		switch(opcion){
			case'a':
				agregar();
				break;
			case'b':
				listar();
				break;
			case'c':
				eliminar();
				break;
			case'd':
				modificar();
				break;
			case'e':
				break;
			default:
				cout<<"\nno ingreso una opcion correcta\n";
		}
	}while(opcion!='e');
	
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
//modificar es la mezcla entre escribir y leer y parsear


void eliminar(){
	fstream leer;
	ofstream escribir;
	vector<string> lista;
	string linea;
	int cent=0;
	leer.open("./prueba.txt");
	string codigo;
	cout<<"codigo a eliminar: ";
	cin>>codigo;
	while(!leer.eof()){//cargar al vector
		getline(leer,linea);
		if(token(linea,";",1)==codigo){
			cent=1;
		}else{
			if(linea[0]!='\0'){//no es eof
				lista.push_back(linea);
			}
			
		}
	}
	leer.close(); 
	//sobreescribir el archivo
	if(cent==1){
		escribir.open("./prueba.txt");
		for(int i=0;i<lista.size();i++){
			escribir<<lista[i]<<endl;
		}
	}
	
}

void modificar(){
	fstream leer;
	ofstream escribir;
	vector<string> lista;
	string linea;
	int cent=0;
	leer.open("./prueba.txt");
	string codigo;
	cout<<"codigo a modificar: ";
	cin>>codigo;
	while(!leer.eof()){//cargar al vector
		getline(leer,linea);
		if(token(linea,";",1)==codigo){
			cent=1;
			//si agrego el nodo pero modificado
			string vn,ve;
			cout<<"nombre: ";
			cin>>vn;
			cout<<"edad: ";
			cin>>ve;
			lista.push_back(codigo+";"+vn+";"+ve);
		}else{
			if(linea[0]!='\0'){//no es eof
				lista.push_back(linea);
			}
			
		}
	}
	leer.close(); 
	//sobreescribir el archivo
	if(cent==1){
		escribir.open("./prueba.txt");
		for(int i=0;i<lista.size();i++){
			escribir<<lista[i]<<endl;
		}
	}
	
}

