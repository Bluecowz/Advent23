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
    regmatch_t match;
    while (regexec(&regex, buf, 1, &match, 0) == 0) {
      if (match.rm_so == (size_t)-1) break;

      char* substr = malloc(255);
      strncpy(substr, buf + match.rm_so, match.rm_eo - match.rm_so);
      printf("Start: %d | End: %d | Value: %s\n", match.rm_so, match.rm_eo,
             substr);
      strncpy(buf, buf + match.rm_eo, sizeof(buf) - match.rm_eo);
    }
    break;
  }
}

int main() {
  printf("Part One:\n");
  part_one();
  return 0;
}
