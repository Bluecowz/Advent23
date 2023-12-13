#include "regex.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void part_one() {
  /**
   * 12 RED
   * 13 GREEN
   * 14 BLUE
   */

  char buf[100000];
  regex_t regex;
  char* match_s = "(([1-9]+) (blue|red|green))";
  int value;
  const int maxGroups = 32;
  regmatch_t groupArray[maxGroups];
  FILE* file = fopen("test_one.txt", "r");

  if (file == NULL) {
    printf("Error opening file.");
    return;
  }

  value = regcomp(&regex, match_s, REG_EXTENDED);
  if (value != 0) {
    printf("Regex did not compile.");
    return;
  }

  while (fgets(buf, sizeof(buf), file) != NULL) {
    int rc = 0;
    if (0 != (rc = regexec(&regex, buf, maxGroups, groupArray, 0))) {
      printf("Failed to match '%s' with '%s', returned %d\n", match_s, buf, rc);
    } else {
      for (int i = 0; i < maxGroups; i++) {
        if (groupArray[i].rm_so == (size_t)-1) break;

        // use strcpy to get substring from buffer:
        char* substr = malloc(255);
        strncpy(substr, buf + groupArray[i].rm_so,
                groupArray[i].rm_eo - groupArray[i].rm_so);
        printf("Start: %d | End: %d | Value: %s\n", groupArray[i].rm_so,
               groupArray[i].rm_eo, substr);
      }
    }
    break;
  }
}

int main() {
  printf("Part One:\n");
  part_one();
  return 0;
}
