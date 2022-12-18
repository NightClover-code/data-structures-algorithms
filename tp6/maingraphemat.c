#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphemat.h"

int menu() {
  int cod;
  printf("\n\nGESTION DE GRAPHES\n\n");
  printf("1-Creer un graphe\n");
  printf("2-Ajouter un sommet\n");
  printf("3-Ajouter un arc\n");
  printf("4-Afficher le graphe\n");
  printf("5-Parcours en profondeur\n");
  printf("6-Fin\n");
  printf("\n");
  printf("Votre choix?\n");
  scanf("%d", &cod);
  getchar();
  printf("\n");
  return cod;
}

void main() {
  GrapheMat *graphe;

  bool fini = false;
  int n, value, cout;
  NomSom nomS, som1, som2;

  while (!fini) {
    switch (menu()) {
      case 1: {
        printf("Entrez le nombre de sommets: ");
        scanf("%d", &n);
        printf("Entrez 1 si le graphe est value et 0 sinon: ");
        scanf("%d", &value);
        graphe = creerGrapheMat(n, value);
        break;
      }
      case 2: {
        printf("Nom du sommet a ajouter: ");
        scanf("%s", nomS);
        ajouterUnSommet(graphe, nomS);
        break;
      }
      case 3: {
        printf("Nom du premier sommet: ");
        scanf("%s", som1);
        printf("Nom du deuxieme sommet: ");
        scanf("%s", som2);
        printf("Cout de l'arc: ");
        scanf("%s", &cout);
        ajouterUnArc(graphe, som1, som2, cout);
        break;
      }
      case 4: {
        ecrireGraphe(graphe);
        break;
      }
      case 5: {
        parcoursProfond(graphe);
        break;
      }
      case 6: {
        fini = true;
        break;
      }
      default:
        break;
    }
  }
}
