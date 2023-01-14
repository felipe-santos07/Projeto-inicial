#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome [100];
	int idade;
	float salario;
}funcionario;

int main(int argc, char *argv[]) {
	funcionario *empresa;
	int i,quant,menoridade,maioridade=0;
	char nomeidade[100],nomesalario[100];
	char nomeidademaior[100],nomesalariomenor[100];
	float maiorsalario=0,menorsalario;
	printf ("Digite a quant.de funcionarios: \n");
	scanf("%i",&quant);
	empresa=(funcionario*)malloc(
				sizeof(funcionario)*quant);
	for(i=0;i<quant;i++){
		printf("Digite o nome: \n");
		fflush (stdin);
		gets (empresa [i].nome);
		printf("Digite a idade: \n");
		scanf ("%i" ,&empresa [i].idade);
		printf("Digite o salario: \n");	
		scanf ("%f" ,&empresa [i].salario);
					
				
	}
	for (i=0;i<quant;i++){
		printf("%s\t",empresa [i].nome);
		printf("%i\t",empresa [i].idade);
		printf("%.2f\n",empresa [i].salario);
		if(empresa[i].salario>maiorsalario){
			maiorsalario=empresa[i].salario;
			strcpy (nomesalario,empresa[i].nome);
		}
		if(empresa[i].idade>maioridade){
			maioridade=empresa[i].idade;
			strcpy (nomeidademaior,empresa[i].nome);
			
		}
		if (i==0){
			menoridade=empresa[0].idade;
			menorsalario=empresa[0].salario;
			strcpy (nomesalariomenor,empresa[0].nome);
			strcpy (nomeidade,empresa[0].nome);
		}
		if(empresa[i].idade<menoridade){
			menoridade=empresa[i].idade;
			strcpy(nomeidade,empresa[i].nome);
		}
		if (empresa [i].salario<menorsalario){
			menorsalario=empresa[i].salario;
			strcpy (nomesalariomenor,empresa[i].nome);
		}
	}
	printf("%s tem o maior salario %.2f\n", nomesalario, maiorsalario);
	printf ("%s tem o menor salario %.2f\n",nomesalariomenor,menorsalario);
	printf("%s e o mais novo tendo %i anos\n", nomeidade,menoridade);
	printf("%s e o mais velho tem %i anos \n",nomeidademaior,maioridade);
	free (empresa);
	return 0;
}

