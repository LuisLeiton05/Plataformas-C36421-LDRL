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
        # Creamos las variables para poder llevar el tiempo, usando el comando date.
        tiempo_inicial=$( date +%s )

        # Revisar periodicamente el proceso y registrar.
        while true ; do
            # Tiempo actual.
            tiempo_actual=$( date +%s )

            # Calculamos el tiempo.
            transcurrido=$( $tiempo_actual - $tiempo_inicial )

            # Revisar cuando ya hayan pasado 30 segundos (lo hago asi para que a la hora de graficar sea mas comodo).
            if [ $transcurrido -ge 30 ] ;  then
                echo "Paso el tiempo de registro."
                break
            else
                mem_cpu=$( ps -p 3707 -o %mem,%cpu | tail -n +2 )
                

            fi
            # Esperar 5 segundos antes de hacer el segundo registro.
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