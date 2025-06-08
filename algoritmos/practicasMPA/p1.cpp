#include <iostream>
#include <vector>
using namespace std;

int Contar(std::vector<int> &vec, int n, int x) {
    int nveces = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] == x) {
            nveces = nveces + 1;
        }
    }
    return nveces;
}

int main() {
    /*SUMAR DOS NUMS
    int x = 3;
    int y = 3;
    int suma = x + y;
    cout << suma << endl;*/

    /* ARRAY ESTATICO
    int array[] = {1, 2, 3, 4, 5};
    cout << "Todo el array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " " << "\n";
    }

    cout << "Elementos del array:" << endl;
    int elementos_array = sizeof(array) / sizeof(array[0]);
    cout << elementos_array << endl;
    */

    // Array dinamico
    int n;
    cout << "Introduce tamano n del array:" << endl;
    cin >> n;

    vector<int> V(n);
    // anadir un num desde 0 hasta antes de n o sea de 0 a 9 si n es 10
    for (int i = 0; i < n; i++) {
        V[i] = i + 1;
    }

    cout << "Array OG:" << endl;
    for (int i = 0; i < n; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Buscar numero x en array:" << endl;
    cin >> x;
    cout << endl;

    // Contar sin funcion
    //  int pos = -1; // numero no valido porque es antes de 0

    /*for (int i = 0; i < n; i++) {
        if (V[i] == x) {
            pos = i;
            break;
        }
    }*/

    /*if (pos != -1) {
        std::cout << "El número " << x << " está en la posición " << pos << std::endl;
    } else {
        std::cout << "El número " << x << " no está en el vector" << std::endl;
    }*/

    vector<int> Vpeor(n);
    for (int i = 0; i < n; i++) {
        Vpeor[i] = x;
    }

    cout << "Array Peor:" << endl;
    for (int i = 0; i < n; i++) {
        cout << Vpeor[i] << " ";
    }
    cout << endl;

    int VpeorEle = Contar(Vpeor, n, x);

    cout << "En el Array Peor aparece " << VpeorEle << " veces" << endl;
    cout << endl;
    vector<int> Vmejor(n);
    for (int i = 0; i < n; i++) {
        if (V[i] != x) {
            Vmejor[i] = i + 1;
        }
    }

    cout << "Array Mejor:" << endl;
    for (int i = 0; i < n; i++) {
        cout << Vmejor[i] << " ";
    }

    int VmejorEle = Contar(Vmejor, n, x);

    cout << "En el Array Mejor aparece " << VmejorEle << " veces" << endl;
    cout << endl;

    vector<int> Vcualq(n);
    for (int i = 0; i < n; i++) {
        if (V[i] <= n / 2) {
            Vcualq[i] = x;
        } else {
            Vcualq[i] = i + 1;
        }
    }

    cout << "Array cualquier hvda:" << endl;
    for (int i = 0; i < n; i++) {
        cout << Vcualq[i] << " ";
    }
    int VcualqEle = Contar(Vcualq, n, x);

    cout << "En el Array Mejor aparece " << VcualqEle << " veces" << endl;
    cout << endl;
    return 0;
}