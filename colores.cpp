#include <windows.h>
#include <iostream>

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

void menucout(){
    set_color(3);
cout<<"                         __  __ _____ _   _ _   _    "<<endl;                     
cout<<"                        |  \\/  | ____| \\ | | | | |    "<<endl;                    
cout<<" _____ _____ _____ _____| |\\/| |  _| |  \\| | | | |_____ _____ _____ _____ "<<endl;
cout<<"|_____|_____|_____|_____| |  | | |___| |\\  | |_| |_____|_____|_____|_____|"<<endl;
cout<<"                        |_|  |_|_____|_| \\_|\\___/                    "<<endl;     
}