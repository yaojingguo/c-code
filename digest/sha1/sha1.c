#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define S(bits,word) \
  (((word) << (bits)) | ((word) >> (32-(bits))))

char table[] = {
  [0]  = '0',
  [1]  = '1',
  [2]  = '2',
  [3]  = '3',
  [4]  = '4',
  [5]  = '5',
  [6]  = '6',
  [7]  = '7',
  [8]  = '8',
  [9]  = '9',
  [10] = 'a',
  [11] = 'b',
  [12] = 'c',
  [13] = 'd',
  [14] = 'e',
  [15] = 'f'
};

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

// l: byte length
uint8_t* sha1(uint8_t *message, uint64_t l, uint8_t* digest)
{
  // pad
  uint64_t nblock, i;
  int nremainder, t;
  uint8_t last[64];
  uint8_t W[80];
  uint32_t temp, A, B, C, D, E;
  uint32_t* H;

  nblock = l / 64;
  nremainder = l % 64;
  if (nremainder > 0)
    pad(message + nblock * 64, nremainder, l, last);

  H = (uint32_t*) digest;
  H[0] = 0x67452301;
  H[1] = 0xEFCDAB89;
  H[2] = 0x98BADCFE;
  H[3] = 0x10325476;
  H[4] = 0xC3D2E1F0;

  for (i = 0; i <= nblock; ++i) {
    if (i < nblock)
      memcpy(W, message +  64 * i, 64);
    else if (nremainder > 0)
      memcpy(W, last, 64);
    else
      break;
    for (t = 16; t <= 79; ++t) 
      W[t] = S(1, (W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]));
    A = H[0]; 
    B = H[1]; 
    C = H[2]; 
    D = H[3]; 
    E = H[4];
    for (t = 0; t <= 79; ++t) {
      temp = S(5, A) + f(t, B, C, D) + E + W[t] + K(t);
      E = D;
      D = C;
      C = S(30, B);
      B = A;
      A = temp;
    }
    H[0] += A;
    H[1] += B;
    H[2] += C;
    H[3] += D;
    H[4] += E;
  }
}

void to_text(uint8_t* digest, char* text)
{
  int i;
  for (i = 0; i < 20; ++i) {
    text[2*i] = table[digest[i] >> 4];
    text[2*i+1] = table[digest[i] & 0x0F];
  }
}

int main(int argc, const char *argv[]) 
{
  uint8_t digest[20];
  char text[41];
  uint8_t* message = "abc";
  sha1(message, 3, digest);
  text[40] = '\0';
  to_text(digest, text);
  printf("message: %s\n", message);
  // printf("digest: %s\n", digest);
  printf("text: %s\n", text);
  return 0;
}
