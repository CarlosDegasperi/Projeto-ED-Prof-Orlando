#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale (LC_ALL, "Portuguese");
	int op;
	int soma =0;
	int i=0;
	string pais[10];
	int pontos[10]={0,0,0,0,0,0,0,0,0,0};
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
		cout << "Escolha a opcao: ";
		cin >> op;
		
		switch(op){
			case 1:
				for(int i=0; i < 10; i++){
				
				   if (i <10){
				     	cout << "-Cadastro de Candidatos \n";
					    cout << "Pais: " << i << "\n";
					    cout << "Informe Nome Pais: \n";
					    cin >> pais[i];
					    
					}else{
					    cout << "Maximo de Paises é 10!!! \n";
				}
			    }  

				break;
			case 2:
				cout << "-Cadastro de Eleitores \n";
				cout << "OBS: Informe o Numero do pais que ganhou o 9 para empate";
				int matriz[10][3];
				for(int linha=0; linha < 10; linha++){
				
						cout << "Pais: " << linha <<"=" << pais[linha+0] << " X "<< linha+1 << "=" << pais[linha+1] << "\n";
						cout << "Informe Resultado: \n";
						matriz[linha][0]=linha;
						matriz[linha][1]=linha+1;
						cin >> matriz[linha][2];
						linha++;
											
				}

				break;
			case 3:
				cout << "-Registro dos Votos \n";
				
				for(int linha=0; linha < 10; linha++){
					if (matriz[linha][2] == 9){
					   pontos[linha+0]=pontos[linha+0]+1;
					   pontos[linha+1]=pontos[linha+1]+1;
					}else {
					   pontos[matriz[linha][2]]=pontos[matriz[linha][2]]+3;
					}
					linha++;
				}	
				for(int linha=0; linha < 10; linha++){
					cout << pais[linha] << " = " << pontos[linha]<< "\n";
					
				}

				break;
			case 4:
				cout << "-Relatórios \n";
	            for(int linha=0; linha < 10; linha++){
					cout << pais[linha] << " = " << pontos[linha]<< "\n";
					
				}				
							
			case 5:
				break;
			default:
				cout << "OPCAO INVALIDA!!! \n";
				break;
		}
		
	
	} while(op != 5);
		
return 0;		
}
