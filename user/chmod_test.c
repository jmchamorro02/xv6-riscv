#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"
int main() {
  int fd = open("testfile", O_CREATE | O_RDWR);
  if (fd < 0) {
    printf("Error: no se pudo crear el archivo\n");
    exit(1);
  }
  write(fd, "aguante la u", 4);
  close(fd);
  chmod("testfile", 1); // Cambiar a solo lectura
  fd = open("testfile", O_WRONLY);
  if (fd < 0)
    printf("No se puede abrir en modo solo escritura\n");
  else
    printf("Error archivo es solo lectura\n");
  chmod("testfile", 5); // Marcar como inmutable
  if (chmod("testfile", 3) < 0)
    printf("Archivo no se pudo modificar\n");
  unlink("testfile");
  exit(0);
}