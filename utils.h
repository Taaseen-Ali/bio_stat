#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define READ_BUFFER_SIZE 1000

void usage();
char* get_seq(char* file);
int read_len(char* file);
int search_seq(char* seq, char* read);
