#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<string>
using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"Bienvenido"<<endl;
	cout<<"1. Agregar Palabra"<<endl;
	cout<<"2. Ver Palabras"<<endl;
	cout<<"3. Buscar Palabra"<<endl;
	cout<<"4. Modificar Palabra"<<endl;
	cout<<"5. salir"<<endl;
	cin>>x;
	return x;
}



void agregar(ofstream &es){
	system("cls");
	string pal;
	string tra;
	string sig, pal1;
	es.open("Palabras.txt", ios::out | ios::app);
	if(es.fail()){
		cout<<"no se pudo abrir";
		exit(1);
	}

	cout<<"INGRESE LOS DATOS QUE USTED DESEA"<<endl;
	getline(cin,pal1);
	cout<<"Palabra: "<<endl;
	getline(cin,pal);
	cout<<"Traduccion: ";
	getline(cin,tra);
	cout<<"Significado: ";
	getline(cin,sig);
	es<<pal<<" "<<tra<<" "<<sig<<"\n";			
	
	es.close();
}

void verRegistros(ifstream &Lec){
	system("cls");
	string pal;
	string tra;
	string sig;

	
	Lec.open("Palabras.txt", ios::in);
	if(Lec.is_open()){	
		cout<<"--------------Palabras Registrados------------------"<<endl<<endl;
		Lec>>pal;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>sig;
			
			if (!Lec.eof() ){
				cout<<"Palabra-"<<pal<<endl;
				cout<<"Traducción: "<<tra<<endl;
				cout<<"Significado: "<<sig<<endl;
			cout<<"-----------------------------------------------"<<endl;
			Lec>>pal;
			}
				
		}
		Lec.close();
	}else
		cout<<"error"<<endl;
		system("pause");
}


void buscarPersona(ifstream &Lec){
	system("cls");
	Lec.open("Palabras.txt", ios::in);
	string pal, tra, sig, codigoaux;
	bool encontrado = false;
	cout<<"Digite el nombre: ";
	cin>>codigoaux;
	Lec>>pal;
	while(!Lec.eof()&&!encontrado){
		Lec>>tra;
		Lec>>sig;
		
		
		if(pal==codigoaux){
			cout<<"palabra-----------: "<<pal<<endl;
			cout<<"traduccion-----------: "<<tra<<endl;
			cout<<"significado-----------: "<<sig<<endl;
			
			cout<<"-----------------------------------------------"<<endl;
			encontrado = true;	
		}
		
		Lec>>pal;
	}
	Lec.close();
	if (!encontrado)
		cout<<"dato no encontrado"<<endl;
		system("pause");	
}


void modificar(ifstream &Lec){
	system("cls");
	string pal;
	string tra;
	string sig;

	string codigoaux;
	string nombreaux;
	Lec.open("Palabras.txt", ios::in);
	ofstream aux("Personas.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Palabra: ";
		cin>>codigoaux;
		Lec>>pal;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>sig;
			if(pal==codigoaux){
				cout<<"coloca el nuevo nombre: ";
				cin>>nombreaux;
				aux<<nombreaux<<" "<<tra<<" "<<sig<<"\n";
			}else{
				aux<<pal<<" "<<tra<<" "<<sig<<"\n";
			}
			
			Lec>>pal;
		}
		Lec.close();
		aux.close();
	}else
		cout<<"Error"<<endl;
	remove("Palabras.txt");
	rename("personas.txt", "Palabras.txt");	
	system("pause");
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
			case 2:
				verRegistros(Lec);
			break;
			case 3:
				buscarPersona(Lec);
			break;
			case 4:
				modificar(Lec);
			break;
		}
	}while(op!=5);
	return 0;
}
