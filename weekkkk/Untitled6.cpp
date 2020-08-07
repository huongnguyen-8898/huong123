#include<stdio.h>
int main()
{
    FILE *fp1, *fp2;
    char ch;
    int pos;

    if ((fp1 = fopen("output.txt", "r")) == NULL)
    {
        printf("\nFile cannot be opened.");
    }
    else
    {
        printf("\nFile opened for copy...\n ");
    }
    fp2 = fopen("dssv.txt", "w");
    fseek(fp1, 0L, SEEK_END);   // File pointer at end of file
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);   // File pointer set at start
    while (pos--)
    {
        ch = fgetc(fp1);    // Copying file character by character
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
