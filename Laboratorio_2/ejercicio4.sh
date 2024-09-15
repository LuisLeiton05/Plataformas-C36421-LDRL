#!/bin/bash 

directorio="/home/ldrl05/scripting"

    # Revisar periodicamente el directorio y registrar en caso de actividad.
    inotifywait -m -e create -e modify -e delete "$directorio" | while read -r evento; do

    # Logica para que se registre con fecha y hora en el .log.
    fecha=$(date "+%Y-%m-%d %H:%M:%S") 
    echo "$fecha  $evento" >> "registro_dir.log"

    done
