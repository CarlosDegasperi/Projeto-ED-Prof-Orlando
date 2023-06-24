#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

	struct Candidato{
		int numero;
		string nome;
		Candidato *proximo;
	};
	struct Eleitor{
		int numero;
		string nome;
		Eleitor *proximo;
	};
	struct Voto{
		int titulo;
		string nome;
		Voto *proximo;
	};

void InserirCandidato(Candidato*& Lista, const std::string& nome, int numero);
void SalvarCandidato(const Candidato* candidato);
void CadastrarCandidato(Candidato* Lista);
void CarregarCandidato(Candidato*& Lista);
void ListarCandidato(const Candidato* Lista);
void SobrescreveArquivoCandidato(Candidato *&Lista);
void LiberarMemoriaCandidato(Candidato *&Lista);
void RemoverCandidato(Candidato *&Lista);

void InserirEleitor(Eleitor*& Lista, const std::string& nome, int numero);
void SalvarEleitor(const Eleitor* Eleitor);
void CadastrarEleitor(Eleitor* Lista);
void CarregarEleitor(Eleitor*& Lista);
void ListarEleitor(const Eleitor* Lista);
void SobrescreveArquivoEleitor(Eleitor *&Lista);
void LiberarMemoriaEleitor(Eleitor *&Lista);
void RemoverEleitor(Eleitor *&Lista);

int main() {
	setlocale (LC_ALL, "Portuguese");
	int op_main,op_can,op_ele;
	Candidato *ListaCandidato = NULL;
	Eleitor *ListaEleitor = NULL;
	Voto *ListaVoto = NULL;
	
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
					cout << "- CADASTRO DE CANDIDATOS: \n";
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
							// Inserir/Cadastrar Candidatos
							CadastrarCandidato(ListaCandidato);
							LiberarMemoriaCandidato(ListaCandidato);
								
							break;
						case 2:
							// Remover Candidatos
							RemoverCandidato(ListaCandidato);
							LiberarMemoriaCandidato(ListaCandidato);					
							break;
						case 3:
							// Listar Candidatos
							CarregarCandidato(ListaCandidato);
							ListarCandidato(ListaCandidato);
							LiberarMemoriaCandidato(ListaCandidato);
												
							break;
						case 4:
							// Voltar Menu Principal
							break;
						default:
							cout << "MSG: OPÇÃO INVALIDA!!! \n";
								
					}
										
				}while(op_can != 4);
					
				break;
			case 2:
				do{
					cout << "- CADASTRO DE ELEITORES: \n";
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
							// Inserir/Cadastrar Eleitores
							CadastrarEleitor(ListaEleitor);
							LiberarMemoriaEleitor(ListaEleitor);
								
							break;
						case 2:
							// Remover Eleitores
							RemoverEleitor(ListaEleitor);
							LiberarMemoriaEleitor(ListaEleitor);					
							break;
						case 3:
							// Listar Eleitores
							CarregarEleitor(ListaEleitor);
							ListarEleitor(ListaEleitor);
							LiberarMemoriaEleitor(ListaEleitor);
												
							break;
						case 4:
							// Voltar Menu Principal
							break;
						default:
							cout << "MSG: OPÇÃO INVALIDA!!! \n";
								
					}
								
				}while(op_ele != 4);
					
				break;				
				break;
			case 3:
				cout << "- REGISTRO DE VOTOS (ELEIÇÃO): \n";
				
				break;
			case 4:
				cout << "- RELATÓRIOS: \n";
	            				
				break;			
			case 5:
				break;
			default:
				cout << "MSG: OPCAO INVALIDA!!! \n";
				break;
		}
		
	} while(op_main != 5);
		
return 0;		
}
// Funçoes para Cadastro de Candidatos
void SalvarCandidato(const Candidato* candidato) {
 	//                12345678.TXT
    ofstream arquivo("CANDIDAT.TXT", ios::app);
    if (arquivo.is_open()) {
        arquivo << candidato->nome << "| " << candidato->numero << endl;
        arquivo.close();
        cout << "MSG: CANDIDATO SALVO COM SUCESSO!!!" << endl;
    } else {
        cout << "MSG: ERRO NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!!" << endl;
    }
}

void InserirCandidato(Candidato*& Lista, const std::string& nome, int numero) {
    Candidato* NovoCandidato = new Candidato;
    NovoCandidato->nome = nome;
    NovoCandidato->numero = numero;
    NovoCandidato->proximo = NULL;

    if (Lista == NULL) {
        Lista = NovoCandidato;
        SalvarCandidato(NovoCandidato);
    } else {
        Candidato* ultimo = Lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = NovoCandidato;
        SalvarCandidato(NovoCandidato);
    }
}

void CadastrarCandidato(Candidato* Lista){
	string nome;
	int numero;
	cout << "- INFORME O NOME DO CANDIDATO..: ";
	cin >> nome;
	cout << "- INFORME O NUMERO DO CANDIDATO: ";
	cin >> numero;
	InserirCandidato(Lista, nome, numero);
	 
}

void CarregarCandidato(Candidato*& Lista) {
    ifstream arquivo("CANDIDAT.TXT");
    if (arquivo.is_open()) {
        string nome;
        int numero;
        while (arquivo >> nome >> numero) {
            Candidato* NovoCandidato = new Candidato;
            NovoCandidato->nome = nome;
            NovoCandidato->numero = numero;
            NovoCandidato->proximo = NULL;

            if (Lista == NULL) {
                Lista = NovoCandidato;
            } else {
                Candidato* atual = Lista;
                while (atual->proximo != NULL) {
                    atual = atual->proximo;
                }
                atual->proximo = NovoCandidato;
            }
        }
        arquivo.close();
		cout << "MSG: LISTA DE CANDIDADOS FOI CARREGADA!!!" << endl;
    } else {
        cout << "MSG: LISTA DE CANDIDATOS NAO FOI CARREGADA!!!" << endl;
    }
}

void ListarCandidato(const Candidato* Lista) {
    if (Lista == NULL) {
        cout << "MSG: LISTA DE CANDIDATOS ESTÁ VAZIA!!!" << endl;
        return;
    }
    
    const Candidato* CandidatoAtual = Lista;
    while (CandidatoAtual != NULL) {
        cout << "NOME CANDIDATO: " << CandidatoAtual->nome << " NÚMERO: " << CandidatoAtual->numero << endl;
        CandidatoAtual = CandidatoAtual->proximo;
    }
}

void SobrescreveArquivoCandidato(Candidato *&Lista){
	 ofstream arquivo("CANDIDAT.TXT");
    if (arquivo.is_open()) {
        Candidato *atual = Lista;
        while (atual != NULL) {
//          arquivo << atual->nome << "| " << atual->numero << endl;
			arquivo << atual->nome << " "   << atual->numero << endl;
            atual = atual->proximo;
        }
        arquivo.close();
    } else {
        cout << "MSG: ERRO AO GRAVAR O ARQUIVO!!!" << endl;
    } 
}

void LiberarMemoriaCandidato(Candidato *&Lista){
	Candidato *CandidatoAtual = NULL;
	if(Lista == NULL){
		cout << "MSG: LISTA DE CANDIDATOS ESTÁ VAZIA!!!" << endl;
			
	}else{
		CandidatoAtual = Lista;
		while(CandidatoAtual != NULL){
			Candidato *prox = CandidatoAtual->proximo;
			delete CandidatoAtual;
			CandidatoAtual = prox;
		}
		Lista = NULL;
	}
}

void RemoverCandidato(Candidato *&Lista) {
    CarregarCandidato(Lista);

    if (Lista == NULL) {
        cout << "MSG: LISTA DE CANDIDATOS ESTÁ VAZIA!!!" << endl;
    } else {
    	ListarCandidato(Lista);
        int num = 0;
        cout << "- ATENCAO: INFORME O NÚMERO QUE DESEJA (EXCLUIR): ";
        cin >> num;

        Candidato *auxiliar = NULL;
        Candidato *atual = Lista;

        while (atual != NULL) {
            if (num == atual->numero) {
                if (auxiliar == NULL) {
                    Lista = atual->proximo;
                } else {
                    auxiliar->proximo = atual->proximo;
                }
                delete atual;
                cout << "MSG: O CANDIDATO INFORMADO FOI REMOVIDO!!!" << endl;
                break;
            } else {
                auxiliar = atual;
                atual = atual->proximo;
            }
        }
        SobrescreveArquivoCandidato(Lista);
    }

    LiberarMemoriaCandidato(Lista);
}

// Funçoes para Cadastro de Eleitors
void SalvarEleitor(const Eleitor* Eleitor) {
 	//                12345678.TXT
    ofstream arquivo("ELEITOR.TXT", ios::app);
    if (arquivo.is_open()) {
        arquivo << Eleitor->nome << "| " << Eleitor->numero << endl;
        arquivo.close();
        cout << "MSG: ELEITOR SALVO OM SUCESSO!!!" << endl;
    } else {
        cout << "MSG: ERRO NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!!" << endl;
    }
}

void InserirEleitor(Eleitor*& Lista, const std::string& nome, int numero) {
    Eleitor* NovoEleitor = new Eleitor;
    NovoEleitor->nome = nome;
    NovoEleitor->numero = numero;
    NovoEleitor->proximo = NULL;

    if (Lista == NULL) {
        Lista = NovoEleitor;
        SalvarEleitor(NovoEleitor);
    } else {
        Eleitor* ultimo = Lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = NovoEleitor;
        SalvarEleitor(NovoEleitor);
    }
}

void CadastrarEleitor(Eleitor* Lista){
	string nome;
	int numero;
	cout << "- INFORME O NOME DO Eleitor..: ";
	cin >> nome;
	cout << "- INFORME O NUMERO DO Eleitor: ";
	cin >> numero;
	InserirEleitor(Lista, nome, numero);
	 
}

void CarregarEleitor(Eleitor*& Lista) {
    ifstream arquivo("ELEITOR.TXT");
    if (arquivo.is_open()) {
        string nome;
        int numero;
        while (arquivo >> nome >> numero) {
            Eleitor* NovoEleitor = new Eleitor;
            NovoEleitor->nome = nome;
            NovoEleitor->numero = numero;
            NovoEleitor->proximo = NULL;

            if (Lista == NULL) {
                Lista = NovoEleitor;
            } else {
                Eleitor* atual = Lista;
                while (atual->proximo != NULL) {
                    atual = atual->proximo;
                }
                atual->proximo = NovoEleitor;
            }
        }
        arquivo.close();
		cout << "MSG: LISTA DE ELEITOR FOI CARREGADA!!!" << endl;
    } else {
        cout << "MSG: LISTA DE ELEITOR NAO FOI CARREGADA!!!" << endl;
    }
}

void ListarEleitor(const Eleitor* Lista) {
    if (Lista == NULL) {
        cout << "MSG: LISTA DE ELEITOR ESTÁ VAZIA!!!" << endl;
        return;
    }
    
    const Eleitor* EleitorAtual = Lista;
    while (EleitorAtual != NULL) {
        cout << "NOME ELEITOR: " << EleitorAtual->nome << " NÚMERO: " << EleitorAtual->numero << endl;
        EleitorAtual = EleitorAtual->proximo;
    }
}

void SobrescreveArquivoEleitor(Eleitor *&Lista){
	 ofstream arquivo("ELEITOR.TXT");
    if (arquivo.is_open()) {
        Eleitor *atual = Lista;
        while (atual != NULL) {
//          arquivo << atual->nome << "| " << atual->numero << endl;
			arquivo << atual->nome << " "  << atual->numero << endl;
            atual = atual->proximo;
        }
        arquivo.close();
    } else {
        cout << "MSG: ERRO AO GRAVAR O ARQUIVO!!!" << endl;
    }
}

void LiberarMemoriaEleitor(Eleitor *&Lista){
	Eleitor *EleitorAtual = NULL;
	if(Lista == NULL){
		cout << "MSG: LISTA DE ELEITOR ESTÁ VAZIA!!!" << endl;
			
	}else{
		EleitorAtual = Lista;
		while(EleitorAtual != NULL){
			Eleitor *prox = EleitorAtual->proximo;
			delete EleitorAtual;
			EleitorAtual = prox;
		}
		Lista = NULL;
	}
}

void RemoverEleitor(Eleitor *&Lista) {
    CarregarEleitor(Lista);

    if (Lista == NULL) {
        cout << "MSG: LISTA DE ELEITOR ESTÁ VAZIA!!!" << endl;
    } else {
    	ListarEleitor(Lista);
        int num = 0;
        cout << "- ATENCAO: INFORME O NÚMERO QUE DESEJA (EXCLUIR): ";
        cin >> num;

        Eleitor *auxiliar = NULL;
        Eleitor *atual = Lista;

        while (atual != NULL) {
            if (num == atual->numero) {
                if (auxiliar == NULL) {
                    Lista = atual->proximo;
                } else {
                    auxiliar->proximo = atual->proximo;
                }
                delete atual;
                cout << "MSG: O ELEITOR INFORMADO FOI REMOVIDO!!!" << endl;
                break;
            } else {
                auxiliar = atual;
                atual = atual->proximo;
            }
        }
        SobrescreveArquivoEleitor(Lista);
    }

    LiberarMemoriaEleitor(Lista);
}

