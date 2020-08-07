#include <stdio.h>
#define MAX 101

 
int main()
{
   int list[100],c, n;
   int copy[100], pos[100];
   char name[n][11];
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (c = 0; c < n; c++)
   {
      scanf("%d", &list[c]);
      pos[c] = c;
  }
   for (c = 0; c < n; c++)
	{
		scanf("%s", name[c]);
	}
   for (c = 0; c < n; c++)
      copy[c] = list[c];
   int swap, i, j;
   for(i=0; j < n - 1; j++){
		for (i = 0; i < n - 1; i++)
		{
		if(list[i] < list[i+1])
		{
			swap = pos[i+1];
			pos[i+1] = pos[i];
			pos[i] = swap; 
			
			swap = list[i+1];
			list[i+1] = list[i];
			list[i] = swap;
		}
		}
}
int k;
	for (c = 0; c < n; c++)
	{
		for( k = 0; k < n; k++)
		{
			if(c == pos[k])
			{
				printf(" %s rank at %d\n", name[c], k + 1);
			}
		}
	}
	
     return 0;
  }

