#define N 20
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    double vt[N], *pvt=vt;
    for(i = 0;i<N; i++)
    {
        *(pvt++) =1+rand()%100;
    }
    pvt=vt;
    for(i = 0;i<N; i++)
    {
        printf("%f ", *pvt++);
    }
    return 0;
}
