#include <iostream>
using namespace std;
int servicios();
void cita();
struct pacientes {
    string nombres[100];
    string apellidos[100];
    string numero[100];
    string correo[100];

}paciente; 

int main(){
    for(int i=0;i<65;i++){
        cout<<"-";
    }
    cout<<"\n                          MENU:"<<endl;
    for(int i=0;i<65;i++){
        cout<<"-";
    }
    int opcion;
    cout<<"\nIngresa el número de la acción que deseas hacer: "<<endl;
    cout<<"1. ¿Deseas ver nuestros servicios? "<<endl;
    cout<<"2. ¿Deseas agendar una cita?"<<endl;
    cout<<"3. Salir?"<<endl;
    cin>>opcion;
    if(opcion=1){
        int servicios ();
    }
    if(opcion=2){
        int cita();
    }
    if (opcion=3){
    return 0;
    }
}

void cita(){

}

int servicios(){
    int servicio;
    cout<<"1. CALZAS DENTALES."<<endl;
    cout<<"2. ORTODONCIA. "<<endl;
    cout<<"3. LIMPIEZA. "<<endl;
    cout<<"¿Deseas agendar alguno de nuestros servicios?\n Escribe 1 para confirmar. \n Escribe 0 para salir.";
    cin>>servicio;
    if(servicio=1){
        void cita();
    }
    else{
        return 0;
    }

}

