#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct DATE
{
unsigned char ngay;
unsigned char thang;
int nam;
};
 
struct SinhVien{
    char hoten[30];
    char gioitinh[5];
    char MSV[10];
    struct DATE ngaysinh;
    float diemtb;
};
typedef SinhVien SV;

void nhapngaysinh(DATE &d)
{
	printf("\nNhap vao ngay: ");
	scanf("%u", &d.ngay);
	printf("\nNhap vao thang: ");
	scanf("%u", &d.thang);
	printf("\nNhap vao nam: ");
	scanf("%d", &d.nam);
}
void xuatngaysinh(DATE d){
	printf("%02u / %02u / %04d", d.ngay, d.thang, d.nam);
}

void nhapsv(SV &sv){
	printf("\nnhap vao ho ten sv:");
	gets(sv.hoten);
	printf("\nnhap vao MSV:");
	gets(sv.MSV);
	printf("\nnhap vao gioi tinh:");
	gets(sv.gioitinh);
	printf("\nnhap vao ngay sinh cua sv");
	nhapngaysinh(sv.ngaysinh);
	printf("\nNhap vao diem trung binh:");
	float d;
	scanf("%f", &d);
	sv.diemtb=d;
}
void xuatsv(SV sv){
	printf("\n Ho va ten: %s",sv.hoten);
	printf("\n MSV: %s",sv.MSV);
	printf("\n Gioi tinh: %s",sv.gioitinh);
	printf("\n Ngay sinh: ");
	xuatngaysinh(sv.ngaysinh);
	printf("\n diem trung binh: %2.2f",sv.diemtb);
}
//int ss(char *s1,char *s2){
//	if(strcmp(s1,s2)==0){
//		}
//		return 1;
//	}
//	
//int xoasv(SV a[], char *MSV_DL, int n)
//{
//	int found = 0;
//	int i, j;
//	for(i = 0; i < n; i++)
//	{
//		if(ss(a[i].MSV, MSV_DL)==1)
//		{
//			found =1;
//			for (j = i; j < n; j++)
//			{
//				a[j] = a[j+1];
//			}
//			printf("\n Da xoa SV co MSV = %s",MSV_DL);
//			break;
//		}
//	}
//	if (found == 0)
//	{
//		printf("\n Sinh vien co MSV = %s khong ton tai!", MSV_DL);
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//
//}


void ghifile(FILE* fp, SV a[], int n)
{

	int i;
    fprintf(fp, "%10s\t %30s\t %15s\t %15s\t %10s\n", "MSV", "Ho va ten", "gioi tinh" ," ngay sinh","diem trung binh");
    for (i = 1; i <= n; i++){
        fprintf(fp, "%10s\t %30s\t %15s\t %02u / %02u / %04d\t\t %2.2f\n", a[i].MSV, a[i].hoten,a[i].gioitinh, a[i].ngaysinh.ngay,a[i].ngaysinh.thang,a[i].ngaysinh.nam, a[i].diemtb);
    }

}
int main(){
	SV a[MAX];
	int n;
	int i;
	FILE* fpOut;
	fpOut = fopen("dssv.txt", "wt");
	printf("\n nhap vao so luong sinh vien cua lop :");
	scanf("%d",&n);
	for (i=1;i<=n; i++){
		printf("\nnhap vao thong tin sv thu %d",i);
		int c;
		while((c=getchar())!='\n'&&c!=EOF);{
		nhapsv(a[i]);}
	}
	for (i=1;i<=n;i++){
		printf("\nThong tin sv thu %d",i);
		xuatsv(a[i]);
		
	}
	ghifile(fpOut,a,n);
	fclose(fpOut);
}
