/***
Voc� deve implementar duas fun��es para a lei dos senos:

uma que recebe dois �ngulos e um lado, e retorna outro lado. O lado recebido � oposto ao primeiro �ngulo, 
o lado retornado � oposto ao segundo.
uma que recebe dois lados e um �ngulo, e retorna outro �ngulo. O �ngulo recebido � oposto ao primeiro lado, 
o �ngulo retornado � oposto ao segundo.

Voc� deve implementar uma fun��o para a lei dos cossenos:

recebe tr�s lados, retorna o �ngulo oposto ao primeiro deles.
As leis dos senos e cossenos s� devem ser tratadas no programa por essas 3 fun��es. 

Al�m dessas fun��es, voc� pode implementar fun��es auxiliares (como para c�lculo de fun��es trigonom�tricas 
com graus e convers�es entre graus e radianos).

Todos os �ngulos acima est�o em graus.

Imprime os dados do tri�ngulo (use uma fun��o para isso, com 6 argumentos)
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
	printf("\n\nOs valores s�o:\nAngulos: %.2lf, %.2lf, %.2lf", angulo1, angulo2, angulo3);
	printf("\nLados: %.2lf, %.2lf, %.2lf", lado1, lado2, lado3);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	double lado1 = 0.0, lado2 = 0.0, lado3 = 0.0;
	double angulo1 = 0.0, angulo2 = 0.0, angulo3 = 0.0;
	double aux[3];
	char opcao[3];
	
	printf("Ol�\nQual a sua op��o de modalidade? ");
	printf("\nModalidades aceitas: LLL, LAL, LLA, ALA, AAL. ");
	scanf("%s", &opcao);
	
	printf("\nVoc� escolheu: %s", opcao);
	
	printf("\nDigite os tr�s valores na mesma ordem da modalidade: ");
	printf("Valor 1, %c: ", opcao[0]);
	scanf("%lf", &aux[0]);
	printf("Valor 2, %c: ", opcao[1]);
	scanf("%lf", &aux[1]);
	printf("Valor 3, %c: ", opcao[2]);
	scanf("%lf", &aux[2]);
	
	system("cls");
	
	printf("Os tr�s valores digitados foram: %c: %.2lf, %c: %.2lf, %c: %.2lf", opcao[0], aux[0], opcao[1], aux[1], opcao[2], aux[2]);
	
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
		printf("\nHmm. Algo n�o deu certo.");
		exit(-1);
	}
	
	imprimeValores(lado1, lado2, lado3, angulo1, angulo2, angulo3);
	
	return 0;
}
