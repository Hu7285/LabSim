/*
Autor: Lab3
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilador: gcc lab3-ej1.c -o lab3-ej1
Fecha: Mon Mar  9 17:19:12 CST 2020
Librerias: 
Resumen: Se leera un numero ingresado por el usuario que sea mayor que 1 y se determinara si el numero es primo.
Entradas: x, i
Salidas: 
*/
//librerias
#include <stdio.h>

/*
Declaracion de variables:
x: numero ingresado por el usuario.
i=2: contador para verificar si es numero primo.
*/
int x, i = 2;
int main()
{
	//Pide al usuario que ingrese un numero y lo asigna a x.
	printf("Please enter a number \n");
	scanf("%d", &x);
	/*if: verfica que el numero ingresado sea mayor a 1
	Verdad: imprimira que el usuario ingreso un numero invalido y cancelara el programa.
	Falso: verificara si el numero es primo.
	*/
	if ( x <= 1 ) {
		printf("ERROR. You have entered an invalid value. Process has been canceled. \n");
	}
	else {
		//while: mientras se tenga la condicion residuo x%1!=0 se le aumentara i=i+1.
		while ( x % i != 0 ) {
			i++;
			//if, break: verificara si residuo x%i=0, Verdad: se saldra del loop-while.
			if ( x % i == 0 ) {
				break;
			}
		}
		//Una vez que se haya salido del loop-while se tendra que verificar la condicion de i. Si i es igual que x esto significa que x es primo.
		/*if: verificara x=i
		Verdad: imprimira que x Si es primo.
		Falso: imprimira que x No es primo.
		*/
		if ( x == i ) {
			printf("The number %d IS prime \n", x);
		}
		else {
			printf("The number %d IS NOT prime \n", x);
		}
	}
return 0;
}
