/*exerc�ios do 1 ao 5 menos o que dava certo com n�meros inteiros*/

#include <stdio.h>
#include <locale.h>
int main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf ("Exerc�cio 1\nSua idade em dias � %.2f", 18.0 * 365.25);
    
    printf("\n\nExerc�cio 2\nSua altura em polegadas � %.2f", 171.0 / 2.5);
        
    printf("\n\nExerc�cio 4\nO pre�o m�dio da laranja � %.2f reais", (5.0 + 10.0 + 4.0)/3.0);
    
    printf("\n\nExerc�cio 5\nO carro pode andar %.2f quil�metros", (100.0/7.0) * 10.0);
	
	return 0;
}
