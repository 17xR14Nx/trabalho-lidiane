#include<stdio.h>
#include<string.h>
#include<locale.h>

struct {

char nome[20];
char matricula[20];
char cargo[20];

}cadastro;
void cadastrar();
void listar();

main(){

int menu;

do{
printf("Digite 1 - cadastrar.\n");
printf("Digite 2 - listar.\n");
printf("Digite 0 - sair.\n");
scanf("%d", &menu);
switch(menu){
case 1:
    cadastrar();
    break;
case 2:
    listar();
    break;
}
} while(menu != 0);

return 0;
}

void cadastrar(){
 FILE *arquivo;
    int resp;
    char virgula[100];

do{

        setlocale(LC_ALL,"Portuguese");
    strcpy(virgula,"");
  arquivo = fopen("Arquivo.txt", "a");

  printf("Digite o número da matrícula: \n");
  scanf("%s", &cadastro.matricula);
  strcat(virgula,cadastro.matricula);
  strcat(virgula,",");
  printf("Digite o nome do funcionário: \n");
  scanf("%s", &cadastro.nome);
  strcat(virgula,cadastro.nome);
  strcat(virgula,",");
  printf("Digite o nome da cargo: \n");
  scanf("%s", &cadastro.cargo);
  strcat(virgula,cadastro.cargo);
  strcat(virgula,"\n");

  fprintf(arquivo,"%s", virgula);
  fclose(arquivo);

  printf("Deseja cadastrar mais usuários?\n");
  printf("1 - Sim 2 - Não\n");
  scanf("%d", &resp);


}while(resp == 1);

}

void listar(){
FILE *arquivo;

char linha[100];
arquivo = fopen("Arquivo.txt", "r");
while(fgets(linha, 100, arquivo) != NULL){
scanf(arquivo,"%s", linha);

char matricula[100];
char nome[100];
char cargo[100];

printf("Matricula: %s\n",strtok(linha,","));
printf("NOME: %s\n",strtok(NULL,","));
printf("CARGO: %s\n\n",strtok(NULL,"\n"));

}
fclose(arquivo);
}
