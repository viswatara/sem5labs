#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pwd.h>
#include<sys/types.h>
#include<grp.h>
#include <time.h>
 
char * getUser(uid_t uid) {
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}
 
char * getGroup(gid_t gid) {
    struct group *pws;
    pws = getgrgid(gid);
    return pws->gr_name;
}
 
int main() {
    char cwd[256];
    getcwd(cwd, 256);
    DIR *dp;
    struct dirent *entry;
    struct stat fileStat;
    if((dp = opendir(cwd)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", cwd);
        return 0;
    }
    chdir(cwd);
    while ((entry = readdir(dp)) != NULL) {
        if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
                continue;
        lstat(entry->d_name,&fileStat);
        printf((S_ISDIR(fileStat.st_mode))  ? "d" : "-");
        printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
        printf(" %ld", fileStat.st_nlink);
        printf(" %s", getUser(fileStat.st_uid));
        printf(" %s", getGroup(fileStat.st_gid));
        printf(" %ld", fileStat.st_size);
        printf(" %s", asctime(gmtime(&fileStat.st_mtime)));
        printf(" %s",entry->d_name);        
        printf("\n");
    }
    chdir("..");
    closedir(dp);
}
