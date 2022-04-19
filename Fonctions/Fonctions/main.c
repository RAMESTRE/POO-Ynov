#include <stdlib.h>
#include <stdio.h>
#define RECT 1
#define CERCLE 2
#define CARRE 3
#define PERIMETRE 1
#define AIRE 2

float aireRectangle(float longueur, float largeur) {
	return longueur * largeur;
}

float aireCercle(float rayon) {
	return 3.14 * rayon * rayon;
}

float perimetreRectangle(float longueur, float largeur) {
	return 2 * (longueur + largeur);
}

float perimetreCercle(float rayon) {
	return 2 * 3.14 * rayon;
}

float menu(int numberMenu, int menuCalcul) {
	if (numberMenu == CARRE) {
		float cote;
		printf("Choisissez vos dimension (cote): ");
		scanf_s("%f", &cote);
		if (menuCalcul == 1) {
			return perimetreRectangle(cote, cote);
		}
		return aireRectangle(cote, cote);
	}
	else if (numberMenu == RECT) {
		float longueur, largeur;
		printf("Choisissez vos dimension (longueur, largeur): ");
		scanf_s("%f%f", &longueur, &largeur);
		if (menuCalcul == 1) {
			return perimetreRectangle(longueur, largeur);
		}
		return aireRectangle(longueur, largeur);
	}
	float rayon;
	printf("Choisissez vos dimension (rayon): ");
	scanf_s("%f", &rayon);
	if (menuCalcul == 1) {
		return perimetreCercle(rayon);
	}
	return aireCercle(rayon);
}

float choixFigure() {
	int numberMenu;
	int menuCalcul;
	do {
		printf("Choisissez la figure que vous voulez utiliser.\n 1-Rectangle\n 2-Cercle \n 3-Carre\n Entrez votre choix: ");
		scanf_s("%d", &numberMenu);
		if (numberMenu < 1 || numberMenu > 3) {
			continue;
		}
		printf("Choisissez le calcul a effectuer.\n 1-Perimetre\n 2-Aire\n Entrez votre choix: ");
		scanf_s("%d", &menuCalcul);
		break;
	} while (1);
	float result;
	result = menu(numberMenu, menuCalcul);
	return result;
}

int main() {
	printf("Le resultat est %f", choixFigure());
	return 0;
}