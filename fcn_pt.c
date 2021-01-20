/*
 * fcn_pt.c
 *
 *  Created on: Jan 19, 2021
 *      Author: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void add(int a,int b){
	printf("a+b=%d\n",a+b);
}
void sub(int a, int b){
	printf("a-b=%d\n",a-b);
}
void multi(int a,int b){
	printf("axb=%d\n",a*b);
}
int main(){
	void (*fcn_pt[])(int,int)={add,sub,multi};
	int i=0;
	for(i=0;i<=2;i++){
	fcn_pt[i](100,200);
	}
	return 0;
}
