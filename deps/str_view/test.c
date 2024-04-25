#include "str_view.h"

int main(void) {
  str_view sv = {0};
  str_view dest = sv_from_parts("hel", 3);
  str_view src = sv_from_parts("lo", 2);
  sv = sv_concat(dest, src);
  sv_print(sv);
  return 0;
}
