#include <iostream>
#include <string>
#include <ctime>
using namespace std;
void menu();
void cita();
int servicios();
void productos();

struct Paciente{
    string nombres; //std sol,uciona error del getline en agendar citas por alguna razon??? NO QUITAR()
    string apellidos;
    string numero;
    string correo;
    int mesCita;
    int fecha;
    int hora;
    int segundos;
    int servicio;
    
} paciente[100]; 

//structs de productos kkke
const int MAX_PROD = 5;
const int MAX_CATEGORIAS = 3;



struct Producto
{
    string nombre;
    double precio_prod;
};

struct Categoria
{
    string nombre;
    Producto productos[MAX_PROD];
    int num_productos;
};





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
#define hora_calza 1
#define hora_limpieza 1
#define hora_ortodoncia 2 
int horas_dia=0;
//#define 