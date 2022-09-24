#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  int bin = open("bin/func.bin", O_RDWR);
  assert(bin >= 0);

  struct stat bin_stat;
  int err = fstat(bin, &bin_stat);
  assert(err >= 0);

  void *bin_addr = mmap(NULL, bin_stat.st_size, PROT_EXEC, MAP_PRIVATE, bin, 0);
  assert(bin_addr != MAP_FAILED);
  ((void (*)(void))bin_addr)();
}
