/*exercíios do 1 ao 5 menos o que dava certo com números inteiros*/

#include <stdio.h>
#include <locale.h>
int main ()
{
	setlocale(LC_ALL, "Portuguese");
    
    float altura, altura_em_polegadas;
    
    printf("Digite sua altura: ");
    
	scanf("%f", &altura);
	
	altura_em_polegadas = altura / 2.5;
	
	printf("Sua altura em polegadas é %.2f", altura_em_polegadas);
    
	return 0;
}
