#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void menu(){
	printf("1-Inserir valores no vetor 1\n");
	printf("2-Inserir valores no vetor 2\n");
	printf("3-Inserir valores no vetor 3\n");
	printf("4-Imprimir vetor 1\n");
	printf("5-Imprimir vetor 2\n");
	printf("6-Imprimir vetor 3\n");
	printf("7-Busca sequencial no vetor 1\n");
	printf("8-Ordenação por trocas no vetor 1\n");
	printf("9-Ordenação por seleção no vetor 2\n");
	printf("10-Ordenação por inserção no vetor 3\n");
	printf("11-Busca binária no vetor 3\n");
	printf("12-Sair\n");
}

int buscaSequencial(int *v, int tamanho, int numero){
	int i=0;
	while (i<tamanho){
		if (v[i] == numero) return i+1;
		i++;
	}
	return 0;
}

void bubbleSort(int v[], int tamanho){
	int aux, fase, i;
	for(fase=0;fase<tamanho;fase++){
		for(i=0;i<tamanho-fase;i++){
			if(v[i]>v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
			}
		}
	}
}

void selection_sort(int num[], int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void insertionSort(int *v, int tamanho){
	int i,j,atual;
	for(i=1;i<tamanho;i++){
		atual=v[i];
		for (j=i-1; j>=0 && atual<v[j]; j--){
			v[j+1]=v[j];
		}
		v[j+1]=atual;
	}
}


int buscaBinaria(int v[], int tamanho, int numero){
	int inicio=0, fim=tamanho-1, meio, i;

	//printf("É necessário que os elementos estejam ordenados antes desta função ser chamada.");

	for(i=0;i<tamanho;i++){
		meio=(inicio+fim)/2;
		if(numero==v[meio]) return meio+1;
		else if(numero>v[meio]) inicio=meio+1;
		else fim=meio-1;
	}

	return (-1);
}

void imprimir(int *v, int tamanho){
	int i;

	for(i=0; i<tamanho; i++){
		printf("%d  ", v[i]);
	}

}



int main(){
	setlocale(LC_ALL, "portuguese");

	int tamanho, x=1, op;

	printf("Tamanho dos vetores: ");
	scanf("%d", &tamanho);

	system("color 3f");

	int v1[tamanho], v2[tamanho], v3[tamanho], i, numero, busca;

	while(x==1){
		menu();
		scanf("%d", &op);

		switch(op){
			case 1:

				for(i=0; i<tamanho; i++){
                    v1[i]=rand();
					/*system("cls");
					printf("%dº elemento do vetor", i+1);
					scanf("%d", &v1[i]);*/
				}

				printf("Pronto!");
				system("pause");
				system("cls");
				break;

			case 2:


				for(i=0; i<tamanho; i++){
                    v2[i]=rand();
					/*system("cls");
					printf("%dº elemento do vetor", i+1);
					scanf("%d", &v2[i]);*/
				}

				printf("Pronto!");
				system("pause");
				system("cls");
				break;

			case 3:


				for(i=0; i<tamanho; i++){
					v3[i]=rand();
					/*system("cls");
					printf("%dº elemento do vetor", i+1);
					scanf("%d", &v3[i]);*/
				}

				printf("Pronto!");
				system("pause");
				system("cls");
				break;

			case 4:
				imprimir(v1, tamanho);
				system("pause");
				system("cls");
				break;

			case 5:
				imprimir(v2, tamanho);
				system("pause");
				system("cls");
				break;

			case 6:
				imprimir(v3, tamanho);
				system("pause");
				system("cls");
				break;

			case 7:

				printf("Digite um número:");
				scanf("%d", &numero);

				busca=buscaSequencial(v1, tamanho, numero);

				if(busca != 0){
					printf("Número %d encontrado na %dª posição do vetor.\n", numero, busca);
				}else printf("O número não existe no vetor.\n");

				system("pause");
				system("cls");
				break;

			case 8:
				bubbleSort(v1, tamanho);
				printf("Pronto!\n");
				system("pause");
				system("cls");
				break;

			case 9:
				selection_sort(v2, tamanho);
				printf("Pronto!\n");
				system("pause");
				system("cls");
				break;

			case 10:
				insertionSort(v3, tamanho);
				printf("Pronto!\n");
				system("pause");
				system("cls");
				break;

			case 11:
				printf("Digite um número\n");
				scanf("%d", &numero);

				busca=buscaBinaria(v3, tamanho, numero);

				if(busca != -1){
					printf("Número %d encontrado na %dª posição do vetor.\n", numero, busca);
				}else printf("O número não existe no vetor.\n");

				system("pause");
				system("cls");
				break;

			case 12: exit(0);

			default:
				printf("Digite uma opção válida.");
				Sleep(1500);
				system("cls");
				break;
		}
	}
}
