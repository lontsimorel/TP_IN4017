#include <iostream>
#define n 8 //taille de la matrice X
#define m 8 //taille de la matrice Y

//
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}


int main (){
    int x[]={0,1,2,3,4,5,5};
    int y[]={0,1,5,6,2,3,5};
   /* int x[]={0,7,1,2,6,3,6,1};
    int y[]={0,2,4,5,3,8,1,5};*/


    int c[n][m],e[n][m ]; // C  matrice pour l'algorithme  e matrice pour exploitation du resultat
    //initialisation des matrices suivant laxe des i
    for (int j = 0; j < n; j++)
    {
        c[0][j]=0;
        e[0][j]=2;
    }
     //initialisation des matrices suivant laxe des j
    for (int i = 0; i < n; i++)
    {
        c[i][0]=0;

    }

    // Algorithme proprement dit
    // Concernant la matrice e on attribue la valeur 0 pour indiquer la fleche inclin�e 1 pour la fleche haut et -1 pour gauche

    for (int i = 1;i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1] +1;
                e[i][j]=0;

            }
            else if(c[i-1][j]>=c[i][j-1]){
                //c[i][j]=max(c[i-1][j],c[i][j-1]);
                c[i][j]=c[i-1][j];
                e[i][j]=1;
            }
            else{
                c[i][j]=c[i][j-1];
                e[i][j]=-1;
            }
        }
    }

    //L exploitation
    // c[n-1][m-1]  Cest le resultat

    int i=n-1,j=m-1,k=c[n-1][m-1]-1;
    int tab[c[n-1][m-1]];// le tableau pour afficher en ordtre
    while(c[i][j]!=0)
    {
        if(e[i][j]==0)
        {
            tab[k]=i;
            k=k-1;
            i=i-1;
            j=j-1;
        }
        else if(e[i][j]==1)
        {
            i=i-1;
        }
         else if(e[i][j]==-1)
        {
            j=j-1;
        }
    }
    for(int t=0;t<c[n-1][m-1];t++)
    {
        std::cout<<x[tab[t]];
    }

    return 0;

}
