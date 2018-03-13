//
//  prelude.c
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

#include "Header.h"
double normalize (double *v, int distance){
    int i;
    double normevec=0;
    for ( i = 0; i < distance-1; ++i){
        normevec+= pow(v[i],2);
        //printf("%f+\n",normevec );
        
        
    }
    
    normevec= sqrt(normevec);
    //printf(" distance %d\n",distance );
    //printf("Finale :%f\n",normevec );
    
    return normevec;
}

base normalisation ( base b){
    int i;
    for (i=0; i < b.nb_lignes; ++i){
        b.data[i].norme=normalize(b.data[i].vect, b.taille_vec);
        //printf("%lf\n",b.data[i].norme);
        
    }
    return b;
}

base DivisionParNorme(base b){
    int i,j;
    for (i=0; i < b.nb_lignes; ++i){
        for (j = 0; j< (b.taille_vec-1); ++j){
            b.data[i].vect[j]/=b.data[i].norme;
            //printf("[%d]==%f Norme= %f\n",i,b.data[i].vect[j],b.data[i].norme );
        }
    }
    return b;
}

base CalculVecMoy(base b){
    b.VecMoy = (double*) calloc ((b.taille_vec-1), sizeof(double));
    int i,j;
    for (j = 0; j< b.taille_vec-1; j++){
        for (i=0; i < b.nb_lignes; i++){
            b.VecMoy[j]+= b.data[i].vect[j];
            //printf("%f j==%d\n",b.data[i].vect[j],j );
        }
        
        b.VecMoy[j] = b.VecMoy[j] / b.nb_lignes;
        printf("%f j==%d\n", b.VecMoy[j],j);
    }
    return b;
    //b.VecMoy[j]/= b.nb_lignes;
}
base mallocationFirst(base b){
    
    
    b.nb_lignes=150;
    b.taille_vec=5;
    int z;
    b.data=(Data*) malloc( b.nb_lignes*sizeof(struct base));
    for (z=0; z <= b.nb_lignes; ++z){
        b.data[z].vect=  (double *) malloc( (b.taille_vec-1)*sizeof(double));
        b.data[z].name=  (char *) malloc(30 *sizeof(char));
    }
    // for (zz=0; zz <= b.nb_lignes; ++zz){
    // b.data[z].name=  (char *) malloc(4000 *sizeof(char));
    // }
    
    return b;
}


grille mallocationname( grille g)
{int sa,saer;
    for ( sa = 0; sa < g.longueur; sa++) {
        for (  saer = 0; saer < g.largeur; saer++) {
            //printf("COUCOU\n");
            g.Grille[sa][saer].etiquette= (int *) calloc(3, 3*sizeof(int));
            
            //printf("%d\n",g.Grille[sa][saer].etiquette[0] );
            
            
        }
    }
    return g;
}

grille mallocationPREM( grille g)
{int count,counter;
    g.Grille= (neurone **) malloc( g.largeur *g.longueur*sizeof(struct neurone));
    for ( count = 0; count < g.longueur; count++) {
        for ( counter = 0; counter < g.largeur; counter++) {
            g.Grille[count]=  (neurone *)malloc( g.longueur*g.longueur*sizeof(neurone*));
            
            
        }
    }
    return g;
}

grille mallocationDEU( grille g,base b)
{int count,counter;
    for ( count = 0; count < g.longueur; count++) {
        for ( counter = 0; counter < g.largeur; counter++) {
            g.Grille[count][counter].valeur= (double *) malloc( (b.taille_vec-1) *sizeof(double));
            
            
        }
    }
    return g;
}


base extration(base b) {
    FILE *fp;
    fp = fopen("iris.txt" , "r");
    char *str;
    char s[1]=",";
    char s1[1]="\n";
    char *token;
    char line[600];
    int i,j=0;
    char *ptr;
    for ( i = 0; i < b.nb_lignes; ++i)  {
        fgets (line, sizeof line, fp);
        str = line;
        token=strtok(str,s);
        
        b.data[i].vect[j]= strtod(token, &ptr);
        //printf(" 1 : %f\n",b.data[i].vect[j]);
        j++;
        //printf(" %s\n",b.data[i].vect[j]);
        
        while(token!=NULL){
            while(j<b.taille_vec-1){
                token=strtok(NULL,s);
                // printf(" %d\n",b.taille_vec-1);
                b.data[i].vect[j]=strtod(token,&ptr);
                //printf(" 2 : %f\n",b.data[i].vect[j]);
                j++;
                
            }
            //token = NULL;
            token=strtok(NULL,s);
            //printf("%s\n",token);
            b.data[i].name=strcpy(b.data[i].name,token);
            token = NULL;
            //strcpy(b.data[i].name,token);
            j=0;
            
        }
        //printf("%s\n",token );
    }
    //printf("%s",b.data[10].name);
    
    // printf("%d\n",compt);
    fclose(fp);
    //printf("%s",b.data[10].name);
    
    return b;
}
