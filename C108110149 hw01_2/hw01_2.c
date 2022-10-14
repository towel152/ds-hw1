#include <stdio.h>
#include <string.h>

#define MAX_TERMS 100 

/*Define the structure of polynomials and declare arrays of polynomials 
  using the methods of structures and arrays*/
typedef struct{
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;

void printPoly(int n)
{/*print the polynomial*/
	int i=0, p=0;
//	printf("avail=%d\n", avail);
	p=avail-n-1;
	for(i=n; i<avail; i++){
		if(terms[i].coef == 0){
			p--;
		} 
	}
	for(i=n; i<avail; i++){
		if(terms[i].coef != 0){
			printf("%.2fx^%d", terms[i].coef, terms[i].expon);
			if(p>0){
				printf("+");
				p--;
			}
		}

	}
	
}

void attach(float coefficient, int exponent){
	if(avail >= MAX_TERMS){
		printf("Too many terms in the polynomial\n");
	}
	terms[avail].coef = coefficient;
	terms[avail].expon = exponent;
//	printf("avail_attach=%d\n", avail);
//	printf("coef_attach=%f\n", terms[avail].coef);
//	printf("expon_attach=%d\n", terms[avail].expon);
	avail++;
}

int count(int n, int index){
	int i = 0, count=0;
	for(i = 0; i < n; i++){
		if(terms[index].expon == terms[i].expon){
			count++;
		}
	} 
	return count;
}

void padd(int n){
	int i=0, j=0, c=0, k=0, expon=0;
	float coefficient=0;
	for(i=0; i<n; i++){
		coefficient=0;
		j=i; 
		expon=terms[i].expon;
		c=count(n, i);
		if(c>1){
			i=i+c-1;
			if(c%2==0){
				c=c/2;	
			}
			else{
				c=(c/2)+1;
			}
			
			for(k=0; k<c; k++){
				coefficient=terms[j].coef+terms[++j].coef;
//				printf("coefficient1=%f\n", coefficient);
				j++;
			}
//			printf("coefficient_total=%f\n", coefficient);
//			printf("expon=%d\n", expon);
			attach(coefficient, expon); 
//			printf("c=%d\n", c);
		}
		else{
			attach(terms[i].coef, terms[i].expon);
		}
	}
}



void sort(int n){
	int i=0, j=0, tmp_expon=0, tmp_coef=0;
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			if(terms[i].expon > terms[j].expon){
				tmp_expon = terms[i].expon;
				tmp_coef = terms[i].coef;
				terms[i].expon = terms[j].expon;
				terms[i].coef = terms[j].coef;
				terms[j].expon = tmp_expon;
				terms[j].coef = tmp_coef;
			}
		}
	}

}

void readPoly(int n)
{/*read in a polynomial*/
	int i=0, j=0, exponent=0, c=0;
	float coefficient=0;
	avail=n;
	for(i=0; i<n; i++){
		printf("Exponent: ");
		scanf("%d", &exponent);
		printf("coefficient: ");
		scanf("%f", &coefficient);
		terms[j].coef = coefficient;
		terms[j].expon = exponent;
		j++;
	}
	//先大到小排序 
	sort(n);
	padd(n);
}

int main()
{
   	int n=0;
   	printf ("Enter the number of terms in your polynomial(1<=n<=100): ");
  	scanf("%d", &n);
  	while (n >= MAX_TERMS) {
		printf("Too many terms in the polynomial\n");
		printf("Number of terms: ");
		scanf("%d", &n);
	}
   	readPoly(n);
   	printPoly(n);
}

