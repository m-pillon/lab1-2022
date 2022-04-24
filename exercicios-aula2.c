/*exercíios do 1 ao 5 menos o que dava certo com números inteiros*/

#include <stdio.h>
#include <locale.h>
int main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf ("Exercício 1\nSua idade em dias é %.2f", 18.0 * 365.25);
    
    printf("\n\nExercício 2\nSua altura em polegadas é %.2f", 171.0 / 2.5);
        
    printf("\n\nExercício 4\nO preço médio da laranja é %.2f reais", (5.0 + 10.0 + 4.0)/3.0);
    
    printf("\n\nExercício 5\nO carro pode andar %.2f quilômetros", (100.0/7.0) * 10.0);
	
	return 0;
}
