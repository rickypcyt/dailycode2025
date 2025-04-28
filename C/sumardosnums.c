#include <stdio.h>

int main(){
    int numero1;
    int numero2;
    
    printf("\nIntroduce el primer numero: ");
    scanf("%d",&numero1);
    printf("\nIntroduce el segundo numero: ");
    scanf("%d",&numero2);

    int suma = numero1 + numero2;
    printf("\n%d ", suma);
}
