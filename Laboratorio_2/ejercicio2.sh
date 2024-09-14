#!/bin/bash

# Parametros que recibe.
nom_proceso=$1
comando=$2

# Verficar que se pasan los parametros y que son correctos.
if [ -z "$inom_proceso" ] && [-z "$comando" ] ; then 
    echo "Proporcione tanto el nombre como el comando del proceso."
    exit 1
elif pgrep "$nom_proceso" > /dev/null 2>&1 ; then  

    # Creamos una funcion que nos imprima la informacion.
    revisar_proceso() {

        while [] ; do

            # Estructura de condiciones para revisar.
            if [] ; then 


            else


            fi

        done
        
    }


    # Llamamos la funcion.
    revisar_proceso

else
    echo "No existe un proceso con ese nombre y comando."
    exit 1
fi