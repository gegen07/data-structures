#include "Data.h"

static int DataCreate(Data *data, Item value, uint itemLength) {
  (*data) = (Data) malloc(sizeof(struct data_t));
  (*data)->data = (Item) malloc(itemLength);
  (*data)->next = NULL;
  memcpy((*data)->data, value, itemLength);
  return 0;
}

static int DataFree(Data *data) {
  if((*data) == NULL) {
    return 0;
  }
  free((*data)->data);
  free((*data));
  *data = NULL;
  return 0;
}

static int DataValueCopy(Item *dest, Item orig, uint itemLength) {
  memcpy(*dest, orig, itemLength);
  return 0;
}

int DataInit(Data *data) {
  *data = NULL;
}

int DataInsertAt(Data *data, uint index, Item value, uint itemLength) {
  if((*data) == NULL) {
    DataCreate(data, value, itemLength);
    return 0;
  }
  Data new;
  DataCreate(&new, value, itemLength);
  if(index == 0) {
    new->next = *data;
    *data = new;
    return 0;
  }
  Data iterator = *data;
  while(--index) {
    iterator = iterator->next;
  }
  Data next = iterator->next;
  iterator->next = new;
  new->next = next;
  return 0;
}

int DataRemoveAt(Data *data, uint index) {
  Data iterator = *data;
  Data previous = NULL;
  while(index--) {
    previous = iterator;
    iterator = iterator->next;
  }
  Data next = iterator->next;
  DataFree(&iterator);
  if(previous == NULL) {
    (*data) = next;
  } else {
    previous->next = next;
  }
  return 0;
}

int DataAt(Data *data, uint index, Item value, uint itemLength) {
  Data iterator = *data;
  while(index--) {
    if(iterator == NULL) {
      return 1;
    }
    iterator = iterator->next;
  }
  DataValueCopy(&value, iterator->data, itemLength);
  return 0;
}