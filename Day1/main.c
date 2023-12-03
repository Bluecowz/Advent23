#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void part_one() {
  FILE* file;
  char buf[100];
  int total = 0;

  file = fopen("input.txt", "r");

  while (fscanf(file, "%s", buf) == 1) {
    int s = strlen(buf);
    char f;
    char l;

    for (int i = 0; i < s; i++) {
      if (isdigit(buf[i])) {
        f = buf[i];
        break;
      }
    }

    for (int i = s - 1; i > -1; i--) {
      if (isdigit(buf[i])) {
        l = buf[i];
        break;
      }
    }

    char str[2] = {f, l};
    int num = atoi(str);
    total += num;
  }

  fclose(file);
  printf("Sum: %d\n", total);
}

void part_two() {
  FILE* file;
  char buf[100];
  int total = 0;
}

int main() {
  // this is part 1
  printf("Part One:\n");
  part_one();

  printf("\n\nPart Two:\n");

  return 0;
}

