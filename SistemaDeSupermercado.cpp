*
@Projeto: SMKT MONITOR

@integrantes:
Caio Rodrigues Lino Mesquita - 202014842
Caio Vinicius Sanches Moreira - 211027222
Leonardo Costa Mota - 211027474

@Descrição: Sistema de caixa de supermercado que registra o inventário de produtos do estoque e,
ao longo do p atualiza o número de produtos de acordo com as vendas e outras condições,  ao final do dia o caixa poderá retirar um relatório.
*/

// 1 - POO
// 2 - ORDENAÇÃO - QUICKSORT
// 3 - BUSCA - SENTINELA
// 4 - LISTA

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <locale.h>
#include <vector>
#include <cstdio>
#include <sstream>
#include <limits>
#include <stdio.h>
#include <list>

using namespace std;

// prototipos
void limpar_buffer(void);

fstream lista;

class Produtos
{

public:
    int id;
    string nome;
    int quantidade;
    float precocusto;
    float precovenda;
    float lucro;

    Produtos()
    {
        quantidade = 0;
        nome = "NULL";
        precocusto = 0;
        precovenda = 0;
        id = 0;
        lucro = 0;
    }

    void abrir_arquivo(int escolha)
    {
        // caso escolha seja 0, abre o arquivo na ultima linha escrita e é do tipo out
        if (escolha == 0)
        {
            lista.open("inventario.txt", ios::out | ios::app);
            if (!lista.is_open())
            {
                cerr << "Não foi poss?vel abrir o arquivo | OUT" << endl;
                getch();
            }
        }
        // caso escolha seja 1, abre o arquivo na primeira linha e é do tipo in
        else if (escolha == 1)
        {
            lista.open("inventario.txt", ios::in);
            if (!lista.is_open())
            {
                cerr << "Não foi poss?vel abrir o arquivo | IN" << endl;
                getch();
            }
        }
        // caso escolha seja outro numero, abre o arquivo na primeira linha e é do tipo out
        else
        {
            lista.open("inventario.txt", ios::out);
            if (!lista.is_open())
            {
                cerr << "Não foi poss?vel abrir o arquivo | OUT" << endl;
                getch();
            }
        }
    }

    // funcao do tipo void que fecha o arquivo banco toda vez que e chamada
    void fecha_arquivo()
    {
        lista.close();
    }

    void limpar_buffer(void)
    {

        fflush(stdin);
    }

    void limpar_txt(void)
    {
        lista.open("inventario.txt", ios::out | ios::trunc);
        lista.close();
    }

    void registrar_produtos()
    {

        string n1;
        int n2;
        float n3, n4;

        cout << "Digite o id do produto a ser cadastrado: ";
        limpar_buffer();
        cin >> n2;

        cout << "Nome do produto: ";
        limpar_buffer();
        cin >> n1;

        cout << "Digite o preco de custo: ";
        limpar_buffer();
        cin >> n4;

        cout << "Digite o preco de venda: ";
        limpar_buffer();
        cin >> n3;

        setPrecocusto(n4);
        setPrecovenda(n3);
        setNome(n1);
        setId(n2);
        //  imprimir_no_arquivo();
    }

    // getters e setters

    void setId(int m) { id = m; }
    void setNome(string m) { nome = m; }
    int getId() { return id; }
    string getNome() { return nome; }
    void setQuantidade(int m) { quantidade = m; }
    void setPrecovenda(float m) { precovenda = m; }
    void setPrecocusto(float m) { precocusto = m; }
    int getQuantidade() { return quantidade; }
    float getPrecovenda() { return precovenda; }
    float getPrecocusto() { return precocusto; }
    void setLucro(float m) { lucro = m; }
    float getLucro() { return lucro; }

    void adicionar_produtos()
    {

        int n2;
        cout << "|ID: " << getId() << "| NOME: " << getNome() << "| QUANTIDADE: " << getQuantidade() << endl;
        cout << "Quantidade a ser adicionada: " << endl;
        limpar_buffer();
        cin >> n2;

        setQuantidade(quantidade + n2);
    }

    void vender_produtos()
    {

        int quant;

        cout << "VENDA DE PRODUTOS" << endl;
        
        cout << "Digite a quantidade do produto a ser vendido: ";
        limpar_buffer();

        cin >> quant;

        setQuantidade(quantidade - quant);

        setLucro(quant * precovenda - precocusto * quant);

        cout << "O lucro obtido com a venda foi de: " << getLucro() << endl;
    }

    void imprimirestoque()
    {
        cout << "ESTOQUE ATUAL DE PRODUTOS" << endl;
        cout << "|ID: " << getId() << "| NOME: " << getNome() << "| QUANTIDADE: " << getQuantidade() << "| PRECO CUSTO: " << getPrecocusto() << "| PRECO VENDA: " << getPrecovenda() << endl;
    }

    void imprimirrelatoriofinal()
    {

        abrir_arquivo(0);

        lista << "| ID: " << getId();
        lista << "| NOME: " << getNome();
        lista << "| QUANTIDADE: " << getQuantidade();
        lista << "| PRECO CUSTO: " << getPrecocusto();
        lista << "| PRECO VENDA: " << getPrecovenda();
        lista << "| LUCRO:" << getLucro();
        lista << endl;

        fecha_arquivo();
    }
};

void preencher(long int v[])
{ // serial numbers pre- definidos dos funcionarios do sistema//
    v[0] = 202014842;
    v[1] = 211027222;
    v[2] = 211027474;
}

void ordenar(int a, Produtos products[])
{

    int i, pivot, parede, troca;

    parede = 0;
    pivot = a - 1;

    while (pivot != 0)
    {
        troca = 0;
        parede = 0;

        for (i = 0; i < a - 1; i++)
        {

            if ((products[pivot].nome[0] > products[i].nome[0]) && (pivot > i))
            {

                swap(products[i].nome, products[parede].nome);
                parede++;

                troca++;
            }
        }

        if (troca >= pivot)
        {
            pivot--;
            parede = 0;
        }

        if (troca < pivot)
        {

            swap(products[pivot].nome, products[parede].nome);

            parede = 0;
        }
    }
}

 void cadastrar_cliente(list <string> clientes)
{                                       //funcao para cadastrar 

    string cliente;

    cout << "Digite o nome do cliente a ser cadastrado: " << endl;
    cin >> cliente;

    clientes.push_back(cliente);
 }

int main()
{

    Produtos products[50];

    list <string> clientes;
    list <string> aux;

    int id, i;
    string usuario = "";
    string senha = "";
    int qde_registros;

    products[0].limpar_txt();

    long int v[3];

    int n, q, sentinela;
    bool achou; // busca sentinela para encontrar os funcionarios do sistema

    while (!achou)
    {

        preencher(v);

        achou = false;

        cout << "Insira o codigo do funcionario que deseja logar:\n";
        cin >> n;

        sentinela = n;
        v[5] = sentinela;

        for (q = 0; v[q] != sentinela; q++)
        {
        }

        if ((q != 5) && (v[q] == n))
        {
            achou = true;
        }

        if (achou == true)
        {
            cout << "CODIGO DE USUARIO NUMERO:  " << n << " BEM VINDO!\n\n";
        }
        if (achou == false)
        {
            cout << "CODIGO DE USUARIO :" << n << " NAO FOI ENCONTRADO NA BASE DE DADOS! DIGITE NOVAMENTE!\n\n";
        }
    }
    while (1)
    {

        system("CLS");
        // menu com cases//
        
        int opcao;
                                                                                            //MENU SWITCH CASE
        cout << "----------------------MENU!---------------------------" << endl;
        cout << "1 - Registrar Produto: " << endl;
        cout << "2 - Adicionar quantidade de produtos: " << endl;
        cout << "3 - Cadastrar cliente: " << endl;
        cout << "4 - Vender produtos: " << endl;
        cout << "5 - Imprimir Estoque: " << endl;
        cout << "6 - Imprimir Relatorio Final: " << endl;
        cout << "7 - Imprimir clientes: " <<endl;
        cout << "8 - Sair" << endl;

        cout << endl;
        cout << "Opcao: ";
        cin >> opcao;

        cout << endl
             << endl;

        switch (opcao)
        {

        case 1:
        {

            system("CLS");

            cout << "Quantos produtos voce deseja registrar? ";
            cin >> qde_registros;

            for (i = 0; i < qde_registros; i++)
            {                                                                   //case para registrar produtos

                products[i].registrar_produtos();
            }

            ordenar(i, products);

            break;
        }
        case 2:
        {
                                                                                // case para adicionar produtos
            system("CLS");
            cout << "Digite o id: ";
            cin >> id;

            products[id - 1].adicionar_produtos();

            break;
        }
        case 3:
        {
            system("CLS");
                string cliente;
                                                                                //cadastro de clientes
    cout << "Digite o nome do cliente a ser cadastrado: " << endl;
    cin >> cliente;

    clientes.push_back(cliente);

            break;
        }
        case 4:
        {
            system("CLS");                                                      //case para vender produtos
            cout << "Digite o ID do produto a ser vendido: " << endl;

            cin >> id;

            products[id - 1].vender_produtos();

            break;
        }

        case 5:
        {
                                                            //case para imprimir estoque
            system("CLS");
            cout << "(IMPRIMIR ESTOQUE)" << endl;
            cout << "ID - Nome - Preco de Venda - Preco de Custo - Quantidade " << endl;
            for (int k = 0; k < i; k++)
            {
                products[k].imprimirestoque();
            }
            getch();
            break;
        }
        case 6:
        {
                                                            //case para invocar o relatorio final
            system("CLS");
            cout << "(IMPRIMIR RELATORIO FINAL)" << endl;
            for (int j = 0; j < i; j++)
            {
                products[j].imprimirrelatoriofinal();
            }
            break;
        }
        case 7:
        {
            system("CLS");
            int x = 1;
            while(!clientes.empty()){
                                                                    //FUNCAO PARA IMPRIMIR OS CLIENTES
                cout << "Cliente " << x << ": ";                                       
                cout << clientes.front() << endl;
                aux.push_back(clientes.front());
                clientes.pop_front();
                x++;
            }

            while(!aux.empty()){

             clientes.push_back(aux.front());
             aux.pop_front();
              
            }

             getch();
            break;
        }
        case 8:
        {
            system("CLS");                                              //encerrar programa
            cout << "Encerrando programa! " << endl;
            exit(1);
            break;
        }
        }
    }
}
//end//
