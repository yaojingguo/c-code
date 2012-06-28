#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, const char *argv[]) 
{
	int fd;
	char *filename = "nonexistent";

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror("open error");
	}
	
	return 0;
}
