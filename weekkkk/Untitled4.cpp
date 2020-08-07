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
struct Node{
	SV data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List{
	NODE *pHead, *pTail;
};
typedef struct List LIST;

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

void AddTail(List &l,NODE* new_ele)
{
    if(l.pTail==NULL)
        l.pHead=l.pTail=new_ele;
    else
    {
        l.pTail->pNext=new_ele;
        l.pTail=new_ele;
    }
}
NODE* GetNode(SV DATA)
{
	NODE *p = new NODE; 
	if(p == NULL)
	{
		printf("\nKhong du bo nho de cap phat con tro");
		getch();
		return NULL;
	}
	p ->data = DATA; 
	p ->pNext = NULL;
	return p;
}
