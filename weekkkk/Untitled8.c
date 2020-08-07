#include<stdio.h>

int main()
{
    char aj[1000];
    int c = 0;
    int count[26] = {0};   

    printf("\n\nnhap vao chuoi :   ");
    gets(aj);

    while(aj[c] != '\0')
    {
        if(aj[c] >= 'a' && aj[c] <= 'z')
        {
            count[aj[c] - 'a']++; 
        }
        c++;
    }

    for(c = 0; c < 26; c++)
    {
        if(count[c] != 0)  
        {
            printf("\n\t\t%c xuat hien %d lan trong chuoi \n",c+'a' ,count[c]);
        }
    }
    return 0;
}
