#include <iostream>
#include <string>
#include <ctime>

void menu();
void cita();
int servicios();
void productos();

struct Paciente{
    std :: string nombres;
    std :: string apellidos;
    std :: string numero;
    std :: string correo;
    int mesCita;
    int fecha;
    int hora;
    int segundos;
    int servicio;
    
} paciente[100]; 

int cont = 0; // Contador para el número de pacientes

void calendario();
int calcDias();
bool esBisiesto();
int zeller();
int getTime ();

void fechas();
void calculoFechas();

int dia_mes,mes,year,mesop;

#define NUM_ALLOWED 8
