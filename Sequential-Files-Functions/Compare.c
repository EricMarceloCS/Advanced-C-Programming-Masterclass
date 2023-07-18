#include <stdio.h>
#include <stdlib.h>

int compare(char* file1, char* file2) {

  FILE* compare1 = fopen(file1, "r");
  FILE* compare2 = fopen(file2, "r");

  if(compare1 == NULL) {
    printf("File 1 Could Not Be Opened\n");
    return -1;
  }

  if(compare2 == NULL) {
    printf("File 2 Could Not Be Opened\n");
    fclose(compare1);
    return -1;
  }

  char c1 = fgetc(compare1);
  char c2 = fgetc(compare2);

  while((c1 != EOF) || (c2 != EOF)) {
    if(c1 != c2){
      fclose(compare1);
      fclose(compare2);
      return 0;
    }
    c1 = fgetc(compare1);
    c2 = fgetc(compare2);
  }

  fclose(compare1);
  fclose(compare2);

  if(c1 != c2) {
    return 0;
  }else {
    return 1;
  }

}

int main() {

  int result;
  result = compare("CompareFile1.txt", "CompareFile2.txt");
  switch(result) {
    case 0:
      printf("Files are not identical\n");
      break;
    case 1:
      printf("Files are identical\n");
      break;
    default:
      printf("Error occurred\n");
  }
  return 0;
}
