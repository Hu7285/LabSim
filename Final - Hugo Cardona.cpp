/*
Autor: final
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc final.c -o final
Fecha: Wed May 20 08:17:40 CST 2020
Librerias: 
Resumen: final
Entradas: 
Salidas: 
*/
//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

int i=0;
double delta=0.01;
double tf=1800;
double G=6.693E-11;
double rt=6.378E6;
double mt=5.9736E24;
double r=287.06;
double l=6.5E-3;
double g0=9.81;
double t0=288.15;
double p0=101325;
//Declaracion para las funciones
double gr(double fg);
double fric(double F);
double ma(double mc);
double den(double rho);
double ef(double e);
double edo(double dy);
//Algunas variables
double e0;
double tsfc;
double cd;
double a;
double m0;
double mf0;
double y;
double vel;
double mf;
double mc;
double dy;
double F;
double e;
double g;
double rho;

//Declaracion de la clase Cohete
class Cohete{
    public:
        double e0;
        double tsfc;
        double cd;
        double a;
        double m0;
        double mf0;
        double y;
        double vel;
        void despegar();
    public:
        Cohete(double, double, double, double, double, double, double, double);
};

//Constructor de la clase Cohete
Cohete::cohete(double e0, double tsfc, double cd, double a, double m0, double mf0, double y, double vel)
{
    e0=_e0;
    tsfc=_tsfc;
    cd=_cd;
    a=_a;
    m0=_m0;
    mf0=_mf0;
    y=_y;
    vel=_vel;
};

void Cohete::despegar(){
    y=0;
    vel=0;
    i=0;
    //Punteros para crear los archivos
    FILE * daty1;
    FILE * daty2;
    FILE * daty3;
    FILE * datvel1;
    FILE * datvel2;
    FILE * datvel3;
    daty1=fopen( "datosy1.dat", "wt" );
    datvel1=fopen( "datovel1.dat", "wt" );
    daty2=fopen( "datosy2.dat", "wt" );
    datvel2=fopen( "datovel2.dat", "wt" );
    daty3=fopen( "datosy3.dat", "wt" );
    datvel3=fopen( "datovel3.dat", "wt" );
    //Calculo de y(altura) vel(velocidad)
    while( i<1800 && y >=0){
        fprintf(daty1, "%lf\t %lf \n", delta*i, y);
        fprintf(daty2, "%lf\t %lf \n", delta*i, y);
        fprintf(daty3, "%lf\t %lf \n", delta*i, y);
        fprintf(datvel1, "%lf\t %lf \n", delta*i, y);
        fprintf(datvel2, "%lf\t %lf \n", delta*i, y);
        fprintf(datvel3, "%lf\t %lf \n", delta*i, y);
        vel=vel+delta*edo(dy)*i;
        y=y+delta*vel*i;
        i++;
    }
}

//Funciones para las ecuaciones
double den(double rho){
    double ren(rho);
    if( y<t0/l ){
        rho=p0/(r*t0)*(pow(1-(l*y/t0), g0/(r*l)));
    }
    else{
        rho=0;
    }
    return rho;
}

double gr(double g){
    g=(G*mt)/pow(rt+y, 2);
    return g;
}

double fric(double F){
    F=0.5*den(rho)*cd*a*vel*abs(vel);
    return F;
}

double ma(double mc){
    for( i=0; i<50; i++){
        mf=mf-delta*tsfc*e0*i;
    }
    mc=mf0+mf;
    return mc;
}

double ef(double e){
    if( ma==0 ){
        e=0;
    }
    else{
        e=e0;
    }
    return e;
}

double edo(double dy){
    dy=ef(e)/ma(mc)-fric(F)/ma(mc)-gr(g);
    return dy;
}

//Funcion main que creara las graficas
int main(){
    Cohete c1(3E7,3.248E-4, 61.27, 201.06, 1.1E5, 1.5E6, 0.00, 0.00);
    Cohete c2(2E7,2.248E-4, 61.27, 201.06, 1.1E5, 1.5E6, 0.00, 0.00);
    Cohete c3(2.5E7,2.248E-4, 70.25, 215.00, 1.8E5, 2.1E6, 0.00, 0.00);
    c1.despegar();
    c2.despegar();
    c3.despegar();
    system("gnuplot -p grafica.gp");
    system("replot datosy1.dat, datosy2.dat, datosy3.dat, datosvel1.dat, datosvel2.dat, datosvel3.dat");
}

void grafica(){
    FILE * graf;
    graf=fopen("grafica.gp", "wt");
    fprintf(graf, "plot 'grafica.txt'");
    fclose(graf);
}