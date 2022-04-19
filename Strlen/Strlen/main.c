#include <stdlib.h>
#include <stdio.h>

int strlen(const char* tab) {
	int i = 0;
	int result = 0;
	while (tab[i] != 0) {
		i++;
		result++;
	}
	return result;
}


int main(int argc, char* argv[]) {
	char chaine[] = "Salut";
	if (strlen(chaine) == 5) {
		printf("strlen ok\n");
	}
	else {
		printf("not ok");
	}
}