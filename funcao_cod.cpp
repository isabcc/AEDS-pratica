/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.012
 *
 * Created on 12 de junho de 2025, 08:57
 */

#include <cstdlib>
#include <stdio.h>
#include "funcao.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int TAM=10;
    
    int valeat[]={17, 14, 16, 12, 20, 15, 19, 11, 13, 18};
    int v2[]={11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int v3[]={20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    
    bubblesort(valeat,valeat+TAM);
    cout << endl << "Estado do vetor depois da ordenação" << endl;
    for(int *p=valeat; p<valeat+TAM;p++){
        cout << *p << " ";
        cout <<endl;
    }
    
    selectionsort(v2, v2+TAM);
    cout << "Selection Sort:";
    for(int *p= v2; p < v2+TAM;p++){
        cout << *p << " ";
        cout <<endl;
    }
    
    insertionsort(v3, v3+TAM);
    cout << "Insertion Sort:";
    for(int *p= v3; p < v3+TAM;p++){
        cout << *p << " ";
        cout <<endl;
    }
    
    
    
    
    
    

    
    
    
    
    

    return 0;
}

