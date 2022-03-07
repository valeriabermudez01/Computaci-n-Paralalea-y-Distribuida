#!/usr/bin/perl

########################################################################################
# Fecha: 17 febrero 2022
# Materia: Parallel Computing
# Tema: Diseño de Experimentos, Automatización de ejecución (promedio y desviación)
########################################################################################


$PATH = `pwd`;
chomp($PATH);
# Variable que represente la cantidad de repeticiones
$N = 2;
#Se crea un vector de ejecutables

@ejecutables = ('bench01');
#Se crea un vector de DImensiones NXN

@dimension = ("100","200");

foreach $exe (@ejecutables){
    foreach $size (@dimension){
        $File = "$PATH/"."$exe"."-$size"."txt";
        #print "$File \n";
        for($i=0; $i<$N;$i++){
            system "$PATH/$exe $size >> $File";
            #print "$PATH/$exe $size \n";
        }
        close($File);
    }
}
exit(0);
