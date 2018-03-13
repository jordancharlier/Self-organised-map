//
//  main.c
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"

int main(int argc, char *argv[])
{
    base b;
    grille g;
    
    b=mallocationFirst(b);
    g=TailleGrille(g,b);
    b=extration(b);
    g= mallocationPREM(g);
    g= mallocationDEU(g,b);
    g= mallocationname(g);
    
    
    b = normalisation(b);
    
    b = DivisionParNorme (b);
    b = CalculVecMoy(b);
    g=  initNeuronne(g,b);
    
    int nb_iteration_tot=250*b.nb_lignes;// sqrt(b.nb_lignes);
    double alpha_init=0.7;
    Apprentissage(nb_iteration_tot,b,g,alpha_init);
    AffichageReseau(g);
    AffichageReseaufinal(g);
    double *Vec_Malloc;//pour les fonction ADD SOUS MUL
    int toto =CalculRayon(  b,  g );
    printf("%d",toto);

    return 0;
}

