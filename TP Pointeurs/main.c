#include <stdlib.h>
#include <stdio.h>

int compte(const int* tab, int longueur_tab, int chiffre_a_compter) {
	int result = 0;
	for (int i = 0; i < longueur_tab; i++) {		
		if (chiffre_a_compter == tab[i]) {
			result++;
		}
	}
	return result;
}

void multi(const int* tab_in, int longueur_tab, int* tab_out, int multiplicateur) {
	for (int i = 0; i < longueur_tab; i++) {
		tab_out[i] = tab_in[i] * multiplicateur;
	}
}

void calcul(const int* tab_in, int longueur_tab, int* tab_out, int operation, int valeur) {
	for (int i = 0; i < longueur_tab; i++) {
		if (operation == 0) {
			tab_out[i] = tab_in[i] + valeur;
		}
		else if (operation == 1) {
			tab_out[i] = tab_in[i] - valeur;
		}
		else if (operation == 2) {
			tab_out[i] = tab_in[i] * valeur;
		}
		else if (operation == 3 && valeur != 0) {
			tab_out[i] = tab_in[i] / valeur;
		}
	}
}

int checkTab(const int* tab_func, const int* tab_test, int size) {
	for (int i = 0; i < size; i++) {
		if (tab_func[i] != tab_test[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int tab[] = { 1, 2, 3, 4, 1, 2, 3, 4, 5};
	const int size = sizeof(tab) / sizeof(int);

	if (compte(tab , size, 1) == 2) {
		printf("Compte ok\n");
	} else {
		printf("Compte KO\n");
	}

	int multiOut[9];
	int tabMult[] = { 2, 4, 6, 8, 2, 4, 6, 8, 10 };

	multi(tab, size, multiOut, 2);
	if (checkTab(multiOut, tabMult, size)) {
		printf("Multi ok\n");
	} else {
		printf("Multi KO\n");
	}

	// 0 = add, 1 = sous, 2 = mult, 3 = div 
	int tabAdd[] = { 3, 4, 5, 6, 3, 4, 5, 6, 7 };
	int tabSous[] = { -1, 0, 1, 2, -1, 0, 1, 2, 3 };
	int tabDiv[] = {0, 1, 1, 2, 0, 1, 1, 2, 2};
	int tabResult[] = { tabAdd, tabSous, tabMult, tabDiv };
	int calculOut[9];
	
	for (int i = 0; i < 4; i++) {
		calcul(tab, size, calculOut, i, 2);
		if (checkTab(calculOut, tabResult[i], size)) {
			printf("calcul ok\n");
		}
		else {
			printf("calcul KO\n");
		}
	}
	return 0;
}