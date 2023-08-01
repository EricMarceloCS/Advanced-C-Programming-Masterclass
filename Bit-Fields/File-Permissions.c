#include <stdio.h>

typedef struct permissions {
  unsigned int read : 1;
  unsigned int write : 1;
  unsigned int execute : 1;
} Permissions;

void printInfo(Permissions permission) {
  printf("Permissions: \n");
  printf("Read: %u\n", permission.read);
  printf("Write: %u\n", permission.write);
  printf("Execute: %u\n", permission.execute);
}

Permissions createVariable(unsigned int read, unsigned int write, unsigned int execute) {
  Permissions permission;
  permission.read = read;
  permission.write = write;
  permission.execute = execute;

  return permission;
}

void changePermissions(Permissions* permissions, unsigned int read, unsigned int write, unsigned int execute) {
  permissions->read = read;
  permissions->write = write;
  permissions->execute = execute;
}

int main() {

  Permissions p = createVariable(1, 1, 0);
  printInfo(p);
  changePermissions(&p, 1, 1, 1);
  printInfo(p);

  return 0;
}
