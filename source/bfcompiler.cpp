#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int checkbrackets(char *f)
{
  int b = 0;
  ifstream s(f, std::ifstream::in);
  char c;
  while (s >> c)
  {
    if(c=='[')
    {
      b++;
    }
    if(c==']')
    {
      b--;
    }
    if(b < 0) 
    {
      return b;
    }
  }
  return b;
}
int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    cout<<"Please use with 1 file\n";
    return 0;
  }
  if(checkbrackets(argv[1]))
  {
    cout<<"Source has bracketing problems\n";
    return 0;
  }
  ifstream s(argv[1], std::ifstream::in);
  freopen("brainfuck.c", "w", stdout);
  printf("char a[65536];\n");
  printf("int p=0;\n");
  printf("int main()\n");
  printf("{\n");
  char c;
  while (s >> c)
  {
    if(c == '>')
    {
      printf("p++;");
    }
    if(c == '<')
    {
      printf("p--;");
    }
    if(c == '+')
    {
      printf("a[p]++;");
    }
    if(c == '-')
    {
      printf("a[p]--;");
    }
    if(c == '[')
    {
      printf("while(a[p])");
      printf("{");
    }
    if(c == ']')
    {
      printf("}");
    }
    if(c == ',')
    {
      printf("a[p]=getchar();");
    }
    if(c == '.')
    {
      printf("putchar(a[p]);");
    }
    printf("\n");
  }
  printf("return 0;\n");
  printf("}\n");
  return 0;
}
