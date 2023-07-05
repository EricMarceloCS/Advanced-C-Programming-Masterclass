#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
  char name[10];
  float age;
  int id;
} Employee;

Employee* getArray(int size) {

  Employee* employees;
  employees = (Employee*)calloc(size, sizeof(Employee));
  for(int i = 0; i < size; i++) {
    printf("Enter the employee Name: ");
    scanf("%s", &employees[i].name);
    printf("Enter the employee Age: ");
    scanf("%f", &employees[i].age);
    printf("Enter the employee Id: ");
    scanf("%d", &employees[i].id);
  }

  return employees;
}

void updateArray(Employee** employeeArrayPtr, int size) {
  for(int i = 0; i < size; i++) {
    printf("Enter the employee Name: ");
    scanf("%s", &(*employeeArrayPtr)[i].name);
    printf("Enter the employee Age: ");
    scanf("%f", &(*employeeArrayPtr)[i].age);
    printf("Enter the employee Id: ");
    scanf("%d", &(*employeeArrayPtr)[i].id);
  }
}

int main() {

  Employee* employees;
  int size;

  printf("Enter the number of employees: ");
  scanf("%d", &size);

  employees = getArray(size);
  for(int i = 0; i < size; i++) {
    printf("Name: %s\n", employees[i].name);
    printf("Age: %f\n", employees[i].age);
    printf("Id: %d\n", employees[i].id);
  }
  updateArray(&employees, size);

  for(int i = 0; i < size; i++) {
    printf("Name: %s\n", employees[i].name);
    printf("Age: %f\n", employees[i].age);
    printf("Id: %d\n", employees[i].id);
  }

  return 0;
}
