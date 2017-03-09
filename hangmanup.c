#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
char word1[20],word2[20];
int tries=7;
int main()
{
    char letter;
    int i,len,chance=7,pos;
    printf("Enter the word:");
    scanf("%s",&word1);
    system("cls");
    strcpy(word2,word1);
    replace();
    printf("%s\n GUESS THE LETTERS IN THE FORMAT:POSITION-LETTER(eg)2-B\n",word1);
    do
    {
        guesses();
        if(strcmp(word1,word2)==0)
        {
            printf("YOU'VE WON!!\n\t THE WORD IS %s",word2);
            break;
        }
    }while(tries>0);
    if(strcmp(word1,word2)!=0)
        printf("YOU'VE LOST!!\n\t THE WORD IS %s",word2);
   getch();
   return 0;
}
void replace()
{   int i,len;
    len=strlen(word1);
   for(i=0;i<len;i++)
   {
       if((word1[i]!='a')&&(word1[i]!='e')&&(word1[i]!='i')&&(word1[i]!='o')&&(word1[i]!='u'))
       {
           word1[i]='_';
       }
   }
}
void guesses()
{   int pos;
    char letter;
    scanf("%d-%c",&pos,&letter);
        if(word2[pos-1]==letter)
        {
            printf("CORRECT!! GUESS THE REMAINING LETTER(S)\n YOU HAVE %d CHANCES LEFT\n",tries);
            word1[pos-1]=letter;
        }
        else
        {
            tries--;
            printf("WRONG! TRY GUESSING AGAIN\n YOU HAVE %d CHANCES LEFT\n",tries);
        }
}



