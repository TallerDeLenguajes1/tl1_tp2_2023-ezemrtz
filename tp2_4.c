#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
}typedef compu;

int main(){
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu pc[5];

    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        pc[i].velocidad = 1+rand()%4;
        pc[i].anio = 2015+rand()%8;
        pc[i].cantidad = rand()%9;
        pc[i].tipo_cpu = tipos[rand()%7];
    }
    

    printf("%d\n", pc[1].velocidad);
    printf("%d\n", pc[1].anio);
    printf("%d\n", pc[1].cantidad);
    puts(pc[1].tipo_cpu);
    
    


    return 0;
}