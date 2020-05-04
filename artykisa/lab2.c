#include <stdio.h> 
#include <stdlib.h> 
#include<math.h> 
int plzast(int okon, int plok, int balc, int plbalc) {
	return plok * okon + plbalc * balc;
}
int stzato(int okon, int cenaok, int nacenka) {
	return okon * cenaok*nacenka;
}
int stustdveri(int balc, int cenabalc, int nacenka) {
	return balc * cenabalc*nacenka;
}
int obshayastoimost(int okon, int cenaok, int balc, int cenabalc, int nacenka) {
	return ((okon*cenaok) + (balc*cenabalc))*nacenka;
}
int main() 
{ 
int proverka;
float okon, balc, etash; 
float cenaok=100, cenabalc=150; 
double plok = 2.15*1.5, plbalc = 0.7*2.15; 
while (true) {
		printf("1 - start\n 2 - exit\n");
		scanf_s("%d", &proverka);
		if (proverka == 1) {
			printf("Vvedite kol-vo okon\n");
			scanf("%f", &okon);
			printf("Vvedite kol-vo balconov\n");
			scanf("%f", &balc);
			printf("Vvedite etash\n");
			scanf("%f", &etash);
			float nacenka = 0.15*(etash - 1) + 1;
			printf("Obshaya ploshad' zasteklenia=%fm2\n", plzast(okon, plok, balc, plbalc));
			printf("Stoimost' zasteklenia okon=%f$\n", stzato(okon, cenaok, nacenka));
			printf("Stoimost' ustanovki balc dveri=%f$\n", stustdveri(balc, cenabalc, nacenka));
			printf("Nacenka=%f%%\n", (round((nacenka - 1) * 100)));
			printf("Obshaya stoimost'=%f$\n", obshayastoimost(okon, cenaok, balc, cenabalc, nacenka));
			printf("Kompaniya SV-Svet, Minsk, Yankovskogo-4\n+375292530101 - Artyom, Director\n");
		}
		else if (proverka > 2 || proverka < 1) {}
		else break;
	}
}
