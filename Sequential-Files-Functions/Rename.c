#include <stdio.h>

int main() {
  int result;

  char fileName[100];
  char newName[100];
  char extension[100];
  int dot = -1;

  printf("Enter the file name:");
  scanf("%s", &fileName);


  printf("Enter the NEW file extension:");
  scanf("%s", &extension);

  printf("%s", fileName);
  printf("\n");

  int i = 0;
  while(fileName[i] != '\0') {
    if(fileName[i] == '.'){
      dot = i;
    }
    i++;
  }

  if(dot == -1) {
    printf("Error: filename does not have an extension.\n");
    return -1;
  }

  i = 0;
  while(fileName[i] != '.') {
    newName[i] = fileName[i];
    i++;
  }
  newName[i] = '.';
  i = 0;
  while(extension[i] != '\0') {
    newName[++dot] = extension[i++];
  }
  result = rename(fileName, newName);
  if(result != 0)
    printf("Error: Unable to rename file\n");
  else
    printf("New Name: %s\n", newName);

  return 0;
}
