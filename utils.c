#include "utils.h"

void usage(){
  printf("USAGE \n");
}

char* get_seq(char* file){
  FILE* fd = fopen(file, "rb");

  if(!fd)
    printf("Error opening file: %s\n",strerror(errno));

  if(fseek(fd, 0, SEEK_END))
    printf("error reading file");
 
  int size = ftell(fd);
  char* string = malloc(size*sizeof(char));
 
 printf("%d\n", size);
}

int num_reads(char* file){

  FILE* fd = fopen(file, "rb");
  char read[READ_BUFFER_SIZE];
  int lines;
    
  if(!fd)
    printf("Error opening file: %s\n",strerror(errno));
  
  fgets(read, READ_BUFFER_SIZE, fd);
  for(lines=0; fgets(read, READ_BUFFER_SIZE, fd); lines++);

  return lines/3;
}

int read_len(char* file){

  int fd= open(file, O_RDONLY);
  int size;
  char read_buf[READ_BUFFER_SIZE];

  if(!fd)
    printf("Error opening file: %s\n",strerror(errno));

  read(fd, read_buf, READ_BUFFER_SIZE);
  size = read(fd, read_buf, READ_BUFFER_SIZE);

  int line;
  while(size=read(fd, read_buf, READ_BUFFER_SIZE)){
    if(line!=size | line!=1)
      return 0;
  }
  return size;
}
int main(int argc, char* argv[]){
  if(argc>1){
    printf("num reads in %s: %d\n", argv[1], num_reads(argv[1]));
    printf("num bases per read in %s: %d\n", argv[1], read_len(argv[1]));
  }
  else
    usage();
}

