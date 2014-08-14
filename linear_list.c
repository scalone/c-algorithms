#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define LIST_MAX_LEN 10

typedef char Node;

void initialize(Node list[LIST_MAX_LEN], int *pos_final) {
  int x;

  // clear list
  for(x = 0; x < LIST_MAX_LEN; ++x) {
    list[x] = '\0'; // Caractere nulo (ASCII 0)
  }

  // -1 convetion, means the list is clean
  *pos_final = -1;

}

// 0  - Sucess
// -1 - Error
int insert(Node list[LIST_MAX_LEN], int position, Node new, int *pos_final) {
  // 1) Empty list, could insert only on first position
  if(*pos_final < 0 && position != 0) {
    printf("%s", "Error: Empty list, you can't enter on this position.\n");
    return -1; // ERROR
  }

  // 2) List full
  if(position >= LIST_MAX_LEN) {
    printf("%s", "Error: Full list.\n");
    return -1; // ERROR
  }

  // 3) Insert at the end of list.
  if(position == *pos_final + 1) {
    (*pos_final)++;
    list[position] = new;
    return 0; // OK
  }

  // 4) Insert at the beginning or middle of list
  if(position >= 0 && position <= *pos_final) {
    // Check if list is full
    if(*pos_final == LIST_MAX_LEN - 1) {
      printf("%s", "Error: Full list.\n");
      return -1; // ERROR
    }

    // Move for next position
    int i;
    for(i = *pos_final; i >= position; --i) {
      list[i + 1] = list[i];
    }

    list[position] = new;

    (*pos_final)++;

    return 0; // OK
  }
}

int delete(Node list[LIST_MAX_LEN], int position, int *pos_final) {

  // 1) Empty list
  if(*pos_final < 0) {
    printf("%s", "Error: Empty list, you can't remove this position.\n");
    return -1;
  }

  // 2) Out of list range
  if(position > *pos_final) {
    printf("%s", "Error: Out of range.\n");
    return -1;
  }

  // 3) Remove last list postion
  if(position == *pos_final) {
    list[position] = '\0';
    (*pos_final)--; // ou: *pos_final -= 1; ou: *pos_final = *pos_final - 1
    return 0;
  }

  // 4) Remove at the beginning or middle of list
  else {
    // Arrange position, fix any white space
    int x;
    for(x = position; x < *pos_final; x++) {
      list[x] = list[x + 1];
    }

    // Clear garbage at last position
    list[*pos_final] = '\0';

    (*pos_final)--;

    return 0;
  }
}

void show(Node list[LIST_MAX_LEN], int pos_final) {
  // Empty List
  if(pos_final < 0) {
    printf("%s", "(empty)\n\n");
  }
  else {
    int i;
    // count
    for(i = 0; i <= pos_final; ++i) {
      printf("%d ", i);
    }
    printf("%s", "\n");

    for(i = 0; i <= pos_final; ++i) {
      printf("%c ", list[i]);
    }
    printf("%s", "\n\n");
  }
}

char menu(void) {
  char option;

  do {
    option = '\0';
    printf("\nOperation\n (i)nsert\n (r)remove\n (c)lear\n (s)how\n (e)xit? \n");
    scanf("%c", &option);
    getchar();
  } while (option != 'i' && option != 'r' && option != 'e' && option != 'c' && option != 's');

  return option;
}

int main(int argc, char *argv[]) {
  Node list[LIST_MAX_LEN], new;
  int pos_final, pos_insert, pos_remove;

  initialize(list, &pos_final);
  show(list, pos_final);

  while(1) {
    char option = menu();
    switch(option) {
      case 'i':
        printf("\n\nInform new element (character): ");
        scanf("%c", &new);
        getchar();

        printf("\nPosition to insert: ");
        scanf("%d", &pos_insert);
        getchar();

        insert(list, pos_insert, new, &pos_final);
        break;

      case 'r':
        printf("\nPosition to delete: ");
        scanf("%d", &pos_remove);
        getchar();

        delete(list, pos_remove, &pos_final);
        break;

      case 'c':
        initialize(list, &pos_final);
        break;

      case 's':
        show(list, pos_final);

      default:
        exit(0);
    }

    show(list, pos_final);
  }

  return 0;
}

