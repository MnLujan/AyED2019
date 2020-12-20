#!/bin/bash
#Analizador de LOG
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'
echo '              Bienvenido al Analizador de LOG: '
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

#Variables que seran utilizadas para analizar el txt
NPack=0
NPag=0
dato=''
Ori=0
Dest=0

read -p "Mostrar estadisiticas de paginas enviadas y recibidas? (Y/n): " -n 2 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]]; then
  echo ''
  # shellcheck disable=SC2046
  echo $(cat cmake-build-debug/Log.txt | grep -E '/// Paginas TOTALES a ENVIAR: .*')
  echo ''
  # shellcheck disable=SC2046
  echo '-----> Cantidad de paginas recibidas por las maquinas: ' $(cat cmake-build-debug/Log.txt | sort -k1 | grep -c -E 'Recepcion')
  echo ''
fi

while [[ 1 ]]; do
  echo ''
  echo '==================================================================='
  echo ''
  read -p 'Ingrese el numero de PAQUETE y de PAGINA que se quiere filtrar: ' NPack NPag
  echo ''
  echo '==================================================================='
  echo ''
  read -p 'A continuacion ingrese el DATO que viaja en el paquete: ' dato
  echo ''
  echo '==================================================================='
  echo ''
  read -p 'Finalmente ingrese la IP de ORIGEN y DESTINO respectivamente: ' Ori Dest
  echo ''
  echo '==================================================================='
  echo ''
  read -p 'Proceder con el analisis de los resultados? (Y/n) ' -n 2 -r

  if [[ $REPLY =~ ^[Yy]$ ]]; then
    while [[ 1 ]]; do
      echo
      echo '----------------------------------------------------'
      echo ''
      echo '        Se procede a analizar el LOG: '
      echo ''
      cat cmake-build-debug/Log.txt | grep -E 'Input-Output \| Turno: .* \| .* \| NºPaquete '$NPack' Pag Nº'$NPag' \| Dato: '$dato' \| Origen: '$Ori' \| Destino: '$Dest' .*'
      cat cmake-build-debug/Log.txt | grep -E 'Llegada \| .* \| N°Paquete: '$NPack' Pag N°'$NPag' \| Dato: '$dato' \| Destino: '$Dest
      cat cmake-build-debug/Log.txt | grep -E 'Recepcion \| MaquinaIP: '$Dest' \| N° Pag '$NPag' \| Origen '$Ori' \| Destino '$Dest' \| .*'
      echo ''
      echo ''
      read -p "----> BUSCAR OTRO DATO DE LA MISMA PAGINA? (Y/n) " -n 2 -r
      if [[ $REPLY =~ ^[Nn]$ ]]; then
        break #Me voy del loop
      fi
      #Solo cargo el dato y el NPack
      echo ''
      read -p "---->INGRESE SEPARADO POR ESPACIO EL NUMERO DE PAGINA Y LA LETRA: " NPack dato
    done
  fi

  echo ''
  echo ''
  read -p "Volver a cargar NUEVOS datos para ANALIZAR? (Y/n) " -n 2 -r

  if [[ $REPLY =~ ^[Nn]$ ]]; then
    echo '~~~~~~~~~~~~~~~~~~~~~~~~~'
    echo '     Close... Bye !'
    echo '~~~~~~~~~~~~~~~~~~~~~~~~~'
    break
  fi

done
