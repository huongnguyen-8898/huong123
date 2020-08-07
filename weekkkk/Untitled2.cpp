#include<stdio.h>
#include<string.h>
#define max 100
void ghepchuoi(char *s1,char *s2, char *s3){
	int i = 0, j = 0;
	while(s1[i] != '\0')
	{
		s3[i]=s1[i];
		i++;
	}
	while(s2[j] != '\0'){
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	printf("\n chuoi sau ghep la:\n");
	puts(s3);

}
void daochuoi(char *s1, char *s2)
{
	int i;
	int l= strlen(s1);
	for( i=0; i<l;i++){
		s2[i]=s1[l-i-1];
		s2[l]='\0';
	}

}
void sosanh2chuoi( char *s1, char *s2)
{
	if(strcmp(s1, s2)==0){
		printf("\n2 chuoi la giong nhau");
	}
	else{
		printf("\n 2 chuoi la khac  nhau");
	}
}
int main(){
	char chuoi1[max], chuoi2[max], chuoi3[max], chuoi4[max],x;
	printf("nhap vao ki tu:\n");
	scanf("%c",&x);
	printf("\nnhap vao chuoi 1:\n");
	gets(chuoi1);
	printf("chuoi 1 la : %s\n",chuoi1);
	printf("\nnhap vao chuoi 2:\n");
	gets(chuoi2);
	printf("\nchuoi 2 la : %s\n",chuoi2);
	ghepchuoi(chuoi1,chuoi2, chuoi3);
	daochuoi(chuoi1,chuoi4);
	printf("\n chuoi 1 sau khi dao la:\n");
	puts(chuoi4);
	sosanh2chuoi(chuoi1,chuoi2);
	return 0;
}

