/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 1lab-4.c -o 1lab-4
Fecha: Thu Mar 26 22:16:18 CST 2020
Librerias: 
Resumen: Con un vector ingresado de 10 elementos, numeros pares del 2 al 20, el programa debe de pedir al usuario como quiere ver el vector, de forma ascendente (a) o descendente (d), si el usuario no ingresa un valor correcto el programa debe de volver a preguntarle al usuario hasta que el usuario ingrese un valor acceptado.
Entradas: v, via, vna, vid, vnd, m
Salidas: a, d
*/

//librerias
#include <stdio.h>
#include <math.h>

char m[256];
int via=0, vna=9;
int vid=9, vnd=0;
int v[]={2,4,6,8,10,12,14,16,18,20};
void main()
{
    printf("        MAIN MENU     \n");
    printf("------------------------- \n");
    printf("*a). ascendent \n");
    printf("*d). descendent \n");
    printf("Please select an option: ");
    while ( scanf("%s", &m[256]) ) {
        switch (m[256]) {
        case 'a':
            for ( via; via<=vna; via++ ) {
                printf(" %d", v[via]);
            }
            printf("\n");
            break;
        case 'd':
            for ( vid; vid>=vnd; vid-- ) {
                printf(" %d", v[vid]);
            }
            printf("\n");
            break;
        default:
            printf("ERROR, Invalid value. \n");
            printf("To cancel process input 'Lctrl+C' \n");
            printf("Please enter a valid value: ");
            break;
        }
        if ( m[256]=='a' || m[256]=='d' ) {
            break;
        }
    }
}
