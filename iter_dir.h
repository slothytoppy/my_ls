#include "./deps/nom/nom.h"

Nom_cmd iter_dir(char* dir) {
  Nom_cmd dir_list = {0};
  if(dir == NULL) {
    return dir_list;
  }
  DIR* dirp = opendir(dir);
  struct dirent* dirent;
  for(int i = 0; (dirent = readdir(dirp)) != NULL; i++) {
    if(strlen(dirent->d_name) <= 2 && dirent->d_name[0] == '.' || dirent->d_name[1] == '.') {
      continue;
    }
    nom_cmd_append(&dir_list, dirent->d_name);
  }
  return dir_list;
}
