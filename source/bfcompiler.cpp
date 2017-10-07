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
  s.close();
  return b;
}

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    cerr<<"Improper use";
    return 1;
  }
  if(checkbrackets(argv[1]))
  {
    cerr<<"Source has bracketing problems\n";
    return 1;
  }
  ifstream s(argv[1], std::ifstream::in);
  freopen(argv[2], "w", stdout);
  printf("#include \"memlib.c\"\n");
  printf("#include <stdio.h>\n");
  printf("int main()");
  printf("{MEM_T *p=new_node(),*eraser=p;");
  char c;
  while (s >> c)
  {
    switch(c){
      case '>':
        printf("p=next(p);");
        break;
      case '<':
        printf("p=prev(p);");
        break;
      case '+':
        printf("(*get(p))++;");
        break;
      case '-':
        printf("(*get(p))--;");
        break;
      case '[':
        printf("while(*get(p)){");
        break;
      case ']':
        printf("}");
        break;
      case ',':
        printf("fread(get(p),MEM_V_SIZE,1,stdin);");
        break;
      case '.':
        printf("fwrite(get(p),MEM_V_SIZE,1,stdout);");
        break;
    }
  }
  printf("erase(eraser);");
  printf("return 0;");
  printf("}\n");
  s.close();
  return 0;
}
