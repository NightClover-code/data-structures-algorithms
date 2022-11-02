#include <stdio.h>

#include "liste.h"
#include "personne.h"

int menu() {
  printf("\n\n GESTION D'UNE LISTE D'ENTIERS \n\n");
  printf("0 - Fin\n");
  printf("2 - Insertion en tete de liste \n");
  printf("3 - Insertion en fin de liste \n");
  printf("4 - Retrait en tete de liste \n");
  printf("5 - Retrait en fin de liste \n");
  printf("6 - Retrait d’un element à partir de son nom\n");
  printf("7 - Parcours de la liste \n");
  printf("8 - Recherche d’un element à partir de son nom \n");
  printf("9 - Destruction de la liste \n");
  printf("\n");
  printf("Votre choix ? ");

  int code;
  scanf("%d", &code);
  printf("\n");
  return code;
}

void main() {
  Liste* lp = creer_liste(0, afficher_personne, comparer_personne);
  bool fini = false;
  while (!fini) {
    switch (menu()) {
      case 0:
        fini = true;
        break;
      case 1:
        printf("Nom de la personne: ");
        ch15 nom;
        scanf("%s", &nom);
        printf("Prenom de la personne: ");
        ch15 prenom;
        scanf("%s", &prenom);
        Personne* p = cree_personne(nom, prenom);
        inserer_en_tete(lp, p);
        break;
      case 2:
        printf("Nom de la personne: ");
        ch15 nom;
        scanf("%s", &nom);
        printf("Prenom de la personne: ");
        ch15 prenom;
        scanf("%s", &prenom);
        Personne* p = cree_personne(nom, prenom);
        inserer_en_fin(lp, p);
        break;
      case 3:
        Personne* extrait = (Personne*)extraire_en_tete(lp);
        if (extrait != NULL) {
          printf("Element %s %s extrait de la liste!", extrait->nom,
                 extrait->prenom);
        } else {
          printf("Liste vide");
        }
        break;
      case 4:
        Personne* extrait = (Personne*)extraire_fin(lp);
        if (extrait != NULL) {
          printf("Element %s %s extrait de la liste!", extrait->nom,
                 extrait->prenom);
        } else {
          printf("Liste vide");
        }
      case 5:
        printf("Nom de la personne a extraire: ");
        ch15 nom;
        scanf("%s", &nom);
        Personne* personne_cherche = cree_personne(nom, "?");
        Personne* pp = (Personne*)chercher_objet(lp, personne_cherche);
        if (extraire_objet(lp, pp)) {
          printf("Element %s %s extrait de la liste!", pp->nom, pp->prenom);
        } else {
          printf("Element introuvable");
        }
        break;
      case 6:
        lister_liste(lp);
        break;
      case 7:
        printf("Nom de la personne a rechercher: ");
        ch15 nom;
        scanf("%s", &nom);
        Personne* personne_cherche = cree_personne(nom, "?");
        Personne* pp = (Personne*)chercher_objet(lp, personne_cherche);
        if (pp != NULL) {
          printf("%s %s trouvé dans la liste!", pp->nom, pp->prenom);
        } else {
          printf("Element introuvable");
        }
      case 8:
        detruire_liste(lp);
        break;
    }
  }
}