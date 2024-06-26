#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime> //para obtener el tiempo y fecha actual
#include "structs.h"
#include "getPATH.cpp"

using namespace std;
void set_color(int col)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, col);
}

void reset_color()
{
    set_color(7);
}

void menu()
{
    int opcion;

    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }
    cout << "\n                         MENU" << endl;

    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }
    cout << "\nElige una de las opciones siguientes: " << endl;
    cout << "1. ¿Deseas ver nuestros servicios? " << endl;
    cout << "2. ¿Deseas agendar una cita?" << endl;
    cout << "3. ¿Deseas ver nuestros productos? " << endl;
    cout << "4. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("cls");
        servicios();
        break;
    case 2:
        system("cls");
        calendario();
        break;
    case 3:
        system("cls");
        productos();
        break;
    case 4:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        menu();
    }
}

void mostrarProductos(const Categoria &categoria)
{
    cout << "=========================================\n";
    cout << "Categoria: " << categoria.nombre << "\n";
    for (int i = 0; i < categoria.num_productos; i++)
    {
        cout << "Producto: " << categoria.productos[i].nombre
             << ", Precio: $" << categoria.productos[i].precio_prod << "\n";
    }
    cout << "\nPorfi presione enter para continuar...";
    cin.ignore();
    cin.get();
}

void productos()
{

    cout << "==========CATEGORIAS DISPONIBLES============" << endl;
    Categoria categorias[MAX_CATEGORIAS] = {
        {
            "Cepillos dentales",
            {
                {"Cepillos estándar", 20},
                {"Cepillos eléctricos", 20},
                {"Cepillos interdentales", 20},
                {"Cepillos para niños", 20},
            },
            4 // productos en esta categoria
        },

        {"Higiene bucal",
         {
             {"Enjuague bucal sensitive", 20},
             {"Enjuague bucal terapéutico", 20},
             {"Spray mentol", 20},
             {"Limpiador de lengua", 20},
             {"Pasta dental con o sin fluor", 20},
         },
         5},

        {"Articulos para brackets",
         {
             {"Cera para brackets", 20},
             {"Ligas surtidas", 20},
             {"Gel para aftas y llagas bucales", 20},
         },
         3}};

    int opcion;
    do
    {
        system("cls");
        cout << "========== CATEGORIAS DISPONIBLES ============\n";
        for (int i = 0; i < MAX_CATEGORIAS; ++i)
        {
            cout << i + 1 << ". " << categorias[i].nombre << "\n";
        }
        cout << "0. Salir\n";
        cout << "Seleccione una categoria (0 para salir): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= MAX_CATEGORIAS)
        {
            mostrarProductos(categorias[opcion - 1]);
        }
        else if (opcion != 0)
        {
            cout << "Opción inválida. Por favor, intente de nuevo.\n";
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 0);
    system("cls");
    menu();
}

void cita()
{
    if (cont >= 100)
    {
        cout << "No podemos agendar más citas. La lista de pacientes está llena." << endl;
        return;
    }
    // CAMBIAR SEGUN DIRECTORIO IMPORTANTEEEE!!!!
    FILE *ptrF;
    std::string directorioActual = obtenerDirectorioActual(); // Obtenemos el directorio actual
    if ((ptrF = fopen((directorioActual + "\\fechas.dat").c_str(), "a")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
    }
    else
    {
        cin.ignore();
        printf("Ingrese los datos para agendar su cita. \n");

        fechas();

        printf("Ingresa el nombre del paciente: ");
        getline(cin, paciente[cont].nombres);
        printf("Ingresa el apellido del paciente: ");
        getline(cin, paciente[cont].apellidos);
        printf("Ingresa el número de contacto del paciente: \n Num nic:");

        getline(cin, paciente[cont].numero);
        printf("Ingresa el correo del paciente: ");
        getline(cin, paciente[cont].correo);

        fprintf(ptrF, "%s %s %s %s\n", paciente[cont].nombres.c_str(), paciente[cont].apellidos.c_str(), paciente[cont].numero.c_str(), paciente[cont].correo.c_str());

        cont++;
        cout << "Datos agendados correctamente." << endl;

        fclose(ptrF);
    }
}

void fechas()
{
    FILE *ptrF;
    std::string directorioActual = obtenerDirectorioActual(); // Obtenemos el directorio actual
    if ((ptrF = fopen((directorioActual + "\\fechas.dat").c_str(), "a")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
    }
    else
    {
        printf("Ingresa la fecha en que agendaras tu cita: ");
        int fecha;
        std::cin >> fecha;
        fprintf(ptrF, "%d", fecha);
        std::cout << "Fecha agendada correctamente." << std::endl;
        fclose(ptrF);
    }
}

int servicios()
{
    int servicio;
    cout << "1. CALZAS DENTALES." << endl;
    cout << "2. ORTODONCIA. " << endl;
    cout << "3. LIMPIEZA. " << endl;
    cout << "¿Deseas agendar alguno de nuestros servicios?\nEscribe 1 para confirmar.\nEscribe 2 para volver al menú principal. \nEscribe otra tecla para salir." << endl;
    cin >> servicio;
    // preguntar servicio

    if (servicio == 1)
    {
        calendario();
    }
    else if (servicio == 2)
    {
        cout << "Regresando al menú principal..." << endl;
        menu();
    }
    else
    {
        cout << "Saliendo..." << endl;
    }

    return 0;
}

int getTime()
{
    // NULL = devuelve tiempo actual
    // time_t= sinonimo de un int largo   -> %ld
    time_t fecha = time(NULL); // regresa cantidad de segundos desde Enero. 1, 1970

    // ctime = string of actual time

    // puntero a "fecha" para convertir los números en un string utilizando ctime
    // convierte time_t value a una cadena legible para humanos

    struct tm *cur_time = localtime(&fecha);

    // se utiliza "->" para acceder a los miembros de una estructura (struct) a través de un puntero (*cur_time)
    dia_mes = (cur_time->tm_mday);     // Día del mes (1-31)
    mes = (cur_time->tm_mon) + 1;      // Mes desde enero (0-11)
    year = (cur_time->tm_year) + 1900; // Cantidad de años desde 1900
    // cout << "Fecha actual: " << dia_mes << "/" << mes << "/" << year << endl;

    return mes;
}

void calendario()
{
    getTime();
    char opcion;
    cout << "Ingresa los datos de su cita:\n ";
    cout << "Mes (1-12): ";
    cin >> mesop;
    if (mesop < mes || mesop > 12 || mesop < 1)
    {
        cout << "Escribe un mes válido. ";
        calendario();
    }

    if (mesop >= mes)
    {
        cout << "\nFechas disponibles en color blanco, las grises ya están reservadas.";

        // impresion del mes
        cout << "\n\nMes: ";
        switch (mesop)
        {
        case 1:
            cout << "ENERO";
            break;
        case 2:
            cout << "FEBRERO";
            break;
        case 3:
            cout << "MARZO";
            break;
        case 4:
            cout << "ABRIL";
            break;
        case 5:
            cout << "MAYO";
            break;
        case 6:
            cout << "JUNIO";
            break;
        case 7:
            cout << "JULIO";
            break;
        case 8:
            cout << "AGOSTO";
            break;
        case 9:
            cout << "SEPTIEMBRE";
            break;
        case 10:
            cout << "OCTUBRE";
            break;
        case 11:
            cout << "NOVIEMBRE";
            break;
        case 12:
            cout << "DICIEMBRE";
            break;
        }
        cout << "\n";
        // Días de la semana
        printf("%-8s %-8s %-8s %-8s %-8s %-8s %-8s\n", "DOM", "LUN", "MAR", "MIE", "JUE", "VIE", "SAB");

        int z = zeller();

        // Imprimir espacios en blanco para los días antes del primer día del mes
        for (int i = 0; i < z; i++)
        {
            printf("%-9s", " ");
        }

        int diasMonth = calcDias();
        for (int dia = 1; dia <= diasMonth; dia++)
        {
            printf("%-9d", dia);
            z++;
            if (z % 7 == 0)
            {
                cout << "\n";
            }
        }
        cout << "\n\n";
    }
    cout << "\nDeseas agendar una cita en las fechas disponibles? (s/n)\n";
    cout << "Escribe: ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S')
    {
        cita();
    }
    else
    {
        cout << "Saliendo...\n\n";
        system("pause");
    }
}

int calcDias()
{

    if (mesop == 1 || mesop == 3 || mesop == 5 || mesop == 7 || mesop == 8 || mesop == 10 || mesop == 12)
        return 31;
    else if (mesop == 2)
    {
        if (esBisiesto())
        {
            return 29;
        }
        return 28;
    }
    else
    {
        return 30;
    }
}

bool esBisiesto()
{
    getTime();
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

/*Devuelve
0= domingo, 1=lunes, 2=martes, 3=miercoles, 4=jueves, 5=viernes, 6=sabado*/

int zeller()
{

    int a = (14 - mesop) / 12;
    int y = year - a;
    int m = mesop + 12 * a - 2;
    int dia = 1, d;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}
