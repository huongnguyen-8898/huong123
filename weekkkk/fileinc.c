

/*
 * file_in_c.c
 *
 *  Created on: 1 Feb 2021
 *      Author: huong
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
void read_file_byte(const char *filename, char *ouput){
	FILE *fp;
	fp=fopen(filename,"r");
	fscanf(fp,"%s",(ouput));
	fclose(fp);
}
void write_file(const char *filename, char *input1, char *input2){
	FILE *fp;
	int i,l1,l2;
	l1=strlen(input1);
	l2=strlen(input2);
	fp=fopen(filename,"w");
	fprintf(fp,"%s  %s%s",input1,"hoan doi thanh:",input2);
	fclose(fp);
}
char *bytestring_to_bitstring(char *input){
	int l,i;
	char *output;
	l=strlen(input);
	output=malloc(4*l);
	for (i=0;i<l;i++){
		switch (*(input+i)) {
			case '0':
				strcat(output,"0000");
				break;
			case '1':
				strcat(output,"0001");
				break;
			case '2':
				strcat(output,"0010");
				break;
			case '3':
				strcat(output,"0011");
				break;
			case '4':
				strcat(output,"0100");
				break;
			case '5':
				strcat(output,"0101");
				break;
			case '6':
				strcat(output,"0110");
				break;
			case '7':
				strcat(output,"0111");
				break;
			case '8':
				strcat(output,"1000");
				break;
			case '9':
				strcat(output,"1001");
				break;
			case 'A':
			case 'a':
				strcat(output,"1010");
				break;
			case 'B':
			case 'b':
				strcat(output,"1011");
				break;
			case 'C':
			case 'c':
				strcat(output,"1100");
				break;
			case 'D':
			case 'd':
				strcat(output,"1101");
				break;
			case 'E':
			case 'e':
				strcat(output,"1110");
				break;
			case 'F':
			case 'f':
				strcat(output,"1111");
				break;
		}
	}
	return output;
}

void display(char *input){
	printf("%s\n",(input));

}
int main(){
	char *a;
	char *b;
	a=(char*)malloc(max*sizeof(char));
	printf("chuoi byte trong file data.txt: ");
	read_file_byte("data.txt",a);
	display(a);
	b=(char*)malloc(max*sizeof(char));
	printf("doi ra chuoi bit thanh: ");
	b=bytestring_to_bitstring(a);
	display(b);
	//write_file("output.txt",a,b);
	free(a);
	free(b);
}



