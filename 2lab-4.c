/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 2lab-4.c -o 2lab-4
Fecha: Fri Mar 27 03:01:32 CST 2020
Librerias: 
Resumen: El usuario ingresara 5 numeros enteros, con estos el programa los guardara a un vector y luego los ordenara de forma ascendente.
Entradas: v
Salidas: vo
*/

//librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo
 
int o, r;
int vi, vn=4;
int v[5];
void main(){
    printf("Please enter 5 numbers: \n");
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%d", &v[vi]);
    }
    printf("The vector is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %d", v[vi]);
    }
    printf("\n");
    for ( vi=0; vi<=vn; vi++ ) {
        for ( o=0; o<=vi; o++ ) {
            if ( v[o]>v[vi] ) {
                r=v[vi];
                v[vi]=v[o];
                v[o]=r;
            }
        }
    }
    printf("The vector in ascending order is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %d", v[vi]);
    }
    printf("\n");
}
