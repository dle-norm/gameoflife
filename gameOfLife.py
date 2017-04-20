import pygame
from pygame.locals import *
pygame.init()
fenetre = pygame.display.set_mode((400, 400))
fenetre = pygame.display.set_mode((400, 400), RESIZABLE)
def rander(tab):
    i = 0;
    while i < 200:
        j = 0
        while j < 200:
            import random
            if random.randint(0,7) == 1:
                tab[i][j] = 1
            else:
                tab[i][j] = 0
            j += 1
        i += 1
    return tab

def printer(tab, ecran):
    i = 0
    while i < 200:
        j = 0
        while j < 200:
            if tab[i][j] == 1:
                pygame.Surface.set_at(ecran, ((i * 2), (j * 2)), pygame.Color("white"))
                pygame.Surface.set_at(ecran, ((i * 2) + 1, (j * 2)), pygame.Color("white"))
                pygame.Surface.set_at(ecran, ((i * 2), (j * 2) + 1), pygame.Color("white"))
                pygame.Surface.set_at(ecran, ((i * 2) + 1, (j * 2) + 1), pygame.Color("white"))
            j += 1
        i += 1

def check_point(tab, i, j):
    neighbor = 0
    a = 0
    k = i - 1
    l = j - 1
    while a < 3:
        b = 0
        while b < 3:
            if (l >= 0 and k >=0 and l < 200 and k < 200 and tab[k][l] == 1) and (l != j or k != i):
                neighbor += 1
            b += 1
            l += 1
        a += 1
        k += 1
        l -= 3
    if neighbor == 2:
        return tab[i][j]
    elif neighbor == 3:
        return 1
    else:
        return 0

def check_map(tab):
    i = 0
    result = []
    while i < 200:
        j = 0
        result.append([0] * 200)
        while j < 200:
            result[i][j] = check_point(tab, i, j)
            j += 1
        i += 1
    return result

tab = []
i = 0
while i < 200:
    tab.append([0] * 200)
    i += 1
tab = rander(tab)
printer(tab, fenetre)
j = 0
while j != 1:
    fenetre.fill(Color('black'))
    for event in pygame.event.get():
        if event.type == QUIT:
            j = 1
    tab = check_map(tab)
    printer(tab,fenetre)
    pygame.display.flip()

    
