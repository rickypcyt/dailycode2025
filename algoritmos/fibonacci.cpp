#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

// Versión 1: detallada paso a paso (como la que tienes)
void fibonacci_paso_a_paso(int cantidad_terminos) {
    vector<int> fibonacci;
    fibonacci.push_back(0);

    if (cantidad_terminos > 1) {
        fibonacci.push_back(1);
    }

    cout << "Versión 1 - Serie de Fibonacci paso a paso:" << endl;

    cout << fibonacci[0] << endl;

    if (cantidad_terminos == 1) return;

    cout << fibonacci[0] << ", " << "\033[32m" << fibonacci[1] << "\033[0m" 
         << " (" << fibonacci[0] << "+" << fibonacci[1] << ")" << endl;

    for (int i = 3; i <= cantidad_terminos; ++i) {
        int siguiente = fibonacci[i - 3] + fibonacci[i - 2];
        fibonacci.push_back(siguiente);

        for (int j = 0; j < fibonacci.size(); ++j) {
            if (j == (int)fibonacci.size() - 1) {
                cout << "\033[32m" << fibonacci[j] << "\033[0m";
            } else {
                cout << fibonacci[j];
            }
            if (j != (int)fibonacci.size() - 1) cout << ", ";
        }
        cout << " (" << fibonacci[fibonacci.size() - 3] << "+" << fibonacci[fibonacci.size() - 2] << ")" << endl;
    }
    cout << endl;
}

// Versión 2: iterativa rápida (solo imprime la lista completa al final)
vector<int> fibonacci_iterativo(int n) {
    vector<int> fibonacci;
    if (n <= 0) return fibonacci;
    fibonacci.push_back(0);
    if (n == 1) return fibonacci;
    fibonacci.push_back(1);

    for (int i = 2; i < n; ++i) {
        fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
    }
    return fibonacci;
}

// Versión 3: recursiva simple (ineficiente sin memoización)
int fibonacci_recursivo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

vector<int> fibonacci_recursivo_lista(int n) {
    vector<int> fib;
    for (int i = 0; i < n; ++i) {
        fib.push_back(fibonacci_recursivo(i));
    }
    return fib;
}

// --- Versión 4: recursiva con memoización ---
unordered_map<int, int> memo;

int fibonacci_memo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Si ya calculamos fibonacci(n), lo retornamos
    if (memo.find(n) != memo.end()) return memo[n];

    // Si no, calculamos y guardamos
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo[n];
}

vector<int> fibonacci_memo_lista(int n) {
    memo.clear();  // Limpiar cache antes de usar
    vector<int> fib;
    for (int i = 0; i < n; ++i) {
        fib.push_back(fibonacci_memo(i));
    }
    return fib;
}


int main() {
    int cantidad_terminos;
    cout << "¿Cuántos términos de la serie de Fibonacci deseas ver? ";
    cin >> cantidad_terminos;

    if (cantidad_terminos <= 0) {
        cout << "Por favor ingresa un número mayor a 0." << endl;
        return 0;
    }

    // 1) Versión paso a paso
    fibonacci_paso_a_paso(cantidad_terminos);

    // 2) Versión iterativa rápida con chrono
    auto start_iter = high_resolution_clock::now();
    vector<int> fib_iter = fibonacci_iterativo(cantidad_terminos);
    auto end_iter = high_resolution_clock::now();
    auto duration_iter = duration_cast<microseconds>(end_iter - start_iter);

    cout << "Versión 2 - Iterativa rápida:" << endl;
    for (int i = 0; i < (int)fib_iter.size(); ++i) {
        cout << fib_iter[i];
        if (i != (int)fib_iter.size() -1) cout << ", ";
    }
    cout << endl;
    cout << "Tiempo ejecución iterativa: " << duration_iter.count() << " microsegundos\n\n";

    // 3) Versión recursiva con chrono (puede ser lenta para muchos términos)
    auto start_rec = high_resolution_clock::now();
    vector<int> fib_rec = fibonacci_recursivo_lista(cantidad_terminos);
    auto end_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<microseconds>(end_rec - start_rec);

    cout << "Versión 3 - Recursiva simple:" << endl;
    for (int i = 0; i < (int)fib_rec.size(); ++i) {
        cout << fib_rec[i];
        if (i != (int)fib_rec.size() -1) cout << ", ";
    }
    cout << endl;
    cout << "Tiempo ejecución recursiva: " << duration_rec.count() << " microsegundos\n\n";

    // Versión 4 - recursiva con memoización
    auto start_memo = high_resolution_clock::now();
    vector<int> fib_memo = fibonacci_memo_lista(cantidad_terminos);
    auto end_memo = high_resolution_clock::now();
    auto duration_memo = duration_cast<microseconds>(end_memo - start_memo);

    cout << "Versión 4 - Recursiva con memoización:" << endl;
    for (int i = 0; i < (int)fib_memo.size(); ++i) {
        cout << fib_memo[i];
        if (i != (int)fib_memo.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Tiempo ejecución recursiva con memoización: " << duration_memo.count() << " microsegundos\n";

    return 0;
}

