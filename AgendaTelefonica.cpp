//Importando bibliotecas
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
using namespace std;

//Struct (Registro) para os dados existentes nos contatos
typedef struct
{
	string nome;
	string email;
	string telefone;
	string cel;
	string insta;
} Contatos;

//Declaracao de uma struct do registro de contatos
Contatos Pessoa;
fstream banco;

//Prototipos das funcoes utilizadas no programa
void abrir_arquivo(int escolha);
void fecha_arquivo();
void criar_contato(int *qnt);
int procurar(string nomeProcura);
void Pesquisar_contato();
void editar();
void excluir(int *qnt);
void limpar_buffer(void);
void limpar_tela(void);
void listar();
void pausar();

//funcao do tipo void que abre o arquivo banco, utilizado no programa, recebe como parametro um inteiro e
//verifica se o arquivo foi aberto, e caso n√£o, printa que n√£o foi possivel abrir o arquivo
void abrir_arquivo(int escolha)
{
	//caso escolha seja 0, abre o arquivo na ultima linha escrita e √© do tipo out
	if (escolha == 0)
	{
		banco.open("ProjetoBanco.txt", ios::out | ios::app);
		if (!banco.is_open())
		{
			cerr << "N„o foi possÌvel abrir o arquivo | OUT" << endl;
			pausar();
		}
	}
	//caso escolha seja 1, abre o arquivo na primeira linha e √© do tipo in
	else if (escolha == 1)
	{
		banco.open("ProjetoBanco.txt", ios::in);
		if (!banco.is_open())
		{
			cerr << "N„o foi possÌvel abrir o arquivo | IN" << endl;
			pausar();
		}
	}
	//caso escolha seja outro numero, abre o arquivo na primeira linha e √© do tipo out
	else
	{
		banco.open("ProjetoBanco.txt", ios::out);
		if (!banco.is_open())
		{
			cerr << "N„o foi possÌvel abrir o arquivo | OUT" << endl;
			pausar();
		}
	}
}
//funcao do tipo void que fecha o arquivo banco toda vez que e chamada
void fecha_arquivo()
{
	banco.close();
}

//Funcao do tipo void para pausar
void pausar()
{
	getch();
}

//Funcao do tipo void que limpa o armazenamento temporario de dados, otimizando o programa
//e evitando erros de buffer
void limpar_buffer(void)
{

	fflush(stdin);
}

//Funcao do tipo void para limpar a tela toda vez que uma opcao desejada eh selecionada
void limpar_tela(void)
{

	system("CLS");
}

void limpar_txt(void)
{
	banco.open("ProjetoBanco.txt", ios::out | ios::trunc);
	banco.close();
}

//Funcao do tipo void para criar um contato, pergunta ao usuario quantos contatos deseja adicionar e os seus dados,
//armazena na struct Pessoa e em seguida insere os dados dentro do arquivo banco
void criar_contato(int *qnt)
{
	int opMenu = 0;
	int N;

	do
	{
		limpar_tela();

		cout << "Quantos contatos deseja criar?" << endl;
		cin >> N;

		for (int i = 0; i < N; i++)

		{
			abrir_arquivo(0);
			cout << endl
				 << "NOVO CADASTRO " << *qnt + 1 << endl
				 << endl;

			cout << "Digite o nome: ";
			limpar_buffer();
			getline(cin, Pessoa.nome);

			cout << "Digite o email: ";
			limpar_buffer();
			getline(cin, Pessoa.email);

			cout << "Digite o telefone: ";
			limpar_buffer();
			getline(cin, Pessoa.telefone);

			cout << "Digite o celular: ";
			limpar_buffer();
			getline(cin, Pessoa.cel);

			cout << "Digite o instagram: ";
			limpar_buffer();
			getline(cin, Pessoa.insta);

			banco << Pessoa.nome << endl
				  << Pessoa.email << endl
				  << Pessoa.telefone << endl
				  << Pessoa.cel << endl
				  << Pessoa.insta << endl
				  << endl;

			fecha_arquivo();
			*qnt += 1;
		}

		cout << "\n\nDeseja efetuar outro cadastro? (1-Sim / 0-N„o): ";
		cin >> opMenu;

	} while (opMenu == 1);
}

//Funcao do tipo int que retorna a linha de um elemento que esta sendo procurado
//no arquivo banco, devolvendo -1 caso nao seja encontrado
int procurar(string Pessoanome)
{

	abrir_arquivo(1);

	string text;
	bool achou = false;
	int linha = 1;

	while (getline(banco, text))
	{
		if (Pessoanome != "")
		{
			int pos = text.find(Pessoanome);
			if (pos != string::npos && text.length() == Pessoanome.length())
			{
				achou = true;
				break;
			}
			else
			{
				linha++;
			}
		}
		else
		{
		}
	}
	fecha_arquivo();
	if (achou)
	{
		return linha;
	}
	else
	{
		return -1;
	}
}

//Funcao do tipo void para a edicao de contatos, mostra a opcao de editar ou voltar ao menu principal
void editar()
{
	int opMenu = 0;
	string nome;
	int pos;
	string elemento;

	do
	{
		limpar_tela();

		cout << "EDITAR CONTATOS" << endl
			 << endl;
		cout << "1-Editar" << endl;
		cout << "0-Voltar ao menu principal" << endl;
		cout << "OpÁ„o: ";
		cin >> opMenu;

		switch (opMenu)
		{
		//Caso a opcao de editar seja escolhida, lista os contatos ja cadastrados, pergunta o nome do contato que deseja editar
		//e procura o contato no aquivo, caso o nome seja encontrado da a opcao de editar todos os dados do contato
		case 1:

			listar();
			cout << "\nDigite o nome do contato que deseja editar: " << endl;
			limpar_buffer();
			getline(cin, nome);
			pos = procurar(nome);
			if (pos == -1)
			{
				cout << "Nome n„o encontrado!" << endl;
				pausar();
			}
			else
			{

				limpar_tela();
				cout << "Nome encontrado! Digite seus novos dados:" << endl
					 << endl;
				cout << "Digite o nome: ";
				limpar_buffer();
				getline(cin, Pessoa.nome);

				cout << "Digite o email: ";
				limpar_buffer();
				getline(cin, Pessoa.email);

				cout << "Digite o telefone: ";
				limpar_buffer();
				getline(cin, Pessoa.telefone);

				cout << "Digite o celular: ";
				limpar_buffer();
				getline(cin, Pessoa.cel);

				cout << "Digite o instagram: ";
				limpar_buffer();
				getline(cin, Pessoa.insta);

				int linha = 1;
				ofstream temp;
				string linhas[5];
				abrir_arquivo(1);
				//percorre todas as linhas do arquivo procurando os dados iguais ao do contato pesquisado
				//caso seja encontrado, armazena em um array os dados a serem editados
				while (getline(banco, elemento))
				{
					if (linha == pos)
					{
						linhas[0] = elemento;
					}
					else if (linha == pos + 1)
					{
						linhas[1] = elemento;
					}
					else if (linha == pos + 2)
					{
						linhas[2] = elemento;
					}
					else if (linha == pos + 3)
					{
						linhas[3] = elemento;
					}
					else if (linha == pos + 4)
					{
						linhas[4] = elemento;
					}

					linha++;
				}
				fecha_arquivo();

				abrir_arquivo(1);
				//Para a edicao dos contatos, foi criado um arquivo temporario que armazena os contatos, com os de edi√ß√£o ja editados,
				//em seguida apaga o antigo arquivo banco e renomeia o temporario para banco
				temp.open("temp.txt");
				while (getline(banco, elemento))
				{
					if (elemento == linhas[0])
					{
						elemento.replace(elemento.find(linhas[0]), linhas[0].length(), Pessoa.nome);
					}
					if (elemento == linhas[1])
					{
						elemento.replace(elemento.find(linhas[1]), linhas[1].length(), Pessoa.email);
					}
					if (elemento == linhas[2])
					{
						elemento.replace(elemento.find(linhas[2]), linhas[2].length(), Pessoa.telefone);
					}
					if (elemento == linhas[3])
					{
						elemento.replace(elemento.find(linhas[3]), linhas[3].length(), Pessoa.cel);
					}
					if (elemento == linhas[4])
					{
						elemento.replace(elemento.find(linhas[4]), linhas[4].length(), Pessoa.insta);
					}

					temp << elemento << endl;
				}
				temp.close();
				fecha_arquivo();

				remove("ProjetoBanco.txt");
				rename("temp.txt", "ProjetoBanco.txt");

				cout << endl
					 << "Contato editado!" << endl;
				pausar();
			}

			break;

		case 0:
			break;

		default:
			opMenu = 1;
			break;
		}

	} while (opMenu == 1);
}

//Funcao do tipo void para pesquisar um contato ja cadastrado, utilizando a funcao procurar(),
//que ira encontrar o contato escolhido entre os demais contatos do arquivo, caso seja encontrado, printa os seus dados
void Pesquisar_contato()
{
	int opMenu = 0, pos;
	string nome;

	do
	{
		limpar_tela();

		cout << "CONSULTA DE CONTATOS" << endl;
		cout << "Digite o nome do contato que deseja pesquisar: ";
		limpar_buffer();
		getline(cin, nome);
		pos = procurar(nome);

		if (pos == -1)
		{
			cout << "Nome n„o encontrado!" << endl;
		}
		else
		{
			limpar_tela();
			cout << "Nome encontrado! Seus dados s„o os seguintes:" << endl
				 << endl;
			cout << "________________________________________________________________" << endl
				 << endl;

			string text;
			int linha = 1;
			abrir_arquivo(1);
			while (getline(banco, text))
			{
				if (linha == pos)
				{
					for (int i = 0; i < 5; i++)
					{
						cout << text << endl;
						getline(banco, text);
					}
				}
				linha++;
			}
			fecha_arquivo();

			cout << "________________________________________________________________" << endl;
		}

		cout << endl
			 << "Pesquisar outro contato? (1-Sim / 0-N„o): ";
		cin >> opMenu;

	} while (opMenu == 1);
}

//Funcao do tipo void que percorre todas as linhas do arquivo
// para listar todos os dados dos contatos existentes no arquivo
void listar()
{
	abrir_arquivo(1);

	limpar_tela();

	string line;

	while (getline(banco, line))
	{
		cout << line << endl;
	}

	fecha_arquivo();
}

//Funcao do tipo void para excluir um contato, que pergunta o nome do contato da lista que deseja excluir,
//assim retirando seu valor do arquivo banco
void excluir(int *qnt)
{
	int opMenu = 0;
	string nome;
	string elemento;
	int pos;
	do
	{
		limpar_tela();

		cout << "EXCLUS√O DE CONTATOS" << endl
			 << endl;
		cout << "1 - Excluir um contato" << endl;
		cout << "0 - Voltar ao menu " << endl
			 << endl;
		cout << "Opcao: ";
		cin >> opMenu;

		switch (opMenu)
		{
		case 1:

			listar();
			cout << "Digite o nome do contato que deseja excluir: ";
			limpar_buffer();
			getline(cin, nome);
			pos = procurar(nome);
			if (pos == -1)
			{
				cout << "\nContato n„o encontrado!" << endl;
				pausar();
			}
			else
			{
				int linha = 1;
				ofstream temp;
				string linhas[6];
				abrir_arquivo(1);
				//Percorre todas as linhas do arquivo procurando os dados iguais ao do contato pesquisado
				//ao encontrar, armazena no array os dados a serem excluidos
				while (getline(banco, elemento))
				{
					if (linha == pos)
					{
						linhas[0] = elemento;
					}
					else if (linha == pos + 1)
					{
						linhas[1] = elemento;
					}
					else if (linha == pos + 2)
					{
						linhas[2] = elemento;
					}
					else if (linha == pos + 3)
					{
						linhas[3] = elemento;
					}
					else if (linha == pos + 4)
					{
						linhas[4] = elemento;
					}
					else if (linha == pos + 5)
					{
						linhas[5] = elemento;
					}
					linha++;
				}
				fecha_arquivo();
				int numlinhas = 1;
				abrir_arquivo(1);
				//Para excluir o contato do arquivo, cria-se um arquivo temporario, no qual so se insere os outros contatos
				//sem os dados do contato que se deseja excluir. Em seguida o arquivo antigo e deletado e o temporario
				//renomeado para banco
				temp.open("temp.txt");

				while (getline(banco, elemento))
				{
					if (elemento == linhas[0] || elemento == linhas[1] || elemento == linhas[2] || elemento == linhas[3] || elemento == linhas[4] || elemento == linhas[5])
					{
					}
					else
					{
						temp << elemento << endl;
					}
					if (numlinhas != linha - 7)
					{
						if (numlinhas % 6 == 0)
						{
							temp << endl;
						}
					}

					numlinhas++;
				}

				temp.close();
				fecha_arquivo();

				remove("ProjetoBanco.txt");
				rename("temp.txt", "ProjetoBanco.txt");
				*qnt -= 1;

				cout << "Contato excluÌdo! " << endl;

				pausar();
			}
			break;

		case 0:

			break;

		default:
			opMenu = 1;
			break;
		}

	} while (opMenu == 1);
}

int main()
{
	int opMenu = 0;
	int qnt = 0;

	limpar_txt();

	setlocale(LC_ALL, "");

	//Menu principal, mostra todas as opcoes do programa enquanto a opcao 6 (sair) nao for escolhida, para cada opcao, sua funcao e chamada
	do
	{
		limpar_tela();

		cout << "              Agenda de contatos             " << endl;
		cout << "----------------------------------------------" << endl;
		cout << "1- Criar contato" << endl;		//Criar contato
		cout << "2- Editar contato" << endl;	//Editar contato
		cout << "3- Pesquisar contato" << endl; //Pesquisar contato
		cout << "4- Listar contato" << endl;	//Listar contato
		cout << "5- Excluir contato" << endl;	//Apagar dados do contato
		cout << "6- Sair" << endl
			 << endl; //Sair
		cout << "OpÁ„o: ";
		cin >> opMenu;

		if (opMenu != 6)
		{
			switch (opMenu)
			{
			case 1:
				criar_contato(&qnt);
				break;

			case 2:
				editar();
				break;

			case 3:
				Pesquisar_contato();
				break;

			case 4:
				listar();
				pausar();
				break;

			case 5:
				excluir(&qnt);
				break;

			default:
				cout << "OpÁ„o inv·lida!" << endl;
				break;
			}
		}

	} while (opMenu != 6);

	cout << endl
		 << "Encerrando programa..." << endl;

	return 0;
}
