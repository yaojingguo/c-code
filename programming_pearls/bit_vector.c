#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N/BITSPERWORD]

void set(int i) {
  a[i>>SHIFT] |= (1 << (i & MASK));
}

void clr(int i) {
}

int test(int i) {
}
