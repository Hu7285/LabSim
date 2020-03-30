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

/*Declaracion de Variables:
char m[]: este array tendra la funcion de 'proteger' el programa cuando el usuario no ingrese una opcion valida, se usara un array para que de esta forma el programa solo lea una vez lo ingresado y solo responda una vez.
via=0, vna=9: numeros enteros que nos serviran de apoyo para desplegar los numeros del array v de forma ascendente, via servira como punto de partida y vna como punto de llegada.
vid=9, vnd=0: numeros enteros que nos serviran de apoyo para desplegar los numeros del array v de forma descendente, via servira como punto de partida y vna como punto de llegada.
v[]: vector creado por el programa que contiene los numeros pares en el rango [2,20].
NOTA: el problema no especifica que metodologia utilizar para ordenar los vectores y como el vector esta fijo es mucho mas rapido y eficiente simplemente imprimir los vectores ordenados. Dado que le problema no especifica, no es necesario utilizar un metodo de ordenacion.
NOTA: el programa podria ser mas eficiente si quitaramos las constantes vni y vnd, pero no es necesario ser eficientes.
*/
char m[];
int via=0, vna=9;
int vid=9, vnd=0;
int v[]={2,4,6,8,10,12,14,16,18,20};
void main()
{
    //Desplegar al usuario: muestra el menu principal y pede que ingrese una opcion.
    printf("        MAIN MENU     \n");
    printf("------------------------- \n");
    printf("*a). ascendent \n");
    printf("*d). descendent \n");
    printf("Please select an option: ");
    //while: crea un loop para mantener al ususario adentro del menu principal hasta que el ususario ingrese un valor aceptado, el valor ingresado por el usuario se guardara en el array m[].
    while ( scanf("%s", &m[256]) ) {
        //switch: crea el menu y los caso.
        //NOTA: utilizamos el array m[] para proteger el programa para el caso en que el usuario no ingresa un valor acceptable, se utiliza el array para leer lo ingresado por el usuario como un solo bloque en vez de leerlo de forma individual.
        switch (m[]) {
        //caso 'a': despliega el array de forma ascendente, una vez despliege los numeros se sale del switch.
        case 'a':
            //for: loop que empieza en via y termina en vna, verifica si via<=vna, Verdadero: imprime el elemento v[via] del array v[].
            for ( via; via<=vna; via++ ) {
                printf(" %d", v[via]);
            }
            printf("\n");
            break;
        //caso 'd': despliega el array de forma descendente, una vez despliege los numeros se sale del switch.
        case 'd':
            //for: loop que empieza en vid y termina en vnd, verifica si vid<=vnd, Verdadero: imprime el elemento v[vid] del array v[].
            for ( vid; vid>=vnd; vid-- ) {
                printf(" %d", v[vid]);
            }
            printf("\n");
            break;
        //caso defautl: el usuario ingresa un valor invalido, despliega un mensaje de error, luego sale del switch.
        default:
            printf("ERROR, Invalid value. \n");
            printf("To cancel process input 'Lctrl+C' \n");
            printf("Please enter a valid value: ");
            break;
        }
        //if: verifica el valor del array m[]=a o m[]=b, Verdadero: se saldra del while.
        if ( m[]=='a' || m[]=='d' ) {
            break;
        }
    }
}
