#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   int  b=0, c=1, n=b+c,i,ii;
   pid_t pid;

   printf("Enter no of elements in  Fibonacci Sequence:\n");
   scanf("%d", &ii);

   if (ii < 0)
      printf("enter one non negative no !\n");
   else
   {
      pid = fork();
      if (pid == 0)
      {
         printf("child process is creating some sequence...\n");
         printf("%d %d",b,c);
         for (i=0;i<ii;i++)
         {
            n=b+c;
            printf("%d ", n);
            b=c;
            c=n;
         }
         printf("end of child process\n"); 
      }
      else 
      {
         printf("parent is waiting for completion of child process...\n");
         wait(NULL);
         printf("end of parent process\n");
      }
   }
   return 0;
}

