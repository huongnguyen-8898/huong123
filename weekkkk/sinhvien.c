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
 
struct sinhvien{
    char hoten[30];
    char gioitinh[5];
    char MSV[10];
    struct DATE ngaysinh;
    float diemtb;
};

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
	printf("%02u / %02u / %4d", d.ngay, d.thang, d.nam);
}

void nhapsv(sinhvien &sv){
	float d;
	printf("\nnhap vao MSV:");
	gets(sv.MSV);
	printf("\nnhap vao ho ten sv:");
	gets(sv.hoten);
	printf("\nnhap vao gioi tinh:");
	gets(sv.gioitinh);
	printf("\nnhap vao ngay sinh cua sv");
	nhapngaysinh(sv.ngaysinh);
	printf("\nNhap vao diem trung binh:");
	scanf("%f", &d);
	sv.diemtb=d;
}
void xuatsv(sinhvien sv){
	printf("\nMSV: %s",sv.MSV);
	printf("\nHo va ten: %s",sv.hoten);
	printf("\n Gioi tinh: %s",sv.gioitinh);
	printf("\n Ngay sinh: ");
	xuatngaysinh(sv.ngaysinh);
	printf("diem trung binh: %2.2f",sv.diemtb);
}
//int xoasv(SV *a[], char *MSV_DL, int n)
//{
//	int found = 0;
//	int i, j;
//	for(i = 0; i < n; i++)
//	{
//		if(strcmp(a[i].MSV,MSV_Dl)==0)
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
void nhapDSSV(sinhvien a[], int n){
	int i;
	printf("\nNhap vao so luong SV: ");
	scanf("%d", &n);
	for( i=0; i<n; i++){
	printf("\nNhap vao thong tin cua hoc sinh thu %d:\n", i+1);
	nhapsv(a[i]); 
	}
}
void xuatDSSV(sinhvien a[], int n){
	int i;
	for( i=0; i<n; i++){
		printf("thong tin SV thu %d",i+1);
		xuatsv(a[i]);
	}
}

void ghifile(sinhvien a[], int n, char fileName[])
{
	FILE *fp;
	fp = fopen (fileName, "w");
	int i;
    fprintf(fp, "%-10s %-15s %-15s %-10s %-10s\n", "MSV", "Ho va ten", "gioi tinh" ," ngay sinh","diem trung binh");
    for (i = 0; i < n; i++){
        fprintf(fp, "%-10s %-15s %-15s %-10d %-2.2f\n", a[i].MSV, a[i].hoten,a[i].gioitinh, a[i].ngaysinh, a[i].diemtb);
    }
    fclose(fp);
}
void main{
	sinhvien a[MAX];
	int n;
	nhapDSSV(a,n);
	xuatDSSV(a,n);	
}
