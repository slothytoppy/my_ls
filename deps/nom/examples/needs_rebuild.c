#include "../nom.h"

int main(void) {
  // compares the last modified time of file1 to file2, returns true if the first argument is modified after the second argument
  needs_rebuild(__FILE__, base(__FILE__));
  printf("file first: %d\n", needs_rebuild(__FILE__, base(__FILE__)));
}
