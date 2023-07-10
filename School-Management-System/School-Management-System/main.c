#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct
typedef struct student {
  char name[20];
  unsigned int id;
  double grade;
} Student;

typedef struct course {
  char name[20];
  double averageGrade;
  unsigned int totalStudents;
  Student* studentArray;
} Course;

typedef struct school {
  char name[20];
  unsigned int totalCourses;
  Course* courseArray;
} School;


// Create
Student* createStudent() {

  printf("Creating student...\n");
  Student* newStudent = (Student*)malloc(sizeof(Student));

  printf("Enter the student name: ");
  scanf("%s", newStudent->name);

  printf("Enter the student id: ");
  scanf("%u", &newStudent->id);

  printf("Enter the student grade: ");
  scanf("%lf", &newStudent->grade);

  return newStudent;
}

Course* createCourse() {

  printf("Creating course...\n");
  Course* newCourse = (Course*)malloc(sizeof(Course));

  printf("Enter course name: ");
  scanf("%s", newCourse->name);

  printf("Enter the average Grade: ");
  scanf("%lf", &newCourse->averageGrade);

  printf("Enter the total students: ");
  scanf("%u", &newCourse->totalStudents);

  newCourse->studentArray = (Student*)calloc(newCourse->totalStudents, sizeof(Student));

  for(int i = 0; i < newCourse->totalStudents; i++) {
    Student* student = createStudent();
    newCourse->studentArray[i] = *student;
    free(student);
  }

  return newCourse;
}

School* createSchool() {
  printf("Creating School...\n");
  School* newSchool = (School*)malloc(sizeof(School));

  printf("Enter school name: ");
  scanf("%s", newSchool->name);

  printf("Enter the total number of courses:");
  scanf("%u", &newSchool->totalCourses);

  newSchool->courseArray = (Course*)calloc(newSchool->totalCourses, sizeof(Course));
  for(int i = 0; i < newSchool->totalCourses; i++) {
    Course* course = createCourse();
    newSchool->courseArray[i] = *course;
    free(course);
  }
  return newSchool;
}

// Update
void updateAverageGrade(Course* course) {
  double totalGrades = 0.0;
  for (int i = 0; i < course->totalStudents; i++) {
    totalGrades += course->studentArray[i].grade;
  }
  course->averageGrade = totalGrades / course->totalStudents;
}

void updateStudentGrade(Course* course, unsigned int studentID, unsigned int newGrade) {
  for(int i = 0; i < course->totalStudents; i++) {
    if(course->studentArray[i].id == studentID) {
      course->studentArray[i].grade = newGrade;
      updateAverageGrade(course);
      return;
    }
  }
}

void updateStudentName(Course* course, unsigned int studentID, unsigned int newName) {
  for(int i = 0; i < course->totalStudents; i++) {
    if(course->studentArray[i].id == studentID) {
      strcpy(course->studentArray[i].name, newName);
      return;
    }
  }
}

void updateCourseName(Course* course, char* newName) {
  strcpy(course->name, newName);
}
// boolean
bool getCourseExists(School* school, char* coursename) {

  for(int i = 0; i < school->totalCourses; i++) {
    if(strcmp(school->courseArray[i].name, coursename) == 0) {
      return true;
    }
  }

  return false;
}

// Print
void printStudent(Student* student) {
  printf("Student Name: %s\n", student->name);
  printf("Student Id: %u\n", student->id);
}

void printCourse(Course* course) {
  printf("Course Name: %s\n", course->name);
  printf("Course average: %lf\n",course->averageGrade);
  printf("Course students: %d\n", course->totalStudents);

  for(int i = 0; i < course->totalStudents; i++) {
    printStudent(&course->studentArray[i]);
  }
}

void printAllStudentCourses(School* school, int studentId) {
  printf("Courses for student %d\n", studentId);
  for(int i = 0; i < school->totalCourses; i++) {
     for(int j = 0; j < school->courseArray[i].totalStudents; j++) {
       if(school->courseArray[i].studentArray[j].id == studentId) {
         printf("- %s\n", school->courseArray[i].name);
         break;
       }
     }
  }
}

void printFailingStudents(Course* course, double cutOffGrade) {
  printf("Failing Students: \n");
  for(int i = 0; i < course->totalStudents; i++) {
    if(course->studentArray[i].grade < cutOffGrade) {
      printStudent(&course->studentArray[i]);
    }
  }
}

void printPassingStudents(Course* course, double cutOffGrade) {
  printf("Successful Students: \n");
  for(int i = 0; i < course->totalStudents; i++) {
    if(course->studentArray[i].grade >= cutOffGrade) {
      printStudent(&course->studentArray[i]);
    }
  }
}

void printAllFailingCourses(School* school, double cutOffGrade){
  printf("Successful Courses: \n");
  for(int i = 0; i < school->totalCourses; i++) {
    if(school->courseArray[i].averageGrade  < cutOffGrade) {
      printCourse(&school->courseArray[i]);
    }
  }
}

void printAllSuccessfulCourses(School* school, double cutOffGrade){
  printf("Successful Courses: \n");
  for(int i = 0; i < school->totalCourses; i++) {
    if(school->courseArray[i].averageGrade  >= cutOffGrade) {
      printCourse(&school->courseArray[i]);
    }
  }
}

void printAvreageGradeOfSchool(School* school) {

  double totalGrade = 0;
  double average = 0.0;
  for(int i = 0; i < school->totalCourses; i++) {
    totalGrade += school->courseArray[i].averageGrade;
  }

  average = totalGrade / school->totalCourses;
  printf("Average Grade: %lf\n", average);
}

void printHighestAverageCourse(School* school) {

  double highestAverage = 0.0;
  Course* courseHigh = NULL;
  for(int i = 0; i < school->totalCourses; i++) {
    if(school->courseArray[i].averageGrade > highestAverage) {
      highestAverage = school->courseArray[i].averageGrade;
      courseHigh = &school->courseArray[i];
    }
  }

  printf("Course with the highest average grade: \n");
  printCourse(courseHigh);
}


void printSchoolDetails(School* school) {

  for(int i = 0; i < school->totalCourses; i++) {
    printCourse(&school->courseArray[i]);
  }
}

void printSchoolsCommonCourses(School* school1, School* school2) {

  for(int i = 0; i < school1->totalCourses; i++) {
    if(getCourseExists(school2, school1->courseArray[i].name)) {
      printf("%s\n", school1->courseArray[i].name);
    }
  }
}

void printSchoolsUncommonCourses(School* school1, School* school2) {

  for(int i = 0; i < school1->totalCourses; i++) {
    if(!getCourseExists(school2, school1->courseArray[i].name)) {
      printf("%s\n", school1->courseArray[i].name);
    }
  }
}

// Free
void freeStudents(Student* students) {
  free(students);
}

void freeCourses(Course* courses, unsigned int totalCourses) {

  for(int i = 0; i < totalCourses; i++) {
    freeStudents(courses[i].studentArray);
    courses[i].studentArray = NULL;
  }
}

void freeSchool(School* school) {
  freeCourses(school->courseArray, school->totalCourses);
  free(school->courseArray);
  free(school);
}


int main() {

  School* school = createSchool();
  printSchoolDetails(school);
  printAllStudentCourses(school, 123);
  printFailingStudents(&(school->courseArray[0]), 60.0);
  printPassingStudents(&(school->courseArray[0]), 60.0);


  return 0;
}
