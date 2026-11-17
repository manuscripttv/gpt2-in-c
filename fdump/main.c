#include <ctype.h>
#include <stdio.h>

int hexdmp(const char *path) {

  FILE *f;
  size_t ret;
  size_t totalret;
  unsigned char buf[16];

  // open the file
  f = fopen(path, "rb");
  if (!f) {
    fprintf(stderr, "fdump: ");
    perror(path);
    return 1;
  }

  // read file
  while (1) {
    ret = fread(buf, sizeof(*buf), 16, f);
    if (ret == 0) {
      break;
    }

    // print index position in hex
    printf("%08zx: ", totalret);

    // print hex values of chars before
    for (size_t i = 0; i < ret; i++) {
      printf("%02x", buf[i]);
      if (i % 2 != 0)
        printf(" ");
    }

    // TODO: how much space to delineate?
    // For missing bytes. missing bytes start at ret and end
    // at 16 bytes.
    for (size_t i = ret; i < 16; i++) {
      printf("  ");
      if (i % 2 != 0)
        printf(" ");
    }

    printf(" ");

    // print chars
    for (size_t i = 0; i < ret; i++) {
      if (isprint(buf[i])) {
        printf("%c", buf[i]);
      } else {
        printf(".");
      }
    }

    totalret += ret;
    printf("\n");
  }

  if (ferror(f)) {
    fprintf(stderr, "fdump: ");
    perror(path);
    fclose(f);
    return 1;
  }

  fclose(f);
  return 0;
}

int main(int argc, char **argv) {

  if (argc == 2) {
    return hexdmp(argv[1]);
  } else {
    printf("USAGE %s FILE\n", argv[0]);
  }
}
