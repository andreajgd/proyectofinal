#include <iostream>
#include <string>
#include <windows.h>

// Función para obtener el directorio de trabajo actual
std::string obtenerDirectorioActual() {
    char cwd[MAX_PATH]; // Buffer para almacenar el directorio actual
    // Obtiene el directorio de trabajo actual y lo almacena en el buffer
    if (GetCurrentDirectoryA(MAX_PATH, (LPSTR)cwd)) {
        return std::string(cwd); // Convierte el buffer a un string y lo retorna
    } else {
        std::cerr << "Error obteniendo el directorio de trabajo actual" << std::endl;
        return ""; // Retorna una cadena vacía en caso de error
    }
}

// Función para abrir un archivo en un modo específico
FILE* abrirArchivo(const std::string& nombreArchivo, const std::string& modo) {
    std::string directorioActual = obtenerDirectorioActual(); // Obtiene el directorio actual
    if (directorioActual.empty()) { // Verifica si se pudo obtener el directorio
        return nullptr; // Retorna nulo en caso de error
    }

    // Construye la ruta completa del archivo concatenando el directorio actual con el nombre del archivo
    std::string rutaCompleta = directorioActual + "\\" + nombreArchivo;
    // Abre el archivo en el modo especificado (por ejemplo, "r" para leer, "w" para escribir)
    FILE* archivo = fopen(rutaCompleta.c_str(), modo.c_str());

    // Verifica si el archivo se abrió correctamente
    if (archivo == nullptr) {
        std::cerr << "Error abriendo el archivo: " << rutaCompleta << std::endl;
    }

    return archivo; // Retorna el apuntador al archivo
}

