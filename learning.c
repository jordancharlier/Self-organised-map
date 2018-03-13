//
//  learning.c
//  SOM
//
//  Created by Jordan Charlier on 08/11/2017.
//  Copyright © 2017 Jordan Charlier. All rights reserved.
//

#include "Header.h"
void Apprentissage (int nb_iteration_tot, base b, grille g, double alpha_init){
    double alpha=0.0;
    int rayon=0;
    double *Vec_Malloc;//pour les fonction ADD SOUS MUL
    Vec_Malloc=(double *) malloc(b.taille_vec*sizeof(double));
    int *smallest;
    smallest=malloc(2*sizeof(int));//mettre en global
    smallest[0]=0;
    smallest[1]=0;
    int phase=nb_iteration_tot/4;
    int *position_BMU;
    position_BMU=(int *) calloc(2,2*sizeof(int));
    double h=0.0;
    int *vec;
    vec=(int *) malloc(b.nb_lignes*sizeof(int));
    for (int shu = 0; shu < b.nb_lignes; shu++)
    {
        vec[shu]=shu;
        //printf("%d\n", vec[shu]);
    }
    
    for(int nb_iteration=0; nb_iteration<nb_iteration_tot; nb_iteration++)
    {
        vec=shuffle(vec,b);
        if( nb_iteration<=phase)
        {
            h=(double)nb_iteration/nb_iteration_tot;
            // printf("%f :Valeur de H\n",h );
            alpha= alpha_init*(1-h);
            //printf("%f\n",(1-(nb_iteration/nb_iteration_tot)) );
            //printf(" ALPHA  %f alpha_init %f nb_iteration %d nb_iteration_tot %d\n",alpha,alpha_init,nb_iteration,nb_iteration_tot );
            rayon = CalculRayon(b, g);
            
            for(int i=0; i<b.nb_lignes;i++){
                
                position_BMU=Smallest_DE(b,g,vec[i],position_BMU);
                int d;
                d=vec[i];
                g=Voisinage(position_BMU[0],position_BMU[1],b.data[vec[i]].vect,b,g,rayon,alpha,Vec_Malloc,d);
                
            }
        }
        
        else
        {
            
            h=(double)nb_iteration/nb_iteration_tot;
            alpha= alpha_init*(1-h)*0.1;
            rayon =3;
            for(int j=0; j<b.nb_lignes;j++)
            {
                position_BMU=Smallest_DE(b,g,vec[j],position_BMU);
                int c;
                c=vec[j];
                g=Voisinage(position_BMU[0],position_BMU[1],b.data[vec[j]].vect,b,g,rayon,alpha,Vec_Malloc,c);
                
            }
            
        }
    }
    
}
