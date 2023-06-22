#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

	struct Candidato{
		int numero_can;
		string nome_can;
		Candidato* proximo;
	};
	struct Eleitor{
		int numero_ele;
		string nome_ele;
		Eleitor* proximo;
	};
	struct Fila{
		Eleitor *inicio, *fim;
		int total;
		Fila* proximo;
	};
	
	void InserirCandidatos(int numero_can,string nome_can);
	void RemoverCandidatos(int numero_can);
	void ListarCandidatos();
	
	void InserirEleitores(int numero_ele,string nome_ele);
	void RemoverEleitores(int numero_ele);
	void ListarEleitores();

int main() {
	setlocale (LC_ALL, "Portuguese");
	int op_main,op_can,op_ele;
	
	system("CLS");
	do {
		cout << "- A FESTA DA DEMOCRACIA!!! \n";
		cout << "- E L E I Ç Õ E S: \n";
		cout << "+============== M E N U ==============+ \n";
		cout << "| (1) - Cadastro de Candidatos        | \n";
		cout << "| (2) - Cadastro de Eleitores         | \n";
		cout << "| (3) - Registro dos Votos            | \n";
		cout << "| (4) - Relatórios                    | \n";
		cout << "| (5) - Sair                          | \n";	
		cout << "|=====================================| \n";
		cout << "Escolha a opção ou (5) Sair ";
		cin >> op_main;
		
		switch(op_main){
			case 1:
				do{
					cout << "-Cadastro de Candidatos \n";
					cout << "+==================================+ \n";		
					cout << "| (1) Inserir Candidatos           | \n";
					cout << "| (2) Remover Candidatos           | \n";				
					cout << "| (3) Listar  Candidatos           | \n";
					cout << "| (4) Voltar                       | \n";
					cout << "|==================================| \n";
					cout << "Escolha a opção ou (4) Voltar ";
					cin >> op_can;
					switch(op_can){
						case 1:
							// InserirCandidatos();
					
							break;
						case 2:
							// RemoverCandidatos();
					
							break;
						case 3:
							// ListarCandidatos();
					
							break;
						case 4:
					
							break;
						default:
							cout << "OPÇÃO INVALIDA!!! \n";
								
					}
				}while(op_can != 4);
					
				break;
			case 2:
				do{
					cout << "-Cadastro de Eleitores \n";
					cout << "+==================================+ \n";		
					cout << "| (1) Inserir Eleitores            | \n";
					cout << "| (2) Remover Eleitores            | \n";				
					cout << "| (3) Listar  Eleitores            | \n";
					cout << "| (4) Voltar                       | \n";
					cout << "|==================================| \n";
					cout << "Escolha a opção ou (4) Voltar ";
					cin >> op_ele;
					switch(op_ele){
						case 1:
							// InserirEleitores();
					
							break;
						case 2:
							// RemoverEleitores();
					
							break;
						case 3:
							// ListarEleitores();
					
							break;
						case 4:
					
							break;
						default:
							cout << "OPÇÃO INVALIDA!!! \n";
								
					}
				}while(op_ele != 4);
					
				break;				
				break;
			case 3:
				cout << "-Registro dos Votos \n";
				
				break;
			case 4:
				cout << "-Relatórios \n";
	            				
				break;			
			case 5:
				break;
			default:
				cout << "OPCAO INVALIDA!!! \n";
				break;
		}
		
	} while(op_main != 5);
		
return 0;		
}
