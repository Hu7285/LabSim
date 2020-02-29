#!/bin/bash
echo "Please enter a name:"
read name
if [ -z $name ]; then
  echo "ERROR, no name was entered, process has been canceled."
elif [ -n $name ]; then
  if [ ${name:(-2)} == ".c" ]; then
    echo "ERROR, please enter name without entension '.c', process has been canceled."
    exit
  else
    if [ -e "Desktop/$name.c" ]; then
      echo "ERROR, this name has been used, process has been canceled."
      exit
    else
      touch "Desktop/$name.c"
      echo "Your file has been created"
    fi
  fi
echo "Please enter a summary"
read summary
echo "Please enter the inputs"
read inputs
echo "Please enter the outputs"
read outputs
echo "$(gcc --version)" > gccversion_placeholder.txt
echo "/*
Autor: $(hostname)
Compilador: $(head -1 gccversion_placeholder.txt)
Compilador: gcc $name.c -o $name
Fecha: $(date)
Librerias: 
Resumen: $summary
Entradas: $inputs
Salidas: $outputs
*/

//librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo" > "Desktop/$name.c"
fi
rm "gccversion_placeholder.txt"
