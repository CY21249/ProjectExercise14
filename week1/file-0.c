#include <fcntl.h>

int main() {
	char buff[5];
	int fd;
	fd = open("test.txt", O_RDONLY);
	read(fd, buff, 5);
	write(1, buff, 5);
	close(fd);
}
