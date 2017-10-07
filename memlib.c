#include <stdlib.h>
#include <stdint.h>
#define MEM_T struct mem_node
#define VAL_T uint8_t
#define MEM_V_SIZE sizeof(VAL_T)

MEM_T
{
  MEM_T *prev;
  MEM_T *next;
  uint8_t index;
  VAL_T values[256];
};

MEM_T *new_node()
{
  return calloc(1, sizeof(MEM_T));
}

MEM_T *next(MEM_T *this)
{
  if(this -> index != 255)
  {
    this -> index++;
    return this;
  }
  if(!(this -> next))
  {
    this -> next = new_node();
    this -> next -> prev = this;
  }
  return this -> next;
}

MEM_T *prev(MEM_T *this)
{
  if(this -> index != 0)
  {
    this -> index--;
    return this;
  }
  if(!(this -> prev))
  {
    this -> prev = new_node();
    this -> prev -> index = 255;
    this -> prev -> next = this;
  }
  return this -> prev;
}

VAL_T *get(MEM_T *this)
{
  return this -> values;
}

void erase(MEM_T *this)
{
  if(this -> prev)
  {
    this -> prev -> next = NULL;
    erase(this -> prev);
  }
  if(this -> next)
  {
    this -> next -> prev = NULL;
    erase(this -> next);
  }
  free(this);
}
