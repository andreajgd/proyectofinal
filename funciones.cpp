#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime> // para obtener el tiempo y fecha actual
#include "structs.h"
#include "getPATH.cpp"
#include "colores.cpp"

using namespace std;

// Función para mostrar el menú principal
void menu()
{
    int opcion;

    set_color(3); // Establece el color del texto
    cout<<"\n";
    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }

    cout<<"\n";

    menucout(); // Llama a una función para mostrar el contenido del menú (asumida definida en otro archivo)
    
    cout<<"\n";
    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }
    cout << "\nElige una de las opciones siguientes: " << endl;
    cout << "1. ¿Deseas ver nuestros servicios? " << endl;
    cout << "2. ¿Deseas ver nuestros productos? " << endl;
    cout << "3. Salir." << endl;
    cout << "Opcion: ";
    reset_color(); // Restaura el color del texto
    cin >> opcion;
    
    switch (opcion)
    {
    case 1:
        system("cls"); // Limpia la pantalla
        servicios();
        break;
    case 2:
        system("cls"); // Limpia la pantalla
        productos();
        break;
    case 3:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        menu(); // Llama al menú nuevamente si la opción es inválida
    }
}

// Función para mostrar los productos de una categoría específica
void mostrarProductos(const Categoria &categoria)
{
    cout << "=========================================\n";
    cout << "Categoria: " << categoria.nombre << "\n";
    for (int i = 0; i < categoria.num_productos; i++)
    {
        cout << "Producto: " << categoria.productos[i].nombre
             << ", Precio: $" << categoria.productos[i].precio_prod << "\n";
    }
    cout << "\nPor favor presione enter para continuar...";
    cin.ignore();
    cin.get();
}

// Función para mostrar las categorías de productos y sus productos
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
            4 // productos en esta categoría
        },
        {
            "Higiene bucal",
            {
                {"Enjuague bucal sensitive", 20},
                {"Enjuague bucal terapéutico", 20},
                {"Spray mentol", 20},
                {"Limpiador de lengua", 20},
                {"Pasta dental con o sin fluor", 20},
            },
            5
        },
        {
            "Artículos para brackets",
            {
                {"Cera para brackets", 20},
                {"Ligas surtidas", 20},
                {"Gel para aftas y llagas bucales", 20},
            },
            3
        }
    };

    int opcion;
    do
    {
        system("cls"); // Limpia la pantalla
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
    system("cls"); // Limpia la pantalla
    menu();
}

// Función para agendar una cita
void cita()
{
    if (cont >= 100)
    {
        cout << "No podemos agendar más citas. La lista de pacientes está llena." << endl;
        return;
    }
    // CAMBIAR SEGÚN DIRECTORIO IMPORTANTEEEE!!!!

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
        printf("Ingresa la fecha en que agendaras tu cita (solo el día): ");
        cin >> paciente[cont].fecha;
        printf("Ingresa el nombre del paciente: ");
        getline(cin, paciente[cont].nombres);
        printf("Ingresa el apellido del paciente: ");
        getline(cin, paciente[cont].apellidos);
        printf("Ingresa el número de contacto del paciente: ");
        getline(cin, paciente[cont].numero);
        printf("Ingresa el correo del paciente: ");
        getline(cin, paciente[cont].correo);

        fprintf(ptrF, "%d\n", paciente[cont].fecha);
        fprintf(ptrF, "%s %s %s %s\n", paciente[cont].nombres.c_str(), paciente[cont].apellidos.c_str(), paciente[cont].numero.c_str(), paciente[cont].correo.c_str());

        fclose(ptrF);

        cont++;
        cout << "Datos agendados correctamente." << endl;
    }
}

// Función para mostrar los servicios disponibles
int servicios()
{
    int servicio;
    cout << "1. CALZAS DENTALES." << endl;
    cout << "2. ORTODONCIA. " << endl;
    cout << "3. LIMPIEZA. " << endl;
    cout << "\n¿Deseas agendar una cita?\nEscribe 1 para confirmar.\nEscribe 2 para volver al menú principal. \nEscribe otra tecla para salir." << endl;
    cin >> servicio;
    // preguntar servicio

    if (servicio == 1)
    {
        calendario();
        horas_dia+=hora_calza;
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

// Función para obtener la fecha y hora actual
int getTime()
{
    time_t fecha = time(NULL); // regresa cantidad de segundos desde Enero. 1, 1970

    struct tm *cur_time = localtime(&fecha);

    dia_mes = (cur_time->tm_mday);     // Día del mes (1-31)
    mes = (cur_time->tm_mon) + 1;      // Mes desde enero (0-11)
    year = (cur_time->tm_year) + 1900; // Cantidad de años desde 1900

    return mes;
}

// Función para mostrar el calendario y agendar citas
void calendario()
{
    getTime();
    char opcion;
    cout << "Ingresa los datos de su cita:\n";
    cout << "Mes (1-12): ";
    cin >> mesop;

    if (mesop < mes || mesop > 12 || mesop < 1)
    {
        cout << "Escribe un mes válido." << endl;
        calendario();
        return;
    }

    if (mesop >= mes)
    {
        cout << "\nFechas disponibles en color blanco, las verdes ya están reservadas.";

        // Impresión del mes
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

        // Leer fechas desde el archivo y mostrar en el calendario
        std::string directorioActual = obtenerDirectorioActual(); // Obtenemos el directorio actual
        FILE *ptrF;
        if ((ptrF = fopen((directorioActual + "\\fechas.dat").c_str(), "r")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
        }
        else
        {
            int diasMonth = calcDias();
            int reservedDates[diasMonth] = {0};
            int fecha;
            int i = 0;
            while (fscanf(ptrF, "%d", &fecha) != EOF && i < diasMonth)
            {
                reservedDates[fecha - 1] = 1;
                i++;
            }

            fclose(ptrF);

            // Imprimir las fechas
            for (int dia = 1; dia <= diasMonth; dia++)
            {
                if (reservedDates[dia - 1] == 1)
                {
                    set_color(10); // Establece el color del texto a verde
                    printf("%-9d", dia);
                }
                else
                {
                    reset_color(); // Restaura el color del texto
                    printf("%-9d", dia);
                }

                z++;

                if (z % 7 == 0)
                {
                    cout << "\n";
                }
            }
        }

        cout << "\n\n";
    }

    cout << "¿Deseas agendar una cita en las fechas disponibles? (s/n)\n";
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

// Función para calcular el número de días en el mes seleccionado
int calcDias()
{
    if (mesop == 1 || mesop == 3 || mesop == 5 || mesop == 7 || mesop == 8 || mesop == 10 || mesop == 12)
        return 31;
    else if (mesop == 2) //mes opcion (opcion del mes que se escogio)
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

// Función para determinar si el año es bisiesto
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

// Función para calcular el día de la semana del primer día del mes (algoritmo de Zeller)
int zeller()
{
    int a = (14 - mesop) / 12;
    int y = year - a;
    int m = mesop + 12 * a - 2;
    int dia = 1, d;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}
