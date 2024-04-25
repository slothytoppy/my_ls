#include "../nom.h"

int main(void) {
  // nom_logs second argument takes fmt style arguments
  // nom_log is a wrapper around nom_gen_log which takes a level, fmt, and a va_list as args
  // nom_logger is an internal struct for logging, everything is on by default
  // nom_logger.new_line can be turned on or off, by default it is on, to turn it off you can do nom_logger.new_line=OFF;
  nom_logger.new_line = ON;
  // nom_logger.show_msg is used to show the msg which is the second argument to nom_log
  nom_logger.show_msg = ON;
  // nom_logger.show_mode is used to show the mode which is [DEBUG], [INFO], etc.
  nom_logger.show_mode = ON;
  // nom_logger.show_debug is used to show messages with the level NOM_DEBUG, if it is off, no debug messages would be shown
  nom_logger.show_debug = ON;
  nom_log(NOM_PANIC, "hello %s", "goodbye");
}
