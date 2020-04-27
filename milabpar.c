/*
Autor: LabPar
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc milabpar.c -o milabpar -lm
Fecha: Sat Apr 23 22:34:32 CST 2020
Librerias: 
Resumen: Se creara un programa que analice datos.
Entradas: d
Salidas: g
*/
//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Declaracion de variables:
sem[8]: double valores dados de las semanas.
alt[8]: double valores dados de las alturas.
i: entero que ayudara para crear for-loops.
p: double, guardara el valor de la prediccion.
xy: double, sumatoria de sem*alt.
x: double, sumatoria de sem.
y: double, sumatoria de alt.
xx: double, sumatoria de x^2.
yy: double, sumatoria de y^2.
m: double, funcion para encontrar la pendiente m.
b: double, funcion para encontrar la interseccion b.
dm: double, error de m.
db: double, error de b.
r: double, coeficiente de correlacion.
*/
double sem[8]={1,2,3,4,5,6,7,8};
double alt[8]={0.01,0.03,0.09,0.13,0.19,0.26,0.37,0.43};
int i;
double p;
double xy(double n);
double x(double n);
double y(double n);
double xx(double n);
double yy(double n);
double m(double a);
double b(double a);
double dm(double a);
double db(double a);
double r(double h);

//funcion principal el cual contiene el despliege de los resultados y la creacion de la grafica comparativa de los resultados creado en gnuplot.
int main() {
    //declaracion local de las variables.
    double n=0;
    double a=0;
    double h=0;
    //despliegue de los resultados.
    printf("Dado los datos la recta que mas se aproxima al comportamiento es: \n");
    printf("y=%lfx%lf \n", m(a), b(a));
    printf("Con una incerteza de: \n");
    printf("dm=%lf \n", dm(a));
    printf("db=%lf \n", db(a));
    printf("r=%lf \n", r(h));
    printf("La altura estimada despues de 23 semanas es: \n");
    p=m(a)*23+b(a);
    printf("%lf m. \n", p);
    //creacion de dos punteros para crear archivos.
    FILE * dat;
    FILE * lin;
    //creacion del archivo data.dat el cual guardara los datos originales dados.
    dat=fopen( "data.dat", "wt" );
    //guaradara los datos desde lso arrays sem y alt al nuevo archivo data.dat.
    for( i=0; i<8; i++ ) {
        fprintf( dat, "%lf\t%lf\n", sem[i], alt[i] );
    }
    fclose(dat);
    //creacion del archivo ec.gp, un archivo de gnuplot, este creara las graficas comparativas.
    lin=fopen("ec.gp", "wt");
    //creando la grafica.
    fprintf(lin, "set title 'Crecimiento de Planta'\n");
    fprintf(lin, "set grid\n");
    fprintf(lin, "set xlabel 'Semanas'\n");
    fprintf(lin, "set ylabel 'Altura'\n");
    fprintf(lin, "set xrange [1:9]\n");
    fprintf(lin, "set yrange [0:0.6]\n");
    fprintf(lin, "plot 'data.dat'\n");
    fprintf(lin, "replot %lf*x%lf\n", m(a), b(a));
    fclose(lin);
    //abriendo la grafica.
    system("gnuplot -p ec.gp");
return 0;
}

//Se crearon funciones por separado para simplificar el main, de esta forma el main solo se enfocara en la creacion de la grafica.
//Para la gran mayoria de estas funciones auxiliares se utilizo el mismo metodo para crear las sumatorias, se utilizo simple for-loop que no requiere de mucha explicacion.
//funcion para la sumatoria de sem*alt.
double xy(double n) {
    for ( i=0; i<8; i++ ) {
        n+=sem[i]*alt[i];
    }
    return n;
}

//funcion para la sumatoria de sem.
double x(double n) {
    for ( i=0; i<8; i++ ) {
        n+=sem[i];
    }
    return n;
}

//funcion para la sumatoria de alt.
double y(double n) {
    for ( i=0; i<8; i++ ) {
        n+=alt[i];
    }
    return n;
}

//funcion para la sumatoria de sem^2.
double xx(double n) {
    for ( i=0; i<8; i++ ) {
        n+=pow(sem[i],2);
    }
    return n;
}

//funcion para la sumatoria de alt^2.
double yy(double n) {
    for ( i=0; i<8; i++ ) {
        n+=pow(alt[i],2);
    }
    return n;
}

//funcion para encontrar m.
double m(double a) {
    double n=0;
    a=(8*xy(n)-x(n)*y(n))/(8*xx(n)-pow(x(n),2));
    return a;
}

//funcion para encontrar b.
double b(double a) {
    double n=0;
    a=(y(n)-m(a)*x(n))/8;
    return a;
}

//funcion para encontrar dm.
double dm(double a) {
    double n=0;
    a=(sqrt(8)*0.01)/(sqrt(8*xx(n)-pow(x(n),2)));
    return a;
}

//funcion para encontrar db.
double db(double a) {
    double n=0;
    a=0.01/sqrt(8);
    return a;
}

//funcion para encontrar r.
double r(double h) {
    double n=0;
    h=(8*xy(n)-x(n)*y(n))/(sqrt((8*xx(n)-x(n)*x(n))*(8*yy(n)-y(n)*y(n))));
    return h;
}