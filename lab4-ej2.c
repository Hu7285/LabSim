/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc lab4-ej2.c -o lab4-ej2
Fecha: Fri Mar 27 03:01:32 CST 2020
Librerias: 
Resumen: El usuario ingresara 5 numeros enteros, con estos el programa los guardara a un vector y luego los ordenara de forma ascendente.
Entradas: v[], vi, vn, o, r.
Salidas: vector ordenado.
*/

//librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo

/*Declaracion de variables:
o, r: enteros que apoyaran para la ordenacion por el metodo de burbuja.
vi, vn=4: enteros que apoyaran en la creacion y presentacion del vector v[].
v[]: array de enteros que sera el vector por ordenar.
*/
int o, r;
int vi, vn=4;
int v[5];
void main(){
    //Desplegar al usuario: pide que ingrese 5 numeros enteros.
    printf("Please enter 5 numbers: \n");
    //for: loop que empieza en vi=0, verifica si vi<=vn, Verdadero: lee lo que ingreso el usuario y lo guarda en el elemento v[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%d", &v[vi]);
    }
    //Despliega el vector al usuario.
    printf("The vector is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %d", v[vi]);
    }
    printf("\n");
    //Ordenacion por metodo de burbuja.
    //for: loop que empieza en vi=0, verifica si vi<=vn, Verdadero: entra a otro for-loop, luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        //for: loop que empieza en o=0, verifica si o<=vi, Verdadero: entra a un if, luego aumenta vi por 1.
        for ( o=0; o<=vi; o++ ) {
            //if: verifica si v[o]>v[vi], Verdadero: cambiara las variables para crear el array ordenado.
            //NOTA: en este if es donde se empieza la ordenacion, con la variable r de apoyo podemos guardar el primer elemento del array v[vi], guardar el elemento v[vi] a v[0] y por ultimo guardar v[o] a r.
            if ( v[o]>v[vi] ) {
                r=v[vi];
                v[vi]=v[o];
                v[o]=r;
            }
        }
    }
    //Despliega el vector ordenado.
    printf("The vector in ascending order is:");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %d", v[vi]);
    }
    printf("\n");
}
