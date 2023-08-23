#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	struct stat sb;
	int ret;
	if (argc < 2) {
		fprintf (stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}
	ret = symlink (argv[1], "/home/student/210905170_OSLAB/lab4l4q42");
	printf("New path: /home/student/210905170_OSLAB/lab4l4q42\n");
	if(ret) {
		perror("Error");
		return 1;
	}
	unlink("/home/student/210905170_OSLAB/lab4l4q41");
	return 0;
}