#include <iostream>
using namespace std;
int servicios();
void menu();
void cita();
struct pacientes
{
    string nombres[100];
    string apellidos[100];
    string numero[100];
    string correo[100];

} paciente;

void menu()
{
    int opcion;

    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }
    cout << "\n                       MENU" << endl;

    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }
    cout << "Elige una de las opciones siguientes: " << endl;
    cout<<"1. ¿Deseas ver nuestros servicios? " << endl;
    cout<<"2. ¿Deseas agendar una cita?" << endl;
    cout<<"3. Salir." << endl;
    switch (opcion)
    {
    case 1:
        //aqui irian los procedimientos de servicio
        int servicios();
        break;
    case 2: 
        //aqui iria procedimiento de agendar cita
        break;
    case 3:
        break;
    }
}

void cita()
{
}

int servicios()
{
    int servicio;
    cout << "1. CALZAS DENTALES." << endl;
    cout << "2. ORTODONCIA. " << endl;
    cout << "3. LIMPIEZA. " << endl;
    cout << "¿Deseas agendar alguno de nuestros servicios?\n Escribe 1 para confirmar. \n Escribe 0 para salir.";
    cin >> servicio;
    if (servicio = 1)
    {
        void cita();
    }
    else
    {
        return 0;
    }
}


int main(){
    //aun no hay nada kkk
}