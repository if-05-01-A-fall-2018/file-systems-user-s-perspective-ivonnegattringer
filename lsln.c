#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char const *argv[]) {
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL) return -1;
    while ((de = readdir(dr)) != NULL) {
      struct stat f;
      if(stat(de->d_name,&f) < 0) return 1;
      printf("\n");

      if(S_ISBLK(f.st_mode)) printf("b");
      else if (S_ISREG(f.st_mode)) printf("-");
      else if (S_ISDIR(f.st_mode)) printf("d");
      else if (S_ISCHR(f.st_mode)) printf("c");
      else if (S_ISLNK(f.st_mode)) printf("l");

      if (f.st_mode & S_IRUSR)printf("r");
      else printf("-");
      if (f.st_mode & S_IWUSR)printf("w");
      else printf("-");
      if (f.st_mode & S_IXUSR)printf("x");
      else printf("-");
      if (f.st_mode & S_IRGRP)printf("r");
      else printf("-");
      if (f.st_mode & S_IWGRP)printf("w");
      else printf("-");
      if (f.st_mode & S_IXGRP)printf("x");
      else printf("-");
      if (f.st_mode & S_IROTH)printf("r");
      else printf("-");
      if (f.st_mode & S_IWOTH)printf("w");
      else printf("-");
      if (f.st_mode & S_IXOTH)printf("x ");
      else printf("- ");
      
      printf("%d ",f.st_uid);
      printf("%d ",f.st_gid);
      printf("%ld \t",f.st_size);
      char time[18];
      strftime(time, 18, "%Y-%m-%d-%H-%M", localtime(&f.st_mtime));
      printf("%s ",time);
      printf("%s",de->d_name );

    }
  closedir(dr);
  return 0;
}
