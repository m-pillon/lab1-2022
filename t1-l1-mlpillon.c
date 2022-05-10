/***
Você deve implementar duas funções para a lei dos senos:

uma que recebe dois ângulos e um lado, e retorna outro lado. O lado recebido é oposto ao primeiro ângulo, 
o lado retornado é oposto ao segundo.
uma que recebe dois lados e um ângulo, e retorna outro ângulo. O ângulo recebido é oposto ao primeiro lado, 
o ângulo retornado é oposto ao segundo.

Você deve implementar uma função para a lei dos cossenos:

recebe três lados, retorna o ângulo oposto ao primeiro deles.
As leis dos senos e cossenos só devem ser tratadas no programa por essas 3 funções. 

Além dessas funções, você pode implementar funções auxiliares (como para cálculo de funções trigonométricas 
com graus e conversões entre graus e radianos).

Todos os ângulos acima estão em graus.

Imprime os dados do triângulo (use uma função para isso, com 6 argumentos)
***/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double convertePraRad(double angulo){
	double anguloRad;
	
	anguloRad = angulo * M_PI / 180.0;
	
	return anguloRad;
}

double convertePraGraus(double angulo){
	double anguloGraus;
	
	anguloGraus = angulo * 180 / M_PI;
	
	return anguloGraus;
}

double fazLeiSenosAAL(double anguloDoLado, double angulo, double lado){
	double ladoDoAngulo;
	
	ladoDoAngulo = lado * sin(anguloDoLado) / sin(angulo);
	
	return ladoDoAngulo;	
}

double fazLeiSenosLLA(double ladoDoAngulo, double lado, double angulo){
	double anguloDoLado;
	
	anguloDoLado = ladoDoAngulo * sin(angulo) / sin(angulo);
	
	anguloDoLado = convertePraGraus(asin(anguloDoLado));
		
	return anguloDoLado;
}

double fazLeiCossenos(double ladoOposto, double lado2, double lado3){
	double angulo, cosseno;
	
	cosseno = (lado2*lado2 + lado3*lado3 - ladoOposto*ladoOposto) / (2 * lado2 * lado3);
	
	angulo = convertePraGraus(acos(cosseno));
	
	return angulo;
}

void imprimeValores(double lado1, double lado2, double lado3, double angulo1, double angulo2, double angulo3){
	printf("\n\nOs valores são:\nAngulos: %.2lf, %.2lf, %.2lf", angulo1, angulo2, angulo3);
	printf("\nLados: %.2lf, %.2lf, %.2lf", lado1, lado2, lado3);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	double lado1 = 0.0, lado2 = 0.0, lado3 = 0.0;
	double angulo1 = 0.0, angulo2 = 0.0, angulo3 = 0.0;
	double aux[3];
	char opcao[3];
	
	printf("Olá\nQual a sua opção de modalidade? ");
	printf("\nModalidades aceitas: LLL, LAL, LLA, ALA, AAL. ");
	scanf("%s", &opcao);
	
	printf("\nVocê escolheu: %s", opcao);
	
	printf("\nDigite os três valores na mesma ordem da modalidade: ");
	printf("Valor 1, %c: ", opcao[0]);
	scanf("%lf", &aux[0]);
	printf("Valor 2, %c: ", opcao[1]);
	scanf("%lf", &aux[1]);
	printf("Valor 3, %c: ", opcao[2]);
	scanf("%lf", &aux[2]);
	
	system("cls");
	
	printf("Os três valores digitados foram: %c: %.2lf, %c: %.2lf, %c: %.2lf", opcao[0], aux[0], opcao[1], aux[1], opcao[2], aux[2]);
	
	if((strcmp(opcao, "LLL") == 0) || (strcmp(opcao, "lll") == 0)){
		lado1 = aux[0];
		lado2 = aux[1];
		lado3 = aux[2];

		angulo1 = fazLeiCossenos(lado1, lado2, lado3);
		angulo2 = fazLeiCossenos(lado2, lado1, lado3);
		angulo3 = 180.0 - (angulo2 + angulo1);
	}
	
	else if((strcmp(opcao, "LAL") == 0) || (strcmp(opcao, "lal") == 0)){
		lado1 = aux[0];
		angulo1 = aux[1];
		lado2 = aux[2];
		
		angulo2 = fazLeiSenosLLA(lado2, lado1, convertePraRad(angulo1));
		angulo2 = convertePraGraus(angulo2);
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado3 = fazLeiSenosAAL(convertePraRad(angulo3), convertePraRad(angulo2), lado2);
	}
	
	else if((strcmp(opcao, "LLA") == 0) || (strcmp(opcao, "lla") == 0)){
		lado1 = aux[0];
		lado2 = aux[1];
		angulo1 = aux[2];
		
		angulo2 = fazLeiSenosLLA(lado2, lado1, convertePraRad(angulo1));
		angulo2 = convertePraGraus(angulo2);
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado3 = fazLeiSenosAAL(convertePraRad(angulo3), convertePraRad(angulo2), lado2);
	}
	
	else if((strcmp(opcao, "ALA") == 0) || (strcmp(opcao, "ala") == 0)){
		angulo1 = aux[0];
		lado1 = aux[1];
		angulo2 = aux[2];
	
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado2 = fazLeiSenosAAL(convertePraRad(angulo2), convertePraRad(angulo1), lado1);
		lado3 = fazLeiSenosAAL(angulo3, convertePraRad(angulo1), lado1);
	}
	
	else if((strcmp(opcao, "AAL") == 0) || (strcmp(opcao, "aal") == 0)){
		angulo1 = aux[0];
		angulo2 = aux[1];
		lado1 = aux[2];
		
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado2 = fazLeiSenosAAL(convertePraRad(angulo2), convertePraRad(angulo1), lado1);
		lado3 = fazLeiSenosAAL(convertePraRad(angulo3), convertePraRad(angulo1), lado1);
	}
	
	else{ 
		printf("\nHmm. Algo não deu certo.");
		exit(-1);
	}
	
	imprimeValores(lado1, lado2, lado3, angulo1, angulo2, angulo3);
	
	return 0;
}
