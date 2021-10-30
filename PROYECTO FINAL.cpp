#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;


const char *nombre_archivo = "archivo.dat";

struct Palabras{
	int id;
	char palabra [30];
	char traducccion [30];
	char descripcion [100];
};
// referencias
void ingresar_palabra();
void abrir_palabras();
void actualizar_palabra();
void eliminar_palabra();
void traducir_codigo();
void lectura();
// CODIGO PRINCIPAL 
int main(){
	
	
	char menu;
	short int opcion;
	do{ 
	system("cls");
	cout<<"Bienvenido al menu:"<<endl;
	cout<<"1)Ingresar palabra:"<<endl;
	cout<<"2)Actualizar"<<endl;
	cout<<"3)Eliminar"<<endl;
	cout<<"4)Revisar"<<endl;
	cout<<"5)Codigo traducido"<<endl;
	cin>>opcion;
	switch (opcion){
		
	case 1: system("cls");ingresar_palabra(); break;	
	case 2: system("cls"); actualizar_palabra(); break;
	case 3: system("cls"); eliminar_palabra(); break; 
	case 4: system("cls"); abrir_palabras();	break;
	case 5: system ("cls"); lectura(); break;
	}
		cout<<"Desea regresar al menu  s/n"<<endl;
		cin>>menu;

}while (menu=='s'||menu=='S');
}
//METODOS
void eliminar_palabra(){
		FILE* archivo = fopen(nombre_archivo,"r+b");
	int id,del;
	Palabras palabras;
	string palabra, traduc, descrip;
	cout<<"INGRESE EL ID DE LA PALABRA QUE DESEA ELIMINAR: "<<endl;
	cin>>id;
	id-=1;
	fseek ( archivo, id * sizeof(Palabras), SEEK_SET );
	palabras.id=del;
	strcpy(palabras.palabra,palabra.c_str());
	strcpy(palabras.traducccion,traduc.c_str());
	strcpy(palabras.descripcion,descrip.c_str());
	fwrite(&palabras,sizeof(Palabras),1,archivo);
	fclose(archivo);
	abrir_palabras();
	system("pause");
}

void actualizar_palabra(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Palabras palabras;
	string palabra, traduc, descrip;
	cout<<"INGRESE EL ID DE LA PALABRA QUE DESEA MODIFICAR: "<<endl;
	cin>>id;
	id-=1;
	fseek ( archivo, id * sizeof(Palabras), SEEK_SET );
	
		cout<<"INGRESE EL ID"<<endl;
		cin>>palabras.id;
		cin.ignore();
		
		cout<<"INGRESE LA PALABRA"<<endl;
		getline(cin,palabra);
		strcpy(palabras.palabra,palabra.c_str());
		
		cout<<"INGRESE LA TRADUCCION"<<endl;
		getline(cin,traduc);
		strcpy(palabras.traducccion,traduc.c_str());

		cout<<"INGRESE LA DESCRIPCION"<<endl;
		getline(cin,descrip);
		strcpy(palabras.descripcion,descrip.c_str());
		
	fwrite(&palabras,sizeof(Palabras),1,archivo);
	fclose(archivo);
	abrir_palabras();
	system("pause");
}


void ingresar_palabra(){
	char continua;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Palabras palabras;
	string palabra, traduc, descrip;
	do{
		fflush(stdin);
		
		cout<<"INGRESE EL ID"<<endl;
		cin>>palabras.id;
		cin.ignore();
		
		cout<<"INGRESE LA PALABRA"<<endl;
		getline(cin,palabra);
		strcpy(palabras.palabra,palabra.c_str());
		
		cout<<"INGRESE LA TRADUCCION"<<endl;
		getline(cin,traduc);
		strcpy(palabras.traducccion,traduc.c_str());

		cout<<"INGRESE LA DESCRIPCION"<<endl;
		getline(cin,descrip);
		strcpy(palabras.descripcion,descrip.c_str());
		
		fwrite(&palabras,sizeof(Palabras),1,archivo);
		cout<<"DESEA INGRESAR UN NUEVO ELEMENTO         s/n"<<endl;
		cin>>continua;
	}while((continua=='s')||(continua=='S'));
	fclose(archivo);
}

void abrir_palabras(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo= fopen(nombre_archivo,"w+b");
	}
	Palabras palabras;
	int id =0;
	fread(&palabras,sizeof(Palabras),1,archivo);
	cout<<"____________________________________________________"<<endl;
	cout<<"ID |PALABRA"<<"|"<<"TRADUCCION"<<"|"<<"DESCRIPCION"<<endl;
	do{
	cout<<"___________________________________________________"<<endl;
	cout<<palabras.id<<"|"<<palabras.palabra<<"|"<<palabras.traducccion<<"|"<<palabras.descripcion<<endl;
	fread(&palabras,sizeof(Palabras),1,archivo);
	
	}while(feof(archivo)==0);
	
	fclose(archivo);

}

void traducir_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo= fopen(nombre_archivo,"w+b");
	}
	Palabras palabras;
	int id =0;
	fread(&palabras,sizeof(Palabras),1,archivo);

	do{

	
	fread(&palabras,sizeof(Palabras),1,archivo);
	
	}while(feof(archivo)==0);
	
	fclose(archivo);

}

void lectura(){
	ifstream archivo;
	string texto;
	
	archivo.open("traducido.txt",ios::in);//aca se abre nuestro archivo
	
	if(archivo.fail()){
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}







