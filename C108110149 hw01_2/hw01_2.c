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
	//計算總共有幾個+
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

//加入到最後方
void attach(float coefficient, int exponent){
	if(avail >= MAX_TERMS){
		printf("Too many terms in the polynomial\n");
	}
	terms[avail].coef = coefficient;
	terms[avail].expon = exponent;
	avail++;
}

//計算出現幾次
int count(int n, int index){
	int i = 0, count=0;
	for(i = 0; i < n; i++){
		if(terms[index].expon == terms[i].expon){
			count++;
		}
	} 
	return count;
}

//將同級的相加
void padd(int n){
	int i=0, j=0, c=0, k=0, expon=0;
	float coefficient=0;
	for(i=0; i<n; i++){
		coefficient=0;
		j=i; 
		expon=terms[i].expon;
		c=count(n, i);
		if(c>1){
			//避免重複相加 跳過已經加過的index
			i=i+c-1;
			//相同的數目為偶數
			if(c%2==0){
				c=c/2;	
			}
			//相同的數目為奇數
			else{
				c=(c/2)+1;
			}
			
			for(k=0; k<c; k++){
				coefficient=terms[j].coef+terms[++j].coef;
				j++;
			}
			attach(coefficient, expon); 
		}
		else{
			attach(terms[i].coef, terms[i].expon);
		}
	}
}

//氣泡排序
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
	int i=0, j=0, exponent=0;
	float coefficient=0;
	//avail表示n+1的index
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
	//進行相加
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

