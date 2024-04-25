#include "../nom.h"

int main(int argc, char** argv) {
  // this function checks whether header.h has been modified after file.c and if it has, it rebuilds file.c with a compiler(the last arg). It doesnt take cli args(argc and argv)
  IS_LIBRARY_MODIFIED("header.h", "file.c", "gcc");
}
