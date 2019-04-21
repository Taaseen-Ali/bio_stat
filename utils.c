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
  while((size=read(fd, read_buf, READ_BUFFER_SIZE))){
    if(line!=size | line!=1)
      return 0;
  }
  return size;
}

int contains_seq(char* to_find, char* seq){
  while((to_find=split_at("n", to_find)){
      int in_seq = split_at(to_find, seq);
      if(in_seq!=-1){
	for(to_find = split_at(to_find, "n");
	    if(!search_seq(to_find
	    

	  test_find;
	test_find != NULL;
	test_find = split_at(test_find, "n");
	){
      
      
    }
    
  }
  
}

int search_seq(char* to_find, char* seq){
  int len = strlen(to_find);
  int end = strlen(seq);

  for(int start=0; start+len-1<end; start++){
    if(!strncmp(to_find, seq+start, len))
      return start;
  }
  
  return -1;
}

char* split_at(char* to_find, char* seq){
  int index = search_seq(to_find, seq);
  char* ret = index!=-1?seq+index+strlen(to_find):NULL;
  return ret;
}

int main(int argc, char* argv[]){
  if(argc>1){
    printf("num reads in %s: %d\n", argv[1], num_reads(argv[1]));
    printf("num bases per read in %s: %d\n", argv[1], read_len(argv[1]));

    char * read1 = "abcdefghijklmnop";
    char * read2 = "mnop";

    printf("checking if %s is in %s: %d\n", read2, read1, search_seq(read2, read1));
    printf("geting split_at of %s with %s: %lu\n", read1, read2, strlen(split_at(read2, read1)));
  }
  else
    usage();
}

