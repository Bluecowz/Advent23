#include "ctype.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* getSubstr(int pos, int len, char string[]) {
  char* substring = malloc(len + 1);
  int i = 0;
  while (i < len) {
    substring[i] = string[pos + i];
    i++;
  }
  substring[len] = '\0';
  return substring;
}

void part_one() {
  char buf[100];
  int total = 0;
  FILE* file = fopen("input.txt", "r");

  if (file == NULL) {
    printf("Failed to open");
    return;
  }

  while (fgets(buf, sizeof(buf), file) != NULL) {
    for (int i = 0; buf[i] != '\0'; i++) {
      if (isdigit(buf[i])) {
        int f = buf[i] - '0';
        int l = buf[i] - '0';
        while (buf[i] != '\0') {
          if (isdigit(buf[i])) {
            l = buf[i] - '0';
          }
          i++;
        }

        int num = f * 10 + l;
        total += num;
        break;
      }
    }

    ;
  }

  fclose(file);
  printf("Sum: %d\n", total);
}

void part_two() {
  int total = 0;
  int f, l = 0;
  char buf[100];
  FILE* file = fopen("input.txt", "r");

  if (file == NULL) {
    printf("Failed to open");
    return;
  }

  char* checks[18] = {"one",   "two",   "three", "four", "five", "six",
                      "seven", "eight", "nine",  "1",    "2",    "3",
                      "4",     "5",     "6",     "7",    "8",    "9"};

  while (fgets(buf, sizeof(buf), file) != NULL) {
    char* nums;
    int f, l = 0;
    const int blen = strlen(buf);

    for (int i = 0; buf[i] != '\0'; i++) {
      for (int x = 0; x < 18; x++) {
        const int len = strlen(checks[x]);
        if (len + i >= blen) continue;
        char* t = getSubstr(i, len, buf);
        if (strcmp(checks[x], t) == 0) {
          int tmp = x;
          if (tmp > 8) tmp -= 9;
          tmp += 1;
          if (f < 1) {
            f = tmp;
            l = tmp;
          } else {
            l = tmp;
          }
        }
        free(t);
      }
    }
    int derp = (f * 10) + l;
    // printf("%d\n", derp);
    total += derp;
    f = 0;
  }
  fclose(file);
  printf("Sum: %d\n", total);
}

int main() {
  // this is part 1
  //

  printf("Part One:\n");
  part_one();

  printf("\n\nPart Two:\n");
  part_two();

  return 0;
}

