#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void QuickSort(int A[N],int inicio, int fin);
void Intercambia(int *a, int *b);
void ImprimeArreglo(int A[N]);
int main()
{
    int A[N]={10, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    time_t inicio,fin;
    ImprimeArreglo(A);
    printf("\n");
    QuickSort(A,0,N-1);
    ImprimeArreglo(A);

}

void QuickSort(int A[N],int inicio, int fin)
{
    int izq=inicio, der=fin, pos=inicio;
    int band=1;

    while(band==1)
    {
       band=0;
       while(A[pos]<=A[der] && pos !=der)
       {
           der--;
       }
       if(pos!=der)
       {
           Intercambia(&A[pos],&A[der]);
           pos=der;

       }
       while(A[pos]>=A[izq] && pos!=izq)
       {
           izq++;
       }
       if(pos!=izq)
       {
           Intercambia(&A[pos],&A[izq]);
           pos=izq;
           band=1;

       }
    }
    if(pos-1>inicio)
    {
        QuickSort(A,inicio,pos-1);
    }
    if(fin > pos+1)
    {
        QuickSort(A,pos+1, fin);
    }

 }
void Intercambia(int *a, int *b)
{
    int tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;
}
void ImprimeArreglo(int A[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d,",A[i]);
    }
}
