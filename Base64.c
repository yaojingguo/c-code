#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char table[64] = {
  [0] = 'A',  [1] = 'B',  [2] = 'C',  [3] = 'D', 
  [4] = 'E',  [5] = 'F',  [6] = 'G',  [7] = 'H', 
  [8] = 'I',  [9] = 'J',  [10] = 'K', [11] = 'L', 
  [12] = 'M', [13] = 'N', [14] = 'O', [15] = 'P', 
  [16] = 'Q', [17] = 'R', [18] = 'S', [19] = 'T', 
  [20] = 'U', [21] = 'V', [22] = 'W', [23] = 'X', 
  [24] = 'Y', [25] = 'Z', [26] = 'a', [27] = 'b', 
  [28] = 'c', [29] = 'd', [30] = 'e', [31] = 'f', 
  [32] = 'g', [33] = 'h', [34] = 'i', [35] = 'j', 
  [36] = 'k', [37] = 'l', [38] = 'm', [39] = 'n', 
  [40] = 'o', [41] = 'p', [42] = 'q', [43] = 'r', 
  [44] = 's', [45] = 't', [46] = 'u', [47] = 'v', 
  [48] = 'w', [49] = 'x', [50] = 'y', [51] = 'z', 
  [52] = '0', [53] = '1', [54] = '2', [55] = '3', 
  [56] = '4', [57] = '5', [58] = '6', [59] = '7', 
  [60] = '8', [61] = '9', [62] = '+', [63] = '/'
};

char* encode(unsigned char* s, int len) 
{
  int i, j;
  int reminder;
  int integral;
  char* dst;
  int en_len;

  reminder = len % 3;
  integral =  len - reminder;

  en_len = (len / 3) * 4;
  if (reminder > 0)
    en_len += 4;
  en_len++;

  dst = (char*) malloc(en_len);
  dst[en_len-1] = '\0';

  for (i = 0, j = 0; i < integral; i +=3, j+=4) {
    dst[j]   = table[(0xFCU & s[i]) >> 2];
    dst[j+1] = table[((0x03U & s[i]) << 4) + ((0xF0U & s[i+1]) >> 4)];
    dst[j+2] = table[((0x0FU & s[i+1]) << 2) + ((0xC0U & s[i+2]) >> 6)];
    dst[j+3] = table[0x3FU & s[i+2]];
  }
  if (reminder == 1) {
    dst[j] = table[(0xFCU & s[i]) >> 2];
    dst[j+1] = table[(0x03U & s[i]) << 4];
    dst[j+2] = '=';
    dst[j+3] = '=';
  }
  if (reminder == 2) {
    dst[j] = table[(0xFCU & s[i]) >> 2];
    dst[j+1] = table[((0x03U & s[i]) << 4) + ((0xF0U & s[i+1]) >> 4)];
    dst[j+2] = table[(0x0FU & s[i+1]) << 2];
    dst[j+3] = '=';
  }
  return dst;
}

void test(unsigned char* de, unsigned char* en)
{
  char* dst = encode(de, strlen(de));
  assert(strcmp(en, dst) == 0);
  free(dst);
}

int main(int argc, const char *argv[]) 
{
  test("YOY", "WU9Z");
  test("YOYO", "WU9ZTw==");
  test("YOYO!", "WU9ZTyE=");
  test("6A7x8x9x2", "NkE3eDh4OXgy");
}

