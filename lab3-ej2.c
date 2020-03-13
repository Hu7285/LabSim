/*
Autor: Lab3
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilador: gcc lab3-ej2.c -o lab3-ej2
Fecha: Tue Mar 10 00:45:05 CST 2020
Librerias: 
Resumen: Se leera dos numeros enteros ingresados por el usuario, con estos dos numeros ingresados se creara un rango del cual se extraeran todos los numeros primos.
Entradas: x1, x2, i1, i2, c.
Salidas: i1, i2.
*/
//librerias
#include <stdio.h>


/*Definicion de variables:
x1: primer valor ingresado por el usuario.
x2: segundo valor ingresado por el usuario.
i1: primer contador para verificar numeros primos.
i2: segundo contador para verificar numeros primos.
c: contador para verificar divisibilidad del numero.
NOTA: ninguna variable tiene un valor especifico global. Los valores se les dara en las funciones locales como mas sea conveniente.
*/
int x1, x2, i1, i2, c;
int main()
{
	//Pide numeros al usuario.
	printf("Please enter the first number of the range: \n");
	scanf("%d", & x1);
	printf("Please enter the second number of the range: \n");
	scanf("%d", & x2);
	//Verificar que los numeros ingresados del usuarios sean validos.
	//if: verifica que por lo menos uno de los dos numeros ingresados sea mayor a 0 ya que para crear un rango valido se requiere por lo menos un numero mayor a 0.
	if ( x1 <= 0 & x2 <= 0 ) {
		printf("ERROR \n");
		printf("The range entered is [%d,%d], this is an invalid range \n", x1, x2);
	}
	//else if: una vez que se verifico que por lo menos un numero es mayor a 0 se verifica que no sea el mismo numero, NOTA: este paso no es muy necesario simplemente es mas elegante.
	else if ( x1 == x2 ) {
		//for: crea un loop empezando con i1=1, c=0, verifica si i1<=x1 y si es verdadero se aumentara i1=i1+1 hasta que i1=x1.
		for ( i1 = 1, c = 0; i1 <= x1; i1++ ) {
			//if: verifica el residuo x1%i1 si es igual a 0, Verdad aumentara al c=c+1.
			if ( x1 % i1 == 0 ) {
				c++;
			}
		}
		//NOTA: para este caso especifico era necesario quitarle al i1=i1-1.
		i1--;
		//if, else: se verificara si el numero es primo y se imprimira lo adecuado.
		if ( c > 2 ) {
			printf("The range entered is [%d,%d] \n", x1, x2);
			printf("There are No prime numbers in this range \n");
		}
		else {
			printf("The range entered is [%d,%d] \n", x1, x2);
			printf("The prime numbers in this range are: \n");
			printf("%d \n", i1);
		}
	}
	//else: una vez verificado que por lo menos se haya ingresado un numero mayor a 0 y que los dos numeros ingresados sean distintos se creara el rango y se extraeran los numeros primos.
	else {
		//Sin importar en que orden el usuario ingreso los numeros, el programa se encargara de crear el rango del numero menor al numero mayor.
		/*if, else: compara x2>x1
		Verdad: asignar i1=x1
		Falso: asignar i1=x2.
		*/
		if ( x2 > x1 ) {
			i1=x1;
		}
		else {
			i1=x2;
			x2=x1;
		}
		//Dado que por lo menos un numero ingresado debe ser mayor a 0 existe la posibilidad que uno sea menor o igual a 0.
		//if: verifica si i1=0, Verdad: cambiara el valor i1=1.
		if ( i1 <= 0 ) {
			i1=1;
		}
		printf("The range entered is [%d,%d] \n", i1, x2);
		//for: contador que empieze en i1, verifica si i1<=x2, Verdad: aumentara i1=i1+1.
		for ( i1; i1 <= x2; i1++ ) {
			//for: con el mismo concepto usado anteriormente, se crea un loop empezando en i2=2, c=0, verifica i2<=i1, Verdad: se aumenta i2=i2+1.
			for ( i2 = 2, c = 0; i2 <= i1; i2++ ) {
				//if: verifica el residuo i1%i2=0, Verdad: aumenta c=c+1.
				if ( i1 % i2 == 0 ) {
					c++;
				}
			}
			//NOTA: esta parte es completamente inecesario, simplemente fue por estetica.
			//Una vez que verifica si es primo imprimira los numeros y al final de la secuencia se imprimira el texto "END.".
			//if: verifica si c<2 y si i1=x2, Verdad: imprimira el ultimo numero primo de la lista de primos y el texto "END." al final.
			if ( c < 2 & i1 == x2 ) {
				printf("%d, END. \n", i1);
			}
			//else if: verifica si i1=x2, Verdad: imprimira el texto "END.". Este paso fue para cuando el ultimo numero del rango no es primo.
			else if ( i1 == x2 ) {
				printf("END. \n");
			}
			//else if: verifica si c<2, Verdad: imprimira el numero primo de la lista.
			else if ( c < 2 ) {
				printf("%d, ", i1);
			}
		}
	}
return 0;
}
