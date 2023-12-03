#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  FILE* file;
  char buf[100];
  int total = 0;
  int count = 0;

  file = fopen("input.txt", "r");

  while (fscanf(file, "%s", buf) == 1) {
    count++;
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
    printf("%s -> %s - %d\n", buf, str, num);
    total += num;
  }

  fclose(file);
  printf("Lines: %d\n", count);
  printf("Sum: %d\n", total);
  return 0;
}

