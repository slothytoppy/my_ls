#include "nom.h"

int main(void) {
  char* in_name = "copy.h";
  if(IS_PATH_EXIST(in_name)) {
    remove(in_name);
  }
  mkfile_if_not_exist(in_name);
  char* file = map_file_into_memory(in_name);
  char* start = "#ifndef NOM_IMPLEMENTATION\n#define NOM_IMPLEMENTATION\n";
  char* end = "\n#endif // NOM_IMPLEMENTATION\n";
  int fd = open(in_name, O_RDWR);
  int c_fd = open("nom.h", O_RDWR);
  write(fd, start, strlen(start));
  long int fsize = nom_get_fsize("nom.h");
  char* buf = map_file_into_memory("nom.h");
  write(fd, buf, fsize);
  write(fd, end, strlen(end));
  char* path = "./home/slothy/base";
  printf("before %s\nafter %s\n", path, file_name(path, '/'));
}
