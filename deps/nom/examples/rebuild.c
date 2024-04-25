#include "../nom.h"

int main(int argc, char** argv) {
  // rebuild() takes argc and argv so that if your program takes cli arguments it can still use them after its been rebuilt.
  // rebuild will compile your program(third argument) with the compiler(last arg) and will produce an executable which is the file name minus the extension
  rebuild(argc, argv, __FILE__, "gcc");
  // rebuild1 works like rebuild except it doesnt take any cli arguments like argc or argv
  rebuild1(__FILE__, "gcc");
}
