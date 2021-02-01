/*
 * shiftbitcir.c
 *
 *  Created on: Jan 20, 2021
 *      Author: cuonglv22
 */

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<stdint.h>

const int length =8;//maxlength bit =32
int i;


char *detobitstring(uint8_t x){
	char *bitstring;
	int t=0;
	uint8_t d;
	bitstring=(char*)malloc(length+1);
	for(i=length-1;i>=0;i--){
		d= x >> i;
		if(d&1)
			*(bitstring+t)= '1';

		else
			*(bitstring+t)='0';

		t++;


	}
	*(bitstring+t)='\0';
	return bitstring;


}


uint8_t shiftbitcir(uint8_t x, uint8_t st){
	st=st%length;

//dich vong phai st bit
	if (st>0){

		for(i=0;i<st;i++){
			int LSB=x&1;
			x=(x>>1)|(LSB<<(length-1));
		}
	}
	//dich vong trai st bit
	else if (st<0){
		st=-st;
		for(i=0;i<st;i++){

			int MSB=x>>(length-1);
			x=(x<<1)|MSB;
		}

	}
	return x;

}
int main(){
	uint8_t x=240, st=12;
	char *str1;
	str1=detobitstring(x);
	printf("chuoi bit ban dau : %s\n",str1);
	free(str1);

	str1=detobitstring(shiftbitcir(x,st));
	printf("chuoi sau khi dich vong : %s\n",str1);

	free(str1);
	return 0;

}



