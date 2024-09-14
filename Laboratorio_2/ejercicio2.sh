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
        id=$( pgrep "$nom_proceso" )
        estado_proceso=$(ps -p "$id" -f -l | tail -n +2 | awk '{print $2}')
        while [ -n "$inom_proceso" ] && [-n "$comando" ]; do

            # Estructura de condiciones para revisar.
            if [ "$estado_proceso" = "T" ] ; then 
                # Levantar el proceso con el comando.
                $comando &
                echo "El proceso estaba inactivo, por lo que fue levantado."
                
            else
                echo "El proceso se encuentra activo."
            fi

        done
        
    }


    # Llamamos la funcion.
    revisar_proceso

else
    echo "No existe un proceso con ese nombre y comando."
    exit 1
fi