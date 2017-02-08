#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int pstl = 0; // printed something this line

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
  s.close();
  return b;
}

void do_print_nl()
{
  if(pstl)
  {
    printf("\n");
  }
  pstl = -1;
}

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    cout<<"Please use with 1 file\n";
    return 1;
  }
  if(checkbrackets(argv[1]))
  {
    cout<<"Source has bracketing problems\n";
    return 1;
  }
  ifstream s(argv[1], std::ifstream::in);
  freopen("brainfuck.c", "w", stdout);
  printf("char a[65536];\n");
  printf("int p=0;\n");
  printf("int main()\n");
  printf("{\n");
  char c;
  pstl = 0;
  while (s >> c)
  {
    switch(c){
      case '>':
        printf("p++;");
        break;
      case '<':
        printf("p--;");
        break;
      case '+':
        printf("a[p]++;");
        break;
      case '-':
        printf("a[p]--;");
        break;
      case '[':
        do_print_nl();
        printf("while(a[p])\n");
        printf("{\n");
        break;
      case ']':
        do_print_nl();
        printf("}\n");
        break;
      case ',':
        printf("a[p]=getchar();");
        break;
      case '.':
        printf("putchar(a[p]);");
        break;
      case '\n':
        do_print_nl();
        break;
    }
  }
  printf("return 0;\n");
  printf("}\n");
  s.close();
  return 0;
}
