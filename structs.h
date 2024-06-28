#include <iostream>
#include <string>
#include <ctime>
using namespace std;
void menu();
void cita();
int servicios();
void productos();

struct Paciente{
    string nombres; 
    string apellidos;
    string numero;
    string correo;
    int mesCita;
    int fecha;
    int hora;
    int minutos;
    int año;
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

struct Carrito {
    string nombre;
    double precio;
    int cantidad;
};

int cont = 0; // Contador para el número de pacientes

void calendario();
int calcDias();
bool esBisiesto();
int zeller();
int getTime ();

void fechas();
void calculoFechas();

int dia_mes,mes,year,mesop,hora,minutos;

#define NUM_ALLOWED 8
