#!/bin/bash

echo "Cripto con chiave Ka"
python2.7 massey_omura.py Lena.tga Lena_A.tga -e key.bin 41 251

echo "Cripto con chiave Kb"
python2.7 massey_omura.py Lena_A.tga Lena_AB.tga -e key2.bin 59 251

echo "Decripto con chiave Ka"
python2.7 massey_omura.py Lena_AB.tga Lena_B.tga -d key.bin 61 251

echo "Decripto con chiave Kb"
python2.7 massey_omura.py Lena_B.tga Lena_decrypt.tga -d key2.bin 89 251
