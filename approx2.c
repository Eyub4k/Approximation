#include <stdio.h>
#include <stdlib.h>
#include <math.h>                                      // pour pouvoir avoir un ajustement exponentiel, nousa vons vue dans les methode qu'il faut mettre les y en ln

typedef struct{                                        //  et ainsi pour avoir y = ce^(dx) , on sait que c vaut exp(b) et d vaut a;
    double c;
    double d;
}coeff;                    //on definit une structure pour pouvoir avoir en sortie notre c et d en sortie lors du calcule d'approxiamtion vue dans l'explication des methodes
                          // donc on definit double c et d, on definit ce type car nous pouvons avoir  un entier ou un float

coeff calculCD (double *x, double *y,int n){
    double sommeX = 0;                             // on a donc en entrée x et y definit dans les jeux d'essaie et n qui definit combien de point nous avons
                                                   // initialisation de la Somme ainsi que du produit des x et y à 0
    double sommeY = 0;
    double produitXY =0;
    int i, j;                         // definition de i,j et de a et b
    double a, b;
    coeff z;
    for (i=0; i<n; i++){
        sommeX += (x[i]);                     // calcule des sommes de x et (ln de y) puis les produit des x et y
        sommeY += log(y[i]);
        produitXY += (x[i] * y[i]);
    }
    printf("x[ ] : ");
    for (i=0; i<n; i++){
        printf("%lf ", x[i]);                // affiche des nouveaux tab de x et y
    }
    printf("\ny[ ] : ");
    for (i=0; i<n; i++){
        printf("%lf ", y[i]);
    }
    a = ( ( sommeX * sommeY )/ n ) - produitXY;            // premiere partie du calcule de a (numerateur) avec la methode vue dans les presentations

    printf("\n");
    printf("sommeX = %lf\n", sommeX);
    printf("sommeY = %lf\n", sommeY);
    printf("produitXY = %lf\n", produitXY);
    printf("a = %lf", a);

    a = a / ( ( (sommeX * sommeX)/n ) - (sommeX * sommeX) );       // on termine le calcule de a en ajoutant le denominateur vue dans la presentation des methodes
    printf("\nd = %lf", a);
    z.d = a;                                                 // affectaztion de a dans d (methode dans les presentations)

    b = ( sommeY / n) - ( ( z.d * sommeX )/n );               // calcule de b avec ola methode vue dans les presentations des methodes avec d qui vaut a
    printf("\nb = %lf", b);
    z.c = exp(b);                                              // et affection de exponentiel de b dans c ( expliqué dans les presentations)
    printf("\nc = %lf", z.c);

    return z;
}



int main(){

    int n, i;
    printf("Combien de points ?");
    scanf("%d",&n);
    double *x = malloc ( (n-1)*sizeof(double));
    double *y = malloc ( (n-1)*sizeof(double));
    double valeur;                                                    // on va creer des tableau de n taille demandé dans les jeux d'essaies
    coeff z;

    for(i = 0 ; i<n ; i++){
        printf("Quelle valeur pour x[%d]\n ",i);
        scanf("%lf", &valeur);
        x[i] = valeur;                                            // on remplie manuellement les x
    }

    for(i=0;i<n;i++){
        printf("Quelle valeur pour y[%d]\n ",i);
        scanf("%lf",&valeur);                                       // on remplie manuellement les y
        y[i]=valeur;
    }


    z = calculCD(x,y,n);                                              // on calcule notre coef c et d pour pouvoir deduire ensuite la fonction
}
