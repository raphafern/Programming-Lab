#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gera_frase(char s1[]);
int compara_string(char s1[], char s2[]);
void gera_filho(char s1[]);
void involucao(char s1[], char s2[]);
char *dupcad(char *s);
struct nodot *lista(struct nodot*, char *);
struct nodot {     	/* o nodo da árvore: */
	char *palavra; /* aponta para o texto */
	int contador; /* número da ocorrências */
	struct nodot *prox;
};
void imprlista(struct nodot *);
int main()
{
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	char frase[26];
	gera_frase(frase);
	printf("A pontuacao inicial e:\n%d\n", compara_string(frase,meta));
	printf("-------------------------\n");
	gera_filho(frase);
	return 0;
}

void gera_frase(char frase[]){
	int i = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (i=0; i< 26; i++){
		frase[i] = letras[ rand() % strlen(letras)];
	}
	frase[i] = '\0';
	printf("A frase gerada e:\n%s\n", frase);	
}
	
int compara_string(char s1[], char s2[]){
	int cont = 0;
	int i = 0;
    for (i=0; i< 26; i++){
			if (s1[i] == s2[i])
			cont++;
		}
    return cont;
}

void involucao(char s1[], char s2[]){
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	if (compara_string(s1,meta) >= compara_string(s2,meta)){
		printf("INVOLUCAO!\n");
	}
}

struct nodot *aloca(void)
{
    return (struct nodot *) malloc(sizeof(struct nodot));
}


struct nodot *lista(struct nodot *p, char *w)
{
    int cond;

    if (p == NULL) {     /* uma nova palavra chegou */
        p = aloca();    /* cria um novo nodo */
        p->palavra = dupcad(w);
        p->contador = 1;
        p->prox = NULL;
    } else if ((cond = strcmp(w, p->palavra)) == 0)
        p->contador++;      /* palavra repetida */
    else
        p->prox = lista(p->prox, w);
    return p;
}

void imprlista(struct nodot *p)
{
    if (p != NULL) {
        imprlista(p->prox);
        printf("%s\n", p->palavra);
    }
}

char *dupcad(char *s) /* cria uma duplicata de s */
{
	char *p;

	p = (char *) malloc(strlen(s)+1);  /* +1 para '\0' */
	if (p!= NULL)
		strcpy(p,s);
	return p;
}

void gera_filho(char s[]){
	int i = 0;
	int j = 0;
  struct nodot *p;
	int aux = 0;
	char maior[100];
	int cria = 0;
	int contador[100];
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	char filho[100][26];
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	strcpy(maior,"0000000000000000000000000");
	for (j=0; j<100; j++){
		strcpy(filho[j],s);
		for (i=0; i<26; i++){
			aux = rand() % 100;
			if (aux < 5){
				filho[j][i] =  letras[ rand() % strlen(letras)];
			}
		}	
		printf("O filho(%d) gerado e:\n%s\n", j, filho[j]);
		contador[j] = compara_string(filho[j],meta);
		//printf("A pontuacao e:\n%d\n", contador[j]);
		
		printf("-------------------------\n");
			if (contador[j] > compara_string(maior,meta)){
				strcpy(maior, filho[j]);
				cria = j;
			}
	}
	filho[j][i] = '\0';
	printf("A nova mae sera:\n%s\n", maior);
	//printf("Que e o filho numero:\n%d\n", cria);
	//printf("Com a pontuacao de:\n%d\n", compara_string(maior,meta));
	involucao(s,maior);
  struct nodot *lista(struct nodot *p, char *maior);
	if(compara_string(maior,meta) != 25){
		gera_filho(maior);
	}
  imprlista(p);
}
