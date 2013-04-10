#include <stdio.h>

#define MAX_LEN 100
int f[MAX_LEN];

// Compute failure function
void compute_failure_function(char* b, int n) {
	int t, s;
	t = 0;
	f[0] = 0;
	
	for (s = 0; s < n -1; s++) {
		while (t > 0 && b[s+1] != b[t])
			t = f[t-1];
		if (b[s+1] == b[t]) {
			t++;
			f[s+1] = t;
		} else {
			f[s+1] = 0;
		}
	}
}

// Match keyword
int match_keyword(char* a, int m, char* b, int n) {
	int s, i;
	s = 0;
	for (i = 0; i <= m-1; i++) {
		while (s > 0 && a[i] != b[s])
			s = f[s-1];
		if (a[i] == b[s])
			s++;
		if (s == n)
			return i;
	}
	return -1;
}

void info_failure_function(int n) {
	int i;
	printf("----------------------------\n");
	printf("Failure Function            \n");
	printf("----------------------------\n");
	printf("s    |");
	for (i = 0; i < n; i++) 
		printf("%3d", i);
	printf("\n");
	printf("f(s) |");
	for (i = 0; i < n; i++)
		printf("%3d", f[i]);
	printf("\n");
	printf("----------------------------\n");
}

void info_matched_keyword(char* a, int n, int end, char*b ) {
	if (end < 0) {
		printf("NO MATCH\n");
		return;
	}
	printf("%s\n", a);
	int i;
	int begin;
	begin = end -n + 1;
	for (i = 0; i < begin; i++)
		printf(" ");
	for (i = begin; i <= end; i++)
		printf("%c", b[i - begin]);
	printf("\n");
}

void kmp(char* a, int m, char* b, int n) {
	int end;
	compute_failure_function(b, n);
	info_failure_function(n);
	end = match_keyword(a, m, b, n);
	info_matched_keyword(a, n, end, b);
}

int main(int argc, const char *argv[]) {
	kmp("abababaab", 9, "ababaa", 6);
	kmp("abababbaa", 9, "ababaa", 6);
	return 0;
}
 
