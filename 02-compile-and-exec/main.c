#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  system("gcc func.c -c -s -nostartfiles "
         "-fno-asynchronous-unwind-tables -fomit-frame-pointer -march=x86-64");

  int bin = open("func.o", O_RDWR);
  assert(bin >= 0);

  struct stat bin_stat;
  int err = fstat(bin, &bin_stat);
  assert(err >= 0);

  void *bin_addr = mmap(NULL, bin_stat.st_size, PROT_EXEC, MAP_PRIVATE, bin, 0);
  void *func_addr = bin_addr + 0x44;
  assert(bin_addr != MAP_FAILED);
  int res = ((int (*)(void))func_addr)();
  printf("Result: %d\n", res);
}
