/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
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

#ifndef MATTRIZ_PONTEIRO_H
#define MATTRIZ_PONTEIRO_H

const int TAM = 128;
typedef int vetor[TAM][TAM];

void multiplicar(vetor m, int linhas, int colunas, int fator);

void matriz_transposta(vetor m, int linhas, int colunas);

void inv_colunas_h(vetor m, int linhas, int colunas);

void inv_linhas_v(vetor m, int linhas, int colunas);

#endif /* MATTRIZ_PONTEIRO_H */

