#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
}typedef compu;

void mostrar(compu *pc);
void masVieja(compu *pc);
void masRapida(compu *pc);

int main(){
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu pc[5], *ppc = pc;

    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        pc[i].velocidad = 1+rand()%3;
        pc[i].anio = 2015+rand()%9;
        pc[i].cantidad = 1+rand()%8;
        pc[i].tipo_cpu = malloc(10*sizeof(char));
        strcpy(pc[i].tipo_cpu, tipos[rand()%6]);
    }
    mostrar(ppc);
    masVieja(ppc);
    masRapida(pc);

    for (int i = 0; i < 5; i++){
        free(pc[i].tipo_cpu);
    }
    return 0;
}

void mostrar(compu *pc){
    for (int i = 0; i < 5; i++){
        printf("\n========= PC Nro: %d =========\n", i+1);
        printf("Velocidad: %d GHz\n", pc->velocidad);
        printf("Anio: %d\n", pc->anio);
        printf("Cantidad de nucleos: %d\n", pc->cantidad);
        printf("CPU: ");
        puts(pc->tipo_cpu);
        pc++;
    }
}

void masVieja(compu *pc){
    compu *pcaux = pc;
    int menor = (pcaux++)->anio, imenor=0;
    for(int i = 1; i < 5; i++){
        if(pcaux->anio < menor){
            menor = pcaux->anio;
            imenor = i;
            pcaux++;
        }
    }
    pcaux = pc+imenor;
    printf("\n====== PC mas vieja ======\n");
    printf("Velocidad: %d GHz\n", (pcaux)->velocidad);
    printf("Anio: %d\n", (pcaux)->anio);
    printf("Cantidad de nucleos: %d\n", (pcaux)->cantidad);
    printf("CPU: ");
    puts((pcaux)->tipo_cpu);
}

void masRapida(compu *pc){
    compu *pcaux = pc;
    int mayor = (pcaux++)->velocidad, imayor=0;
    for(int i = 1; i < 5; i++){
        if(pcaux->velocidad > mayor){
            mayor = pcaux->velocidad;
            imayor = i;
            pcaux++;
        }
    }
    pcaux = pc+imayor;
    printf("\n====== PC con mayor velocidad ======\n");
    printf("Velocidad: %d GHz\n", (pcaux)->velocidad);
    printf("Anio: %d\n", (pcaux)->anio);
    printf("Cantidad de nucleos: %d\n", (pcaux)->cantidad);
    printf("CPU: ");
    puts((pcaux)->tipo_cpu);
}
