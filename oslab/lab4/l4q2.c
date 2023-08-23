#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main (int argc, char *argv[]) {
	struct stat sb;
	int ret;
	if (argc < 2) {
		fprintf (stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}
	ret = stat (argv[1], &sb);
	if (ret) {
		perror ("stat");
		return 1;
	}
	printf ("Device: %ld \n", sb.st_dev);
	printf ("INODE: %ld \n", sb.st_ino);
	printf ("Mode: %d \n", sb.st_mode);
	printf ("No of hard links: %ld \n", sb.st_nlink);
	printf ("User ID: %d \n", sb.st_uid);
	printf ("Group ID: %d \n", sb.st_gid);
	printf ("Device ID: %ld \n", sb.st_rdev);
	printf ("Size in bytes: %ld \n", sb.st_size);
	printf ("Block Size: %ld \n", sb.st_blksize);
	printf ("No. of blocks allocated: %ld \n", sb.st_blocks);
	printf ("Last access time: %s", asctime(gmtime(&sb.st_atime)));
	printf ("Last Modification time: %s", asctime(gmtime(&sb.st_mtime)));
	printf ("Last status change time: %s", asctime(gmtime(&sb.st_ctime)));
	return 0;
}