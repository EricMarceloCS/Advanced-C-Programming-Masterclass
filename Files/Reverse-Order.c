#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} Point;

void reverseFile(char* filename) {

  FILE* fp = fopen(filename, "rb+");
  int bytes = 0;
  int size;

  if(fp != NULL) {

    fseek(fp, 0L, SEEK_END);
    bytes = ftell(fp);
    size = bytes / sizeof(Point);

    Point temp[size];
    rewind(fp);

    for(int i = size - 1; i >= 0; i--) {
      fread(&temp[i], sizeof(Point), 1, fp);
    }

    rewind(fp);
    fwrite(temp, sizeof(Point), size, fp);
    fclose(fp);
  }

}

int main() {

  Point points[5] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 0}};
  FILE* fp = fopen("Points.bin", "wb");
  Point p;

  if(fp != NULL) {
    fwrite(points, sizeof(Point), 5, fp);
    fclose(fp);
  }

  reverseFile("Points.bin");

  fp = fopen("Points.bin", "r");
  for(int i = 0; i < 5; i++) {
    fread(&p, sizeof(Point), 1, fp);
    printf("(%d, %d) ", p.x, p.y);
  }
  printf("\n");
  fclose(fp);

  return 0;
}
