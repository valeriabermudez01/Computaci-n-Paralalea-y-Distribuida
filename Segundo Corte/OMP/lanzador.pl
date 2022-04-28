#!/usr/bin/perl

########################################################################################
# Fecha: Abril 2022
# Materia: Parallel Computing
# Tema: Diseño de Experimentos, Automatización de ejecución (promedio y desviación)
########################################################################################


$PATH = `pwd`;
chomp($PATH);
# Variable que represente la cantidad de repeticiones
$N = 36;

#Se crea un vector de ejecutables
@ejecutables = ('MM1cOMP','MM1fOMP','MMPosix');

#Se crea un vector de Dimensiones NXN
@dimension = ("100","200","400","800","1000","1200","1500","1800","2000","2400","2800","3000","3200");

#Se crea un vector de hilos
@hilos = ("1","2","4","8");

foreach $exe (@ejecutables){
    foreach $size (@dimension){
        foreach $thread (@hilos){
            $File="$PATH/"."ejecuciones/"."$exe"."-$size"."-$thread".".txt";
	  #print"$File \n";
	  for($i=0;$i<$N;$i++){
		  system "$PATH/$exe $size $thread >> $File";
			
	 }
        }
    }
    close($File);
}

