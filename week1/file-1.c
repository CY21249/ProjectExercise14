#include <fcntl.h>

int checkSyscallError(int res, char* comment);

int main() {
	char buff[10];
	int fd;
	fd = checkSyscallError(
		open("test.txt", O_RDONLY),
		"open:"
	);
	checkSyscallError(
		read(fd, buff, 10),
		"read"
	);
	checkSyscallError(
		write(2, buff, 10),
		"write"	
	);
	close(fd);
}

int checkSyscallError(int res, char* comment) {
	if (res < 0) {
		perror(comment);
		exit(1);
	}
	return res;
}
