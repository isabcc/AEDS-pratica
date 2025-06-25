/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: isagr
 *
 * Created on 15 de maio de 2025, 16:29
 */

#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

void salvarNoArquivo(ofstream &arquivo, int vetor[], int tamanho, const string &mensagem) {
    arquivo << mensagem << endl;
    for (int i = 0; i < tamanho; i++) {
        arquivo << vetor[i] << " ";
    }
    arquivo << endl << "-----------------------------" << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {

    const int MAX = 100;

    int vetor[MAX], tamanho = 0, valor, pos, opcao, i, j, temp;
    
    ofstream arquivo("valorvetores.txt");
    if(!arquivo.is_open()){
        cout << "\nErro: Arquivo não encontrado\n";
        return 1;
    }

    cout << "Digite o tamanho do vetor (até " << MAX << "): ";
    cin >> tamanho;

    if (tamanho > MAX || tamanho < 0) {
        cout << "Tamanho inválido!" << endl;
        return 1;
    }

     srand(time(0)); 
     for (i = 0; i < tamanho; i++) {
     vetor[i] = rand() % 100;
     }
     salvarNoArquivo(arquivo, vetor, tamanho, "Vetor gerado aleatoriamente:");
     
    
     
     do{
    cout << "-------------------MENU----------------------" << endl;
    cout << "1) Inverta os valores de um vetor" << endl;
    cout << "2) Adicione um valor a todos os elementos" << endl;
    cout << "3) Adicione um valor a todos os elementos não divisíveis por três" << endl;
    cout << "4) Remova a 1° ocorrência de um valor" << endl;
    cout << "5) Remova do vetor todas as ocorrências de um valor" << endl;
    cout << "6) Inserir um valor no vetor, se não estiver cheio" << endl;
    cout << "7) Inserir um valor em uma posição determinada" << endl;
    cout << "8) Remover todos os valores repetidos de um vetor" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opção das apresentadas acima:" << endl;
    cin >> opcao;


        //inverter os valores de um vetor
        if (opcao == 1) {
            for (i = 0; i < tamanho / 2; i++) {
                temp = vetor[i];
                vetor[i] = vetor[tamanho - 1 - i];
                vetor[tamanho - 1 - i] = temp;
            }
        salvarNoArquivo(arquivo, vetor, tamanho, "Vetor invertido:");
        }           
        
        //adiciona valor em todos os elementos
        else if (opcao == 2) {
            cout << "Digite o valor a adicionar:" <<endl;
            cin >> valor;
            for (i = 0; i < tamanho; i++) {
                vetor[i] += valor;
            }
        salvarNoArquivo(arquivo, vetor, tamanho, "Valor adicionado a todos os elementos:");
        }           
        
        //remove a 1º ocorrencia de um valor
        else if (opcao == 4) {
            cout << "Digite o valor que terá sua 1º ocorrência removida:" << endl;
            cin >> valor;
            for (i = 0; i < tamanho; i++) {
                if (vetor[i] == valor) {
                    for (int j = i; j < tamanho - 1; j++) {
                        vetor[j] = vetor[j + 1];
                    }
                    tamanho--;
                }
            }
             salvarNoArquivo(arquivo, vetor, tamanho, "1ª ocorrência removida:");
        }            
        
        //adiciona um valor a todos os elementos não divisiveir por três
        else if (opcao == 3) {
            cout << "Digite o valor a adicionar:" << endl;
            cin >> valor;
            for (i = 0; i < tamanho; i++) {
                if (vetor[i] % 3 != 0) {
                    vetor[i] = +valor;
                }
            }
             salvarNoArquivo(arquivo, vetor, tamanho, "Valor adicionado a elementos não divisíveis por 3:");
        }           
        
        //remove do vetor todas as ocorrencias de um valor
        else if (opcao == 5) {
            cout << "Digite o valor que terá todas as sua ocorrências removidas:" << endl;
            cin >>valor;
            for (i = 0; i < tamanho; i++) {
                if (vetor[i] == valor) {
                    for (j = i; j < tamanho - 1; j++) {
                        vetor[j] = vetor[j + 1];
                    }
                    tamanho--;
                }
            }
             salvarNoArquivo(arquivo, vetor, tamanho, "Todas as ocorrências removidas:");
        }           
        
        //inseri um valor ao vetor, se não estiver cheio
        else if (opcao == 6) {
            cout << "Digite o valor a ser inserido no vetor:" << endl;
            cin >> valor;
            if (tamanho < MAX) {
                vetor[tamanho++] = valor;
                salvarNoArquivo(arquivo, vetor, tamanho, "Valor inserido no fim:");
            } else {
                cout << "Vetor cheio, impossível adicionar valor!" << endl;
            }
        }           
        
        //inseri um valor em determinada posição
        else if (opcao == 7) {
            cout << "Digite o valor a ser inserido:" << endl;
            cin >> valor;
            cout << "Digite qual posição deseja inserir esse valor:" << endl;
            cin >> pos;
            if (pos < 0 || tamanho >= MAX || pos < tamanho) {
                cout << "Posição inválida ou o vetor já está cheio" << endl;
                cout << "Escolha novamente uma opção das apresentadas acima:" << endl;
                cin >> opcao;
            }
            for (i = tamanho; i > pos; i--) {
                vetor[i] = vetor[i - 1];
            }
            vetor[pos] = valor;
            tamanho++;
            salvarNoArquivo(arquivo, vetor, tamanho, "Valor inserido em posição específica:");
        }            
        
        //remove todos os valores repetido de um vetor]
        else if (opcao == 8) {
            cout << "Digite o valor que terá sua repetições removidas do vetor:" << endl;
            cin >> valor;
            for (i = 0; i < tamanho; i++) {
            }
            for (j = i + 1; j < tamanho;) {
            }
            if (vetor[i] == vetor[j]) {
                for (int k = j; k < tamanho - 1; k++) {
                    vetor[k] = vetor[k + 1];
                }
                tamanho--;
            } else {
                j++;
            }
        salvarNoArquivo(arquivo, vetor, tamanho, "Valores repetidos removidos:");
        }

            else if(opcao==0){
            cout << "Programa finalizado!" << endl;
            
            
        } else{
            cout << "Opção inválida, tente novamente:" << endl;
            cin >>opcao;

        }
    
    }while(opcao != 0);
         arquivo.close();
        
    


     
    return 0;
}

