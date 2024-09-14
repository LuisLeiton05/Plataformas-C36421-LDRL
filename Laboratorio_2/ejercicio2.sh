#!/bin/bash

# Parametros que recibe.
nom_proceso=$1
comando=$2

# Verficar que se pasan los parametros y que son correctos.
if [ -z "$nom_proceso" ] || [ -z "$comando" ] ; then 
    echo "Proporcione tanto el nombre como el comando del proceso."
    exit 1
elif pgrep "$nom_proceso" > /dev/null 2>&1 ; then  

    # Creamos una funcion que nos imprima la informacion.
    revisar_proceso() {
        # Revisar periodicamente el proceso.
        while true ; do
            id=$( pgrep -o "$nom_proceso" ) # Se usa -o para obtener solo el id del mas reciente.
            # Revisar si se encontraron id.
            if [ -z "$id" ]; then
                echo "No se encontró ningún proceso con el nombre proporcionado."
                exit 1
            fi
            estado_proceso=$(ps -p "$id" -f -l | tail -n +2 | awk '{print $2}')

            # Estructura de condiciones para revisar.
            if [ "$estado_proceso" = "T" ] ; then 
                # Levantar el proceso con el comando.
                $comando & 
                echo "El proceso estaba inactivo, por lo que fue levantado."

            else
                echo "El proceso se encuentra activo."
            fi

            # Esperar 20 segundos antes de hacer la segunda verificacion.
            sleep 20
        done
        
    }


    # Llamamos la funcion.
    revisar_proceso

else
    echo "No existe un proceso con ese nombre y comando."
    exit 1
fi