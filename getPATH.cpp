#include <iostream>
#include <string>
#include <windows.h>

using namespace std; //se agregó using namespace std para no repetir std:: en todo el código

string obtenerDirectorioActual() {
    char cwd[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, (LPSTR)cwd)) {
        return string(cwd);
    } else {
        cerr << "Error obteniendo el directorio de trabajo actual" << endl;
        return "";
    }
}

FILE* abrirArchivo(const string& nombreArchivo, const string& modo) {
    string directorioActual = obtenerDirectorioActual();
    if (directorioActual.empty()) {
        return nullptr;
    }

    string rutaCompleta = directorioActual + "\\" + nombreArchivo;
    FILE* archivo = fopen(rutaCompleta.c_str(), modo.c_str());

    if (archivo == nullptr) {
        cerr << "Error abriendo el archivo: " << rutaCompleta << endl;
    }

    return archivo;
}
