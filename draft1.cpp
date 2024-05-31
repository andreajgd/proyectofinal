#include <iostream>
#include <string>

using namespace std;

void menu();
void cita();
int servicios();

struct Pacientes {
    string nombres[100];
    string apellidos[100];
    string numero[100];
    string correo[100];
    int count = 0; // Contador para el número de pacientes
} paciente;

void menu() {
    int opcion;

    for (int i = 0; i < 65; i++) {
        cout << "-";
    }
    cout << "\n                       MENU" << endl;

    for (int i = 0; i < 65; i++) {
        cout << "-";
    }
    cout << "\nElige una de las opciones siguientes: " << endl;
    cout << "1. ¿Deseas ver nuestros servicios? " << endl;
    cout << "2. ¿Deseas agendar una cita?" << endl;
    cout << "3. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        servicios();
        break;
    case 2: 
        cita();
        break;
    case 3:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
    }
}

void cita() {
    if (paciente.count >= 100) {
        cout << "No podemos agendar más citas. La lista de pacientes está llena." << endl;
        return;
    }

    cin.ignore(); 

    cout << "Ingresa el nombre del paciente: ";
    getline(cin, paciente.nombres[paciente.count]);
    cout << "Ingresa el apellido del paciente: ";
    getline(cin, paciente.apellidos[paciente.count]);
    cout << "Ingresa el número de contacto del paciente: ";
    getline(cin, paciente.numero[paciente.count]);
    cout << "Ingresa el correo del paciente: ";
    getline(cin, paciente.correo[paciente.count]);

    paciente.count++;
    cout << "Cita agendada correctamente." << endl;
}

int servicios() {
    int servicio;
    cout << "1. CALZAS DENTALES." << endl;
    cout << "2. ORTODONCIA. " << endl;
    cout << "3. LIMPIEZA. " << endl;
    cout << "¿Deseas agendar alguno de nuestros servicios?\nEscribe 1 para confirmar.\nEscribe 0 para salir." << endl;
    cin >> servicio;

    if (servicio == 1) {
        cita();
    } else {
        cout << "Regresando al menú principal..." << endl;
    }

    return 0;
}

int main() {
    menu();
    return 0;
}
