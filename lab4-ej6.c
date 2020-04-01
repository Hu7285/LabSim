/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc lab4-ej6.c -o lab4-ej6 -lm
Fecha: Fri Mar 27 12:38:39 CST 2020
Librerias: 
Resumen: El usuario ingresa un numero entero positivo y con este el programa realizara unas sumatorias.
Entradas: n
Salidas: r
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

/*Declaracion de variables.
sa(n), sb(n), sc(n), sc(n): double, funciones recursivas, apoyaran para el calculo de las sumatorias.
k: double, numero ingresado por usuario que determinara el limite de la sumatoria.
*/
double sa(double n);
double sb(double n);
double sc(double n);
double sd(double n);
//Funcion principal.
int main() {
    //Declarando n de forma local.
    double n;
    //Pidiendo al usuario un numero y guardandolo a n.
    printf("Please enter a value: ");
    scanf("%lf", &n);
    //Desplegando los resultados de las sumatorias.
    printf("The sum a, k^2(k-3), from [1,%.0lf] is: \n %lf \n", n, sa(n));
    printf("The sum b, 3/(k-1), from [2,%.0lf] is: \n %lf \n", n, sb(n));
    printf("The sum c, 5^(-1/2)((1+5^(1/2))/2)^k-5^(-1/2)((1-5^(1/2))/2), from [1,%.0lf] is: \n %lf \n", n, sc(n));
    printf("The sum d, 0.1(3*2^(k-2)+4), from [2,%.0lf] is: \n %lf \n", n, sd(n));
return 0;
}

//Funcion recursiva sa(n).
double sa(double n) {
    //Funcion recursiva que llegara al valor de la sumatoria cuando n=1 y regresara el valor de la sumatoria.
    /*if: verifica n>1.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sa(n-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando n=1.
    */
    if ( n>1 ) {
        return sa(n-1)+pow(n,2)*(n-3);
    }
    else {
        return pow(1,2)*(1-3);
    }
}

//Funcion recursiva sb(n).
double sb(double n) {
    //NOTA: esta sumatoria tiene que el caso n=1 es un valor inexistente, por lo tanto la sumatoria debe de empezar en n=2.
    //Funcion recursiva que llegara al valor de la sumatoria cuando n=2 y regresara el valor de la sumatoria.
    /*if: verifica n>2.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sb(n-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando n=2.
    */
    if ( n>2 ) {
        return sb(n-1)+(3/(n-1));
    }
    else {
        return (3)/(2-1);
    }
}

//Funcion recursiva sc(n).
double sc(double n) {
    //Funcion recursiva que llegara al valor de la sumatoria cuando n=1 y regresara el valor de la sumatoria.
    /*if: verifica n>1.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sc(n-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando n=1.
    */
    if ( n>1 ) {
        return sc(n-1)+(1/sqrt(5))*(pow((1+sqrt(5))/2,n))-(1/sqrt(5))*(pow((1-sqrt(5))/2,n));
    }
    else {
        return (1/sqrt(5))*(pow((1+sqrt(5))/2,1))-(1/sqrt(5))*(pow((1-sqrt(5))/2,1));
    }
}

//Funcion recursiva sd(n).
double sd(double n) {
    //NOTA: esta sumatoria tiene que el caso k=1 es un valor inexistente, por lo tanto la sumatoria debe de empezar en n=2.
    //Funcion recursiva que llegara al valor de la sumatoria cuando n=2 y regresara el valor de la sumatoria.
    /*if: verifica n>2.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sd(n-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando n=2.
    */
    if ( n>2 ) {
        return sd(n-1)+(0.1)*(3*pow(2,n-2)+4);
    }
    else {
        return (0.1)*(3*pow(2,2-2)+4);
    }
}
