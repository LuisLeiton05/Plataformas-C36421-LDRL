#!/bin/bash

# Pedir id y verficar que existe.
id=$1
if [ -z "$id" ] ; then 
    echo "Proporcione el ID de un proceso."
    exit 1
elif [ $(ps -p "$id") ] ; then  

    # Creamos una funcion que nos imprima la informacion.
    info_proceso() {
        # Con los comando creados se imprime:
        nombre=$( )
        ID=$( )
        PPID=$( )
        usuario=$( )
        CPU=$( )
        memoria=$( )
        estado=$( )
        path=$( )

        # Nombre del proceso.
        echo "Nombre del proceso: $nombre"
        # ID del proceso.
        echo ""
        # Parent Process ID.
        echo ""
        # Usuario propietario.
        echo ""
        # Porcentaje de uso del CPU.
        echo ""
        # Consumo de memoria.
        echo ""
        # Estados.
        echo ""
        # Path del ejecutable.
        echo ""
    }

    ps -p "$id" -l | tail -n +2 | awk '{print $14}' # nombre
    ps -p "$id" -f -l | tail -n +2 | awk '{print $}' # b,c,d y g

    # Llamamos la funcion.
    info_proceso

else
    echo "No existe un proceso con ese ID."
    exit 1
fi
