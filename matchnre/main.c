#include <stdio.h>
#include <stdlib.h>
void read(char *s)
{
    gets(s);
}
void strcopy(char *s1,char *s2)
{
    int i;
    for(i=0;s2[i]!='\0';i++)
        s1[i]=s2[i];
    s1[i]='\0';
}
int matchreplace(char *str,char *pat,char *rep)
{
    char ans[100];
    int i=0,j=0,c=0,m=0,flag=0,k;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            m++;i++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++;c++;m=c;
            i=0;
        }
}
ans[j]='\0';
strcopy(str,ans);
return flag;
}
int main()
{
  char str[100],rep[50],pat[50];
  int flag;
  printf("Enter String\n");
  read(str);
  printf("Enter pattern\n");
  read(pat);
  printf("Enter replacement\n");
  read(rep);
  flag=matchreplace(str,pat,rep);
  if(flag==1)
  {
      printf("Pattern found\n");
      printf("%s",str);
  }
  else
    printf("Pattern not found\n");
  return 0;
}
