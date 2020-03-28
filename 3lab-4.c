/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 3lab-4.c -o 3lab-4
Fecha: Fri Mar 27 03:42:41 CST 2020
Librerias: 
Resumen: El usuario ingresara dos posiciones de la forma (x,y,z), con esto el programa los almacenara como vectores y realizara las siguientes operaciones: magnitud de cada vector, suma de los dos vectores, producto escalar y producto vectorial.
Entradas: v1, v2
Salidas: m, s, pe, pv
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

double v1[3], v2[3];
int vi, vn=2;
double m1, m2;
double s[3], pe, pv[3];
void main(){
    printf("Please enter 3 numbers to create the first vector: \n");
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%lf", &v1[vi]);
    }
    printf("The first vector, v1, is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", v1[vi]);
    }
    printf("\n");
    printf("Please enter 3 numbers to create the second vector: \n");
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%lf", &v2[vi]);
    }
    printf("The second vector, v2, is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", v2[vi]);
    }
    printf("\n");
    for ( vi=0; vi<=vn; vi++ ) {
        
    }
    printf("The magnitud of the first vector, v1, is: \n");
    m1=sqrt(pow(v1[0],2)+pow(v1[1],2)+pow(v1[2],2));
    printf("%lf \n", m1);
    printf("The magnitud of the second vector, v2, is:\n");
    m2=sqrt(pow(v2[0],2)+pow(v2[1],2)+pow(v2[2],2));
    printf("%lf \n", m2);
    printf("The sum of both vectors is: \n");
    for ( vi=0; vi<=vn; vi++ ) {
        s[vi]=v1[vi]+v2[vi];
    }
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", s[vi]);
    }
    printf("\n");
    printf("El producto escalar es: \n");
    pe=v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
    printf("%lf \n", pe);
    printf("El producto vectorial es: \n");      
    pv[0]=v1[1]*v2[2]-v1[2]*v2[1];
    pv[1]=v1[2]*v2[0]-v1[0]*v2[2];
    pv[2]=v1[0]*v2[1]-v1[1]*v2[0];
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", pv[vi]);
    }
    printf("\n");
}
