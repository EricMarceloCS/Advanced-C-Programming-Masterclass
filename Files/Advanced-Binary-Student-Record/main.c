#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  char name[20];
  int total_grades;
  double* grades;
} Student;

void printStudentDetails(Student* student) {

  int g = 0;
  printf("Name: %s\n", student->name);
  printf("Total Grades: %d\n", student->total_grades);
  while(g < student->total_grades){
    printf("Grade: %.2lf\n", student->grades[g++]);
  }

}

Student* createStudent() {
  Student* newStudent = NULL;
  newStudent = (Student*)calloc(1, sizeof(Student));
  if(newStudent != NULL) {

    printf("Enter the student name: ");
    scanf("%s", &newStudent->name);
    printf("Enter the total grades: ");
    scanf("%d", &newStudent->total_grades);

    newStudent->grades = (double*)calloc(newStudent->total_grades, sizeof(double));
    int g = 0;
    while(g < newStudent->total_grades){
      printf("Enter the student grade: ");
      scanf("%lf", &newStudent->grades[g++]);
    }

  }
  return newStudent;
}

int saveStudent(char* fileName, Student* student) {
  FILE* file = fopen(fileName, "ab");
  if(file == NULL) {
    printf("Unable to open file %s\n", fileName);
    return -1;
  }

  fwrite(student->name, sizeof(char), 20, file);
  fwrite(&student->total_grades, sizeof(int), 1, file);
  fwrite(student->grades, sizeof(double), student->total_grades, file);
  fclose(file);

  return 0;
}

int readStudents(char* fileName) {
  FILE* file = fopen(fileName, "rb");
  if(file == NULL) {
    printf("Unable to open file %s\n", fileName);
    return -1;
  }
  printf("Reading File...\n");
  while(!feof(file)) {
    Student* student;
    student = (Student*)calloc(1, sizeof(Student));
    fread(&student->name, sizeof(char), 20, file);
    fread(&student->total_grades, sizeof(int), 1, file);
    student->grades = (double*)malloc(student->total_grades * sizeof(double));
    fread(student->grades, sizeof(double), student->total_grades, file);
    printStudentDetails(student);
    free(student);
    if(fseek(file, 1, SEEK_CUR) == feof(file)){
      break;
    } else {
      fseek(file, -1, SEEK_CUR);
    }
    printf("%ld\n", ftell(file));
  }
  fclose(file);
  return 0;
}

int main()
{
    Student* student = createStudent();
    int saved = saveStudent("Students.bin", student);
    int read = readStudents("Students.bin");
    return 0;
}
