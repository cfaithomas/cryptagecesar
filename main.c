
#include <stdio.h>
#include <string.h>

int decalage;
char direction;
char chainesaisie[255];
char chainecrypted[255];
char chaineuncrypted[255];
char* saisirchaine();
int* saisirdecalage();
char* saisirdirection();
char* crypt_withcesar(char[],int *,char*);
char* uncrypt_withcesar(char[],int *,char*);
void afficherchaine(char []);
char *saisirchaine() {

    printf("Veuillez saisir une chaine");
    scanf(" %[^\n]s",&chainesaisie);
    return &chainesaisie;
}

int *saisirdecalage() {
    printf("Veuillez saisir le décalage");
    scanf("%d",&decalage);
    return &decalage;
}

char *saisirdirection() {
    printf("Veuillez saisir la direction");
    scanf(" %c",&direction);
    return &direction;
}

char* crypt_withcesar(char chaine[], int *decalage, char *direction) {

    if(*direction=='d')
    {
        for(int i=0;i<strlen(chaine);i++)
        {

            chainecrypted[i]=chaine[i]+*decalage;
        }
    }
    else{
        for(int i=0;i<strlen(chaine);i++)
        {

            chainecrypted[i]=chaine[i]-*decalage;
        }
    }
    return chainecrypted;
}

char *uncrypt_withcesar(char chaine[], int *decalage, char *direction) {

    if(*direction=='d')
    {
        for(int i=0;i<strlen(chaine);i++)
        {

            chaineuncrypted[i]=chaine[i]-*decalage;
        }
    }
    else{
        for(int i=0;i<strlen(chaine);i++)
        {

            chaineuncrypted[i]=chaine[i]+*decalage;
        }
    }
    return chaineuncrypted;
}

void afficherchaine(char chaine[]) {

    printf("%s\n",chaine);

}


int main() {

    afficherchaine(crypt_withcesar(saisirchaine(),saisirdecalage(),saisirdirection()));

    afficherchaine(uncrypt_withcesar(saisirchaine(),saisirdecalage(),saisirdirection()));
    return 0;
}