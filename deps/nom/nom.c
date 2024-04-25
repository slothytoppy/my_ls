#define NOM_IMPLEMENTATION
#include "nom.h"

int main(int argc, char* argv[]) {
  nom_logger.show_debug = OFF;
  // every function that can succeed should return either Nom_cmd or 1 on success and on failure it should return either a null nom_cmd or 0
  // nom_logger contains a variable that makes debug mode on by default
  // to disable debug info set nom_logger.debug_mode to anything but 0
  rebuild(argc, argv, __FILE__, "gcc");
  // Nom_cmd is a dynamic array for running commands
  Nom_cmd cmd = {0};
  nom_cmd_append_many(&cmd, 2, "/usr/bin/eza", "-l");
  nom_log_cmd(NOM_INFO, "cmd->", cmd);
  pid_t pid = start_process(cmd);
  nom_log(NOM_INFO, "%d", pid);
  nom_run_sync(cmd);
  // nom_run_async and nom_run_sync both run in PATH
  // nom_run_path(Nom_cmd, char** args) takes a path like ~/build/bin to execute with args, args can be NULL
  // there is nom_cmd_shrink which is used as follows:
  // nom_cmd_shrink(&cmd, count, arr of ints)
  // it removes the elements that are in the array up to count
  // nom_print_cmd(NOM_INFO, "cmd->", &cmd);
  nom_cmd_reset(&cmd);
  nom_log_cmd(NOM_INFO, "cmd again->", cmd);
  nom_cmd_append_many(&cmd, 2, "./build", "build");
  nom_run_path(cmd, argv);
  nom_log_cmd(NOM_INFO, "cmd again->", cmd);
  // nom_log(NOM_INFO, "hello");
  // nom_run_path and nom_run_sync both return 1 on success and 0 on failure
  //  nom_run_async returns pid on success and 0 on failure
}
