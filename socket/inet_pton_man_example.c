#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info(const char *buf, long len)
{
  int i;
  
  for (i = 0; i < len; i++) {
    if (i == 0)
      printf("0x");
    printf("%02x", buf[i]);
  }

  if (i > 0)
    printf("\n");
}

int main(int argc, char *argv[])
{
  unsigned char buf[sizeof(struct in6_addr)];
  int domain, s;
  char str[INET6_ADDRSTRLEN];
  long len;
  const char *af;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s {i4|i6|<num>} string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  af = argv[1];
  if (strcmp(af, "i4") == 0) {
    domain = AF_INET;
    len = sizeof(struct in_addr);
  } else if (strcmp(af, "i6") == 0) {
    domain = AF_INET6;
    len = sizeof(struct in6_addr);
  } else {
    fprintf(stderr, "Unsupported address familiy: %s", af);
    exit(EXIT_FAILURE);
  }

  s = inet_pton(domain, argv[2], buf);
  if (s <= 0) {
    if (s == 0)
      fprintf(stderr, "Not in presentation format");
    else
      perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  info(buf, len);

  if (inet_ntop(domain, buf, str, INET6_ADDRSTRLEN) == NULL) {
    perror("inet_ntop");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", str);

  exit(EXIT_SUCCESS);
}
