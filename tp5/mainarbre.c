#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"
#include "liste.h"

int comparerChar(void *obj1, void *obj2) {
  return strcmp((char *)obj1, (char *)obj2);
}

char *afficherChar(void *obj) { return (char *)obj; }

int menu() {
  int cod;
  printf("\n\nGESTION D'ARBRES\n");
  printf("\nARBRES BINAIRES\n");
  printf("\n0-Fin\n");
  printf("1-Creation de l'arbre genealogique\n");
  printf("2-Creation de l'arbre de l'expression arithmetique\n");
  printf("3-Parcours prefixe\n");
  printf("4-Parcours infixe\n");
  printf("5-Parcours postfixe\n");
  printf("6-Trouver Noeud\n");
  printf("7-Taille\n");
  printf("8-Hauteur\n");
  printf("9-Parcours en largeur\n");
  printf("\n");
  printf("Votre choix?\n");
  scanf("%d", &cod);
  getchar();
  printf("\n");
  return cod;
}

char *create_string(char *nom) {
  char *pNom = (char *)malloc(sizeof(char *));
  strcpy(pNom, nom);
  return pNom;
}

int main() {
  char *a = create_string("Samir");
  char *b = create_string("Kamal");
  char *c = create_string("Yassine");
  char *d = create_string("Hind");
  char *e = create_string("Yasmine");
  char *f = create_string("Sarah");
  char *g = create_string("Karim");

  char *h = create_string("-");
  char *i = create_string("*");
  char *j = create_string("+");
  char *k = create_string("a");
  char *l = create_string("b");
  char *m = create_string("-");
  char *n = create_string("c");
  char *o = create_string("d");
  char *p = create_string("e");

  Arbre *arbre_gen, *arbre_ari;

  Noeud *racine1 = cNd(
      a, cNd(b, cNd(c, NULL, cNd(d, NULL, cF(e))), cNd(f, cF(g), NULL)), NULL);
  Noeud *racine2 =
      cNd(h, cNd(i, cNd(j, cF(k), cF(l)), cNd(m, cF(n), cF(o))), cF(p));

  bool fini = false;

  while (!fini) {
    switch (menu()) {
      case 0: {
        fini = true;
        break;
      }
      case 1: {
        arbre_gen = creer_arbre(racine1, afficherChar, comparerChar);
        break;
      }
      case 2: {
        arbre_ari = creer_arbre(racine2, afficherChar, comparerChar);
        break;
      }
      case 3: {
        prefixe(racine1, afficherChar);
        break;
      }
      case 4: {
        infixe(racine1, afficherChar);
        break;
      }
      case 5: {
        postfixe(racine1, afficherChar);
        break;
      }
      case 6: {
        char *objcherche = (char *)malloc(sizeof(char *));
        printf("Ecrire valeur a chercher:\n");
        scanf("%s", objcherche);
        if (trouver_noeud(racine1, objcherche, comparerChar)) {
          printf("L'objet %s est trouve dans l'arbre genealogique",
                 trouver_noeud(racine1, objcherche, comparerChar)->reference);
        } else {
          printf("Le nom ne se trouve pas dans l'arbre");
        }
        break;
      }
      case 7: {
        printf("La taille de l'arbre genealogique est: %d", taille(racine1));
        printf("\n");
        printf("La taille de l'arbre arithmetique a est: %d", taille(racine2));
        break;
      }
      case 8: {
        printf("La hauteur de l'arbre genealogique est: %d", hauteur(racine1));
        printf("\n");
        printf("La hauteur de l'arbre arithmetique est: %d", hauteur(racine2));
        break;
      }
      case 9: {
        en_largeur(racine1, afficherChar);
        break;
      }
      default:
        break;
    }
  }
}
