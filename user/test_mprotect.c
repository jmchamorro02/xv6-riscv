#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main() {
    // Reservar una página en el heap
    char *page_addr = sbrk(0);
    sbrk(4096);

    // Aplicar protección de solo lectura a la página reservada
    if (mprotect(page_addr, 1) < 0) {
        printf("Error al aplicar mprotect\n");
    } else {
        printf("Protección de solo lectura aplicada correctamente\n");
    }

    // Intentar escribir en la página protegida para verificar que está en modo solo lectura
    printf("Intentando escribir en la página protegida...\n");
    char *ptr = page_addr;
    *ptr = 'X';  // Esto debería fallar o causar una trampa si la protección de solo lectura está activa
    printf("La protección de solo lectura falló\n");

    // Quitar la protección de solo lectura con munprotect para permitir escritura
    if (munprotect(page_addr, 1) < 0) {
        printf("Error al aplicar munprotect\n");
    } else {
        printf("Protección eliminada correctamente con munprotect\n");
    }

    // Realizar prueba de escritura en la página desprotegida después de munprotect
    *ptr = 'A';
    printf("Escritura tras desprotección exitosa, valor en la dirección: %c\n", *ptr);

    // Segunda prueba de escritura para confirmar que la protección se ha eliminado por completo
    *ptr = 'B';
    printf("Escritura de verificación exitosa, valor en la dirección: %c\n", *ptr);

    exit(0);
}
