/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc lab4-ej5.c -o lab4-ej5
Fecha: Fri Mar 27 11:29:22 CST 2020
Librerias: 
Resumen: El usuario ingresara un numero entero y con este el programa encontrara su factorial.
Entradas: m(n).
Salidas: factorial.
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

/*Declaracion de variables:
m(n): entero, funcion recursiva, nos apoyara para encontrar el valor factorial.
n: entero, numero ingresado por el usuario al cual se le encontrara su factorial.
*/
long int m(long int n);
//Funcion principal.
int main() {
    //Declaracion locar de parametro n.
    long int n;
    //Pide al usuario y luego guarada el numero a n.
    printf("Please enter a number: ");
    scanf("%ld", &n);
    //Formula para encontrar el factorial utilizando la funcion recursiva de m(n).
    printf("Factorial of %ld = %ld \n", n, m(n));
return 0;
}

//Funcion recursiva m(n).
long int m(long int n) {
    //Funcion recursiva que llegara al valor 1 y regresara el valor del factorial.
    /*if: verifica n>1.
    Verdad: hace la llamada recursiva y regresa la formula n*m(n-1).
    Falso: regresa el valor 1.
    */
    if ( n>1 ) {
        return n*m(n-1);
    }
    else {
        return 1;
    }
}
