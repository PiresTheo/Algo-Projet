#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


#include "Menu.h"
#include "InterfaceSudoku.h"
#include "InterfaceLoto.h"
#include "InterfaceBN.h"
#include "InterfacePoker.h"


/**Menu Principal*/
void menuPrincipal(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){ /* Le menu principal */
    SDL_Event event; // La variable contenant l'�v�nement
    int continuer = 1;
    imageDeFond = SDL_LoadBMP("menu.bmp");

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'�cran
    SDL_Flip(ecran);

    positionFond.x = 0;
    positionFond.y = 0;


    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2000);

    Mix_Music *music = NULL;



    music = Mix_LoadMUS("menu.mp3");

    Mix_PlayMusic(music, 55);

    while(continuer){
        imageDeFond = SDL_LoadBMP("menu.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'�cran
        SDL_Flip(ecran);
        SDL_WaitEvent(&event);
        switch(event.type) // On teste le type d'�v�nement
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1007 && event.button.x<1335 && event.button.y>27 && event.button.y<72)
                {
                    interBN(ecran,imageDeFond,positionFond);

                }
                else if(event.button.x>1185 && event.button.x<1347 && event.button.y>80 && event.button.y<119)
                {
                    interSudoku(ecran,imageDeFond,positionFond);
                    continuer = 0;
                }
                else if(event.button.x>1220 && event.button.x<1344 && event.button.y>134 && event.button.y<173)
                {
                    interPoker(ecran,imageDeFond,positionFond);
                }
                else if(event.button.x>1244 && event.button.x<1346 && event.button.y>189 && event.button.y<228)
                {
                    interLoto(ecran,imageDeFond,positionFond);
                }
                else if(event.button.x>1199 && event.button.x<1354 && event.button.y>694 && event.button.y<730)
                {
                    continuer = 0;
                }
                break;
            }
            default :
            break;
        }
    }
    Mix_FreeMusic(music); //Lib�ration de la musique
    Mix_CloseAudio(); //Fermeture de l'API
}
