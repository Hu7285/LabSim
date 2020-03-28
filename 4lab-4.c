/*
Autor: Lab4Host
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilador: gcc 4lab-4.c -o 4lab-4
Fecha: Fri Mar 27 05:48:29 CST 2020
Librerias: 
Resumen: El usuario debe ingresar 2 matrices 3X3 y una constante, el programa debe de almacenar estos datos y
Entradas: mata, matb, c
Salidas: respuestas
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

int c, mata[3][3], matb[3][3];
int mataxc[3][3], s[3][3], r[3][3], m[3][3], deta, trb[3][3], adja[3][3];
double ina[3][3];
int i, j;
void main() {
    printf("Please enter values for mata. \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf("Please enter %d%d: ", i+1,j+1);
            scanf("%d", &mata[i][j]);
        }
    }
    printf("The mata is: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", mata[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Please enter values for matb. \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf("Please enter %d%d: ", i+1,j+1);
            scanf("%d", &matb[i][j]);
        }
    }
    printf("The matb is: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", matb[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Please enter a constant c: \n");
    scanf("%d", &c);
    printf("The constant c is: %d \n", c);
    printf("Matrix mataxc: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            mataxc[i][j]=c*mata[i][j];
        }
    }
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", mataxc[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Adition of both matrix: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            s[i][j]=mata[i][j]+matb[i][j];
        }
    }
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", s[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Substraction of both matrix: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            r[i][j]=mata[i][j]-matb[i][j];
        }
    }
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", r[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Multiplication mataxmatb: \n");
    m[0][0]=mata[0][0]*matb[0][0]+mata[0][1]*matb[1][0]+mata[0][2]*matb[2][0];
    m[1][0]=mata[0+1][0]*matb[0][0]+mata[0+1][1]*matb[1][0]+mata[0+1][2]*matb[2][0];
    m[2][0]=mata[0+2][0]*matb[0][0]+mata[0+2][1]*matb[1][0]+mata[0+2][2]*matb[2][0];
    m[0][1]=mata[0][0]*matb[0][0+1]+mata[0][1]*matb[1][0+1]+mata[0][2]*matb[2][0+1];
    m[1][1]=mata[0+1][0]*matb[0][0+1]+mata[0+1][1]*matb[1][0+1]+mata[0+1][2]*matb[2][0+1];
    m[2][1]=mata[0+2][0]*matb[0][0+1]+mata[0+2][1]*matb[1][0+1]+mata[0+2][2]*matb[2][0+1];
    m[0][2]=mata[0][0]*matb[0][0+2]+mata[0][1]*matb[1][0+2]+mata[0][2]*matb[2][0+2];
    m[1][2]=mata[0+1][0]*matb[0][0+2]+mata[0+1][1]*matb[1][0+2]+mata[0+1][2]*matb[2][0+2];
    m[2][2]=mata[0+2][0]*matb[0][0+2]+mata[0+2][1]*matb[1][0+2]+mata[0+2][2]*matb[2][0+2];
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", m[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Determinante de mata: \n");
    deta=mata[0][0]*mata[1][1]*mata[2][2]+mata[0][1]*mata[1][2]*mata[2][0]+mata[1][0]*mata[2][1]*mata[0][2]-mata[0][2]*mata[1][1]*mata[2][0]-mata[0][1]*mata[1][0]*mata[2][2]-mata[1][2]*mata[2][1]*mata[0][0];
    printf("%d \n", deta);
    printf("Transpuesta de matb: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            trb[i][j]=matb[j][i];
            }
    }
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", trb[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("Inverse de mata: \n");
    if ( deta==0 ) {
        printf("The matrix mata does not have an inverse \n");
    }
    else {
        adja[0][0]=+mata[1][1]*mata[2][2]-mata[2][1]*mata[1][2];
        adja[1][0]=-mata[1][0]*mata[2][2]+mata[2][0]*mata[1][2];
        adja[2][0]=+mata[1][0]*mata[2][1]-mata[2][0]*mata[1][1];
        adja[0][1]=-mata[0][1]*mata[2][2]+mata[2][1]*mata[0][2];
        adja[1][1]=+mata[0][0]*mata[2][2]-mata[2][0]*mata[0][2];
        adja[2][1]=-mata[0][0]*mata[2][1]+mata[2][0]*mata[0][1];
        adja[0][2]=+mata[0][1]*mata[1][2]-mata[1][1]*mata[0][2];
        adja[1][2]=-mata[0][0]*mata[1][2]+mata[1][0]*mata[0][2];
        adja[2][2]=+mata[0][0]*mata[1][1]-mata[1][0]*mata[0][1];
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ) {
                ina[i][j]=adja[i][j]*pow(deta,-1);
            }
        }
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ) {
                printf(" %f", ina[i][j]);
                if ( j==2 ) {
                    printf("\n");
                }
            }
        }
    }
}
