#include "../nom.h"

int main(void) {
  // makes file "hello" if it doesnt already exist, it can also deal with slashes like "./dir/dir2/file"
  mkfile_if_not_exist("hello");
  // like mkfile_if_not_exist, it can also deal with nested directories
  mkdir_if_not_exist("./dir1/dir2/dir3");
  // IS_PATH_DIR and IS_PATH_FILE checks where path is a dir or a file and IS_PATH_EXIST checks where path exists
  IS_PATH_DIR("file");
  IS_PATH_FILE("file");
  IS_PATH_EXIST("file");
  // base() takes a char* and returns a char* without any dots in it
  base("file.c");
}
