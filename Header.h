//
//  Header.h
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct Data
{
    double *vect;
    double norme;
    char* name;
};
typedef struct Data Data;
//Data liste_Data[150];
struct base
{
    struct Data* data;
    int nb_lignes;
    int taille_vec;
    double* VecMoy;
};
typedef struct base base;



struct grille
{
    struct neurone** Grille; //grille rectangulaire longueur >largeur
    int longueur;
    int largeur;
    int *shuffle;
    
};
typedef struct grille grille;


struct neurone
{
    double *valeur;
    // double dist; //resultat distance euclidienne entre le vecteur qui doit etre testé et le vec du neuronne
    //char *nom;
    //double act;
    int *etiquette; //initialisé à 0,0,0
    //int nom_etiquette;
    
};
typedef struct neurone neurone;


struct bmu
{
    int bmu_l;//ligne
    int bmu_c;//colonne
    
};
typedef struct bmu bmu;



double normalize (double *v, int distance);
double distance_euclidienne (double *x, double *y, int longueur);
double randfrom( double max) ;
double rand_interval(double a, double b);
int rand_interval_int(int a, int b);

base normalisation( base b);
base DivisionParNorme(base b);
base CalculVecMoy(base b);
int *Smallest_DE(base b, grille g,int shu,int *smallest);
void swap(int *b, int a, int c);
int *shuffle(int *vec,base b);
grille initNeuronne(grille g,base b);
grille TailleGrille(grille g, base b);
double* SousVec(double *valeur, double *neurone, base b,double *Vec_Malloc);
double* MulVec(double valeur, double *neurone, base b,double *Vec_Malloc);
double* AddVec(double *valeur, double *neurone, base b,double *Vec_Malloc);
int PlusGrand(int * p);
grille Voisinage ( int x, int y, double * w, base b, grille g,int rayon,double alpha,double *Vec_Malloc,int shu);
void AfficheTabDouble(double *vec);
void affiche_tab(char *b);
void CopyTab( double * a, double * c, base b);
void Apprentissage (int nb_iteration_tot, base b, grille g, double alpha_init);
base mallocationFirst(base b);
grille mallocationname(grille g);
grille mallocationPREM( grille g);
grille mallocationDEU( grille g,base b);
base extration(base b);
void AffichageReseau(grille g);
void AffichageReseaufinal(grille g);
void SousMulAddVec(double *w, grille g, double alpha, base b, int i, int j);

int CalculRayon( base b, grille g );


#endif /* Header_h */
