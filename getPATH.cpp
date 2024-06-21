#include <iostream>
#include <string>
#include <windows.h>

std::string obtenerDirectorioActual() {
    char cwd[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, (LPSTR)cwd)) {
        return std::string(cwd);
    } else {
        std::cerr << "Error obteniendo el directorio de trabajo actual" << std::endl;
        return "";
    }
}

FILE* abrirArchivo(const std::string& nombreArchivo, const std::string& modo) {
    std::string directorioActual = obtenerDirectorioActual();
    if (directorioActual.empty()) {
        return nullptr;
    }

    std::string rutaCompleta = directorioActual + "\\" + nombreArchivo;
    FILE* archivo = fopen(rutaCompleta.c_str(), modo.c_str());

    if (archivo == nullptr) {
        std::cerr << "Error abriendo el archivo: " << rutaCompleta << std::endl;
    }

    return archivo;
}
