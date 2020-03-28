/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 5lab-4.c -o 5lab-4
Fecha: Fri Mar 27 11:29:22 CST 2020
Librerias: 
Resumen: El usuario ingresara un numero entero y con este el programa encontrara su factorial.
Entradas: n
Salidas: f
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

long int m(long int n);
int main() {
    long int n;
    printf("Please enter a number: ");
    scanf("%ld", &n);
    printf("Factorial of %ld = %ld \n", n, m(n));
return 0;
}

long int m(long int n) {
    if ( n>1 ) {
        return n*m(n-1);
    }
    else {
        return 1;
    }
}
