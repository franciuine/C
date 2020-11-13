#include <stdio.h>
#include <string.h>

int main()
{
   char str[] = "Tutorials Point";
   char str2[] = "TUorials Point";
   
   int result = strcasecmp(str,str2);
   printf("%d",result);
   
   return(0);
}
