#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{   //on definit une structure pour pouvoir avoir en sortie notre a et b en sortie lors du calcule d'approxiamtion vue dans l'explication des methodes
    double a;  // donc on definit double a et b, on definit ce type car nous pouvons avoir  un entier ou un float
    double b;
}coeff;

coeff calculAB (double *x, double *y,int n){       // on a donc en entrée x et y definit dans les jeux d'essaie et n qui definit combien de point nous avons
    double sommeX = 0;       // initialisation de la Somme ainsi que du produit des x et y à 0
    double sommeY= 0;
    double produitXY =0;
    int i, j;                // definition de i,j et de resultat ;
    double resultat;
    coeff z;
    for (i=0; i<n; i++){
        sommeX += x[i];                      // Notre boucle ici calcule la somme des x et y et fait aussi le produit des x et y entre eux
        sommeY += y[i];
        produitXY += (x[i] * y[i]);
    }


    for (i=0; i<n; i++){
        printf("%lf ", y[i]);                                      // on affiche ce que l'on a donc dans notre tableau de y
    }
    resultat = ( ( sommeX * sommeY )/ n ) - produitXY;              // nous affectons donc une fois : la (somme des x) multiplié à (somme des y) divisé a le nombre de point - prduit des x et x
                                                                       // vue dans la formule pour trouver a dans la rubrique rapelle des methodes
    printf("\n");
    printf("sommeX = %lf\n", sommeX);
    printf("sommeY = %lf\n", sommeY);
    printf("produitXY = %lf\n", produitXY);
    printf("a1 = %lf\n", resultat);

    resultat = resultat / ( ( (sommeX * sommeX)/n ) - (sommeX * sommeX) );       // on finit donc la methode pour trouver a car dans resultat nousa vons juste calculer le numerateur,
                                                                                 // donc nous calculons a en ajoutant le denomianteur : (sommeX * sommeX)/n ) - (sommeX * sommeX)
    printf("\na2 = %lf\n", resultat);
    z.a = resultat;                                                              // on a affecte donc resultat à a dans la struct

    resultat = ( sommeY / n) - ( ( z.a * sommeX )/n );                           // on utilise resultat car on a pas cree d'autre variable, nous calculons b vue dans la methode avec
    printf("\nb = %lf", resultat);                                               // le a calculé avant et on finit pas affecter une fois de plus resultat à b dans la struct.
    z.b = resultat;
    return z;
}



int main(){

    int n, i;
    printf("Combien de points ?");
    scanf("%d",&n);
    double *x = malloc ( (n-1)*sizeof(double));
    double *y = malloc ( (n-1)*sizeof(double));                                 // on va creer des tableau de n taille demandé dans les jeux d'essaies
    double valeur;
    coeff z;

    for(i = 0 ; i<n ; i++){
        printf("Quelle valeur pour x[%d]\n ",i);
        scanf("%lf", &valeur);                                                  // on remplie manuellement les x
        x[i] = valeur;
    }

    for(i=0;i<n;i++){
        printf("Quelle valeur pour y[%d]\n ",i);                               // on remplie manuellement les y
        scanf("%lf",&valeur);
        y[i]=valeur;
    }


    z = calculAB(x,y,n);                                                       // on calcule notre coef a et b pour pouvoir deduire ensuite la fonction
}
