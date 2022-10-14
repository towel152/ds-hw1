#include <stdio.h>
#include <string.h>

/*Define a rectangular structure, including length and width*/
/*Define triangular structure, including base and height*/
/*Define circle structure, including radius*/ 

typedef enum tagField {rectangle, triangle, circle} shapeStuff;

typedef struct {
	char name[10];
	shapeStuff shapeType;
	/*Declare the data structure of the union, 
	  including the rectangle, triangle structure and the radius of the circle*/
	union shapeType{
		struct rectangle{
			float lenght;
			float width;
		};
		struct triangle{
			float base;
			float hight;
		};
		float radius;
	};
		
}shape;

void printShape(shape);

int main(){
	shape s1, s2, s3;
  	strcpy(s1.name, "rectangle");
  	s1.shapeType = rectangle;
	s1.lenght = 10;
	s1.width = 20;
	strcpy(s2.name, "triangle");
	s2.shapeType = triangle;
	s2.base = 102;
	s2.hight = 450;
	strcpy(s3.name ,"circle");
	s3.shapeType = circle;
	s3.radius = 2.5;
	printShape(s1);
	printShape(s2);
	printShape(s3);

}

void printShape(shape s){/*print out the information on a shape */

	printf("Name: %s\n", s.name);   
	switch(s.shapeType){
		case rectangle:   
			printf("\tLength:%.2f\n", s.lenght);
			printf("\tWidth:%.2f\n", s.width);
	    	break;
		case triangle:   
			printf("\tBase:%.2f\n", s.base);
			printf("\tHeight:%.2f\n", s.hight);
		    break;
		case circle:   
			printf("\tRadius:%.2f\n", s.radius);
			break;
	}

 	  
}



