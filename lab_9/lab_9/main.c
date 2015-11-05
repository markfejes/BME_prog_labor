#include <stdlib.h>
#include <stdio.h>

typedef struct Lista {
	int adat;
	struct Lista *kov;
} Lista;

void deleteList(Lista* listToDelete); 
Lista* lista_elejere_beszur(Lista* eleje, int insert);
void printList(Lista* listToPrint);
Lista* lista_vegere_beszur(Lista* eleje, int insert);
Lista* searchInList(Lista* searchList, int searchFor);

/* létrehoz egy listát, benne egy csomó számmal */
Lista *lista_letrehoz(void) {
	int szamok[] = { 7, 8, -1 };
	Lista *l = NULL;
	int i;

	for (i = 0; szamok[i] != -1; ++i) {
		Lista *u = (Lista*)malloc(sizeof(Lista));
		u->kov = l;
		u->adat = szamok[i];
		l = u;
	}
	return l;
}

int listLenght ( Lista* listToWorkOn){
	Lista *mozgo;
	int lenght = 0;

	Lista *eleje = listToWorkOn;

	for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
		lenght++;
	}
	return lenght;
}

int main(void) {
	Lista *eleje = lista_letrehoz();

	printList(eleje);
	printf("\n%d \n", listLenght(eleje));

	eleje = lista_vegere_beszur (eleje, 12);
	eleje = lista_elejere_beszur(eleje, 41);
	printList(eleje);

	printf("\n%d\n", searchInList(eleje, 411));
	deleteList(eleje);
	return 0;  
}

void deleteList(Lista* listToDelete){
	Lista* mozgo;
	Lista* tempNext;
	Lista* eleje = listToDelete;
	tempNext = eleje->kov;
	for (mozgo = eleje; mozgo->kov != NULL; mozgo = tempNext) {
		Lista* tempNext = mozgo->kov;
		free(mozgo);
	}
}
Lista* lista_elejere_beszur(Lista* eleje, int insert){
	Lista *u = (Lista*) malloc(sizeof(Lista));
	u->kov = eleje;
	u->adat = insert;
	return u;
}

Lista* lista_vegere_beszur(Lista* lista1, int insert){
	Lista *mozgo;
	Lista* eleje = lista1;
	Lista *u = (Lista*) malloc(sizeof(Lista));
	u->kov = NULL;
	u->adat = insert;

	if (lista1 == NULL)     /* empty list? */
		return u;

	for (mozgo = eleje; mozgo->kov != NULL; mozgo = mozgo->kov);
	mozgo->kov = u;
	return eleje;
}

void printList(Lista* listToPrint){
	Lista *mozgo;
	Lista *eleje = listToPrint;
	for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
		printf("%d ", mozgo->adat);
	}
}

Lista* searchInList(Lista* searchList, int searchFor){
	Lista *mozgo;
	Lista *eleje = searchList;
	for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
		if (mozgo->adat == searchFor)
			return mozgo;
	}

	return NULL;
}