
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); 
	}
}

void inicializar()
{

	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo == NULL) {
		cout << "Houve um erro na alocacao de memoria do elemento";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	NO* anterior = NULL;
	NO * atual = primeiro;

	NO* posicao = posicaoElemento(novo->valor);

	if (posicao == NULL) {

		while (atual != NULL && atual->valor < novo->valor) {
			anterior = atual;
			atual = atual->prox;
		}
		if (anterior == NULL) {
			novo->prox = primeiro;
			primeiro = novo;
		}
		else {
			anterior->prox = novo;
			novo->prox = atual;
		}
		cout << "Elemento " << novo->valor << " adicionada a lista" << endl;
	}
	else {
		cout << "Esse elemento ja esta na lista." << endl;
	}

	

}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		int excluir;
		cout << "Insira o elemento a ser excluido: ";
		cin >> excluir;

		NO* posicao = posicaoElemento(excluir);

		if (posicao != NULL) { 

			if (posicao == primeiro) { //verifica o primeiro
				primeiro = posicao->prox;
			}

			else {
				NO* aux = primeiro;
				while (aux->prox != posicao) {
					aux = aux->prox;
				}
				aux->prox = posicao->prox;
			}
			free(posicao);
			cout << "Elemento excluido" << endl;
		}

		else {
			cout << "Este elemento nao esta na lista \n";
		}
	}
}

void buscarElemento()

{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		int busca;
		cout << "Insira o elemento a ser buscado: ";
		cin >> busca;

		NO* posicao = posicaoElemento(busca);

		if (posicao != NULL) {
			cout << "Elemento " << posicao->valor << " encontrado na posicao " << posicao << endl;
		}
		else {
			cout << "O elemento nao existe na lista" << endl;
		}
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
