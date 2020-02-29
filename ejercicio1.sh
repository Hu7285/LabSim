#!/bin/bash
mkdir "Desktop/Clima"
echo "$(curl wttr.in)" > "Desktop/Clima/Clima.txt"
head -5 Desktop/Clima/Clima.txt
rm -r "Desktop/Clima"
