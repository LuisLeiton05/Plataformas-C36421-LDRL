#!/bin/bash

# Pedir id y verficar que existe.
id=$1
if [ -z "$id" ] ; then 
    echo "Proporcione el ID de un proceso."
    exit 1
elif ps -p "$id" > /dev/null 2>&1 ; then  

    # Creamos una funcion que nos imprima la informacion.
    info_proceso() {
        # Con los comando modificados se imprime:
        nombre=$( ps -p "$id" -l | tail -n +2 | awk '{print $14}' )
        ID=$( ps -p "$id" -f -l | tail -n +2 | awk '{print $4}' )
        parent_id=$( ps -p "$id" -f -l | tail -n +2 | awk '{print $5}' )
        usuario=$( ps -p "$id" -f -l | tail -n +2 | awk '{print $3}' )
        CPU=$( ps -p "$id" -o %cpu | tail -n +2)
        memoria=$( ps -p "$id" -o %mem | tail -n +2 )
        estado=$( ps -p "$id" -f -l | tail -n +2 | awk '{print $2}' )
        path_pro=$( readlink /proc/"$id"/exe )

        # Nombre del proceso.
        echo "Nombre del proceso: $nombre"
        # ID del proceso.
        echo "ID del proceso: $ID"
        # Parent Process ID.
        echo "Parent process ID: $parent_id"
        # Usuario propietario.
        echo "Usuario propietario: $usuario"
        # Porcentaje de uso del CPU.
        echo "Porcentaje de uso del CPU: $CPU"
        # Consumo de memoria.
        echo "Consumo de memoria: $memoria"
        # Estados.
        echo "Estado: $estado"
        # Path del ejecutable.
        echo "Path del ejecutable: $path_pro"
    }


    # Llamamos la funcion.
    info_proceso

else
    echo "No existe un proceso con ese ID."
    exit 1
fi
