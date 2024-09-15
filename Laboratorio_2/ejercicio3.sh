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
            transcurrido=$(( $tiempo_actual - $tiempo_inicial ))

            # Revisar cuando ya hayan pasado 60 segundos (lo hago asi para que a la hora de graficar sea mas comodo).
            if [ "$transcurrido" -ge 60 ] ;  then
                echo "Paso el tiempo de registro."
                break
            else
                # Logica para que se registre con fecha y hora, en el .log.
                fecha=$(date "+%Y-%m-%d %H:%M:%S %S") #Le anadi una columna con los segundos para graficar mejor.
                mem_cpu=$( ps -p 3707 -o %mem,%cpu | tail -n +2 )
                echo "$fecha  $mem_cpu" >> "registro.log"

            fi
            # Esperar 5 segundos antes de hacer el segundo registro.
            sleep 5
        done
        
    }


    # Llamamos la funcion.
    leer_registrar 
    # Almacenamos en una variable el contenido del archivo.
    registro="registro.log"
    # Graficar los valores sobre el tiempo (se usa gnuplot).
    # Grafica de la memoria.
gnuplot -persist <<-EOF
        set title "Uso de memoria del proceso:"
        set xlabel "Tiempo"
        set ylabel "%Memoria"
        set grid
        set key outside 

        # Generar el gráfico con dos columnas distintas
        plot "$registro" using 3:4 with lines title "%mem"
EOF

    # Grafica del CPU.
gnuplot -persist <<-EOF
        set title "Uso de CPU del proceso:"
        set xlabel "Tiempo"
        set ylabel "%CPU"
        set grid
        set key outside 

        # Generar el gráfico con dos columnas distintas
        plot "$registro" using 3:5 with lines title "%cpu"
EOF

else
    echo "No existe un proceso con ese id."
    exit 1
fi