#include <stdio.h>
#include <sys/mman.h>

#include "../../nom.h"
int main(int argc, char* argv[]) {
  int file = open(argv[0], O_RDWR);
  if(file < 0) {
    nom_log(NOM_WARN, "%s", strerror(errno));
    return 1;
  }
  struct stat fi;
  if(stat(argv[0], &fi) < 0) {
    nom_log(NOM_WARN, "%s", strerror(errno));
    return 1;
  }
  char* ptr = mmap(ptr, fi.st_size, MAP_PRIVATE, PROT_READ | PROT_WRITE, file, 0);
  if(ptr == NULL) {
    nom_log(NOM_WARN, "%s", strerror(errno));
    return 1;
  }
  printf("%s\n", ptr);
}
