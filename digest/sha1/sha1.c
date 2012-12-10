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

// block: 64 bytes
// digest: 20 bytes
// void process_block(uint8_t* block, uint8_t* digest)
void process_block(uint8_t* block, uint32_t* H)
{
  uint32_t W[80];
  uint32_t temp, A, B, C, D, E;
  int i, t;


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

  // printf("            A        B        C        D        E\n");
  for (t = 0; t <= 79; ++t) {
    temp = S(5, A) + f(t, B, C, D) + E + W[t] + K(t);
    E = D;
    D = C;
    C = S(30, B);
    B = A;
    A = temp;
    // printf("t = %2d: %08x %08x %08x %08x %08x\n", t, A, B, C, D, E);
  }

  H[0] += A;
  H[1] += B;
  H[2] += C;
  H[3] += D;
  H[4] += E;
  // printf("     H: %08x %08x %08x %08x %08x\n", H[0], H[1], H[2], H[3], H[4]);
}

// l: byte length
uint8_t* sha1(uint8_t *message, uint64_t l, uint32_t* H)
{
  uint64_t nblock, iblock;
  uint8_t block[64];
  int nremainder;

  nblock = l / 64;
  nremainder = l % 64; 

  H[0] = 0x67452301;
  H[1] = 0xEFCDAB89;
  H[2] = 0x98BADCFE;
  H[3] = 0x10325476;
  H[4] = 0xC3D2E1F0;

  for (iblock = 0; iblock < nblock; ++iblock) {
    memcpy(block, message, 64);
    process_block(block, H);
    message += 64;
  }

  memset(block, 0, 64);
  memcpy(block, message, nremainder);
  if (nremainder >= 56 ) { 
    block[nremainder++] = 0x80; 
    process_block(block, H);
    memset(block, 0, 64);
  } else {
    block[nremainder++] = 0x80;
  }

  int j;
  l *= 8;
  for (j = 0; j < 8; j++) {
    block[56 + j] = (uint8_t) ((l >> (8 * (7 - j))) & 0xFF);
  }
  process_block(block, H);
}

#define TEST1 "abc"
#define TEST2 "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
// #define TEST3   "a"
// #define TEST4a  "01234567012345670123456701234567"
// #define TEST4b  "01234567012345670123456701234567"
// an exact multiple of 512 bits
#define TEST4   TEST4a TEST4b
#define M 1000000

void info(uint32_t* digest) 
{
  printf("  sha1: %08x %08x %08x %08x %08x\n", 
         digest[0], 
         digest[1], 
         digest[2], 
         digest[3], 
         digest[4]);
}
int main(int argc, const char *argv[]) 
{
  uint32_t digest[5];
  // sha1(TEST1, strlen(TEST1), digest);
  // sha1(TEST2, strlen(TEST2), digest);

  uint8_t* ma = (uint8_t*) malloc(M);
  memset(ma, 'a', M);
  sha1(ma, M, digest);
  info(digest);
  free(ma);
  return 0;
}
