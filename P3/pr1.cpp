// nx = 3y + 88 + k1
/* Tokens 
	Keywords- BEGIN, END, FOR
	Identifiers- used to describe variables 
	Constants- regular numbers 2,13,21,
	Operators- all arithmetic operations and ++,==
	Delimiters like , ;

	nx,y,k- identifiers 

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char expr[100], operators[20]; 		//Array for storing expression and operator 
	char variables[20][20]; 			//2D array for storing variable or identifier
	int constants[20], ascii[100]={0};	//storing constants and ascii values
	int count, number=0;				//count to store string length
	int i=0, j=-1, k=-1, l=-1, n=0;		//counters for filling arrays 
	int pr[10]={0}, m=0;				//counters for printing identifier arrays

	printf("\n Fexical Analyzer \n\n");

	printf("Enter the String\n");

	scanf("%[^\n]%*c",expr);			//Allows the used to input a string with whitespace
										//stores the input into the expression character array

	count=strlen(expr);					//This gets the length of the inputed expression
	printf("\nString length is: %d", count); //Check

		for(i=0; i < count; ++i){
			ascii[i]= (int)expr[i];		// (int) is used to type cast the character array into a int array
		}
		//the only way a computer can tell the difference between the the characters it
		//uses the ascii values, we made every character in the expression array
		//into its corresponding ascii values and stored it into an array

	for(i=0; i < count; ++i){

		if(isdigit(expr[i])){
			while(isdigit(expr[i])){
				number= 10*number + ascii[i] - '0';
				i++;
			}
			j++;
			constants[j]=number;
			number=0;
		}

		if(isalpha(expr[i])){
			while( isalpha(expr[i]) || isdigit(expr[i]) || expr[i]=='_'){
				k++;
				variables[m][k]=expr[i];
				i++;
			}
			m++;
			pr[n]=k;
			n++;
			k=-1;
		}

		if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='=' || expr[i]=='^' || expr[i]=='/') {
			l++;
			operators[i]=expr[i];
		}
	}

	printf("\nThe literals are: \n\n");
	for(i=0;i<=j;i++){
		printf("\tlit%d\t%d \n",i+1,constants[i]);
	}

	printf("\nThe operators are: \n\n");
	for(i=0;i<=l;i++){
		printf("\top%d\t%c\n",i+1,operators[i]);
	}

	printf("\nThe variables are: \n\n");
	for(i=0;i<m;i++){

		printf("\n\tid%d\t",i+1);
		for(j=0;j<=pr[i];j++){
			printf("%c",variables[i][j]);
		}

	}

}
