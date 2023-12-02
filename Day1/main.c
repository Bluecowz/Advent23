#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  FILE *file;
  char buf[255];
  int total = 0;

  file = fopen("test.txt", "r");

  while (fscanf(file, "%s\n", buf) == 1) {
    int s = strlen(buf);
    char nums[2] = "\0";

    for (int i = 0; i < s; i++) {
      char derp = buf[i];
      if (isdigit(derp)) {
        printf("%s\n", &derp);
        nums[0] = derp;
        break;
      }
    }

    for (int i = s - 1; i >= 0; i--) {
      char derp = buf[i];
      if (isdigit(derp)) {
        printf("%s\n", &derp);
        nums[1] = derp;
        break;
      }
    }

    printf("%s\n", nums);
    int num = atoi(nums);
    printf("%d\n", num);
    total += num;

    return 0;
  }

  fclose(file);
  printf("Sum: %d\n", total);
  return 0;
}

