/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 *Data:24/06/2025
 * 
 *Local:Alfenas-MG
 * 
 *Autora:Isadora Resende Grandeaux
 * 
 *Mátricula:2025.1.08.012
 * 
 *Disciplina:AEDsI(prática)
 * 
 *Professor:Paulo Alexande Bressan
 */

#include "matriz_ponteiro.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ostream>

void multiplicar(vetor m, int linhas, int colunas, int fator) {
    for (int i = 0; i < linhas; i++) {
        int* linha = *(m + i); // Ponteiro para a i-ésima linha
        for (int j = 0; j < colunas; j++) {
            *(linha + j) *= fator; // Acessa a coluna j da linha i
        }
    }
}

void matriz_transposta(vetor m, int linhas, int colunas) {
    if (linhas != colunas) return; //Garante que só funciona com matriz quadradas.
    for(int i=0; i<linhas; i++){
    for (int j = i + 1; j < colunas; j++) {
        //Troca o valor de m[i][j] com o de m[j][i].
            int* a = *(m + i) + j;
            int* b = *(m + j) + i;
            int temp = *a; //"salva" esse valor 
            *a = *b;
            *b = temp; //Troca o valor 
        }
    }
}


void inv_colunas_h(vetor m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        int *linha = *(m + i); //Ponteiro para indicar a linha atual.
        for (int j = 0; j < colunas / 2; j++) {
            int *a = linha + j; //Ponteiro para coluna esquerda
            int *b = linha + (colunas - 1 - j); //Ponteiro para coluna a direita
            int temp = *a; //"salva" o valor da posição atual.
            *a = *b;
            *b = temp; //Troca o valor da posição em questão.
        }
    }    
}

void inv_linhas_v(vetor m, int linhas, int colunas) {
    for (int i = 0; i < linhas / 2; i++) {
        int *linhaA = *(m + i); //Ponteiro para a linha de cima.
        int *linhaB = *(m + (linhas - 1 - i)); //Ponteiro para a linha de baixo.
        for (int j = 0; j < colunas; j++) {
            int temp = *(linhaA + j); //"salva" o valor dessa linha.
            *(linhaA + j) = *(linhaB + j);
            *(linhaB + j) = temp; //Troca o valor entre as duas linhas.
        }
    }
}

