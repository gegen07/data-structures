#include <stdio.h>
#include "./lib/dyn-array.h"

int main() {
  DynArray dynArray;
  Data data;

  dynArrayInit(&dynArray);

  int i;
  for (i = 200; i > -50; i--) {
    // These two next lines is supposed to be in another library, 
    // like a function to set values of Data struct
    
    data.key = i;

    dynArrayAppend(&dynArray, &data);
  }

  printf("Heres the value at index 27 before SetFunction: %d\n", getElement(&dynArray, 27).key);

  data.key = 27;
  setElement(&dynArray, 27, &data);

  printf("Heres the value at index 27 after Setfunction: %d\n", getElement(&dynArray, 27).key);
  dynArrayFree(&dynArray);

  return 0;
}