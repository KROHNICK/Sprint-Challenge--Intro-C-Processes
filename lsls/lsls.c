#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory = argv[1] ? argv[1] : ".";

  // Open directory
  DIR *d = opendir(directory);

  // Repeatly read and print entries
  struct dirent *entry;
  while ((entry = readdir(d)) != NULL)
  {
    char *name = entry->d_name;
    char path[strlen(directory) + strlen(name) + 1];

    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, name);

    struct stat buf;
    stat(path, &buf);

    printf("%10ld %s\n", buf.st_size, name);
  }

  // Close directory
  closedir(d);

  return 0;
}