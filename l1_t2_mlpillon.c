//Mariana Lopes Pillon mlpillon 

//comentei para propositos de debug quando estava tudo dando errado

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

int seleciona_jogador(int ug){
	int a = rand() % 2;
	
	//ug = ultimo ganhador. o que ganhou por ultimo joga na proxima rodada
	if((ug == 1) || (ug == 2)) return ug;
	
	//se for a primeira partida OU se o resultado tiver sido um empate, gera um jogador para iniciar
	else{
		if(a == 1) return 1;
		else return 2;
	}
}

bool checa_desistencia(char j, int vez){
	if(j == 3){ //checa apenas o segundo indice.
		printf("\nPlayer %d, voc� desistiu do jogo!", vez);
		return true;
	}
	else return false;
}

void monta_tabuleiro(int l, int c, char t[l][c]){
	printf("\n\n-------------\n");
	printf("|   |   |   |\n");
	printf("| %c | %c | %c |\n", t[0][0], t[0][1], t[0][2]);
	printf("|   |   |   |\n");
	printf("----+---+----\n");
	printf("|   |   |   |\n");
	printf("| %c | %c | %c |\n", t[1][0], t[1][1], t[1][2]);
	printf("|   |   |   |\n");
	printf("----+---+----\n");
	printf("|   |   |   |\n");
	printf("| %c | %c | %c |\n", t[2][0], t[2][1], t[2][2]);
	printf("|   |   |   |\n");
	printf("-------------\n");
}

void mostra_indices(void){
	printf("\n�ndices:"); //por hora, como as jogadas sao feitas
	printf("\n00 | 01 | 02\n10 | 11 | 12\n20 | 21 | 22\n\n");
}

bool checa_posicao(int l, int c, char t[l][c], int i, int j){		
	if((i != 2) && (i != 1) && (i != 0)){
		printf("\nPrimeiro �ndice inv�lido.");
		return false;
	}
	
	if((j != 2) && (j != 1) && (j != 0)){
		printf("\nSegundo �ndice inv�lido.");
		return false;
	} //checa se nao foi digitado algo maluco
	
	if(t[i][j] == ' '){
		return true;
	}else{
		printf("\nEssa posi��o j� est� preenchida, tente novamente.\n");
		return false;
	}
}

bool checa_escolha(int escolha){
	if((escolha == 'o') || (escolha == 'O') || (escolha == 'x') || (escolha == 'X')) return true;
	else return false;
}

int checa_vitoria(int l, int c, char t[l][c], int vez){
	int i, j;
	
	//horizontal
	for(i = 0; i < 3; i++){
		if((t[i][0] == t[i][1]) && (t[i][0] == t[i][2]) && (t[i][0] != ' ')) return vez;
	}
	
	//vertical
	for(i = 0; i < 3; i++){
		if((t[0][i] == t[1][i]) && (t[0][i] == t[2][i]) && (t[0][i] != ' ')) return vez;
	}
	
	//diagonal principal
	if((t[0][0] == t[1][1]) && (t[0][0] == t[2][2]) && (t[0][0] != ' ')) return vez;
	
	//diagonal secundaria
	if((t[0][2] == t[1][1]) && (t[0][2] == t[2][0]) && (t[0][2] != ' ')) return vez;
	
	return 0;
}

void exibe_placar(int v_p1, int v_p2, int emp){
	printf("\n\n##### PLACAR #####\n");
	printf("Total de vit�rias:");
	printf("\n\tPlayer 1: %d", v_p1);
	printf("\n\tPlayer 2: %d", v_p2);
	printf("\nTotal de empates: %d", emp);
}

int realiza_partida(int vez){
	char tabuleiro[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	
	char escolha, simbolo[2];
	int vitoria = 0, i, j, jogadas = 0;
	bool desistiu, p_valida;
	
	printf("\nLembre-se, o programa preenche automaticamente os quadrados ap�s ser digitada o �ndice.\n");
	printf("O jogo � disposto da seguinte forma: ");
	mostra_indices();
	printf("Voc� pode apertar 3 ao inv�s do segundo �ndice para desistir.\n");
	printf("Player %d, voc� prefere jogar com X ou O? ", vez);
	
	do{
		scanf("%c", &escolha);
	}while(checa_escolha(escolha) == false);
	
	//achei mais intuitivo fazer o jogo "escrever pra ti" X ou O apos escolhido o que cada jogador usa
	//ao inves de se digitarem 3 inputs (indices + x ou o) e se fazerem 2 checagens
	if((escolha == 'x') || (escolha == 'X')){
		if(vez == 1){
			simbolo[0] = 'X';
			simbolo[1] = 'O';
		}else{
			simbolo[1] = 'X'; 
			simbolo[0] = 'O';
		}
	}else{
		if(vez == 2){
			simbolo[1] = 'X';
			simbolo[0] = 'O';
		}else{
			simbolo[0] = 'X';
			simbolo[1] = 'O';
		}
	}
	
	do{
		monta_tabuleiro(3, 3, tabuleiro);
		mostra_indices();
		
		printf("Vez do player %d", vez);
		
		do{
			printf("\nDigite a posi��o de suas jogadas.\n�ndice 1: ");
			scanf("%d", &i);
			printf("�ndice 2: ");
			scanf("%d", &j);

			desistiu = checa_desistencia(j, vez);
			if(desistiu == true) break;
			p_valida = checa_posicao(3, 3, tabuleiro, i, j); //posicao valida
		}while(p_valida == false);
		
		if(desistiu == true){
			//quando alguem desiste, o outro jogador ganha
			if(vez == 1) vitoria = 2;
			else vitoria = 1;
			
			printf("\nO tabuleiro final �: ");
			monta_tabuleiro(3, 3, tabuleiro);
			break;
		}
		
		tabuleiro[i][j] = simbolo[vez-1]; //preenchendo o tabuleiro
		
		vitoria = checa_vitoria(3, 3, tabuleiro, vez);
		
		//troca de quem eh a vez
		if(vez == 1) vez++;
		else vez--;
		
		jogadas++;
		if(jogadas == 9){ //nao h� mais posi��es no tabuleiro
			vitoria = checa_vitoria(3, 3, tabuleiro, vez);
		
			if(vitoria == 0) vitoria = 3; //declara empate e sai do laco daqui a pouco
		}
		
	}while(vitoria == 0);
	
	if(vitoria == 3){
		printf("\nEmpate!");
	}else{
		printf("\nVit�ria do player %d!", vitoria);
	}
	
	printf("\n\nTabuleiro final: ");
	monta_tabuleiro(3, 3, tabuleiro);
	
	return vitoria; //nunca retorna 0
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int continuar, ultimo_ganhador = 0, vez;
	int v_p1 = 0, v_p2 = 0, emp = 0;
	
	printf("Sejam bem-vindos!\n\nAmbos os jogadores, player 1 e player 2, come�am com 0 pontos.");
	
	srand(time(NULL));
	
	do{
		printf("\n\nPara jogar, basta digitar 1. Para parar, digite 0.\nSua escolha: ");
		scanf("%d", &continuar);
		
		if(continuar == 0){
			break;
		}else{
			vez = seleciona_jogador(ultimo_ganhador);
			ultimo_ganhador = realiza_partida(vez);
			if(ultimo_ganhador == 1) v_p1++;
			else if(ultimo_ganhador == 2) v_p2++;
			else emp++;
			exibe_placar(v_p1, v_p2, emp);
			
		}
	}while(continuar != 0);
	
	printf("\nGG\nAt� mais!");
	
	return 0;
}