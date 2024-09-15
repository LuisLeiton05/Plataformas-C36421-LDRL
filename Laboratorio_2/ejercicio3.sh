#!/bin/bash 

# Ejecutable/id 
id=$1

# Verificar si se pasa el parametro.
if [ -z "$id" ] ; then 
    echo "Proporcione el ejecutable/id de un proceso a monitorear."
    exit 1
elif ps -p "$id" > /dev/null 2>&1 ; then  

    # Creamos una funcion que lea y registre en un archivo log.
    leer_registrar() {
        # Revisar periodicamente el proceso y registrar.
        while true ; do
            

            # Esperar 20 segundos antes de hacer el segundo registro.
            sleep 5
        done
        
    }


    # Llamamos la funcion.
    leer_registrar

    # Graficar los valores sobre el tiempo (se usa gnuplot).

else
    echo "No existe un proceso con ese id."
    exit 1
fi