#include <iostream>

using namespace std;

void bubblesort(int *inicio, int *fim){
    for(int *i=inicio; i<fim-1; i++){
        for(int *j= inicio; j<fim-(i-inicio)-1;j++){
            if(*j>*(j+1)){
                int temp=*j;
                *j=*(j+1);
                *(j+1)=temp;
            }
        } 
    }
}

void selectionsort(int *inicio, int *fim){
    for(int *i=inicio; i<fim-1; i++){
        int *menor=i;
        for(int *j=i+1; j< fim; j++){
            if(*j< *menor){
                menor=j;
            }
        }
        if(menor != i){
            int temp=*i;
            *i=*menor;
            *menor=temp;
        }
    }
}

void insertionsort(int *inicio, int *fim){
    for(int *i=inicio+1; i<fim; i++){
        int chave=*i;
        int *j=i-1;
        while(j>=inicio && *j >chave){
            *(j+1)=*j;
            j--;     
        }
        *(j+1)= chave;
    }
}
