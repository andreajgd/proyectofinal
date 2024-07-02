#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime> //para obtener el tiempo y fecha actual
#include "structs.h"
#include "getPATH.cpp"
#include "colores.cpp"

using namespace std;


//Añadir prototipos de funciones y procedimientos
void menu();
void mostrarProductos(Categoria categoria);
void mostrarFactura(Carrito carrito[], int numProductos);
void guardarfactura(Carrito carrito[], int numProductos, const string& nombreArchivo);
void productos();
void cita();
void fechas();
int servicios();
int getTime();
void calendario();
int calcDias();
bool esBisiesto();
int zeller();

void menu()
{
    int opcion;
    //Bucle Do While para repetir menú cada que se finalice una función
    do{
    system("cls");

     set_color(3); // Establece el color del texto
    cout<<"\n";
    
    cout<<"\n";

    menucout(); // Llama a una función para mostrar el contenido del menú
    set_color(8);
    cout << "\nElige una de las opciones siguientes: " << endl;
    set_color(3);
    cout << "1. Agendar una cita." << endl;
    cout<<"2. Eliminar cita."<<endl;
    cout << "3. Ver productos." << endl;
    set_color(4);
    cout << "4. Salir." << endl;
    set_color(3);
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
        system("cls");
        //ok
    case 3:
        system("cls"); // Limpia la pantalla
        productos();
        break;
    case 4:
        set_color(4);
        cout << "Saliendo..." << endl;
        reset_color();
        break;
        
    default:
        set_color(4);
        cout << "Opcion invalida. Intente de nuevo." << endl;
        system("pause");
        menu(); // Llama al menú nuevamente si la opción es inválida
    
    }
    } while (opcion != 4);
    
}

void mostrarProductos(Categoria categoria) {
    cout << "========== PRODUCTOS EN " << categoria.nombre << " ==========" << endl;
    for (int i = 0; i < categoria.num_productos; ++i) {
        cout << i + 1 << ". " << categoria.productos[i].nombre << " - $" << categoria.productos[i].precio_prod << endl;
    }
    cout << "0. Regresar\n";
}

void guardarFactura(Carrito carrito[], int numProductos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        const double IVA = 0.15;
        double totalSinIVA = 0.0;
        double totalConIVA = 0.0;

        archivo << "---------------------------------------------" << endl;
        archivo << "                  FACTURA                " << endl;
        archivo << "---------------------------------------------" << endl;
        archivo << "               " << dia_mes << " / " << mes << " / " << year << "     " << endl;
        archivo << "---------------------------------------------" << endl;
        archivo << left << setw(20) << "Producto" << setw(10) << "Precio" << setw(10) << "Cantidad" << setw(10) << "Total" << endl;
        archivo << "---------------------------------------------" << endl;

        for (int i = 0; i < numProductos; i++) {
            double totalProducto = carrito[i].precio * carrito[i].cantidad;
            totalSinIVA += totalProducto;
            archivo << left << setw(20) << carrito[i].nombre << setw(10) << carrito[i].precio << setw(10) << carrito[i].cantidad << setw(10) << totalProducto << endl;
        }

        double ivaCalculado = totalSinIVA * IVA;
        totalConIVA = totalSinIVA + ivaCalculado;

        archivo << "---------------------------------------------" << endl;
        archivo << left << setw(20) << "Subtotal" << setw(10) << "" << setw(10) << "" << setw(10) << totalSinIVA << endl;
        archivo << left << setw(20) << "IVA (15%)" << setw(10) << "" << setw(10) << "" << setw(10) << ivaCalculado << endl;
        archivo << left << setw(20) << "Total" << setw(10) << "" << setw(10) << "" << setw(10) << totalConIVA << endl;
        archivo << "---------------------------------------------" << endl;
        archivo.close();
        cout << "Factura guardada en " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo para guardar la factura." << endl;
    }
}

void mostrarFactura(Carrito carrito[], int numProductos) {
    system("cls");
    carritocout();
    getTime();
    const double IVA = 0.15;
    double totalSinIVA = 0.0;
    double totalConIVA = 0.0;

    cout << "---------------------------------------------" << endl;
    cout << "                  FACTURA                " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "               " << dia_mes << " / " << mes << " / " << year << "     " << endl;
    cout << "---------------------------------------------" << endl;
    cout << left << setw(20) << "Producto" << setw(10) << "Precio" << setw(10) << "Cantidad" << setw(10) << "Total" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < numProductos; i++) {
        double totalProducto = carrito[i].precio * carrito[i].cantidad;
        totalSinIVA += totalProducto;
        cout << left << setw(20) << carrito[i].nombre << setw(10) << carrito[i].precio << setw(10) << carrito[i].cantidad << setw(10) << totalProducto << endl;
    }

    double ivaCalculado = totalSinIVA * IVA;
    totalConIVA = totalSinIVA + ivaCalculado;

    cout << "---------------------------------------------" << endl;
    cout << left << setw(20) << "Subtotal" << setw(10) << "" << setw(10) << "" << setw(10) << totalSinIVA << endl;
    cout << left << setw(20) << "IVA (15%)" << setw(10) << "" << setw(10) << "" << setw(10) << ivaCalculado << endl;
    cout << left << setw(20) << "Total" << setw(10) << "" << setw(10) << "" << setw(10) << totalConIVA << endl;
    cout << "---------------------------------------------" << endl;
    
    char opcion;
    cout << "¿Desea guardar la factura en un archivo? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo: ";
        cin >> nombreArchivo;
        guardarFactura(carrito, numProductos, nombreArchivo);
    }
}


void productos() {
    
    Categoria categorias[MAX_CATEGORIAS] = {
        {
            "Cepillos dentales",
            {
                {"Cepillos estándar", 1.5},
                {"Cepillos eléctricos", 15.0},
                {"Cepillos interdentales", 2.0},
                {"Cepillos para niños", 1.0},
            },
            4 // productos en esta categoria
        },

        {"Higiene bucal",
            {
                {"Enjuague bucal sensitive", 3.0},
                {"Enjuague bucal terapéutico", 3.5},
                {"Spray mentol", 2.5},
                {"Limpiador de lengua", 1.5},
                {"Pasta dental con o sin fluor", 2.0},
            },
            5},

        {"Articulos para brackets",
            {
                {"Cera para brackets", 1.2},
                {"Ligas surtidas", 0.5},
                {"Gel para aftas y llagas bucales", 3.0},
            },
            3}};

    int opcion;
    Carrito carrito[MAX_PROD * MAX_CATEGORIAS];
    int numComprados = 0;

    do {
        system("cls");
        productoscout();
        cout << "========== CATEGORIAS DISPONIBLES ============\n";
        for (int i = 0; i < MAX_CATEGORIAS; ++i) {
            cout << i + 1 << ". " << categorias[i].nombre << "\n";
        }
        cout << "0. Salir\n";
        cout << "Seleccione una categoria (0 para salir): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= MAX_CATEGORIAS) {
            mostrarProductos(categorias[opcion - 1]);

            int productoOpcion;
            do {
                cout << "Seleccione un producto para comprar (0 para regresar): ";
                cin >> productoOpcion;

                if (productoOpcion > 0 && productoOpcion <= categorias[opcion - 1].num_productos) {
                    cout << "Ingrese la cantidad: ";
                    int cantidad;
                    cin >> cantidad;
                    carrito[numComprados].nombre = categorias[opcion - 1].productos[productoOpcion - 1].nombre;
                    carrito[numComprados].precio = categorias[opcion - 1].productos[productoOpcion - 1].precio_prod;
                    carrito[numComprados].cantidad = cantidad;
                    numComprados++;
                } else if (productoOpcion != 0) {
                    cout << "Opción inválida. Por favor, intente de nuevo.\n";
                }
            } while (productoOpcion != 0);
        } else if (opcion != 0) {
            cout << "Opción inválida. Por favor, intente de nuevo.\n";
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 0);

    if (numComprados > 0) {
        mostrarFactura(carrito, numComprados);
    }
    
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void cita() {
    if (cont >= 100) {
        cout << "No podemos agendar más citas. La lista de pacientes está llena." << endl;
        return;
    }

    FILE *ptrF;
    string directorioActual = obtenerDirectorioActual(); // Obtenemos el directorio actual
    if ((ptrF = fopen((directorioActual + "\\fechas.dat").c_str(), "a")) == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");
    } else {
        cin.ignore();
        printf("Ingrese los datos para agendar su cita. \n");

        // Llamamos a la función fechas para obtener la fecha y hora de la cita
        fechas();

        printf("Ingresa el nombre del paciente: ");
        getline(cin, paciente[cont].nombres);
        printf("Ingresa el apellido del paciente: ");
        getline(cin, paciente[cont].apellidos);
        printf("Ingresa el número de contacto del paciente: \nNum nic: ");
        getline(cin, paciente[cont].numero);
        printf("Ingresa el correo del paciente: ");
        getline(cin, paciente[cont].correo);

        // Guardamos los datos en el archivo
            fprintf(ptrF, "%s %s %s %s %d/%d/%d %d:00\n",
            paciente[cont].nombres.c_str(),
            paciente[cont].apellidos.c_str(),
            paciente[cont].numero.c_str(),
            paciente[cont].correo.c_str(),
            paciente[cont].fecha,   
            paciente[cont].mesCita,
            paciente[cont].year,
            paciente[cont].hora,
            paciente[cont].minutos
        );



        cont++;
        cout << "Datos agendados correctamente." << endl;

        fclose(ptrF);
        system("pause");
    }
}



void fechas() {
    int fecha; // Validador de fecha según el número de días del mes en el calendario
    do {
        printf("Ingresa el día de la cita (1-%d): ", calcDias());
        cin >> fecha;
    } while (fecha > calcDias() || fecha < 1);

    // Asignamos la fecha a la estructura del paciente
    paciente[cont].fecha = fecha;
    paciente[cont].mesCita = mesop;
    paciente[cont].year = year;

    int horaCita;
    do {
        printf("Ingresa la hora de la cita (8-11, 13-17, excluyendo las 12): ");
        cin >> horaCita;
    } while ((horaCita < 8 || horaCita > 17) || horaCita == 12);

    // Validación para no permitir citas duplicadas
    for (int i = 0; i < cont; ++i) {
        if (paciente[i].fecha == fecha && paciente[i].hora == horaCita) {
            cout << "Ya existe una cita programada para esa fecha y hora. Por favor, elige otra." << endl;
            fechas(); // Vuelve a solicitar los datos de la cita
            return; // Salimos de la función para evitar duplicación de la cita
        }
    }

    // Asignamos la hora a la estructura del paciente
    paciente[cont].hora = horaCita;

    cout << "Fecha y hora agendadas correctamente." << endl;

    // Limpia el buffer del teclado
    cin.ignore();
    cin.get();
}


int servicios()
{

    citacout();
    int servicio;
    char servicio_op;
    cout << "========== SERVICIOS ============\n";
    cout << "1. CALZAS DENTALES." << endl;
    cout << "2. ORTODONCIA. " << endl;
    cout << "3. LIMPIEZA. " << endl;
    cout<<"\n¿Desea agendar algún servicio? (s/n)"<<endl;
    cout << "Escribe: ";
    cin>>servicio_op;


    paciente[cont].servicio = servicio;
    if (servicio_op == 's' || servicio_op == 'S')
    {
        cout<<"\n¿Cuál servicio deseas agendar?"<<endl;
        cin>>servicio;

    switch (servicio)
    {
    case 1:
        horas_dia+=hora_calza;
        cout<<"\nAgenda la fecha. "<<endl;
        calendario();
        break;
    case 2:
        horas_dia+=hora_ortodoncia;
        cout<<"\nAgenda la fecha. "<<endl;
        calendario();
        break;
    case 3:
        horas_dia+=hora_limpieza;
        cout<<"\nAgenda la fecha. "<<endl;
        calendario();
        break;

    default:
    break;
    }
   
    }
    if (servicio_op == 'n' || servicio_op == 'N')
    {
        int menuOsalir;
        cout<<"1. Volver al menÃº principal."<<endl;
        cout<<"2. Salir."<<endl;
        cin>>menuOsalir;

    switch (menuOsalir)
    {
    case 1:
        menu();
        break;
        
    default:
        break;
    }

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
    hora = (cur_time->tm_hour);
    minutos = (cur_time->tm_min);
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
        return;
    }

    if (mesop >= mes)
    {
        cout << "\nFechas disponibles en color azul, las rojas ya están llenas.";

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
      
      // Dí­as de la semana
        printf("%-8s %-8s %-8s %-8s %-8s %-8s %-8s\n", "DOM", "LUN", "MAR", "MIE", "JUE", "VIE", "SAB");

        int z = zeller();

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
            int fecha, mesArchivo, yearArchivo;
          
            while (fscanf(ptrF, "%*s %*s %*s %*s %d/%d/%d %*d:00", &fecha, &mesArchivo, &yearArchivo) != EOF)  //se agrega * para que no lea 
            {
                if (mesArchivo == mesop && yearArchivo == year)
                {
                    reservedDates[fecha - 1] = 1;
                }
            }

            fclose(ptrF);

            // Imprimir las fechas
            for (int dia = 1; dia <= diasMonth; dia++)
            {
                if (reservedDates[dia - 1] == 1)
                {
                    set_color(4); // Establece el color del texto a rojo
                    printf("%-9d", dia);
                    reset_color();
                }
                else
                {
                    set_color(1); // Establece el color del texto a azul
                    printf("%-9d", dia);
                    reset_color();
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
    reset_color();
    cout << "¿Deseas agendar una cita en las fechas disponibles? (s/n)\n";
    cout << "Escribe: ";
    cin >> opcion;


    int opcion2;
    if (opcion == 's' || opcion == 'S')
    {
        cita();
    }
    else if (opcion == 'n' || opcion == 'N')
    {
        cout<<"1. Agendar la cita en otro mes"<<endl;
        cout<<"2. Salir."<<endl;
        cout<<"Escribe: ";
        cin>>opcion2;

        if(opcion2 ==1){
            calendario();
        }
        
        else if(opcion2== 2) {
        cout << "Saliendo...\n\n";
        system("pause");
        }

        else{
            cout<<"Opción inválida. Intenta de nuevo.";
            calendario();
        }


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