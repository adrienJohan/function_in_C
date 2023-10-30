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
	float a = intervalle[0] , b = intervalle[1];
	//float middle= 0;
	
	if(f(a) * f(b) > 0) printf("the solution is not in this interval\n\n");
	else
	{

		while((b-a) > EPS)
		{
			//printf("%f\n", b-a);
			//middle = (b-a)/2;
			if(f(a)*f((b+a)/2) <= 0){ b = (b+a)/2;}
			else {a = (b+a)/2;}
			printf("%f\n", (b+a)/2);
			
		}
		printf("approximative solution is %f\n\n", a);
		
	}
	
	
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

