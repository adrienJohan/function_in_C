#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EPS 0.000001

float* take_intervalle ();
float f(float a);


int main () 
{
	float* intervalle = take_intervalle();
	float a = intervalle[0], b = intervalle[1];
	float S = 0;
/*	
  for(int i = a1 ; i <= b ; i += 0.0001)
	{
		S += f(a)*(i-a);
		printf("%f\n", S);
		a += 0.0001;
	}
	printf("%f\n", S);
*/	
	float t;
	t= a+ EPS;
	while(t <= b)
	{
		S += (f(a) * (t-a));
		S += ((t-a)*(f(t)-f(a))/2);
		a += EPS;
		t += EPS;
	//	printf("%f\n", t);
	}
	printf("%f\n" , S);
	return 0;
}


float* take_intervalle ()
{
	float* intervalle = malloc(2* sizeof(float));
	printf("write down below the interval you want.\n");
	printf("a =\t");
	scanf("%f", &intervalle[0]);
	printf("b =\t");
	scanf("%f", &intervalle[1]);
	
	return intervalle;
}

float f(float a)
{
	return log(a)-1;
}
