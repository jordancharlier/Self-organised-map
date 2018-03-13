//
//  smallfunc.c
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

#include "Header.h"



void swap(int *b, int a, int c){
    int temp=0;
    temp=b[a];
    b[a]=b[c];
    b[c]=temp;
}
int* shuffle(int *vec,base b){
    int i=0;
    for (i = 0; i <b.nb_lignes ; i++) {
        swap(vec,i,rand_interval_int(0,b.nb_lignes-1));
        
    }
    return vec;
}
void affiche_tab( char *b){
    for (int i = 0; i < 6; i++) {
        printf("%c\n",b[i] );
    }
}
void AfficheTabDouble(double *vec){
    for (int i = 0; i < 4; i++) {
        printf("%f\n",vec[i] );
    }
}
void CopyTab( double * a, double * c, base b){
    for (int i = 0; i < b.taille_vec-1; i++) {
        a[i]=c[i];
    }
}
double rand_interval(double min, double max){
    return min + ((max - min) * (rand () / (double) RAND_MAX));
}


int rand_interval_int(int min, int max){
    return rand() % (max - min + 1) + min;
}

double distance_euclidienne (double *x, double *y, int longueur){
    int i;
    double distance_euc=0.0,a=0.0;
    //printf("SALAM");
    for ( i = 0; i < longueur; ++i){
        a=x[i] -y[i];
        distance_euc+= pow(a,2);
    }
    distance_euc= sqrt(distance_euc);
    return distance_euc;
}



double* SousVec(double *valeur, double *neurone, base b,double *Vec_Malloc){
    // double *vec;
    // vec=malloc(4*sizeof(double));
    for (int i = 0; i <b.taille_vec-1 ; i++) {
        Vec_Malloc[i]=valeur[i]-neurone[i];
        // printf("Je passe ici\n" );
    }
    return Vec_Malloc;
    //printf("lili\n" );
}



double* MulVec(double valeur, double *neurone, base b,double *Vec_Malloc){
    // double *vec;
    // vec=malloc(4*sizeof(double));
    for (int i = 0; i <b.taille_vec-1 ; i++) {
        Vec_Malloc[i]=valeur*neurone[i];
    }
    return Vec_Malloc;
}


double* AddVec(double *valeur, double *neurone, base b,double *Vec_Malloc){
    // double *vec;
    // vec=malloc(4*sizeof(double));
    for (int i = 0; i <b.taille_vec-1 ; i++) {
        Vec_Malloc[i]=valeur[i]+neurone[i];
    }
    return Vec_Malloc;
}

int PlusGrand(int * p)
{
    int temp=0;
    for (int i = 1; i < 3; ++i)
    {
        if (p[temp]<=p[i])
        {
            temp=i;
        }
    }
    return temp;
}
