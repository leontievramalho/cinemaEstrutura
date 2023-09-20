#include <iostream>
using namespace std;

void exibirCadeiras(int matriz[10][10][2]){
	cout << "Cadeiras Disponiveis: " << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 1; j < 11; j++){
			if(matriz[i][j][1] != 0){
				cout <<"(Cadeira "<< matriz[i][j][0] << ", fileira " << i+1 << ", coluna "<< j << " ), "<< endl;
			}
		}
	}
	cout << "Cadeiras Ocupadas: " << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 1; j < 11; j++){
			if(matriz[i][j][1] == 0){
				cout <<"(Cadeira "<< matriz[i][j][0] << ", fileira " << i+1 << ", coluna "<< j << " ), "<< endl;
			}
		}
	}
}

void venda(int matriz[10][10][2], int numero){
	if(numero < 1 || numero >100){
		cout << "Venda impossivel, o assento deve ser um numero de 1 a 100";
	} else{	
		int i = numero/10;
		int j = numero%10;
		if(matriz[i][j][1] != 0){
			matriz[i][j][1] = 0;
			cout << "Venda concluida com sucesso. (Cadeira "<< matriz[i][j][0] << ", fileira " << i+1 << ", coluna "<< j << " ), "<< endl;
		} else {
			cout << "Venda impossivel, o lugar ja esta ocupado. Veja os assentos disponiveis: ";
			exibirCadeiras(matriz);
		}
	}
}

int main() {
	//Criando a sala
	int cadeiras[10][10][2];
	for(int k = 0; k<2; k++){
		for(int i = 0; i < 10; i++){
			for(int j = 1; j < 11; j++){
				cadeiras[i][j][k] = 10*i + j;
			}
		}
	}
	//Preco
	float preco = 12.5;
	//Exibindo Disponiveis
	exibirCadeiras(cadeiras);
	
	//Vendendo
	int poltrona;
	while(true){
		cout << "Qual poltrona deseja comprar? 0 para parar ";
		cin >> poltrona;
		if(poltrona == 0){
			break;
		}
		venda(cadeiras,poltrona);
		exibirCadeiras(cadeiras);
	}
	//Quantidade de vendas e lucro
	int quantidadeVendas = 0;
	for(int i = 0; i < 10; i++){
			for(int j = 1; j < 11; j++){
				if(cadeiras[i][j][1] == 0){
					quantidadeVendas ++;
				};
			}
		}
	float lucro = quantidadeVendas*preco;
	cout << "Vendas realizadas: " << quantidadeVendas << endl;
	cout << "Lucro obtido: RS " << lucro << endl;
	return 0;
}
