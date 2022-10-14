#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int row;
	int col;
	int value;
}term;

int main(int argc, char *argv[]) {
	int n=0, i=0, j=0, t=0, MAX=0, count=0, k=1;
	printf("輸入n:");
	scanf("%d", &n);
	MAX=n*n;
	term d[MAX], a[MAX], b[MAX];
	int r[MAX];
	srand(time(0));
	
	//產生不重複亂數
	for(i=1; i<=MAX; i++){
		r[i-1]=i;
	} 
	
	for(i=1; i<=MAX; i++){
		j=rand() % (MAX+1-i) + i;
		t=r[i-1];
		r[i-1]=r[j-1];
		r[j-1]=t;
		d[i].value=r[i-1];
	}
	printf("\n");
	
	//建立d矩陣
	d[0].row=n;
	d[0].col=n;
	d[0].value=MAX;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			d[k].row=i;
			d[k].col=j;
			k++;
		}
	} 
	
//	輸出 
	printf("d陣列為:\n\n");
	for(i=1; i<=MAX; i++){
		printf("%d\t", d[i].value);
		count++;
		if(count%n==0){
			printf("\n");
		}
	}
	printf("\n");
	
//	取出下三角
	count=0;
	k=1;
	for(i=1; i<=MAX; i++){
		if(d[i].row>=d[i].col){
			a[k].row=d[i].row;
			a[k].col=d[i].col;
			a[k].value=d[i].value;
			count++;
			k++;
		}
	} 
	a[0].row=d[0].row;
	a[0].col=d[0].col;
	a[0].value=count;

//	輸出下三角
	count=0; 
	k=1;
	printf("a陣列為:\n\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if((a[k].row==i) && (a[k].col == j)) {
				printf("%d\t", a[k].value);	
				k++;
			}
			else{
				printf("0\t");
			}
			count++;
			if(count%n==0){
				printf("\n");
			}
			
		} 
	}
	
//	取出上三角
	count=0;
	k=1;
	for(i=1; i<=MAX; i++){
		if(d[i].row<=d[i].col){
			b[k].row=d[i].row;
			b[k].col=d[i].col;
			b[k].value=d[i].value;
			count++;
			k++;
		}
	} 
	b[0].row=d[0].row;
	b[0].col=d[0].col;
	b[0].value=count;

//	輸出下三角
	count=0; 
	k=1;
	printf("b陣列為:\n\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if((b[k].row==i) && (b[k].col == j)) {
				printf("%d\t", b[k].value);	
				k++;
			}
			else{
				printf("0\t");
			}
			count++;
			if(count%n==0){
				printf("\n");
			}
			
		} 
	}
	
	return 0;
}



