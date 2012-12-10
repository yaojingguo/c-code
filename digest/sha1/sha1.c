#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define S(bits,word) \
  (((word) << (bits)) | ((word) >> (32-(bits))))

uint32_t f(int t, uint32_t B, uint32_t C, uint32_t D) 
{
  if (0 <= t && t <= 19)
    return (B & C) | (~B & D);
  else if (20 <= t && t <= 39 || 60 <= t && t <= 79)
   return B ^ C ^ D;
  else if (40 <= t && t <= 59)
    return (B & C) | (B & D) | (C & D);
  else
    assert(0);
}

uint32_t K(int t) 
{
  if (0 <= t && t <= 19)
    return 0x5A827999;
  else if (20 <= t && t <= 39)
    return 0x6ED9EBA1;
  else if (40 <= t && t <= 59)
    return 0x8F1BBCDC;
  else if (60 <= t && t <= 79)
    return 0xCA62C1D6;
  else 
    assert(0);
}

uint8_t* pad(uint8_t* in, int inl, uint64_t l, uint8_t* block)
{
  int i;
  uint8_t* p;

  memset(block, 0, 64);
  memcpy(block, in, inl);
  block[inl] = 0x80;

  block += 56;
  l *= 8;
  p = (uint8_t*) &l;
  for (i = 0; i <= 7; ++i)
    block[i] = p[7-i];
}

// block: 64 bytes
// digest: 20 bytes
void process_block(uint8_t* block, uint8_t* digest)
{
  uint32_t W[80];
  uint32_t temp, A, B, C, D, E;
  uint32_t* H;
  int i, t;

  H = (uint32_t*) digest;
  H[0] = 0x67452301;
  H[1] = 0xEFCDAB89;
  H[2] = 0x98BADCFE;
  H[3] = 0x10325476;
  H[4] = 0xC3D2E1F0;

  for (t = 0; t <= 15; ++t) {
    W[t] = block[4 * t] << 24;
    W[t] |= block[4 * t + 1] << 16;
    W[t] |= block[4 * t + 2] << 8;
    W[t] |= block[4 * t + 3];
  }

  for (t = 16; t <= 79; ++t) 
    W[t] = S(1, (W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]));

  A = H[0]; 
  B = H[1]; 
  C = H[2]; 
  D = H[3]; 
  E = H[4];

  printf("            A        B        C        D        E\n");
  for (t = 0; t <= 79; ++t) {
    temp = S(5, A) + f(t, B, C, D) + E + W[t] + K(t);
    E = D;
    D = C;
    C = S(30, B);
    B = A;
    A = temp;
    printf("t = %2d: %08x %08x %08x %08x %08x\n", t, A, B, C, D, E);
  }

  H[0] += A;
  H[1] += B;
  H[2] += C;
  H[3] += D;
  H[4] += E;
  printf("  sha1: %08x %08x %08x %08x %08x\n", H[0], H[1], H[2], H[3], H[4]);
}

// l: byte length
uint8_t* sha1(uint8_t *message, uint64_t l, uint8_t* digest)
{
  uint64_t nblock, iblock;
  uint8_t block[64];
  int nremainder;

  nblock = l / 64;
  nremainder = l % 64; 

  for (iblock = 0; iblock < nblock; ++iblock) {
    memcpy(block, message, 64);
    process_block(block, digest);
    message += 64;
  }

  memset(block, 0, 64);
  memcpy(block, message, nremainder);
  if (nremainder >= 56 ) { 
  } else {
    block[nremainder++] = 0x80;
  }

  int j;
  l *= 8;
  for (j = 0; j < 8; j++) {
    block[56 + j] = (uint8_t) ((l >> (8 * (7 - j))) & 0xFF);
  }
  process_block(block, digest);
}

// void info(uint8_t* digest)
// {
//   int i;
//   for (i = 0; i < 20; ++i)
//     printf("%02x", digest[i]);
//   printf("\n");
// }

int main(int argc, const char *argv[]) 
{
  uint8_t digest[20];
  uint8_t* message = "abc";
  sha1(message, strlen(message), digest);
  return 0;
}
