#include "../nom.h"

int main(void) {
  Nom_cmd cmd = {0};
  nom_cmd_append_many(&cmd, 2, "echo", "hello");
  nom_run_async(cmd);
  nom_cmd_reset(&cmd);
  nom_cmd_append_many(&cmd, 2, "ls", "--color=always");
  nom_run_async(cmd);
}
