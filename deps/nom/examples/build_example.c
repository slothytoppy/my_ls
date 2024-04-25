#include "../nom.h"

int main(int argc, char** argv) {
  rebuild(argc, argv, __FILE__, "gcc");
  Nom_cmd cmd = {0};
  if(needs_rebuild("./example_app/app.c", "./example_app/app")) {
    nom_cmd_append_many(&cmd, 4, "gcc", "./example_app/app.c", "-o", "./example_app/app");
    nom_run_sync(cmd);
    nom_cmd_reset(&cmd);
  }
  nom_cmd_append_many(&cmd, 1, "./example_app/app");
  char* args[] = {__FILE__, NULL};
  nom_run_path(cmd, args);
  nom_cmd_reset(&cmd);
}
