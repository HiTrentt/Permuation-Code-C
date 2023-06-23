#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void permute(int length, char *target, char *source, bool *used, int index);

int main() {
  char source[] = "cat"; 
  int length = strlen(source); 

  char target[length]; 
  bool used[length]; 

  for (int i = 0; i < length; i++) {
    used[i] = false;
  }

  permute(length, target, source, used, 0);

  return 0;
}

void permute(int length, char *target, char *source, bool *used, int index) {
  if (index == length) {
    for (int i = 0; i < length; i++) {
      printf("%c", target[i]);
    }
    printf("\n"); 

    return; // don't go on to execute the rest of the function
  }

  for (int i = 0; i < length; i++) {
    if (!used[i]) { // go through all the unused items
      used[i] = true; // mark it as used
      target[index] = source[i]; // place it in the right spot
      permute(length, target, source, used, index + 1); // recurse with updated index
      used[i] = false; // unmark it as used
    }
  }
}
