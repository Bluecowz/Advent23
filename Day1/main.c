#include "stdio.h"

int main() {
  FILE *file;
  char buf[100];

  file = fopen("input.txt", "r");

  while (fscanf(file, "%s\n", buf) == 1) {
    for (int i = 0; i < sizeof(buf); i++) {
      if (isdigit(buf[i])) {
      }
    }

    return 0;
  }

