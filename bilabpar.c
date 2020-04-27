/*
Autor: LabPar
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc bilabpar.c -o bilabpar
Fecha: Mon Apr 24 02:51:03 CST 2020
Librerias: 
Resumen: Dada una funcion se calculara la raiz.
Entradas: a, b, i, me.
Salidas: r.
*/
//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Declaracion de variables:
a: double, intervalo inferior.
b: dobule, intervalo superior.
r: double, raiz.
i: entero, numero de iteraciones.
met: double, funcion que tendra el metodo de biseccion.
*/
double a, b, r;
int i;
double met(double a, double b);

//Funcion principal, este tendra el despliegue de los resultados al igual que la creacion y despliegue de la grafica.
int main() {
    //Declarando los intervalos.
    a=1;
    b=10;
    //Desplegando los resultados.
    printf("La funcion dada es: \n");
    printf("f(x)=(x/2)^1/2-1 \n");
    printf("En un intervalo de [1,10] con 50 iteraciones. \n");
    r=met(a,b);
    printf("La raiz es: \n");
    printf("%lf \n", r);
    //Declaramos un puntoro que servira para crear la grafica.
    FILE * graf;
    //creamos un archivo bi.gp, un archivo de gnuplot que sera de la grafica.
    graf=fopen("bi.gp", "wt");
    //creando la grafica.
    fprintf(graf, "set title 'Ecuacion'\n");
    fprintf(graf, "set grid\n");
    fprintf(graf, "set xlabel 'Eje x'\n");
    fprintf(graf, "set ylabel 'f(x)'\n");
    fprintf(graf, "set xrange [1:10]\n");
    fprintf(graf, "set yrange [-0.5:2]\n");
    fprintf(graf, "plot sqrt(x/2)-1\n");
    //el problema nos pide comparar la grafica creada con el codigo de c en el archivo de minimos cuadrados y la grafica del problema de biseccion, esta paso es para ese fin.
    fprintf(graf, "replot 0.062024*x-0.090357\n");
    fclose(graf);
    //abriendo la grafica.
    system("gnuplot -p bi.gp");
    return 0;
}

//Funcion auxiliar que tendra el metodo de biseccion.
double met(double a, double b) {
    /*Declaracion de variables:
    p: double, variable que guardara la division entre a+b/2.
    ip: double, variable que guardara la funcion evaluada en el punto p.
    fp: double, variable que guardara la funcion evaluada en el punto a.
    s: double, variable que guardara la multiplicacion ip*fp.
    */
    double p, ip, fp, s;
    //for-loop: empieza con i=0, revisa la condicion i<50, y luego aumenta i=i+1.
    for( i=0; i<50; i++ ) {
        p=(a+b)/2;
        ip=sqrt(p/2)-1;
        fp=sqrt(a/2)-1;
        s=ip*fp;
        if( s>0 ) {
            a=p;
        }
        else if( s<0 ) {
            b=p;
        }
    }
    return p;
}