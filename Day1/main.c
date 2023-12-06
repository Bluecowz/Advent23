#include "ctype.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
  char* word;
  int val;
} word;

const word words[9] = {{"one", 1},   {"two", 2},   {"three", 3},
                       {"four", 4},  {"five", 5},  {"six", 6},
                       {"seven", 7}, {"eight", 8}, {"nine", 9}};

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
  int total, f, l = 0;
  char buf[100];
  FILE* file = fopen("test_two.txt", "r");

  if (file == NULL) {
    printf("Failed to open");
    return;
  }

  while (fgets(buf, sizeof(buf), file) != NULL) {
    char* checks[18] = {"one",   "two",   "three", "four", "five", "six",
                        "seven", "eight", "nine",  "1",    "2",    "3",
                        "4",     "5",     "6",     "7",    "8",    "9"};
    char* nums;
    int f, l;
    const int blen = strlen(buf);

    for (int i = 0; buf[i] != '\0'; i++) {
      for (int x = 0; x < 18; x++) {
        const int len = strlen(checks[x]);
        if(
      }
    }

    // fclose(file);
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

