
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

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

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));


	if (novo == NULL)
	{
		cout << "Houve um erro na alocacao de memoria do elemento";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* posicao = posicaoElemento(novo->valor);

	if (posicao == NULL) {
		if (primeiro == NULL)
		{
			primeiro = novo;
			ultimo = novo;
		}
		else
		{
			ultimo->prox = novo;
			ultimo = novo;
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
		cout << "A lista esta vazia" << endl;
	}
	else {
		int excluir;
		cout << "Digite o elemento a ser buscado: ";
		cin >> excluir;

		NO* delElemento = posicaoElemento(excluir);

		if (delElemento == NULL) {
			cout << "O elemento nao esta na lista";
		}
		else {
			if (delElemento == primeiro) {
				primeiro = delElemento->prox;

			}
			else {
				NO* aux = primeiro;
				while (aux->prox != delElemento) {
					aux = aux->prox;
				}
				aux->prox = delElemento->prox;
			}
			cout << "O elemento foi excluido" << endl;
		}
		free(delElemento);

		
	}

}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "A lista esta vazia" << endl;
	}
	else {
		int buscar;
		cout << "Digite o elemento a ser buscado: ";
		cin >> buscar;
		NO* localizar = posicaoElemento(buscar);

		if (localizar == NULL) {
			cout << "O elemento nao esta na lista" << endl;
		}
		else {
			cout << "O elemento " << localizar->valor << " esta na lista na posicao " << localizar << endl;
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
