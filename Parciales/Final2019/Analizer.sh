#!/bin/bash

#Analizador de LOG
echo ''
echo 'Bienvenido al analizador de LOG:'
echo ''

NPack=0
NPag=0
dato=''
Ori=0
Dest=0

read -p "Mostrar estadisiticas de paginas enviadas y recibidas? (y/n): " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]
then
    echo '';
    echo $(cat cmake-build-debug/Log.txt | grep -E 'Paginas totales a enviar: .*' );
    echo ''
    echo '-----> Cantidad de paginas recibidas por las maquinas: ' $(cat cmake-build-debug/Log.txt | sort -k1 | grep -c -E 'Recepcion');
    echo '' 
fi


while [[ 1 ]]
do
 echo ''
 echo '==================================================================='
 echo ''
 read -p 'Ingrese el numero de paquete y de pagina que se quiere filtrar: ' NPack NPag
 echo ''
 echo '==================================================================='
 echo ''
 read -p 'A continuacion ingrese el dato que viaja en el paquete: ' dato
 echo ''
 echo '==================================================================='
 echo ''
 read -p 'Finalmente ingrese la IP de Origen y Destino respectivamente: ' Ori Dest
 echo ''
 echo '==================================================================='
 echo ''
 read -p 'Proceder con el analisis de los resultados? (y/n) ' -n 1 -r

if [[ $REPLY =~ ^[Yy]$ ]]
then 
    echo 
    echo '-----------------------------';
    echo '';
    echo 'Se procede a analizar el LOG: ';
    echo '';
    cat cmake-build-debug/Log.txt | grep -E 'Input-Output \| Turno: .* \| .* \| NºPaquete '$NPack' Pag Nº'$NPag' \| Dato: '$dato' \| Origen: '$Ori' \| Destino: '$Dest' .*';	
fi
echo ''
read -p "Volver a cargar nuevos datos para analizar? (y/n) " -n 1 -r
if [[ $REPLY =~ ^[Nn]$ ]]
then
    echo '';
    echo 'Close... Bye !';
    break;
fi

done





