/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* Autores: Gabriella Caproni e Isadora R. Grandeaux
 * Local: Unifal - Campus Santa Clara
 * Data: 10/06/2025
 * Disciplina: AEDs I - Prática
 * Objetivo: Este código C++ implementa um sistema simples para o gerenciamento informações de um banco de dados de imóveis,
 * que no caso é nomeado como "bdGabriellaIsadora.txt", permitindo operações como inclusão, busca, exclusão e listagem. 
 * O programa tem uma interação com o usuário a partir de um menu de opções feito com switch, o que facilita a realizações de
 * pelas mudanças e vizualização dos dados.
 */

#include <iostream>  
#include <fstream>   
#include <string>   
#include <vector>    
#include <sstream>  
#include <algorithm> 
#include <iomanip>   


using namespace std;

struct Imovel {// Define uma estrutura chamada Imovel para agrupar dados relacionados.
    //declaração das variáveis
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    float area;
    float valor;
    float iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    string cozinha;
    string sala;
    string varanda;
    string area_servico;
    string piso;
    string conservacao;
    string armarios;
    string ar_condicionado;
    string aquecedor;
    string ventilador;
};


// Função para exibir os detalhes de um imóvel
void exibirDetalhesImovel(const Imovel& im) {// Recebe um Imovel constante por referência para exibir seus dados.
    cout << "\nImóvel encontrado:\n";
    cout << "Tipo: " << im.tipo << "\n";
    cout << "Finalidade: " << im.finalidade << "\n";
    cout << "Endereço: " << im.endereco << "\n";
    cout << "Bairro: " << im.bairro << "\n";
    cout << "Cidade: " << im.cidade << "\n";
    cout << "Área: " << im.area << " m²\n";
    cout << "Valor: R$" << im.valor << "\n";
    cout << "IPTU: R$" << im.iptu << "\n";
    cout << "Quartos: " << im.quartos << "\n";
    cout << "Suítes: " << im.suites << "\n";
    cout << "Banheiros: " << im.banheiros << "\n";
    cout << "Vagas: " << im.vagas << "\n";
    cout << "Cozinha: " << im.cozinha << "\n";
    cout << "Sala: " << im.sala << "\n";
    cout << "Varanda: " << im.varanda << "\n";
    cout << "Área de Serviço: " << im.area_servico << "\n";
    cout << "Piso: " << im.piso << "\n";
    cout << "Conservação: " << im.conservacao << "\n";
    cout << "Armários: " << im.armarios << "\n";
    cout << "Ar-condicionado: " << im.ar_condicionado << "\n";
    cout << "Aquecedor: " << im.aquecedor << "\n";
    cout << "Ventilador: " << im.ventilador << "\n";
    cout << "-----------------------------------------------" << endl;
}

//Função que carrega os dados do arquivo BD e faz com que as informações sejam processadas
int carregar(vector<Imovel>& imoveis, const string& nomeArquivo) {// Recebe um vetor de Imovel por referência e o nome do arquivo.
    ifstream arquivo(nomeArquivo);
    string linha;
    int count = 0;

    if (!arquivo.is_open())
     return 0;

    getline(arquivo, linha); // Lê a primeira linha (cabeçalho) e a ignora.

    while (getline(arquivo, linha)) {// Loop para ler cada linha do arquivo.
        if (linha.find("fim") != string::npos) break;// Se encontrar "fim", para a leitura.
        stringstream ss(linha); // Cria um stringstream com a linha lida para facilitar a extração de dados.
        Imovel im;// Cria uma nova estrutura Imovel.

        // Extrai os dados da linha e os atribui aos membros da estrutura Imovel.
        ss >> im.tipo >> im.finalidade >> im.endereco >> im.bairro >> im.cidade
                >> im.area >> im.valor >> im.iptu
                >> im.quartos >> im.suites >> im.banheiros >> im.vagas
                >> im.cozinha >> im.sala >> im.varanda >> im.area_servico
                >> im.piso >> im.conservacao
                >> im.armarios >> im.ar_condicionado >> im.aquecedor >> im.ventilador;

        imoveis.push_back(im);  // Adiciona o imóvel lido ao vetor de imóveis.
        count++;  // Incrementa o contador.
        if (count >= 200) break;  // Limita a 200 imóveis para carregar 
    }

    arquivo.close();   //Fecha o arquivo.
    return count;  //Retorna o número de imóveis carregados.
}

void salvar(const vector<Imovel>& imoveis, const string& nomeArquivo) {  // Salva os dados do vetor de imóveis em um arquivo.
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

   
    arquivo << "tipo finalidade endereco bairro cidade area valor IPTU quartos suites banheiros vagas "
            << "cozinha sala varanda area_servico piso conservacao armarios ar_condicionado aquecedor ventilador\n";

    for (const Imovel& im : imoveis) { // Itera sobre cada imóvel no vetor
        // Escreve os dados de cada imóvel no arquivo, separados por espaço
        arquivo << im.tipo << " " << im.finalidade << " " << im.endereco << " " << im.bairro << " " << im.cidade << " "
                << im.area << " " << im.valor << " " << im.iptu << " "
                << im.quartos << " " << im.suites << " " << im.banheiros << " " << im.vagas << " "
                << im.cozinha << " " << im.sala << " " << im.varanda << " " << im.area_servico << " "
                << im.piso << " " << im.conservacao << " "
                << im.armarios << " " << im.ar_condicionado << " " << im.aquecedor << " " << im.ventilador << "\n";
    }

    arquivo << "fim\n"; // Escreve "fim" para indicar o final dos dados.
    arquivo.close();    // Fecha o arquivo.
}

void incluir(vector<Imovel>& imoveis) { // Permite ao usuário incluir um novo imóvel
    Imovel im; // Cria uma nova estrutura Imovel
    cout << "\nDigite os dados do imóvel:\n";
    cout << "Tipo: ";
    cin >> im.tipo;
    cout << "Finalidade: ";
    cin >> im.finalidade;
    cin.ignore(); // Limpar buffer após leitura de string sem espaços antes de getline
    cout << "Endereço: ";
    getline(cin, im.endereco);
    cout << "Bairro: ";
    getline(cin, im.bairro);
    cout << "Cidade: ";
    getline(cin, im.cidade);
    cout << "Area: ";
    cin >> im.area;
    cout << "Valor: ";
    cin >> im.valor;
    cout << "IPTU: ";
    cin >> im.iptu;
    cout << "Quartos: ";
    cin >> im.quartos;
    cout << "Suítes: ";
    cin >> im.suites;
    cout << "Banheiros: ";
    cin >> im.banheiros;
    cout << "Vagas: ";
    cin >> im.vagas;
    cout << "Cozinha: ";
    cin >> im.cozinha;
    cout << "Sala: ";
    cin >> im.sala;
    cout << "Varanda: ";
    cin >> im.varanda;
    cout << "Area de Serviço: ";
    cin >> im.area_servico;
    cout << "Piso: ";
    cin >> im.piso;
    cout << "Conservação: ";
    cin >> im.conservacao;
    cout << "Armários: ";
    cin >> im.armarios;
    cout << "Ar-condicionado: ";
    cin >> im.ar_condicionado;
    cout << "Aquecedor: ";
    cin >> im.aquecedor;
    cout << "Ventilador: ";
    cin >> im.ventilador;
    imoveis.push_back(im);  // Adiciona o novo imóvel ao vetor
    cout << "Imóvel adicionado com sucesso!\n";
}

void listar(const vector<Imovel>& imoveis) { // Lista todos os imóveis cadastrados
    cout << "\nListagem de Imóveis:\n";
    for (const Imovel& im : imoveis) { // Itera sobre cada imóvel no vetor
        // Exibe os principais dados de cada imóvel.
        cout << "Tipo:" << im.tipo << " Finalidade:" << im.finalidade << " Endereço:" << im.endereco << " Bairro:" << im.bairro << " Cidade:" << im.cidade
                << " Valor: R$" << im.valor << " Área:" << im.area << "m² Quartos:" << im.quartos << " Suítes:" << im.suites
                << " Banheiros:" << im.banheiros << " Vagas:" << im.vagas << " Cozinha:" << im.cozinha << " Sala:" << im.sala
                << " Varanda:" << im.varanda << " Área de serviço:" << im.area_servico << " Piso:" << im.piso
                << " Conservação:" << im.conservacao << " Armários:" << im.armarios << " Ar-condicionado:" << im.ar_condicionado
                << " Aquecedor:" << im.aquecedor << " Ventilador:" << im.ventilador << endl;
    }
}

void excluirRua(vector<Imovel>& imoveis) { // Busca e exclui um imóvel pela rua (endereço)
    cin.ignore(); // Limpar buffer após a leitura de um int no menu principal
    string ruaBuscaUsuario; // Variável para armazenar a rua que o usuário deseja buscar
    cout << "\nDigite o nome da rua (endereço) para buscar e excluir: ";
    getline(cin, ruaBuscaUsuario); // Lê o endereço completo

    bool encontrado = false; //Verifica se algum imóvel foi encontrado.
    vector<Imovel> imoveisNaoExcluidos; // Vetor temporário para imóveis a serem mantidos

    for (const Imovel& im : imoveis) {
        string enderecoImovel = im.endereco;
        if (enderecoImovel == ruaBuscaUsuario) { // Melhor para buscas parciais
            encontrado = true; // Define como o bool como true, ja que um imóvel foi encontrado.
            exibirDetalhesImovel(im); // Exibe o imóvel com o endereço 
            char opcao;
            cout << "Deseja excluir este imóvel? (s/n): ";
            cin >> opcao; // Lê a opção do usuário
            cin.ignore(); // Limpar buffer após ler

            if (opcao == 's' || opcao == 'S') {
                cout << "Imóvel excluído com sucesso.\n";
            } else {
                imoveisNaoExcluidos.push_back(im); // Adiciona ao vetor temporário se não for para excluir
            }
        }
        else {
            imoveisNaoExcluidos.push_back(im); // Adiciona ao vetor temporário se não for correspondente
        }
    }
    

    imoveis = imoveisNaoExcluidos; // Substitui o vetor original pelos imóveis não excluídos

    if (!encontrado) { // Se nenhum imóvel foi encontrado
        cout << "Nenhum imóvel encontrado com essa rua.\n";
    }
}


void buscarPorFaixaDeValor(const vector<Imovel>& imoveis) { // Busca imóveis por faixa de valor e finalidade
    float valorMin, valorMax; // Variáveis para o valor mínimo e máximo
    string finalidade;

    cout << "\n--- Busca por Faixa de Valor ---" << endl;
    cout << "Qual é o valor mínimo: R$";
    cin >> valorMin; //Lê o valor minimo
    cout << "Qual é o valor máximo: R$";
    cin >> valorMax; //Lê o valor máximo

    // Limpar o buffer antes de ler a string da finalidade
    cin.ignore();
    cout << "Digite a finalidade de imovel que deseja buscar (locacao, aluguel, temporada): ";
    getline(cin, finalidade);

    bool encontrado = false; //Verifica se algum imóvel foi encontrado
    cout << "\nImóveis encontrados para '" << finalidade << "' na faixa de R$"
            << valorMin << " a R$" << valorMax << ":\n";

    for (const Imovel& im : imoveis) { //Itera sobre cada imóvel
        string imFinalidade = im.finalidade;

        //Verifica se o valor está na faixa e a finalidade correspondente
        if (im.valor >= valorMin && im.valor <= valorMax && imFinalidade == finalidade) {
            exibirDetalhesImovel(im); //Exibe os detalhes
            encontrado = true;
        }
    }

    if (!encontrado) { //Caso nenhum imóvel for encontrado de acordo com os parametros dados pelo usuario
        cout << "Nenhum imóvel encontrado com os critérios especificados.\n";
    }
}

void buscarPorCaracteristicas(const vector<Imovel>& imoveis) { // Busca imóveis por características (armários, ar, aquecedor, ventilador)
    char armarios, arCondicionado, aquecedor, ventilador; // Variáveis para as respostas do usuário (s/n)

    cout << "\n--- Busca por Características ---" << endl;
    cout << "Deseja que o imóvel tenha armários? (s/n): ";
    cin >> armarios;
    cout << "Deseja que o imóvel tenha ar-condicionado? (s/n): ";
    cin >> arCondicionado;
    cout << "Deseja que o imóvel tenha aquecedor? (s/n): ";
    cin >> aquecedor;
    cout << "Deseja que o imóvel tenha ventilador? (s/n): ";
    cin >> ventilador;

    // Limpar o buffer após a última leitura de char
    cin.ignore();

    bool encontrado = false; //Verifica se algum imóvel foi encontrado
    cout << "\nImóveis encontrados com as características selecionadas:\n";

    for (const Imovel& im : imoveis) {
        //variaveis que serão usadas para a comparação entre o que o usuário quer e o que foi encontrado
        char eArmarios = armarios;
        char eArCondicionado = arCondicionado;
        char eAquecedor = aquecedor;
        char eVentilador = ventilador;

        // Faz uma comparação com o primeiro char da string (que é o vetor "sim" ou "não")
        char imArmarios = im.armarios[0];
        char imArCondicionado = im.ar_condicionado[0];
        char imAquecedor = im.aquecedor[0];
        char imVentilador = im.ventilador[0];

// Compara as características do imóvel com as desejadas pelo usuário.
        if (eArmarios == imArmarios && eArCondicionado == imArCondicionado && eAquecedor == imAquecedor && eVentilador == imVentilador) {
            exibirDetalhesImovel(im); //Exibe os detalhes do imóvel
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum imóvel encontrado com as características especificadas.\n";
    }
}

void buscarPorQuartosSuites(const vector<Imovel>& imoveis) { // Busca imóveis por número de quartos e suítes
    int numQuartos; //Váriavel para o número de quartos
    int numSuites; //Váriavel para o número de suítes

    cout << "\n--- Busca por Número de Quartos e Suítes ---" << endl;
    cout << "Digite o número de quartos desejado: ";
    cin >> numQuartos;

    cout << "Digite o número de suítes desejadas: ";
    cin >> numSuites;

    bool encontrado = false;
    cout << "\nImóveis encontrados com " << numQuartos << " quartos e "
            << numSuites << " suítes:\n";

    for (const Imovel& im : imoveis) {
        // Apenas verifica se os valores são iguais aos desejados
        if (im.quartos == numQuartos && im.suites == numSuites) {
            exibirDetalhesImovel(im);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum imóvel encontrado com " << numQuartos << " quartos e "
                << numSuites << " suítes.\n";
    }
}

void gerarRelatorioEstatisticas(const vector<Imovel>& imoveis) { // Gera um relatório de estatísticas
    cout << "\n--- Relatório de Estatísticas ---" << endl;

    if (imoveis.empty()) { // Verifica se o vetor de imóveis está vazio
        cout << "Nenhum imóvel cadastrado para gerar estatísticas.\n";
        return;
    }

    // 1. Porcentagens de imóveis por finalidade
    int totalImoveis = imoveis.size(); // Obtém o número total de imóveis
    int contVenda = 0; // Contador para imóveis de venda
    int contAluguel = 0; // Contador para imóveis de aluguel
    int contTemporada = 0; // Contador para imóveis de temporada
    int contOutraFinalidade = 0; // Contador para outras finalidades

    for (const Imovel& im : imoveis) {
        string finalidade = im.finalidade;

        if (finalidade == "venda") { // Se a finalidade for venda
            contVenda++; // Adiciona o contador de venda
        } else if (finalidade == "aluguel") { //Se a finalidade for aluguel
            contAluguel++; //Adiciona o contador de aluguel
        } else if (finalidade == "temporada") { //Se a finalidade for temporada
            contTemporada++; //Adiciona no contador de temporada
        } else {
            contOutraFinalidade++; //Adiciona no contador de outras finalidades
        }
    }

    cout << "\n1. Porcentagens de Imóveis por Finalidade:\n";
    cout << fixed << setprecision(2); // Formatar para 2 casas decimais

    if (totalImoveis > 0) {// Se houver imóveis,calcula e exibe as porcentagens de cada finalidade
        cout << "  Venda:   " << (static_cast<float> (contVenda) / totalImoveis) * 100.0 << "%\n";
        cout << "  Aluguel:   " << (static_cast<float> (contAluguel) / totalImoveis) * 100.0 << "%\n";
        cout << "  Temporada: " << (static_cast<float> (contTemporada) / totalImoveis) * 100.0 << "%\n";
        if (contOutraFinalidade > 0) {
            cout << "  Outras:    " << (static_cast<float> (contOutraFinalidade) / totalImoveis) * 100.0 << "%\n";
        }
    } else {
        cout << "  Nenhum imóvel para calcular porcentagens de finalidade.\n";
    }

    // 2. Porcentagem de casas com suítes
    int totalCasas = 0; // Contador para o total de casas
    int casasComSuites = 0; // Contador para casas com suítes

    for (const Imovel& im : imoveis) {
        string tipo = im.tipo; //Obtem o tipo de imóvel

        if (tipo == "casa") { //Se houver casas, adiciona no contador de casas
            totalCasas++;
            if (im.suites > 0) { //Se tiver suítes, adiciona no contador de casas com suítes
                casasComSuites++;
            }
        }
    }

    cout << "\n2. Porcentagem de Casas com Suítes:\n";
    if (totalCasas > 0) { //Se houver casas, calcula e exibe a porcentagem de casas com suítes
        cout << "  " << (static_cast<float> (casasComSuites) / totalCasas) * 100.0 << "%\n";
    } else {
        cout << "  Nenhuma casa cadastrada para calcular a porcentagem de suítes.\n";
    }


    // 3. Porcentagem de pisos com cerâmica nas salas comerciais
    int totalSalasComerciais = 0; // Contador para o total de salas comerciais
    int salasCeramica = 0; // Contador para salas comerciais com piso de cerâmica

    for (const Imovel& im : imoveis) {
        string tipo = im.tipo; //Obtém o tipo de imóvel
        string piso = im.piso; //Obtém o tipo do piso

        if (tipo == "sala_comercial") {
            totalSalasComerciais++;
            if (piso == "cerâmica") { 
                salasCeramica++;
            }
        }
    }

    cout << "\n3. Porcentagem de Salas Comerciais com Piso de Cerâmica:\n";
    if (totalSalasComerciais > 0) { //Se houver salas comerciais, calcula e exibe a porcentagem
        cout << "  " << (static_cast<float> (salasCeramica) / totalSalasComerciais) * 100.0 << "%\n";
    } else {
        cout << "  Nenhuma sala comercial cadastrada para calcular a porcentagem de piso de cerâmica.\n";
    }

    cout << "\n---- Fim do Relatório --=-" << endl;
}

void menu() { // Exibe o menu de opções para o usuário
    cout << "\nMenu de Opções:\n";
    cout << "1 - Incluir novo imóvel na base de dados\n";
    cout << "2 - Buscar e excluir um imóvel da base de dados pela rua \n";
    cout << "3 - Buscar imóveis por uma faixa de valores para locação, aluguel ou temporada\n";
    cout << "4 - Buscar imóvel pela suas características\n";
    cout << "5 - Buscar por quartos e suítes\n";
    cout << "6 - Relatório de estatísticas\n";
    cout << "7 - Listar todos os imóveis\n";
    cout << "0 - Sair e salvar\n";
    cout << "Escolha uma opção: ";
}

int main() {// Função principal do programa
    vector<Imovel> imoveis; // Declara um vetor para armazenar os imóveis
    const string nomeArquivo = "bdGabriellaIsadora.txt"; // Define o nome do arquivo de dados

    carregar(imoveis, nomeArquivo); // Chama a função para carregar os imóveis do arquivo

    int opcao; // Variável para armazenar a opção escolhida pelo usuário
    do {
        menu(); //Exibe o menu de opções
        cin >> opcao; //Lê a opção escolhida pelo usuário

        switch (opcao) { // Usa a estrutura switch para executar a ação correspondente à opção
            case 1:
                incluir(imoveis);
                break;
            case 2:
                excluirRua(imoveis);
                break;
            case 3:
                buscarPorFaixaDeValor(imoveis);
                break;
            case 4:
                buscarPorCaracteristicas(imoveis);
                break;
            case 5:
                buscarPorQuartosSuites(imoveis);
                break;
            case 6:
                gerarRelatorioEstatisticas(imoveis);
                break;
            case 7:
                listar(imoveis);
                break;
            case 0:
                salvar(imoveis, nomeArquivo); // Chama a função para salvar os dados no arquivo
                cout << "Dados salvos e programa encerrado.\n";
                break;
            default:
                cout << "Opção inválida!\n"; // Mensagem para opção inválida
        }
    } while (opcao != 0); // Continua o loop enquanto a opção não for 0

    return 0;
}
