#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 64
char hex[]={'0','1','2','3','4', '5','6','7','8','9','A','B','C','D','E','F','\0'};
//read data from file data.txt
void read_file_byte(const char *filename, char *ouput){
	FILE *fp;
	fp=fopen(filename,"r");
	fscanf(fp,"%s",(ouput));
	fclose(fp);
}
void display(char *input){
	printf("\n%s",input);
}
void bytestring_to_bitstring(char *input, char *output){
	int l=strlen(input);
	int i;
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
}
void bitstringtodecima(char *string, char *hexout){
	int sum=0;
	int sumi=1;
	int i,j;
	for(i=0;i<4;i++){
		if (string[i]=='1'){
			int sumi=1;
				for(j=3-i;j>0;j--){
					sumi=sumi*2;
				}
				sum=sum+sumi;
		}

	}
	
	hexout[0]=hex[sum];
	hexout[1]='\0';
//	printf("%s",hexout);
}

void bitstring_to_bytestring(char*input, char *output){
	int l,i;
	l=strlen(input);
	int n=l/4;
	char tmp[5];
	char outhex[2];
	int count=0;
	
	memset(tmp, 0, 5);
	memset(outhex,0,2);
	
	while (count<n){
		for(i=0;i<4;i++){
		*(tmp+i)=*(input+l-1-i-count*4);	
		}
		//tmp[4]='\0';
		reserve_1_string(tmp);
//	display(tmp);
		bitstringtodecima(tmp,outhex);
		strcat(output,outhex);
		count++;	
	}
	reserve_1_string(output);	
//	display(output);
}

//hoan doi theo vi tri cum byte, 2 byte va 4 byte


void swap_string(char *input,int i,int j){
	char tmp;
	tmp= *(input+i);
	*(input+i)=*(input+j);
	*(input+j)=tmp;	
}

void reserve_1_string(char *input){
	
	int l=strlen(input);
	int i;
	for(i=0;i<l/2;i++){
		
		swap_string(input,i,l-1-i);	
	}	
}



//dao chuoi bit theo cum byte
void reserve(char *input,int nbyte, char *output){
	int nbit= nbyte*8;
	int l=strlen(input);
	memset(output,0,l);
	int n=l/nbit;
	int count=0;
	int i;
	char tmp[nbit+1];
	while(count<n){
		for(i=0;i<nbit;i++){
			*(tmp+i)= *(input+i+(count*nbit));
		}
		tmp[nbit]='\0';
		display(tmp);
		printf("hoan doi thanh:");
		reserve_1_string(tmp);
		display(tmp);
		strcat(output,tmp);
		count++;
	
	}

//	return output;
}


void write_data_in_file(const char *filename, char *string1, char *string2){
	FILE *fp;
	fp=fopen(filename, "w");
	fprintf(fp,"%s %s%s %s\n","- Co chuoi byte: ",string1,", doi ra chuoi bit:",string2);
	fclose(fp);
	
}

void write_in_file(const char *filename, char *string1, char *string2,int nbyte){
	FILE *fp;
	fp=fopen(filename, "a");
	char bytestr1[(strlen(string1))/4+1], bytestr2[(strlen(string2))/4+1];
	
	memset(bytestr1, 0, (strlen(string1))/4+1);
	memset(bytestr2, 0, (strlen(string2))/4+1);
	
	bitstring_to_bytestring(string1,bytestr1);
	bitstring_to_bytestring(string2,bytestr2);
	fprintf(fp,"%s %d %s\n","- Hoan doi theo cum",nbyte,"byte");
	fprintf(fp,"%s ( %s ) %s\n%s ( %s ) \n", string1,bytestr1, "hoan doi thanh", string2,bytestr2);
	fclose(fp);
	
}


int main(){
	// doc chuoi byte tu  file data.txt vaf hien thi chuoi byte va chuoi bit tuong ung len man hinh
	char a[max];
	int nbyte;
	read_file_byte("data.txt",a);
	printf("chuoi byte trong file: ");
	display(a);
	char b[max],c[max],d[max],e[max];
	bytestring_to_bitstring(a,b);
	printf("doi thanh chuoi bit:");
	display(b);
	write_data_in_file("output.txt",a,b);
	reserve(b,1,c);
	write_in_file("output.txt",b,c,1);
	reserve(b,2,d);
	write_in_file("output.txt",b,d,2);
	reserve(b,4,e);
	write_in_file("output.txt",b,e,4);
	return 0;

} 
 
 
 

