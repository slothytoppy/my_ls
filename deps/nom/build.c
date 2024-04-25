#define NOM_IMPLEMENTATION
#include "nom.h"

int main(int argc, char* argv[]) {
  rebuild(argc, argv, __FILE__, "gcc");
  IS_LIBRARY_MODIFIED("nom.h", "build.c", "gcc");
  for(int i = 0; argv[i]; i++) {
    printf("%s ", argv[i]);
  }
  printf("\n");
  /*
  nom_log(NOM_WARN, "hello");
  nom_log(NOM_DEBUG, "hello");
  nom_log(NOM_INFO, "hello");
  nom_log(NOM_PANIC, "hello");
  nom_log(NOM_NONE, "hello");
  nom_logger_reset();
  */
  /*
  if(IS_PATH_DIR("hello")) {
    nom_log(NOM_INFO, "yes");
  }
  */
}
