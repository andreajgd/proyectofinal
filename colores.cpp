#include <windows.h>
#include <iostream>

using namespace std;

// Función para establecer el color del texto en la consola
void set_color(int col)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtiene el manejador de la consola
    SetConsoleTextAttribute(hConsole, col); // Establece el atributo del color del texto
}

// Función para restablecer el color del texto a su valor predeterminado
void reset_color()
{
    set_color(7); // Restablece el color del texto al valor predeterminado (normalmente blanco)
}

// Función para mostrar el encabezado del menú con colores específicos
void menucout(){
    set_color(3); // Establece el color del texto a un color específico (en este caso, azul)
    // Imprime el encabezado del menú con diseño gráfico en la consola
    cout<<"                         __  __ _____ _   _ _   _    "<<endl;                     
    cout<<"                        |  \\/  | ____| \\ | | | | |    "<<endl;                    
    cout<<" _____ _____ _____ _____| |\\/| |  _| |  \\| | | | |_____ _____ _____ _____ "<<endl;
    cout<<"|_____|_____|_____|_____| |  | | |___| |\\  | |_| |_____|_____|_____|_____|"<<endl;
    cout<<"                        |_|  |_|_____|_| \\_|\\___/                    "<<endl;     
}
