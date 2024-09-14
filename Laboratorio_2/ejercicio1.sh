#!/bin/bash

# Pedir id y verficar que existe.
id=$1
if [ -z "$id" ] ; then 
    echo "Proporcione el ID de un proceso."
    exit 1
elif [ -n "$id" ] ; then  
    

else
    echo "No existe un proceso con ese ID."
    exit 1
fi
