#include<stdio.h>
#include<fcntl.h>

int main()
{
   int fd = 0;
   char FileName[20];

   printf("enter name of file that you want open:\n");
   scanf("%s",FileName);

   fd= open(FileName,O_RDWR);
   if(fd== -1)
   {
    printf("unable to oen file\n");
   }
   else
   {
    printf("file succesfully opend with fd:%d\n",fd);
   }
     close(fd);
     
   return 0;

}