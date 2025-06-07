#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void shuffle(int numeros[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }
}

void inicializarSemilla() {
    std::srand(std::time(0));
}

void imprimirSaludo() {
    std::cout << "Hello, World!" << std::endl;
}

void imprimirListaOrdenada(int numeros[], int n) {
    std::cout << "\nLista ordenada:" << std::endl;
    for (int i = 0; i < n; i++) {
        numeros[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
}

void imprimirListaRandomConRepetidos(int numeros_random[], int n) {
    std::cout << "\033[34m"  << "\nLista desordenado(Se repiten elementos):" << "\033[0m" << std::endl;
    for (int i = 0; i < n; i++) {
        numeros_random[i] = 1 + std::rand() % n;
    }
    for (int i = 0; i < n; i++) {
        std::cout << numeros_random[i] << " ";
    }
    std::cout << std::endl;
}

void imprimirListaDesordenadaSinRepetidos(int numeros[], int n) {
    std::cout << "\nLista desordenado(No se repiten elementos):" << std::endl;
    for (int i = 0; i < n; i++) {
        numeros[i] = i + 1;
    }
    shuffle(numeros, n);
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
}

void imprimirNumeroAzarDeLista(int numeros[], int n) {
    std::cout << "\nNumero al azar de lista ordenada O(1):" << std::endl;
    int num_azar = rand() % n;
    int num_azar_array_numeros = numeros[num_azar];
    std::cout << num_azar_array_numeros << std::endl;
}

    // Bubble Sort O(n^2) en Caso peor
    // Selection Sort O(n^2) siempre
    // Insertion Sort O(n) en el mejor y n^2 en el peor
    // Merge Sort O(n log n) siempre
    // Quick Sort O(n log n) y n^2 en peor caso
    // Heap Sort O(n log n) siempre


double bubbleSort(int arr[], int n) {
    std::cout << "\nBubble Sort O(n^2):" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
       }
    }

        auto end = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();

}

int main() {
    const int n = 10;
    int numeros[n];
    int numeros_random[n];

    inicializarSemilla();
    imprimirSaludo();

    imprimirListaOrdenada(numeros, n);
    imprimirListaRandomConRepetidos(numeros_random, n);
    imprimirListaDesordenadaSinRepetidos(numeros, n);
    imprimirNumeroAzarDeLista(numeros, n);

    std::cout << "\033[34m" << "\nOrdenar listas numeros_random:" << "\033[0m" << std::endl;

    double tiempo = bubbleSort(numeros_random, n);
    // Ordenar y mostrar la lista con repetidos
    //bubbleSort(numeros_random, n);
        std::cout << "Tiempo de ejecución: " << tiempo << " ms" << std::endl;

    // Ordenar y mostrar la lista sin repetidos
    // bubbleSort(numeros, n);

    return 0;
}

