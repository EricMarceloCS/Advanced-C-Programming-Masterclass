#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} Point;

void addPoint(char* filename, Point newPoint) {
  FILE* fp = fopen(filename, "ab");
  if(fp != NULL) {
    fwrite(&newPoint, sizeof(Point), 1, fp);
    fclose(fp);
  }
}

int main() {

  Point p = {2, 2};
  addPoint("Points.bin", p);
  FILE* fp = fopen("Points.bin", "r");
  Point p1;
  for(int i = 0; i < 6; i++){
    fread(&p1, sizeof(Point), 1, fp);
    printf("(%d, %d) ", p1.x, p1.y);
  }
  fclose(fp);
  return 0;
}
