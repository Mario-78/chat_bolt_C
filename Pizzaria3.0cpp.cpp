/* Trabalho AV1 2020.1  Teresina 02/10/20

Matéria algoritmos avançados

Professor Hilson Silva

Curso bacharelado em ciência da computação

turma 1001   turno manhã

                          Alunos

Mário José de Sousa ........................... Matrícula ..... 201903455987
Francisco Vitor Machado da Costa .............. Matrícula ..... 201902232372
Diego Xavier de Sousa ......................... Matrícula ..... 201808197372
Hélio de Sousa Campo .......................... Matrícula ..... 201902194276
Victor Orsano Vieira Castelo Branco ........... Matrícula ..... 201901298957
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void menu();
void criarAbrirArquivo(char diretorio[60]);
void leituraArquivo();
void fecharArquivo();
void cadProduto();
void cadMsnSystem0();
void cadMsnSystem1();
void mensegerUser();
void dataClient();
void saveArq(int cont);
void chatBot();
void imprimeDataClient();
void validaDados();
void msn0();
void msn1();
void msn2();
void msn3();
void msn4();
void msn5();
void msn6();
void msn7();
void procPedido();
void imprimeProcPed();
void imprimePed();



void delay(){
	
	int i = 0;
	printf("\n\n>>..");
	while(i!=1000000000){
		if(i%100000000 == 0){
			printf(">>..>>..");
		}
		i++;
	}
	printf(">>\n\n");
}

void menu(){

	setlocale(LC_ALL, "");
	printf("\t\t=======================================================================================\n");
	printf("\t\t|                            Pizzaria3.0/Menu de Sabores                              |\n");
	printf("\t\t|=====================================================================================|\n");
	printf("\t\t| Codigo |      Descrição            ||              Tabela de Preços                 |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   1    | Pizza Mussarela           ||  Codigo  |     Tamanho      |     Preço       |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   2    | Pizza Calabresa           ||     1    |        P         |   R$ 21.00      |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   3    | Pizza Portuguêsa          ||     2    |        M         |   R$ 35.00      |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   4    | Pizza Frango              ||     3    |        G         |   R$ 41.00      |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   5    | Pizza Frango c/ Catupiry  ||     4    |        GG        |   R$ 45.00      |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   6    | Pizza Frango c/ Requeijão ||                                               |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   7    | Pizza Frango c/ Chaddar   ||                                               |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   8    | Pizza Marguerita          ||                                               |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   9    | Pizza Atum                ||                                               |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t|   10   | Pizza Napolitana          ||                                               |\n");
	printf("\t\t|====================================||===============================================|\n");
	printf("\t\t=======================================================================================\n\n");	
}

//Declaração do ponteiro tipo file e variaveis globais.

FILE *arqtxt;

char msnUser[60],
	 
	 diretorio0[60] = {"C:\\Users\\Mario\\Documents\\cadCodPro.txt"},
	 diretorio1[60] = {"C:\\Users\\Mario\\Documents\\cadSaborPro.txt"},
	 diretorio2[60] = {"C:\\Users\\Mario\\Documents\\tabelaPreço.txt"},
	 diretorio3[60] = {"C:\\Users\\Mario\\Documents\\MsnSystemInit.txt"},
	 diretorio4[60] = {"C:\\Users\\Mario\\Documents\\MsnSystem.txt"};

int contProC = 0,
	contProS = 0,
	contPre = 0,
	contMsn0 = 0,
	contMsn1 = 0,
	qtd = 0,
	aux0 = 0,
	aux1 = 0,
	a = 0;
	
float soma,
	  precoP,
	  precoM,
	  precoG,
	  precoGG,
 	  obs;
//Declaração das struct's para carregar e descarregar dados dos e nos arquivos. 

typedef struct produto{
	char codigo[5],  
		 sabor[100],
		 preco[5];	
}produto;

produto pizza[20];

typedef struct cliente{
	char nome[100],
		 rua[100],
		 numero[10],
		 bairro[100],
		 cidade[100],
		 uf[10],
		 cep[10],
		 zona[10],
		 referencia[100];
}cliente;

cliente client[1];

typedef struct msnSystem{
	char msnInt0[100],
	     msnInt1[100];
}msnSystem;

msnSystem msnCad[100];

typedef struct pedido{
	char desc[100],
	     quant[100],
	     vU[100],
	     vTi[100],
	     vtp[100];
	
}pedido;

pedido ped[11];

//void responsável pela criação e gravação  de dados nos arquivos txt
//manipulados pelo APP.

void criarAbrirArquivo(char diretorio[60]){ 

	arqtxt = fopen(diretorio,"a+");
	if(arqtxt==0){
		  printf("\n\t\tErro ao criar ou abrir o arquivo.\n");
	} 
}

//Void responsável pela leitura de dados dos arquivos txt
//manipulados pelo APP.

void leituraArquivo(char diretorio[60]){
	
	arqtxt = fopen(diretorio, "r");
	if(arqtxt == 0){
		printf("\n\t\tErro ao abrir o arquivo para leitura.\n");
	}
}

//Void responsável pelo fechamento dos arquivos txt 
//manipulados pelo APP.

void fecharArquivo(){
	
	fclose(arqtxt);
	
}

//void responsável pela leitura e armazenamento de dados em buffer de memória
//com recurso da struct produto.

void cadProduto(){
	
	setlocale(LC_ALL, "");	
	
	char resposta;
	int x = 1,
		i = 0;
	contProC = 1;
		
	while(x!=0){
		printf("\n\t\tInforme o codigo do produto: \n\n");
		fflush(stdin);
  		fgets(pizza[i].codigo, 100, stdin);
		
		printf("\n\t\tInforme o sabor do produto: \n\n");
		fflush(stdin);
  		fgets(pizza[i].sabor, 40, stdin);
		   		
		resposta = '0';
		while(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
			fflush(stdin);
			printf("\n\t\tDigite (N) para finalizar ou (S) para continuar: \n");
			scanf("%c", &resposta);
			if(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
				printf("\n\t\tInforme uma alternativa válida!!!");
			}
		}
		
		if(resposta =='n' || resposta =='N'){
			x=0;
		}
		i++;
		contProC++;
		contProS++;
		system("cls");
	}
	saveArq(contProC);
	saveArq(contProS);
}

//void responsável pela leitura e armazenamento de dados em buffer de memória
//com recurso da struct produto.

void cadPreco(){
	
	setlocale(LC_ALL, "");
	
	printf("\n\t\tInforme o valor da pizza tamanho P: \n");
	scanf("%f", &precoP);
	printf("\n\t\tInforme o valor da pizza tamanho M: \n");
	scanf("%f", &precoM);
	printf("\n\t\tInforme o valor da pizza tamanho G: \n");
	scanf("%f", &precoG);
	printf("\n\t\tInforme o valor da pizza tamanho GG: \n");
	scanf("%f", &precoGG);
	contPre++;
	
	saveArq(contPre);
}

//void responsável pela leitura e armazenamento de dados em buffer de memória
//com recurso da struct msnSystem.

void cadMsnSystem0(){
	
	setlocale(LC_ALL, "");
	
	char resposta;
	int x = 1,
		i = 0;
		
	while(x!=0){

		printf("\n\t\tInforme a frase ou palavra para primeiro contato: \n\n");
		fflush(stdin);
		fgets(msnCad[i].msnInt0, 60, stdin);
		
		resposta = '0';
		while(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
			fflush(stdin);
			printf("\n\t\tDigite (N) para finalizar ou (S) para continuar: \n\n");
			scanf("\t\t%c", &resposta);
			if(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
				printf("\n\t\tInforme uma alternativa válida!!!");
			}
		}
		
		if(resposta =='n'|| resposta =='N'){
			x=0;
		}
		
		i++;
		contMsn0++;
		system("cls");
	}
	saveArq(contMsn0);
}
	
//void responsável pela leitura e armazenamento de dados temporarios
//com recurso da struct msnSystem.
	
	
void cadMsnSystem1(){
	
	setlocale(LC_ALL, "");
	
	char resposta;
	int x = 1,
		i = 0;
		
		
	while(x!=0){

		printf("\n\t\tInforme a frase ou palavra para primeiro contato: \n\n");
		fflush(stdin);
		fgets(msnCad[i].msnInt1, 60, stdin);
		
		resposta = '0';
		while(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
			fflush(stdin);
			printf("\n\t\tDigite (N) para finalizar ou (S) para continuar: \n");
			scanf("%c", &resposta);
			if(resposta != 'n' && resposta != 'N' && resposta != 's' && resposta != 'S'){
				printf("\n\t\tInforme uma alternativa válida!!!");
			}
		}
		
		if(resposta =='n'|| resposta =='N'){
			x=0;
		}
		
		i++;
		contMsn1++;
		system("cls");
	}
	saveArq(contMsn1);
}

//Void responsável pela leitura das mensagens enviadas pelos usuários	

void mensegerUser(){
	
	setlocale(LC_ALL, "");
	
	printf("\n\t\tAguardando mensagem do usuário!!!\n\n");
	fflush(stdin);
 	fgets(msnUser, 60,stdin);
}

//void responsável pela entrada de dados em buffer de armazenamento
//com recurso da struct cliente.

void dataClient(){

	setlocale(LC_ALL, "");
	
	printf("\n\t\tInforme os dados do endereço para entrega.\n\n");
	printf("\n\t\tInforme o nome da rua: \n\n");
	fflush(stdin);
	fgets(client[0].rua, 60, stdin);		
	
	printf("\n\t\tInforme o número da casa: \n\n");
	fflush(stdin);
	fgets(client[0].numero, 60, stdin);
		
	printf("\n\t\tInforme o nome do bairo: \n\n");
	fflush(stdin);
	fgets(client[0].bairro, 60, stdin);
	
	printf("\n\t\tInforme o nome da cidade: \n\n");
	fflush(stdin);
	fgets(client[0].cidade, 60, stdin);
	
	printf("\n\t\tInforme o nome da sigla do estado: \n\n");
	fflush(stdin);
	fgets(client[0].uf, 60, stdin);
	
	printf("\n\t\tInforme o CEP da rua: \n\n");
	fflush(stdin);
	fgets(client[0].cep, 60, stdin);
	
	printf("\n\t\tInforme o nome da zona urbana: \n\n");
	fflush(stdin);
	fgets(client[0].zona, 60, stdin);
	
	printf("\n\t\tInforme o nome de um ponto de referência: \n\n");
	fflush(stdin);
	fgets(client[0].referencia, 60, stdin);

}

//Void responsável saída formatada de dados armazenadas em buffer de memória
//com recurso da struct cliente.

void imprimeDataClient(){

	setlocale(LC_ALL, "");
	printf("\t\t1 Rua : ...................... %s", client[0].rua);
	printf("\t\t2 Número : ................... %s", client[0].numero);
	printf("\t\t3 Bairro : ................... %s", client[0].bairro);
	printf("\t\t4 Cidade : ................... %s", client[0].cidade);
	printf("\t\t5 UF : ....................... %s", client[0].uf);
	printf("\t\t6 CEP : ...................... %s", client[0].uf);
	printf("\t\t7 Zona : ..................... %s", client[0].zona);
	printf("\t\t8 Ponto de referência : ...... %s", client[0].referencia);
}

//Void responsável validação de dados armazenadas em buffer de memória
//com recurso da struct cliente.

void validaDados(){
	int i = 0;
	
	i = strlen(client[0].rua);
	if(i == 1){
		printf("\t\t%s\t\to item 1 não foi informado, favor informe. \n\n",client[0].nome);
		fflush(stdin);
		fgets(client[0].rua, 60, stdin);
	}
	i = strlen(client[0].numero);
	if(i == 1){
		printf("\n\t\t%s\t\to item 2 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].numero, 60, stdin);
	}
	i = strlen(client[0].bairro);
	if(i == 1){
		printf("\n\t\t%s\t\to item 3 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].bairro, 60, stdin);
	}
	i = strlen(client[0].cidade);
	if(i == 1){
		printf("\n\t\t%s\t\to item 4 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].cidade, 60, stdin);
	}
	i = strlen(client[0].uf);
	if(i == 1){
		printf("\n\t\t%s\t\to item 5 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].uf, 60, stdin);
	}
	i = strlen(client[0].cep);
	if(i == 1){
		printf("\n\t\t%s\t\to item 6 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].cep, 60, stdin);
	}
	i = strlen(client[0].zona);
	if(i == 1){
		printf("\n\t\t%s\t\to item 7 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].zona, 60, stdin);
	}
	i = strlen(client[0].referencia);
	if(i == 1){
		printf("\n\t\t%s\t\to item 8 não foi informado, favor informe. \n",client[0].nome);
		fflush(stdin);
		fgets(client[0].referencia, 60, stdin);
	}
}

//Void responsável pela reinicialização das vriáveis após 
void descarregaDados(){
	
	soma = 0.0;
	a = 0;
	obs = 0.0;
	fgets(client[0].nome, 100, NULL);
	fgets(client[0].bairro, 100, NULL);
	fgets(client[0].cidade, 100, NULL);
	fgets(client[0].referencia, 100, NULL);
	fgets(client[0].cep, 10, NULL);
	fgets(client[0].numero, 10, NULL);
	fgets(client[0].uf, 10, NULL);
	fgets(client[0].zona, 10, NULL);	
	
}

//Void responsável pela gravação de dados nos arquivos txt manipulados pelo APP
//com recurso das struct's produto e msnSystem.	
	
void saveArq(int cont){
	setlocale(LC_ALL, "");
	int i;
	if(cont == contProC){
		
		criarAbrirArquivo(diretorio0);
		
		for(i=0; i<cont; i++){
			fprintf(arqtxt, "%s",pizza[i].codigo);
		}
		fecharArquivo();
	}
		
	
	if(cont == contProS){
		
		criarAbrirArquivo(diretorio1);
		
		for(i=0; i<cont; i++){
			fprintf(arqtxt, "%s",pizza[i].sabor);
		}
		fecharArquivo();
	}
		
		
	if(cont == contPre){
		
		criarAbrirArquivo(diretorio2);
		
		fprintf(arqtxt, "%.2f\n", precoP);
		fprintf(arqtxt, "%.2f\n", precoM);
		fprintf(arqtxt, "%.2f\n", precoG);
		fprintf(arqtxt, "%.2f\n", precoGG);
		
		fecharArquivo();
	}
	
	if(cont == contMsn0){
		
		criarAbrirArquivo(diretorio3);
	 	for(i=0; i<cont; i++){
	 		fprintf(arqtxt, "%s", msnCad[i].msnInt0);
		}
		fecharArquivo(); 
	}else 
	
	if(cont == contMsn1){	
		criarAbrirArquivo(diretorio4);
	 	for(i=0; i<cont; i++){
	 		fprintf(arqtxt, "%s", msnCad[i].msnInt1);
		}
		fecharArquivo(); 
	}	
}

//Void responsável pela leitura dos arquivos txt, carregamento da  
//struct produto com dados dos arquivos txt e realização de calculos  
//matemáticos com gravação dos resultados do processamento em buffer
//de memória com recurso da struct pedido.

void procPedido(){

	setlocale(LC_ALL, "");
	char c[100],
		 s[10];
	float valor, vti;
	int i;
	contProC = 0;
	contProS = 0;
	contPre = 0;
	
		
	leituraArquivo(diretorio1); 
	while(fgets(c, 100, arqtxt) != NULL){
		strcpy(pizza[contProS].sabor, c);
		contProS++;
	}
	fecharArquivo();
	
	leituraArquivo(diretorio2); 
	while(fgets(c, 100, arqtxt) != NULL){
		strcpy(pizza[contPre].preco, c);
		contPre++;
	}
	fecharArquivo();
	
		valor = atof(pizza[aux1-1].preco);
		vti = qtd*valor;
		soma += vti;
		sprintf(ped[a].desc, "Descrição ................... : %d - %s", aux0, pizza[aux0 -1].sabor);
		sprintf(ped[a].quant, "Quantidade .................. : %d Unidades\n", qtd);
		sprintf(ped[a].vU, "Valor unitário .............. : %.2f\n", valor);
		sprintf(ped[a].vTi, "Valor total do item pedido .. : R$ %.2f\n", vti);
		sprintf(ped[0].vtp, "Valor total geral pedido .... : R$ %.2f\n", soma);
	
		a++;
}

//Void responsável pela saída formatada dos dados gravados em buffer
//de memória com recurso da struct pedido.

void imprimeProcPed(){
	int i;
	
	for(i=0; i<a; i++){
		if(a>0){
			printf("\n\t\tItem ............. %d\n", i+1);
		}
		printf("\t\t%s", ped[i].desc);
		printf("\t\t%s", ped[i].quant);
		printf("\t\t%s", ped[i].vU);
		printf("\t\t%s", ped[i].vTi);
		if(i+1 == a){
			printf("\n\t\t%s", ped[0].vtp);
		}
	}
	if(obs != 0){
			printf("\t\tObservação .................. : Troco para R$ %.2f", obs);
			
		}
}

//Void responsável pela saída formatada de dados processados

void imprimePed(){
	
	setlocale(LC_ALL, "");
	int i = 1;
	
	printf("\n");
	printf("\t\t**********************************************************\n");
	printf("\t\t            CANAL VIRTUAL DA PIZZARIA 3.0.COM             \n");
	printf("\t\t**********************************************************\n");
	printf("\t\t------------------  DADOS DO CLIENTE  --------------------\n");
	printf("\t\t**********************************************************\n");
	printf("\t\tCliente ........... : %s                                  ",client[0].nome);
	printf("\n\t\t**********************************************************\n");
	printf("\t\t------------------  DADOS DO ENDEREÇO --------------------\n");
	imprimeDataClient();
	printf("\t\t-------------------  DADOS DO PEDIDO ---------------------\n");
	imprimeProcPed();
	printf("\n\t\t**********************************************************\n");
}

//Os voides a seguir (msn0(); - msn7();) simulam o passo a passo de  um
//diálogo entre pessoas.

void msn0(){
	setlocale(LC_ALL, "");
	printf("\n\t\tSeja bem vindo ao nosso canal de auto atendimento digital!!\n\n");	
	printf("\n\t\tMe informe seu nome: \n");
	fflush(stdin);
	fgets(client[0].nome, 100, stdin);
	delay();
	printf("\n\t\tEm que posso te ajudar?\n");
}

void msn1(){
	setlocale(LC_ALL, "");
	printf("\n\t\tSegue nosso menu, %s", client[0].nome);
	delay();
	menu();
}

void msn2(){
	setlocale(LC_ALL, "");
	printf("\n\t\tInforme o codigo do sabor da pizza: \n");
	scanf("%d", &aux0);
	printf("\n\t\tInforme o codigo do tamanho da pizza: \n");
	scanf("%d", &aux1);
	printf("\n\t\tInforme quantas unidades: \n");
	scanf("%d", &qtd);
}

void msn3(){
	
	setlocale(LC_ALL, "");
	delay();
	fflush(stdin);
	printf("\n\t\t%s\t\tdeseja acrescentar mais algum item? \n", client[0].nome);
	
}

void msn4(){
	
	printf("\n\t\t%s\t\tpor gentileza, aguarde enquanto processamos seu pedido!\n", client[0].nome);
	delay();
	printf("\n");
	delay();
	printf("\n\t\t%s\t\tpor gentileza, confira seu pedido!\n", client[0].nome);
	imprimePed();
	printf("\n\t\tPosso confirmar seu pedido?");
	printf("\n\t\tDigite (sim), se estiver tudo certo.\n");
}


void msn5(){
	
	printf("\n\t\t%s\t\tnecessita de troco pra uma nota de alto valor?\n", client[0].nome);
	
}

void msn6(){
	printf("\n\t\t%s\t\tInforme o valor: \n", client[0].nome);
}

void msn7(){
	printf("\n\t\t%s\t\tseu pedido chegará em 40 minutos\n", client[0].nome);
	printf("\n\t\tA pizzaria 3.0.com, agradece a preferêcia!!!\n");
	printf("\n\t\tVolte Sempre!!!\n");
}

//Void responsável pela leitura dos arquivos txt, carregamento da 
//struct msnSystem com dados dos arquivos txt e coordenar as chamadas 
//das respostas em sintonia com a leitura das entradas para simular um
// diálogo com o usuário.

void chatBot(){
	
	setlocale(LC_ALL, "");
	
	int comp = 0, 
		contato = 0;
	char aux0[100];
	char aux1[100];
	
	leituraArquivo(diretorio3);	
	while(comp == 0){
		
		mensegerUser();
		delay();
		
		while(fgets(aux0, 100, arqtxt) != NULL ){
			
			if(strcmp(aux0, msnUser)==0){
				comp = 1;			
			}
			if(contato == 0 && comp == 1){
				msn0();	
				contato++;
				mensegerUser();
				delay();
			}
		}
	fecharArquivo();
	
	leituraArquivo(diretorio4);	
			
		while(fgets(aux1, 100, arqtxt) != NULL ){
			if(strcmp(aux1, msnUser)==0){
			comp = 1;			
			}
			if(contato == 0 && comp == 1){
				msn0();
				mensegerUser();
				delay();
				contato++;
				msn1();
				msn2();
				procPedido();
				contato++;
			}else if(contato ==1 && comp == 1){
				msn1();
				msn2();
				procPedido();
				contato++;	
			}					 
		}
		if(comp == 0){
			printf("\n\t\tJoe no te conpreendo muchacho(a)!!!!\n\n");
			chatBot();
		}
	
	fecharArquivo();
	}
	
	dataClient();
	validaDados();
	
	msn3();
	mensegerUser();
	delay();
	while(strcmp(msnUser, "sim") == 1){
		
		msn1();
		msn2();
		procPedido();
		msn3();
		mensegerUser();		
	}

	msn4();

	mensegerUser();
	if(strcmp(msnUser, "sim")==1){
		msn5();
		mensegerUser();
		delay();
		if(strcmp(msnUser, "sim")==1){
			msn6();
			scanf("%f", &obs);
			delay();
			
		}else{
			imprimePed();
		}		
	}
	imprimePed();
	msn7();
	descarregaDados();    
	chatBot();
}

// Função principal do APP.
	
int main(){
	
	setlocale(LC_ALL, "");

	int y, op;
	while(y!=1 && y!=2){
		printf("\n\t\tPara dar start no chat bolt digite (1)\n\n");
		printf("\n\t\tPara menu de cadastros digite (2)\n\n");
		scanf("%d", &y);
		if(y!=1 && y!=2){
      		printf("\n\t\tDados incorretos!!!");	
		}
	}
	
	system ("cls");
	
	if(y==1){
		chatBot();
	}else{
		
		while(op!=0){
			printf("\n\t\tPara cadastrar produtos digite ----------------------------------------- (1)\n");
			printf("\n\t\tPara cadastrar mensagens de primeiro contato digite -------------------- (2)\n");
			printf("\n\t\tPara cadastrar mensagens de possíveis solicitações de clientes digite -- (3)\n");
			printf("\n\t\tPara cadastrar os preços dos produtos digite --------------------------- (4)\n");
			printf("\n\t\tPara sair deste menu digite -------------------------------------------- (0)\n");
			scanf("%d", &op);
			
			system ("cls");
		
			switch(op){
				case 0:{
					main();
					break;
				}
				case 1:{
					cadProduto();
					break;
				}
				case 2:{
					cadMsnSystem0();
					break;
				}
				case 3:{
					cadMsnSystem1();
					break;
				}
				
				case 4:{
					cadPreco();
					break;
				}
				case 5:{
					return 0;
					break;
				}
				default :{
					printf("\n\t\tOpção inválida!!!!");
					break;
				}
			}
		}
	}
	
}


