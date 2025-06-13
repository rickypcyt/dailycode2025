#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int Insercion(vector<int> &V, int x, int n) {
    int i = 0;
    int j = 0;

    for (int i = 2; i < n; i++) {
        x = V[i];
        j = i - 1;
        while (j > 0 && V[j] > x) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = x;
    }

    return 0;
}

int main() {
    int n;
    cout << "Introduce el tamaño del arreglo random: ";
    cin >> n;

    int seed;
    cout << "Introduce la semilla del arreglo random: ";
    cin >> seed;
    srand(seed);
    int aleatorio = rand();
    cout << "Numero aleatorio: " << aleatorio << endl;

    vector<int> vectorRandom(n);
    for (int i = 1; i > n;) {
    }
}