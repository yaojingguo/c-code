#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>


void parent_process(int fd) {
	int i;
	fprintf(stderr, "FD of parent process: %d.\n", fd);
	for (i = 0; i < 16; i++) {
		ssize_t l;
		int32_t r_buf;
		int32_t w_buf;
		w_buf = (int32_t)(i);
		l = read(fd, &r_buf, sizeof(r_buf));
		fprintf(stderr, "P: read (%d): %d\n", (int)(l), r_buf);
		l = write(fd, &w_buf, sizeof(w_buf));
		fprintf(stderr, "P: wrote (%d)\n", (int)(l));
	}
	close(fd);
}

void child_process(int fd) {
	int i;
	fprintf(stderr, "FD of child process: %d.\n", fd);
	for (i = 0; i > -16; i--) {
		ssize_t l;
		int32_t r_buf;
		int32_t w_buf;
		w_buf = (int32_t)(i);
		l = write(fd, &w_buf, sizeof(w_buf));
		fprintf(stderr, "C: wrote (%d)\n", (int)(l));
		l = read(fd, &r_buf, sizeof(r_buf));
		fprintf(stderr, "C: read (%d): %d\n", (int)(l), r_buf);
	}
	close(fd);
}

int main(int argc, char ** argv) {
	pid_t child_pid;
	int socket_vector[2];

	if(0 != socketpair(AF_UNIX, SOCK_STREAM, 0, socket_vector)) {
		perror("cannot create socket pair");
		return 2;
	}

	child_pid = fork();
	if(-1 == child_pid) {
		perror("cannot fork process");
		return 2;
	} else if (0 == child_pid) {
		close(socket_vector[0]);
		child_process(socket_vector[1]);
	} else {
		fprintf(stderr, "PID of child process: %d.\n", (int)(child_pid));
		close(socket_vector[1]);
		parent_process(socket_vector[0]);
	}
	return 0;
}
