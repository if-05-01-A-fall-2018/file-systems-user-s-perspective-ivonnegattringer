#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

struct stat attrib;

int main(int argc, char const *argv[]) {
  if(argc != 2)return 1;

  int s = lstat(argv[1], &attrib);
  if(s<0)return 1;

  printf("File type           :" );
  if(S_ISREG(attrib.st_mode))printf("Regular file");
  else if(S_ISDIR(attrib.st_mode))printf("Directory");
  else if(S_ISBLK(attrib.st_mode))printf("Block device");
  else if(S_ISCHR(attrib.st_mode))printf("Character device");
  else printf("unknown????");
  printf("\n");


  printf("Access privileges  : ");
  if(attrib.st_mode & S_IRUSR) printf("r"); else printf("-");
  if(attrib.st_mode & S_IWUSR) printf("w"); else printf("-");
  if(attrib.st_mode & S_IXUSR) printf("x"); else printf("-");
  if(attrib.st_mode & S_IRGRP) printf("r"); else printf("-");
  if(attrib.st_mode & S_IWGRP) printf("w"); else printf("-");
  if(attrib.st_mode & S_IXGRP) printf("x"); else printf("-");
  if(attrib.st_mode & S_IROTH) printf("r"); else printf("-");
  if(attrib.st_mode & S_IWOTH) printf("w"); else printf("-");
  if(attrib.st_mode & S_IXOTH) printf("x"); else printf("-");
  printf("\n");

  printf("inode-Number       : %ld\n", attrib.st_ino);
  printf("Device numbers     : dev = %ld; rdev = %ld\n", attrib.st_dev, attrib.st_rdev);
  printf("Links count        : %ld\n", attrib.st_nlink);
  printf("UID                : %d\n", attrib.st_uid);
  printf("GID                : %d\n", attrib.st_gid);
  printf("File size          : %ld\n", attrib.st_size);
  printf("Last access        : %ld\n", attrib.st_atime);
  printf("Last modification  : %ld\n", attrib.st_mtime);
  printf("Last inode change  : %ld\n", attrib.st_ctime);

  return 0;
}
