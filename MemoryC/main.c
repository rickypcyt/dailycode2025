#include <stdio.h>

typedef struct Personaje {
    char nombrePersonaje[];
    int *vida;
    int fuerza;
    int armadura;
    int nivel;
};

int a = 4;
int b = 5;

Personaje *crear_personaje(char nombrePersonaje, int vida, int fuerza, int armadura, int nivel) {

    int main() {

        Personaje *heroe = crear_personaje("Guts", 100, 20, 15);
        Personaje *monstruo = crear_personaje("Griffith", 80, 18, 10);

        int resultado = a + b;
        printf("%d", resultado, "\n");
    }
