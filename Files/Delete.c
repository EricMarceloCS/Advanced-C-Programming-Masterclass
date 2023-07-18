#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} Point;

void deletePoint(char* filename, int choice) {
  FILE* fp = fopen(filename, "rb");
  FILE* fTemp = fopen("Temp.bin", "wb");

  Point p;
  if(fp != NULL && fTemp != NULL) {
    fseek(fp, 0L, SEEK_END);
    int bytes = ftell(fp);
    int size = bytes / sizeof(Point);

    Point temp[size];
    rewind(fp);
    if(choice - 1 < size) {
      for(int i = 0; i < size; i++) {
        fread(&temp[i], sizeof(Point), 1, fp);
      }
      rewind(fp);
      for(int i = 0; i < size ; i++) {
        if(i != choice - 1) {
          fwrite(&temp[i], sizeof(Point), 1, fTemp);
        }
      }
    }

    fclose(fp);
    fclose(fTemp);
    if(remove(filename) == 0)
      rename("Temp.bin", filename);
  }
}

int main() {

  deletePoint("Points.bin", 6);
  FILE* fp = fopen("Points.bin", "r");
  Point p;

  if(fp != NULL) {
    while(!feof(fp)) {
      fread(&p, sizeof(Point), 1, fp);
      if(feof(fp))
        break;
      printf("(%d, %d) \n", p.x, p.y);
    }
    fclose(fp);
  }
  return 0;
}
