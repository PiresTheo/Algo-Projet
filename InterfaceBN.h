#include "Grille.h"
#include "Menu.h"
#include "scores.h"
#ifndef INTERFACEBN_H_INCLUDED
#define INTERFACEBN_H_INCLUDED
/**Headers Bataille Navale*/
int interBN(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
void ecrireBN(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int etape);
SDL_Rect cliqueSourisBN(Compteur cpt,SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int etape, int typebateau);
#endif // INTERFACEBN_H_INCLUDED


