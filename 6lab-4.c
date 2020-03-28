/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 6lab-4.c -o 6lab-4
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

double sa(double k);
double sb(double k);
double sc(double k);
double sd(double k);
int main() {
    double k;
    printf("Please enter a value: ");
    scanf("%lf", &k);
    printf("The sum a is: %.1lf \n", sa(k));
    printf("The sum b is: %lf \n", sb(k));
    printf("The sum c is: %lf \n", sc(k));
    printf("The sum d is: %lf \n", sd(k));
return 0;
}

double sa(double k) {
    if ( k>1 ) {
        return sa(k-1)+pow(k,2)*(k-3);
    }
    else {
        return pow(1,2)*(1-3);
    }
}

double sb(double k) {
    if ( k>2 ) {
        return sb(k-1)+(3/(k-1));
    }
    else {
        return (3)/(2-1);
    }
}

double sc(double k) {
    if ( k>1 ) {
        return sc(k-1)+(1/sqrt(5))*(pow((1+sqrt(5))/2,k))-(1/sqrt(5))*(pow((1-sqrt(5))/2,k));
    }
    else {
        return (1/sqrt(5))*(pow((1+sqrt(5))/2,1))-(1/sqrt(5))*(pow((1-sqrt(5))/2,1));
    }
}

double sd(double k) {
    if ( k>2 ) {
        return sd(k-1)+(1/10)*(3*(pow(2,k-2))+4);
    }
    else {
        return (1/10)*((3)*(pow(2,2-2))+4);
    }
}
