#include <iostream>
using namespace std;

void bubbleSort(string vetor[], int tamanhoVetor){
	for(int i = 0; i < tamanhoVetor; i++){
		for(int j = 0; j < tamanhoVetor - (i + 1); j++){
			if(vetor[j]>vetor[j+1]){
				string aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

void insertionSort(string vetor[], int tamanhoVetor){
	for(int i = 1; i < tamanhoVetor; i++){
		string aux = vetor[i];
		int indexMenor = i-1;
		while(indexMenor >= 0 && aux<vetor[indexMenor]){
			vetor[indexMenor + 1] = vetor[indexMenor];
			indexMenor --;
		}
		vetor[indexMenor + 1] = aux;
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

void selectionSort(string vetor[], int tamanhoVetor){
	for(int i = 0; i < tamanhoVetor; i++){
		string menor = vetor[i];
		int indexMenor = i;
		for(int j = i + 1; j < tamanhoVetor; j++){
			if(vetor[j] < menor){
				indexMenor = j;
				menor = vetor[j];
			} 
		}
		vetor[indexMenor] = vetor[i];
		vetor[i] = menor;
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

void merge(string vetor[], int inicio, int meio, int final){
	int tam1 = meio + 1 - inicio;
	int tam2 = final - meio;
	string esquerda[tam1];
	string direita[tam2];
	
	for(int i = 0; i<tam1; i++){
		esquerda[i] = vetor[inicio + i];
	}
	for(int j = 0; j<tam2; j++){
		direita[j] = vetor[meio + 1 + j];
	}
	
	int i = 0;
	int j = 0;
	int k = inicio;
	while(i < tam1 && j < tam2){
		if(esquerda[i]<=direita[j]){
			vetor[k] = esquerda[i];
			i++;
		}else{
			vetor[k] = direita[j];
			j++;
		}
		k++;
	}
	while(i < tam1){
		vetor[k] = esquerda[i];
		i++;
		k++;
	}
	while(j < tam2){
		vetor[k] = direita[j];
		j++;
		k++;
	}
}
void mergeSort(string vetor[], int inicio, int final){
	if(inicio < final){
		int meio = (inicio + final)/2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, final);
		merge(vetor, inicio, meio, final);
	}
}

void quickSort(int vetor[], int inicio, int final){
	if(inicio < final){
		int meio = (inicio + final)/2;
		int pivo = vetor[meio];
		int i = inicio;
		int j = final;
		while(i<j){
			while(vetor[i]<=pivo){
				i++;
			}
			while(vetor[j]>pivo){
				j--;
			}
			if(i < j){
				int aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		vetor[meio] = vetor[j];
		vetor[j] = pivo;
		quickSort(vetor, inicio, j-1);
		quickSort(vetor, j+1, final);
	}
}

void qum(){
	int n;
	cout << "Quantos nomes deseja inserir?";
	cin >> n;
	string nomes[n];
	for(int i = 0; i < n; i++){
		cout << "Digite um nome: ";
		cin >> nomes[i];
	}
	insertionSort(nomes, n);
}

void qdois(){
	string palavra;
	cout << "Digite uma palavra: ";
	cin >> palavra;
	string letras[palavra.length()];
	for(int i=0; i<palavra.length();i++){
		letras[i] = palavra[i];
	}
	insertionSort(letras, palavra.length());
}

void qtres(){
	int n;
	cout << "Quantos nomes deseja inserir?";
	cin >> n;
	string nomes[n];
	for(int i = 0; i < n; i++){
		cout << "Digite um nome: ";
		cin >> nomes[i];
	}
	selectionSort(nomes, n);
}

void qquatro(){
	string palavra;
	cout << "Digite uma palavra: ";
	cin >> palavra;
	string letras[palavra.length()];
	for(int i=0; i<palavra.length();i++){
		letras[i] = palavra[i];
	}
	mergeSort(letras, 0, palavra.length()-1);
	for(int i = 0; i < palavra.length(); i++){
	cout << letras[i] << ", ";
	}
}

void qcinco(){
	int vetor[30] = {12, 3, 45, 7, 4, 12, 0, 4, 6, 3, 3, 4, 6, 4, 87,
	 4, 3, 3, 5, 3, 12, 43, 54, 56, 76, 54, 45, 23, 6, 100};
	quickSort(vetor, 0, 29);
	for(int i = 0; i < 30; i++){
	cout << vetor[i] << ", ";
	}
}

void qseis(){
	cout << "Letra C, 6 comparacoes e 6 trocas.";
}

void qsete(){
	cout << "Letra A, selecao - SelectionSort.";
}

void qoito(){
	cout << "No BubbleSort, o algoritmo percorre um vetor comparado um elemento com seu sucessor, "; 
	cout << "dois a dois, \ne trocando caso o elemento sucessor seja menor.";
	cout << "\nCada vez que algoritmo passa, um elemento eh ordenado no final." << endl;
		
	cout << "\nNo InsertionSort, o algoritmo comeca a ordenar a partir da esquerda,";
	cout << "\n considerando que o primeiro elemento ja esta ordenado, em seguida percorre";
	cout << "\n os outros e vai comparando com os que estão na esquerda(ordenados), e desloca-os um indice para a direita se forem maiores";
	cout << "\n ate que ache sua posicao. No final todos estarao ordenados." << endl;
	
	cout << "\nNo caso do SelectionSort, o algoritmo procura o menor elemento e troca com o primeiro, em seguida ";
	cout << "\n procura o segudo menor e troca com a segunda posicao, e assim sucessivamente ate todos estarem ordenados." << endl;
	
	cout << "\n No MergeSort o algoritmo divide o vetor repetidamente ate que fique de tamamho um, em seguida vai juntando as partes novamente";
	cout << "\n obedecendo a ordem. Dessa forma todos ficarao ordenados. Para isso utiliza-se a estrategia dividir para conquistar por meio da recursividade." << endl;
	
	cout << "\nDa mesma forma o QuickSort tambem faz uso da recursividade realizando um processo de determinar um numero chamado pivo.";
	cout << "\nEm seguida o algoritmo percorre o vetor a partir da esquerda, parando assim que identificar um numero maior que o pivo, depois ele percorre pela direita";
	cout << "\n procurando um numero menor que o pivo, ao achar troca de lugar o menor e o maior. Esse processo se repete ate que o indice da esquerda ultrapassa o da direita";
	cout << "\n entao o pivo o indice da direita trocam de posicao, e o pivo estara ordenado. Em seguida, o vetor e dividido em dois usando como base o pivo.";
	cout << "\n Atraves da recursividade esse algoritmo e reaplicado nas partes do vetor sucessivamente, ate todos estarem nas suas posicoes corretas.";
}

int main() {
	qquatro();
	return 0;
}
