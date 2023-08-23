#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	struct stat sb;
	int ret;
	if (argc < 2) {
		fprintf (stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}
	ret = link (argv[1], "/home/student/210905170_OSLAB/lab4exprin");
	if(ret) {
		perror("Error");
		return 1;
	}
	unlink("/home/student/210905170_OSLAB/lab4expri");
	return 0;
}