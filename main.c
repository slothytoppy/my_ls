#include "./deps/colors.h"
#include "./deps/nom/nom.h"
#include "./deps/str_view/str_view.h"
#include "./iter_dir.h"

char* file_perms(char* file) {
  char* perms = calloc(1, 9);
  struct stat fi;
  stat(file, &fi);
  char _perms[4] = "rwx-";
  perms[0] = (fi.st_mode & S_IRUSR) ? _perms[0] : _perms[3];
  perms[1] = (fi.st_mode & S_IWUSR) ? _perms[1] : _perms[3];
  perms[2] = (fi.st_mode & S_IXUSR) ? _perms[2] : _perms[3];
  perms[3] = (fi.st_mode & S_IRGRP) ? _perms[0] : _perms[3];
  perms[4] = (fi.st_mode & S_IWGRP) ? _perms[1] : _perms[3];
  perms[5] = (fi.st_mode & S_IXGRP) ? _perms[2] : _perms[3];
  perms[6] = (fi.st_mode & S_IROTH) ? _perms[0] : _perms[3];
  perms[7] = (fi.st_mode & S_IWOTH) ? _perms[1] : _perms[3];
  perms[8] = (fi.st_mode & S_IXOTH) ? _perms[2] : _perms[3];
  return perms;
}

char* fsize_to_cstr(char* file) {
  struct stat fi;
  stat(file, &fi);
  struct tm* tm = localtime(&fi.st_mtime);
  char* time = calloc(1, 200);
  memset(time, '\0', 200);
  strftime(time, 200, "%a %H:%M:%S", tm);
  return time;
}

int main(int argc, char** argv) {
  char* fsize = calloc(1, sizeof(long int));
  Nom_cmd dir = {0};
  if(argc <= 1) {
    dir = iter_dir(".");
    for(int i = 0; i < dir.count; i++) {
      snprintf(fsize, sizeof(long int), "%li", nom_get_fsize(dir.items[i]));
      printf("%s %s %s %s\n", file_perms(dir.items[i]), fsize, fsize_to_cstr(dir.items[i]), dir.items[i]);
    }
  }
  if(argc > 1 && !IS_PATH_EXIST(argv[1])) {
    nom_log(NOM_WARN, "no such file or dir\n");
    return 1;
  }
  if(IS_PATH_FILE(argv[1])) {
    snprintf(fsize, sizeof(long int), "%li", nom_get_fsize(argv[1]));
    printf("%s %s %s %s\n", file_perms(argv[1]), fsize, fsize_to_cstr(argv[1]), argv[1]);
  } else {
    dir = iter_dir(argv[1]);
    for(int i = 0; i < dir.count; i++) {
      snprintf(fsize, sizeof(long int), "%li", nom_get_fsize(dir.items[i]));
      printf("%s %s %s %s\n", file_perms(dir.items[i]), fsize, fsize_to_cstr(dir.items[i]), dir.items[i]);
    }
  }
  return 0;
}
