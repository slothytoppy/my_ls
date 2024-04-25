#ifndef STR_VIEW_H
#define STR_VIEW_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Str_view {
  unsigned len;
  char* data;
};

typedef struct Str_view str_view;

char* cstr_trim_left(char* str, long int count) {
  return str + count;
}

char* cstr_trim_right(char* str, long int count) {
  char* dst = NULL;
  return (char*)memcpy(dst, str, strlen(str) - count);
}

char* cstr_chop_left(char* str) {
  long int i = 0;
  char* dst = NULL;
  for(i = 0; i < strlen(str) && str[i] == ' '; i++) {
  }
  return (char*)memcpy(dst, str, i);
}

char* cstr_chop_right(char* str) {
  long int i = 0;
  char* dst = NULL;
  for(i = strlen(str); i > 0 && str[i] == ' '; i++) {
  }
  return (char*)memcpy(dst, str, i);
}

bool cstr_prefix(char* src, char* dst) {
  if(src == NULL || dst == NULL) {
    return false;
  }
  for(int i = 0; i < strlen(dst); i++) {
    if(src[i] != dst[i]) {
      return false;
    }
  }
  return true;
}

bool cstr_suffix(char* src, char* dst) {
  if(src == NULL || dst == NULL) {
    return false;
  }
  char* src_copy = src + strlen(src) - strlen(dst);
  return cstr_prefix(src_copy, dst);
}

bool cstr_equal(char* src, char* dst) {
  if(src == NULL || dst == NULL || strlen(src) != strlen(dst)) {
    return false;
  }
  if(memcmp(src, dst, strlen(src)) == 0) {
    return true;
  } else {
    return false;
  }
}

str_view sv_from_parts(char* data, unsigned len) {
  str_view sv = {.data = data, .len = len};
  return sv;
}

unsigned sv_equal(str_view a, str_view b) {
  if(a.len != b.len) {
    return 0;
  }
  if(memcmp(a.data, b.data, a.len) == 0) {
    return 1;
  } else {
    return 0;
  }
}

str_view sv_from_cstr(char* data) {
  return sv_from_parts(data, strlen(data));
}

str_view sv_trim_left(str_view sv, unsigned count) {
  return sv_from_parts(sv.data + count, sv.len - count);
}

str_view sv_trim_right(str_view sv, unsigned count) {
  return sv_from_parts(sv.data, sv.len - count);
}

str_view sv_chop_left(str_view sv) {
  int i = 0;
  for(i = 0; i < sv.len && sv.data[i] == ' '; i++)
    ;
  return sv_from_parts(sv.data + i, sv.len - i);
}

str_view sv_chop_right(str_view sv) {
  int i = 0;
  for(i = 0; i < sv.len && sv.data[sv.len - i] == ' '; i++)
    ;
  return sv_from_parts(sv.data, sv.len - i);
}

void sv_print(str_view sv) {
  if(sv.len < 0) {
    return;
  }
  printf("%.*s\n", sv.len, sv.data);
  return;
}

str_view sv_concat(str_view dest, str_view src) {
  str_view cpy;
  cpy.data = (char*)calloc(1, dest.len + src.len);
  memcpy(cpy.data, dest.data, dest.len);
  memcpy(cpy.data + dest.len, src.data, src.len);
  cpy.len = dest.len + src.len;
  return cpy;
}

unsigned sv_prefix(str_view sv, str_view prefix) {
  if(prefix.len <= sv.len) {
    str_view expected = sv_from_parts(sv.data, prefix.len);
    return sv_equal(expected, prefix);
  }
  return 0;
}

unsigned sv_suffix(str_view sv, str_view suffix) {
  if(suffix.len <= sv.len) {
    str_view expected = sv_from_parts(sv.data + sv.len - suffix.len, suffix.len);
    return sv_equal(expected, suffix);
  }
  return 0;
}

#endif // STR_VIEW_H
