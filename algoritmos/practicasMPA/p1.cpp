#include <iostream>
#include <vector>
using namespace std;

int contarOcurrencias(vector<int> &arreglo, int tamaño, int numero) {
    int numeroDeVeces = 0;
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == numero) {
            numeroDeVeces++;
        }
    }
    return numeroDeVeces;
}

int main() {
    // Crear arreglo dinámico
    int tamaño;
    cout << "Introduce el tamaño del arreglo: ";
    cin >> tamaño;

    vector<int> arregloOriginal(tamaño);

    // Llenar arreglo original con números del 1 hasta tamaño
    for (int i = 0; i < tamaño; i++) {
        arregloOriginal[i] = i + 1;
    }

    cout << "Arreglo Original: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arregloOriginal[i] << " ";
    }
    cout << endl;

    int numeroBuscado;
    cout << "Introduce el número a buscar en el arreglo: ";
    cin >> numeroBuscado;
    cout << endl;

    // Caso peor: todos los elementos son el número buscado
    vector<int> arregloCasoPeor(tamaño);
    for (int i = 0; i < tamaño; i++) {
        arregloCasoPeor[i] = numeroBuscado;
    }

    cout << "Arreglo Caso Peor: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arregloCasoPeor[i] << " ";
    }
    cout << endl;

    int ocurrenciasCasoPeor = contarOcurrencias(arregloCasoPeor, tamaño, numeroBuscado);
    cout << "En el Arreglo Caso Peor aparece " << ocurrenciasCasoPeor << " veces" << endl;
    cout << endl;

    // Caso mejor: ningún elemento es el número buscado
    vector<int> arregloCasoMejor(tamaño);
    for (int i = 0; i < tamaño; i++) {
        if (arregloOriginal[i] != numeroBuscado) {
            arregloCasoMejor[i] = i + 1;
        } else {
            arregloCasoMejor[i] = (numeroBuscado == 1) ? 2 : 1; // Evitar el número buscado
        }
    }

    cout << "Arreglo Caso Mejor: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arregloCasoMejor[i] << " ";
    }
    cout << endl;

    int ocurrenciasCasoMejor = contarOcurrencias(arregloCasoMejor, tamaño, numeroBuscado);
    cout << "En el Arreglo Caso Mejor aparece " << ocurrenciasCasoMejor << " veces" << endl;
    cout << endl;

    // Caso promedio: la mitad de los elementos son el número buscado
    vector<int> arregloCasoPromedio(tamaño);
    for (int i = 0; i < tamaño; i++) {
        if (i < tamaño / 2) {
            arregloCasoPromedio[i] = numeroBuscado;
        } else {
            arregloCasoPromedio[i] = i + 1;
        }
    }

    cout << "Arreglo Caso Promedio: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arregloCasoPromedio[i] << " ";
    }
    cout << endl;

    int ocurrenciasCasoPromedio = contarOcurrencias(arregloCasoPromedio, tamaño, numeroBuscado);
    cout << "En el Arreglo Caso Promedio aparece " << ocurrenciasCasoPromedio << " veces" << endl;
    cout << endl;

    return 0;
}