//Mariana Lopes Pillon - CC2

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
	
	anguloGraus = angulo * 180.0 / M_PI;
	
	return anguloGraus;
}

double fazLeiSenosAAL(double anguloOposto, double lado, double angulo){
	double ladoOposto;
	
	ladoOposto = lado * sin(convertePraRad(anguloOposto)) / sin(convertePraRad(angulo));
	
	return ladoOposto;	
}

double fazLeiSenosLLA(double ladoOposto, double lado, double angulo){
	double anguloOposto;
	
	anguloOposto = ladoOposto * sin(convertePraRad(angulo)) / lado;
	
	anguloOposto = convertePraGraus(asin(anguloOposto));
		
	return anguloOposto;
}

double fazLeiCossenosLLL(double ladoOposto, double lado2, double lado3){
	double angulo, cosseno;
	
	cosseno = (lado2 * lado2 + lado3 * lado3 - ladoOposto * ladoOposto) / (2 * lado2 * lado3);
	
	angulo = convertePraGraus(acos(cosseno));
	
	return angulo;
}

double fazLeiCossenosLAL(double lado1, double lado2, double angulo){
	double ladoOposto;
	
	ladoOposto = sqrt(lado1 * lado1 + lado2 * lado2 + 2 * lado1 * lado2 * cos(convertePraRad(angulo)));
	
	return ladoOposto;
}

void imprimeValores(double lado1, double lado2, double lado3, double angulo1, double angulo2, double angulo3){
	printf("\n\nOs valores são:\nÂngulos: %.2lf, %.2lf, %.2lf", angulo1, angulo2, angulo3);
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
	
	printf("\nDigite os 3 valores na mesma ordem da modalidade: ");
	printf("Valor 1, %c: ", opcao[0]);
	scanf("%lf", &aux[0]);
	printf("Valor 2, %c: ", opcao[1]);
	scanf("%lf", &aux[1]);
	printf("Valor 3, %c: ", opcao[2]);
	scanf("%lf", &aux[2]);
	
	system("cls");
	
	printf("Os 3 valores digitados foram: %c: %.2lf, %c: %.2lf, %c: %.2lf", opcao[0], aux[0], opcao[1], aux[1], opcao[2], aux[2]);
	
	if((strcmp(opcao, "LLL") == 0) || (strcmp(opcao, "lll") == 0)){ //três lados
		lado1 = aux[0];
		lado2 = aux[1];
		lado3 = aux[2];

		angulo1 = fazLeiCossenosLLL(lado1, lado2, lado3);
		angulo2 = fazLeiCossenosLLL(lado2, lado1, lado3);
		angulo3 = 180.0 - (angulo2 + angulo1);
	}
	
	else if((strcmp(opcao, "LAL") == 0) || (strcmp(opcao, "lal") == 0)){ //dois lados e o ângulo entre eles
		lado1 = aux[0];
		angulo3 = aux[1];
		lado2 = aux[2];
		
		lado3 = fazLeiCossenosLAL(lado1, lado2, angulo3);
		angulo2 = fazLeiSenosLLA(lado2, lado3, angulo3);
		angulo1 = 180.0 - (angulo2 + angulo3);
	}
	
	else if((strcmp(opcao, "LLA") == 0) || (strcmp(opcao, "lla") == 0)){ //dois lados e o ângulo adjacente ao segundo lado e oposto ao primeiro
		lado1 = aux[0];
		lado2 = aux[1];
		angulo1 = aux[2];
		
		angulo2 = fazLeiSenosLLA(lado2, lado1, angulo1);
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado3 = fazLeiCossenosLAL(lado1, lado2, angulo3);
	}
	
	else if((strcmp(opcao, "ALA") == 0) || (strcmp(opcao, "ala") == 0)){ //dois ângulos e o lado entre eles
		angulo1 = aux[0];
		lado3 = aux[1];
		angulo2 = aux[2];
		
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado1 = fazLeiSenosAAL(angulo1, lado3, angulo3);
		lado2 = fazLeiCossenosLAL(lado3, lado1, angulo2);
	}
	
	else if((strcmp(opcao, "AAL") == 0) || (strcmp(opcao, "aal") == 0)){ //dois ângulos e o lado adjacente ao segundo ângulo e oposto ao primeiro
		angulo1 = aux[0];
		angulo2 = aux[1];
		lado1 = aux[2];
		
		angulo3 = 180.0 - (angulo2 + angulo1);
		lado2 = fazLeiSenosAAL(angulo2, lado1, angulo1);
		lado3 = fazLeiSenosAAL(angulo3, lado1, angulo1);
	}
	
	else{ 
		printf("\nHmm. Algo não deu certo.");
		exit(-1);
	}
	
	imprimeValores(lado1, lado2, lado3, angulo1, angulo2, angulo3);
	
	return 0;
}
