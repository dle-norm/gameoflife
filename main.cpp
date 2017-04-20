#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
/*
int **rander(int **tab)
{
    int i;
    int j;

    i = 0;
    srand(time(NULL));
    while (i < 400) {
            j = 0;
        while (j < 400) {
            if (rand() % 4 == 1) {
                tab[i][j] = 1;
            }
            else {
                tab[i][j] = 0;
            }
            j++;
        }
        i++;
    }
    return tab;

}*/
int **rander(int **tab)
{
    int i;
    int j;

    i = 0;
    while (i<400) {
        j = 0;
        while(j<400) {
            tab[i][j] = 0;
            j++;
        }
        i++;
    }
    tab[200][195] = 1;
    tab[200][196] = 1;
    tab[200][197] = 1;
    tab[200][198] = 1;
    tab[200][199] = 1;
    tab[200][200] = 1;
    tab[200][201] = 1;
    tab[200][202] = 1;
    tab[200][203] = 1;
    tab[200][204] = 1;


    tab[100][102] = 1;
    tab[100][101] = 1;
    tab[100][103] = 1;
    tab[100][104] = 1;
    tab[100][105] = 1;
    tab[101][101] = 1;
    tab[101][105] = 1;

    return tab;
}


void printer(int **tab, SDL_Surface *ecran)
{
    int i;
    int j;
    SDL_Surface *rectangle = NULL;
    SDL_Surface *rectangle2 = NULL;
    SDL_Rect position;

    i = 0;
    j = 0;
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    rectangle2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangle2, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    while (i < 400) {
        j = 0;
        while (j < 400) {
            if (tab[i][j] == 1) {
                position.x = j *2; // Les coordonnées de la surface seront (0, 0)
                position.y = i *2;
                SDL_BlitSurface(rectangle, NULL, ecran, &position);
            }
            else {
                position.x = j *2; // Les coordonnées de la surface seront (0, 0)
                position.y = i *2;
                SDL_BlitSurface(rectangle2, NULL, ecran, &position);
            }
            j++;
        }
        i++;
    }
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(rectangle2);
}

int check_point(int **tab, int i, int j)
{
	int neighbor;
	int a;
	int b;
	int k;
	int l;

	neighbor = 0;
	a = 0;
	k = i - 1;
	l = j - 1;
	while (a < 3)
	{
		b = 0;
		while (b < 3)
		{
			if (((l >= 0) && (k >= 0) && (l < 400) && (k < 400) && (tab[k][l] == 1)) && ((l != j) || (k != i)))
				neighbor++;
			b++;
			l++;
		}
		a++;
		k++;
		l -= 3;
	}
	if (neighbor == 2)
		return (tab[i][j]);
	else if (neighbor == 3)
		return (1);
	else
		return (0);
}

int **copytab(int **tab, int **result)
{
    int i;
    int j;

    i = 0;
    while (i < 400) {
        j = 0;
        while (j < 400) {
            tab[i][j] = result[i][j];
            j++;
        }
        i++;
    }
    return (tab);
}

int **check_map(int **tab)
{
	int i;
	int j;
	int **result;

	i = 0;
	result = (int **)malloc(sizeof(int *) * 400);
	while (i < 400)
	{
		j = 0;
		result[i] = (int*)malloc(sizeof(int) * 400);
		while (j < 400)
		{
			result[i][j] = check_point(tab, i, j);
			j++;
		}
		i++;
	}
	tab = copytab(tab, result);
	i = 0;
	while(i < 400)
    {
        free(result[i]);
        i++;
	}
	free(result);
	return (tab);
}


int main(int ac, char **av)
{
    int **tab;
    int i;
    SDL_Surface *ecran = NULL;

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    ecran = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE  | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Jeu de la vie en SDL !", NULL);
    tab = (int**)malloc(sizeof(int*) * 400);
    i = 0;
    while (i < 400) {
        tab[i] = (int*)malloc(sizeof(int) * 400);
        i++;
    }
    tab = rander(tab);
    printer(tab, ecran);
    SDL_Event event;
    bool done = false;
    while (!done)
    {
        // message processing loop
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                {
                   done = true;
                break;
                }
                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing
        tab = check_map(tab);
        printer(tab, ecran);
        SDL_Flip(ecran);
    }
    free(tab);
    SDL_Quit();
    return 0;
}
