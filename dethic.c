#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100000//32byte*2=64kytu*4bit+1bit null krt thuc chuoi
char hex[]={'0','1','2','3','4', '5','6','7','8','9','A','B','C','D','E','F','\0'};
//doc du lieu file data.txt và luu vào ouput
void read_file_byte(const char *filename, char *ouput){
	FILE *fp;
	fp=fopen(filename,"r");
	fgets(ouput,"%s",fp);
	fclose(fp);
}

//display : in  chuoi ra man hinh
void display(char *input){
	printf("%s\n",input);
}

// string2hexString chuyen chuoi ki tu kieu char sang hexa

void string2hexString(char* input, char* output)
{
    int l;
    int i; 
    i=0;
    l=0;
    memset(output,0,(2*strlen(input)+1));
    
    while(input[l] != '\0')
    {
        sprintf((output+i),"%02X", input[l]);
        l+=1;
        i+=2;//moi ki tu char bieu dien bang2 ki tu kieu hex
    }
    
}

//chuyen chuoi byte sang chuoi bit

void bytestring_to_bitstring(char *input, char *output){

	int l=strlen(input);
	memset(output,0,2*l+1);
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
// bitstringtodecima chuyen chuoi 4 bit sang decimal(sum),
// hex[sum] tuong ung la hex cua chuoi bit do voi sum la vi tri cua ki tu hex tai chuoi hex[];
// luu ket qua tra ve vao hexout
void bitstringtodecima(char *string, char *hexout){
	int sum=0;
	int sumi=1;
	int i,j;
	memset(hexout,0,2);
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
//	hexout[1]='\0';
//	printf("%s",hexout);
}



/* thuc hien cat chuoi bit thanh cac chuoi 4 bit tu bit thap den cao.
chuyen cac chuoi 4 bit thanhf HEX ==bitstringtodecima ,
noi cac Hex thanh chuoi de dao chuoi theo dung thu tu byte*/

void bitstring_to_bytestring(char*input, char *output){
	int l,i;
	l=strlen(input);
	int n=l/4;
	char tmp[5];
	char outhex[2];
	int count=0;
	
	memset(tmp, 0, 5);
	memset(outhex,0,2);
	//
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



//hoan doi vi tri 2 ky tu
void swap_string(char *input,int i,int j){
	char tmp;
	tmp= *(input+i);
	*(input+i)=*(input+j);
	*(input+j)=tmp;	
}
// dao chuoi
void reserve_1_string(char *input){
	
	int l=strlen(input);
	int i;
	for(i=0;i<l/2;i++){
		
		swap_string(input,i,l-1-i);	
	}	
}



//dao chuoi bit theo cum byte

// cat chuoi bit theo cum byte
// thuc hien dao cac chuoi bit
// ghep cac chuoi cat da dao thanh chuoi ban dau dao theo cum byte
void reserve(char *input,int nbyte, char *output){
	int nbit= nbyte*8;//so bit = so byte *8
	int l=strlen(input);
	memset(output,0,l);
	int n=l/nbit;
	int count=0;
	int i;
	char tmp[nbit+1];
	memset(tmp,0,nbit+1);
	while(count<n){
		for(i=0;i<nbit;i++){
			*(tmp+i)= *(input+i+(count*nbit));
		}
	//	tmp[nbit]='\0';
	//	display(tmp);
	//	printf("hoan doi thanh:");
		reserve_1_string(tmp);
	//	display(tmp);
		strcat(output,tmp);
		count++;
	
	}

//	return output;
}

// ghi vao file
void write_data_in_file(const char *filename, char *string1, char *string2){
	FILE *fp;
	fp=fopen(filename, "w");
	fprintf(fp,"%s %s%s %s\n","- Co chuoi byte: ",string1,", doi ra chuoi bit:",string2);
	fclose(fp);
	
}
//ghi tiep vap file
void write_in_file(const char *filename, char *string1, char *string2,int nbyte){
	FILE *fp;
	fp=fopen(filename, "a");
	char bytestr1[(strlen(string1))/4+1], bytestr2[(strlen(string2))/4+1];
	
	memset(bytestr1, 0, (strlen(string1))/4+1);
	memset(bytestr2, 0, (strlen(string2))/4+1);
	
	bitstring_to_bytestring(string1,bytestr1);
	bitstring_to_bytestring(string2,bytestr2);
	fprintf(fp,"%s %d %s\n","- Hoan doi theo cum",nbyte,"byte");
	fprintf(fp,"%s ( %s ) %s\n%s ( %s ) \n", string1 , bytestr1, "hoan doi thanh", string2,bytestr2);
	fclose(fp);
	
}


int main(){
	// doc chuoi byte tu  file data.txt vaf hien thi chuoi byte va chuoi bit tuong ung len man hinh
	char *data;//data la chuoi kieu char doc duoc tu file data.txt
	data=malloc(max);
	int nbyte;
	read_file_byte("data.txt",data);
	printf("noi dung trong file: ");
	display(data);
	char hexstring[max];//hexstring la chuoi hex duoc chuyen tu chuoi char dau vao
	string2hexString(data,hexstring);
	free(data);
	char *b;//b la chuoi duoc chuyen tu hex sang chuoi bit
	b=malloc(max);
	char c[max];
	printf("Co chuoi byte: ");
	display(hexstring);
	bytestring_to_bitstring(hexstring,b);
	printf("Doi thanh chuoi bit:");
	display(b);
	write_data_in_file("output.txt",hexstring,b);
	reserve(b,1,c);
	write_in_file("output.txt",b,c,1);
	reserve(b,2,c);
	write_in_file("output.txt",b,c,2);

	reserve(b,4,c);
	write_in_file("output.txt",b,c,4);

	free(b);
	return 0;

} 
 
 
 


