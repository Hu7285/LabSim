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

/*Declaracion de variables:
v1[3], v2[3]: dos arrays de 3 elementos double ingersados por el usuario.
vi, vn=2: enteros que apoyaran en la creacion y manejo de los vectores.
m1, m2: doubles que guardaran el valor de las magnitudes de v1 y v2 respectivamente.
s[3], pv[3]: arrays vompuestos de 3 elementos double que guardaran el valor de la suma y producto vectorial respectivamente entre los vectores v1 y v2.
pe: double que guardara el valor del producto escalar entre v1 y v2.
NOTA: los arrays son double porque el problema no especifica si deben ser int o double y dado que son posiciones estos pueden ser double.
*/
double v1[3], v2[3];
int vi, vn=2;
double m1, m2;
double s[3], pe, pv[3];
void main(){
    //Despliega: pide al usuario que ingrese 3 numberos para el vector v1.
    printf("Please enter 3 numbers to create the first vector: \n");
    //for: loop que empeiza en vi=0, verifica si vi<=vn, Verdadero: lee lo ingresado por el usuario y lo guarada en el elemento v1[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%lf", &v1[vi]);
    }
    //Despliega: el vector v1.
    printf("The first vector, v1, is:i \n");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", v1[vi]);
    }
    printf("\n");
    //Despliega: pide al usuario que ingrese 3 numberos para el vector v2.
    printf("Please enter 3 numbers to create the second vector: \n");
    //for: loop que empeiza en vi=0, verifica si vi<=vn, Verdadero: lee lo ingresado por el usuario y lo guarada en el elemento v2[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        scanf("%lf", &v2[vi]);
    }
    //Despliega: el vector v2
    printf("The second vector, v2, is: \n");
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", v2[vi]);
    }
    printf("\n");
    //NOTA: para algunas operaciones entre vectores se tiene un patron sencillo el cual se podia hacer por medio de un for-loop pero para otras operaciones el patron era demasiado complicado y era mas sencillo simplemente ingresar los elementos de forma directa.
    //Magnitud de vi y guardarla a m1.
    printf("The magnitud of the first vector, v1, is: \n");
    //formula directa para la magnitud de vi.
    m1=sqrt(pow(v1[0],2)+pow(v1[1],2)+pow(v1[2],2));
    printf("%lf \n", m1);
    //Magnitud de v2 y guardarla a m2.
    printf("The magnitud of the second vector, v2, is:\n");
    //formula directa para la magnitud de v2.
    m2=sqrt(pow(v2[0],2)+pow(v2[1],2)+pow(v2[2],2));
    printf("%lf \n", m2);
    //Suma entre v1 y v2 guardarla a s.
    printf("The sum of both vectors is: \n");
    //for: loop que empieza en vi=0, verifica si vi<=vn, Verdero: ingresa la formula para encontrar los valores de los elementos de s[vi] que es la suma v1[vi]+v2[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        s[vi]=v1[vi]+v2[vi];
    }
    //for: loop que empieza en vi=0, verifica si vi<=vn, Verdero: despliega el elemento s[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", s[vi]);
    }
    printf("\n");
    //Producto escalar entre v1 y v2 y guardarla a pe.
    printf("El producto escalar es: \n");
    //formula direcra para el producto escalar.
    pe=v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
    printf("%lf \n", pe);
    //Producto vectorial entre v1 y v2 y guardarla a pv.
    printf("El producto vectorial es: \n");
    //formula directa para cada elemento de pv.
    pv[0]=v1[1]*v2[2]-v1[2]*v2[1];
    pv[1]=v1[2]*v2[0]-v1[0]*v2[2];
    pv[2]=v1[0]*v2[1]-v1[1]*v2[0];
    //for: loop que empieza en vi=0, verifica si vi<=vn, Verdero: despliega el elemento pv[vi], luego aumenta vi por 1.
    for ( vi=0; vi<=vn; vi++ ) {
        printf(" %lf", pv[vi]);
    }
    printf("\n");
}
