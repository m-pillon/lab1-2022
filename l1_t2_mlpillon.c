//Mariana Lopes Pillon || mlpillon || CC2

//comentei para propositos de debug quando estava tudo dando errado
// gcc -Wall -o l1_t2_mlpillon l1_t2_mlpillon.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro

#include "tela.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int seleciona_jogador(int ug){
	int a = (rand() % 2) + 1;

	//ug = ultimo ganhador. o que ganhou por ultimo joga na proxima rodada
	if((ug == 1) || (ug == 2)) return ug;

	//se for a primeira partida OU se o resultado tiver sido um empate, gera um jogador para iniciar
	else{
		if(a == 1) return 1;
		else return 2;
	}
}

bool checa_desistencia(char j, int vez, int** d_p1, int** d_p2, int** v_p1, int** v_p2){
	if(j == 3){ //checa apenas o segundo indice.
		printf("\nPlayer %d, você desistiu do jogo!", vez);
		if(vez == 1){
            **d_p1 = **d_p1 + 1;
            **v_p2 = **v_p2 + 1;
		}else{
            **d_p2 = **d_p2 + 1;
            **v_p1 = **v_p1 + 1;
		}
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
	printf("\nÍndices:"); //por hora, como as jogadas sao feitas
	printf("\n00 | 01 | 02\n10 | 11 | 12\n20 | 21 | 22\n\n");
}

bool checa_posicao(int l, int c, char t[l][c], int i, int j){
	if((i != 2) && (i != 1) && (i != 0)){
		printf("\nPrimeiro índice inválido.");
		return false;
	}

	if((j != 2) && (j != 1) && (j != 0)){
		printf("\nSegundo índice inválido.");
		return false;
	} //checa se nao foi digitado algo maluco

	if(t[i][j] == ' '){
		return true;
	}else{
		printf("\nEssa posição já está preenchida, tente novamente.\n");
		return false;
	}
}

bool checa_escolha(int escolha){
	if((escolha == 'o') || (escolha == 'O') || (escolha == 'x') || (escolha == 'X')) return true;
	else return false;
}

int checa_vitoria(int l, int c, char t[l][c], int vez){
	int i;

	//horizontal
	for(i = 0; i < 3; i++){
		if((t[i][0] == t[i][1]) && (t[i][0] == t[i][2]) && (t[i][0] != ' ')){
            return vez;
		}
	}

	//vertical
	for(i = 0; i < 3; i++){
		if((t[0][i] == t[1][i]) && (t[0][i] == t[2][i]) && (t[0][i] != ' ')){
            return vez;
		}
	}

	//diagonais
	if(((t[0][0] == t[1][1]) && (t[0][0] == t[2][2]) && (t[0][0] != ' ')) || ((t[0][2] == t[1][1]) && (t[0][2] == t[2][0]) && (t[0][2] != ' '))){
        return vez;
	}

	return 0;
}

void exibe_placar(int* v_p1, int* v_p2, int* emp, int* d_p1, int* d_p2){
	printf("\n\n##### PLACAR #####\n");
	printf("Total de vitórias:");
	printf("\n\tPlayer 1: %d", *v_p1);
	printf("\n\tPlayer 2: %d", *v_p2);
	printf("\nTotal de empates: %d", *emp);
	printf("\nTotal de desistências:");
	printf("\n\tPlayer 1: %d", *d_p1);
	printf("\n\tPlayer 2: %d", *d_p2);
}

int realiza_partida(int vez, int *v_p1, int *v_p2, int *emp, int *d_p1, int *d_p2){
	char tabuleiro[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

	char escolha, simbolo[2];
	int vitoria = 0, i, j, jogadas = 0;
	bool desistiu, p_valida;

	printf("\nLembre-se, o programa preenche automaticamente os quadrados após ser digitada o índice.\n");
	printf("O jogo é disposto da seguinte forma: ");
	mostra_indices();
	printf("Você pode apertar 3 ao invés do segundo índice para desistir.\n");
	printf("Player %d, você prefere jogar com X ou O? ", vez);

	do{
		scanf("%c", &escolha);
	}while(checa_escolha(escolha) == false);

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
			printf("\nDigite a posição de suas jogadas.\nÍndice 1: ");
			scanf("%d", &i);
			printf("Índice 2: ");
			scanf("%d", &j);

			desistiu = checa_desistencia(j, vez, &d_p1, &d_p2, &v_p1, &v_p2);
			if(desistiu == true) break;
			p_valida = checa_posicao(3, 3, tabuleiro, i, j); //posicao valida
		}while(p_valida == false);

		if(desistiu == true){
			printf("\nO tabuleiro final é: ");
			monta_tabuleiro(3, 3, tabuleiro);
			break;
		}

		tabuleiro[i][j] = simbolo[vez-1]; //preenchendo o tabuleiro

		vitoria = checa_vitoria(3, 3, tabuleiro, vez);

		//troca de quem eh a vez
		if(vez == 1) vez++;
		else vez--;

		jogadas++;
		if(jogadas == 9){ //nao há mais posições no tabuleiro
			if(vitoria == 0){
                *emp = *emp + 1;
                printf("\nEmpate!");
                break;
			} //declara empate e sai do laco
		}

	}while(vitoria == 0);

	if(vitoria == 1){
		printf("\nVitória do player 1");
        *v_p1 = *v_p1 + 1;
	}else if(vitoria == 2){
		printf("\nVitória do player 2");
        *v_p2 = *v_p2 + 1;
	}

	printf("\n\nTabuleiro final: ");
	monta_tabuleiro(3, 3, tabuleiro);

	return vitoria;
}

int main(){
	tela_inicio(500, 500, "jogo_da_velha");

	while(true) {
        tela_retangulo(20, 20, 480, 480, 2, branco, transparente);

        int ultimo_ganhador = 0, vez;
        //int v_p1 = 0, v_p2 = 0, emp = 0, d_p1 = 0, d_p2 = 0;

        tela_texto(250, 180, 30, branco, "Sejam bem-vindos!");
        tela_texto(250, 220, 15, branco, "Ambos os jogadores comecam com 0 pontos.");
        tela_texto(250, 250, 15, branco, "Voce pode digitar qualquer tecla para sair.");

        srand(time(NULL));

        while(tela_tecla() = '\0'){
            vez = seleciona_jogador(ultimo_ganhador);
            //ultimo_ganhador = realiza_partida(vez, &v_p1, &v_p2, &emp, &d_p1, &d_p2);
            //exibe_placar(&v_p1, &v_p2, &emp, &d_p1, &d_p2);
        }

        tela_atualiza();

        if(tela_tecla() != '\0'){
            break;
        }
    }

    tela_fim();

	return 0;
}
