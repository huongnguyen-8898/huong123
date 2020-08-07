#include <stdio.h>
//dequy
int giaithua(int n){
	int gt;
	if(n==0){
		gt=1;
	}
	else{
		gt=n*giaithua(n-1);
	}
	return gt;
}
int main()
{
	int n, s;
	scanf("%d", &n);
	if(n<0)
	{
		printf("%d khong ton tai giai thua", n);
	}
	else {
		s=giaithua(n);
		printf("%d!=%d",n,s);
	}
	return 0;
}
