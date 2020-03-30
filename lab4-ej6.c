/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 6lab-4.c -o 6lab-4 -lm
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
sa(k), sb(k), sc(k), sc(k): double, funciones recursivas, apoyaran para el calculo de las sumatorias.
k: double, numero ingresado por usuario que determinara el limite de la sumatoria.
*/
double sa(double k);
double sb(double k);
double sc(double k);
double sd(double k);
//Funcion principal.
int main() {
    //Declarando k de forma local.
    double k;
    //Pidiendo al usuario un numero y guardandolo a k.
    printf("Please enter a value: ");
    scanf("%lf", &k);
    //Desplegando los resultados de las sumatorias.
    printf("The sum a, k^2(k-3), from [1,%.0lf] is: \n %lf \n", k, sa(k));
    printf("The sum b, 3/(k-1), from [2,%.0lf] is: \n %lf \n", k, sb(k));
    printf("The sum c, 5^(-1/2)((1+5^(1/2))/2)^k-5^(-1/2)((1-5^(1/2))/2), from [1,%.0lf] is: \n %lf \n", k, sc(k));
    printf("The sum d, 0.1(3*2^(k-2)+4), from [2,%.0lf] is: \n %lf \n", k, sd(k));
return 0;
}

//Funcion recursiva sa(k).
double sa(double k) {
    //Funcion recursiva que llegara al valor de la sumatoria cuando k=1 y regresara el valor de la sumatoria.
    /*if: verifica k>1.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sa(k-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando k=1.
    */
    if ( k>1 ) {
        return sa(k-1)+pow(k,2)*(k-3);
    }
    else {
        return pow(1,2)*(1-3);
    }
}

//Funcion recursiva sb(k).
double sb(double k) {
    //NOTA: esta sumatoria tiene que el caso k=1 es un valor inexistente, por lo tanto la sumatoria debe de empezar en k=2.
    //Funcion recursiva que llegara al valor de la sumatoria cuando k=2 y regresara el valor de la sumatoria.
    /*if: verifica k>2.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sa(k-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando k=2.
    */
    if ( k>2 ) {
        return sb(k-1)+(3/(k-1));
    }
    else {
        return (3)/(2-1);
    }
}

//Funcion recursiva sc(k).
double sc(double k) {
    //Funcion recursiva que llegara al valor de la sumatoria cuando k=1 y regresara el valor de la sumatoria.
    /*if: verifica k>1.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sa(k-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando k=1.
    */
    if ( k>1 ) {
        return sc(k-1)+(1/sqrt(5))*(pow((1+sqrt(5))/2,k))-(1/sqrt(5))*(pow((1-sqrt(5))/2,k));
    }
    else {
        return (1/sqrt(5))*(pow((1+sqrt(5))/2,1))-(1/sqrt(5))*(pow((1-sqrt(5))/2,1));
    }
}

//Funcion recursiva sd(k).
double sd(double k) {
    //NOTA: esta sumatoria tiene que el caso k=1 es un valor inexistente, por lo tanto la sumatoria debe de empezar en k=2.
    //Funcion recursiva que llegara al valor de la sumatoria cuando k=2 y regresara el valor de la sumatoria.
    /*if: verifica k>2.
    Verdad: hace la llamada recursiva y regresa la formula de la sumatoria con sa(k-1), con el valor anterior.
    Falso: regresa el valor de la sumatoria cuando k=2.
    */
    if ( k>2 ) {
        return sd(k-1)+(0.1)*(3*pow(2,k-2)+4);
    }
    else {
        return (0.1)*(3*pow(2,2-2)+4);
    }
}
