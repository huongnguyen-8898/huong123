#include<stdio.h>
#include<string.h>
#define max 100
int abc;
void ghepchuoi(char *s1,char *s2, char *s3){
	int i = 0, j = 0;
	while(s1[i] != '\0')
	{
		s3[i]=s1[i];
		i++;
	}
	s3[i]=' ';
	i++;
	while(s2[j] != '\0'){
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	printf("\n chuoi sau ghep la:\n");
	puts(s3);

}

char* ghepchuoi2(char* s1, char* s2)
{
	char* output;
	int length;
	length = sizeof(s1) + sizeof(s2) - 1;
	output = (char*) malloc(length*sizeof(char));
	// ghep chuoi
	
	return output;
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
int kiemtrakitu(char *s,char x){
	int dem=0;
	int i;
	int l= strlen(s);
	for(i=0; i<l; i++){
		if(s[i]==x){
			dem++;
		}
	}
	return dem;
}
void chuyenkituThuongthanhHoa(char *s){
	int i;
	int l=strlen(s);
	for(i=0;i<l;i++){
		if (s[i]>='a' && s[i]<='z')
		{
			s[i]= s[i]-32;
		}
	}
	puts(s);
}
void chuyenkituHoasangThuong(char *s){
	int i;
	int l=strlen(s);
	for(i=0;i<l;i++){
		if (s[i]>='A' && s[i]<='Z')
		{
			s[i]= s[i]+32;
		}
	}
	puts(s);
}

int main(){
	char chuoi1[max], chuoi2[max], chuoi3[max], chuoi4[max], x;
	int k1, k2;
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
	printf("\n nhap vao ki tu kiem tra x=");
	scanf("%c",&x);
	k1=kiemtrakitu(chuoi1,x);
	k2=kiemtrakitu(chuoi2,x);
	if(k1==0){
		printf("\n ki tu %c khong xuat hien lan nao trong chuoi 1\n ",x);
	}
	else {
		printf(" \n ki tu %c xuat hien %d lan trong chuoi 1\n",x,k1);
	}
	if(k2==0){
		printf("\n ki tu %c khong xuat hien lan nao trong chuoi 2\n",x);
	}
	else {
		printf(" \n ki tu %c xuat hien %d lan trong chuoi 2\n",x,k2);
	}
	printf("\n chuoi 1 sau chuyen tat ca cac ki tu thuong sang Hoa la: ");
	chuyenkituThuongthanhHoa(chuoi1);
	printf("\n chuoi 2 sau chuyen tat ca cac ki tu thuong sang Hoa la: ");
	chuyenkituThuongthanhHoa(chuoi2);
	printf("\n chuoi 1 sau chuyen tat ca cac ki tu hoa sang thuong la: ");
	chuyenkituHoasangThuong(chuoi1);
	printf("\n chuoi 2 sau chuyen tat ca cac ki tu hoa sang thuong la:");
	chuyenkituHoasangThuong(chuoi2);
	char* out;
	out = ghepchuoi2(chuoi1, chuoi2);
	
	//printf
	
	free(out);
	
	return 0;
}

