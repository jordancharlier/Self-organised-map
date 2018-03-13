#include "Header.h"
grille initNeuronne(grille g,base b){
    int i,j,z=0;
    //printf("%f,%f,%f,%f\n",b.VecMoy[0],b.VecMoy[1],b.VecMoy[2],b.VecMoy[3]);
    for (i = 0; i < g.longueur; ++i){
        for (j= 0; j < g.largeur; ++j){
            for (z = 0; z < 4; ++z){
                g.Grille[i][j].valeur[z]=rand_interval(-0.02 + b.VecMoy[z], 0.05 + b.VecMoy[z]);
            }
            //printf("%f %f %f %f\n",g.Grille[i][j].valeur[0],g.Grille[i][j].valeur[1],g.Grille[i][j].valeur[2],g.Grille[i][j].valeur[3]);
            
        }
    }
    return g;
}


grille TailleGrille(grille g, base b){
    int n;
    int *temp;
    temp=malloc(100*sizeof(int));
    n=5*sqrt(b.nb_lignes);
    int count=0;
    int i=2;
    if ( n%10!=0){
        n=n/10;
        n++;
        n*=10;
    }
    while(i <= sqrt(n)){
        if(n%i==0){
            temp[count]=i;
            count++;
            if (i != (n / i)){
                temp[count]=n/i;
                count++;
            }
        }
        i++;
    }
    g.longueur=temp[count-1];
    g.largeur=temp[count-2];
    return g;
}


int *Smallest_DE(base b, grille g,int shu,int *smallest){
    // printf("adresse dans la fonction %p\n",smallest);
    //int h=0;
    //char str1[100];
    double distance_euc=1.0;
    // double distance_euc=distance_euclidienne(b.data[shu].vect,g.Grille[3][3].valeur,b.taille_vec-1);
    //distance_euc=distance_euclidienne(b.data[shu].vect,g.Grille[0][0].valeur,b.taille_vec-1);//1.0;
    //printf(" DISTANCE EUC%f",distance_euc);
    double distance_temp=0.0;
    //double distance_temp;
    smallest[0]=0;
    smallest[1]=0;
    for (int i = 0; i < g.longueur; i++) {
        for (int j = 0; j < g.largeur; j++) {
            
            distance_temp = distance_euclidienne(b.data[shu].vect,g.Grille[i][j].valeur,b.taille_vec-1);
            
            
            if (distance_euc>distance_temp) {
            
                distance_euc=distance_temp;
            
                smallest[0]=i; //x de la plus petite distance euclidienne
                smallest[1]=j; //y de la plus petite distance euclidienne
            
            
                
            }
        }
        
    }
    
    if(strcmp(b.data[shu].name, "Iris-setosa")==10) {
        g.Grille[smallest[0]][smallest[1]].etiquette[0]+=1;
        
    }
    if(strcmp(b.data[shu].name, "Iris-versicolor")==10){
        g.Grille[smallest[0]][smallest[1]].etiquette[1]+=1;
    }
    if(strcmp(b.data[shu].name, "Iris-virginica")==10) {
        g.Grille[smallest[0]][smallest[1]].etiquette[2]+=1;
        
    }
    
    
    //printf("%d\n",g.Grille[smallest[0]][smallest[1]].etiquette[0]);
    return smallest;
}
void SousMulAddVec(double *w, grille g, double alpha, base b, int i, int j){
    for(int z=0; z<b.taille_vec-1;++z)
    {
        g.Grille[i][j].valeur[z]= g.Grille[i][j].valeur[z]+ (alpha*(w[z]-g.Grille[i][j].valeur[z]));
    }
}


int CalculRayon( base b, grille g ){
    int taille_reseau=g.longueur * g.largeur;
    taille_reseau/=2;
    int temp = 8;
    int rayon=1;
    while (temp < taille_reseau){
        temp += temp * 2;
        rayon += 1;
    }
    return rayon;
}

grille Voisinage ( int x, int y, double * w, base b, grille g,int rayon,double alpha, double *Vec_Malloc,int shu){
    int x0=0,y0=0,x1=0,y1=0;
    double *temp;
    temp=(double*) calloc(4,4*sizeof(double*));
    x0= (x-rayon)<0 ? 0 : x-rayon;
    y0= (y-rayon)<0 ? 0 : y-rayon;
    x1= (x+rayon)>g.longueur ? g.longueur : x+rayon;
    y1= (y+rayon)>g.largeur ? g.largeur : y+rayon;
    //printf("x0=%d y0=%d x1= %d y1=%d x=%d y=%d \n",x0,y0,x1,y1,x,y);
    //AfficheTabDouble(b.)
    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++) {
            SousMulAddVec(w,g,alpha,b,i,j);
            
            if(strcmp(b.data[shu].name, "Iris-setosa")==10) {
                g.Grille[i][j].etiquette[0]+=1;
                
            }
            if(strcmp(b.data[shu].name, "Iris-versicolor")==10){
                g.Grille[i][j].etiquette[1]+=1;
            }
            if(strcmp(b.data[shu].name, "Iris-virginica")==10) {
                g.Grille[i][j].etiquette[2]+=1;
                
            }
        }
    }
    free(temp);
    return g;
}

void AffichageReseaufinal(grille g)
{
    for (int i = 0; i < g.longueur; ++i)
    {
        for (int j = 0; j < g.largeur; ++j)
        {
            printf("%d     ", PlusGrand(g.Grille[i][j].etiquette)); 
        }
        printf("\n\n") ;
    }
}
void AffichageReseau(grille g)
{
    for (int i = 0; i < g.longueur; ++i)
    {
        for (int j = 0; j < g.largeur; ++j)
        {
            printf("i%d j%d      1=%d     2=%d      3=%d\n", i,j,g.Grille[i][j].etiquette[0],g.Grille[i][j].etiquette[1],g.Grille[i][j].etiquette[2]);
            
        }
        printf("\n") ;
    }
}//
//  network.c
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

