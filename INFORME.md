
##Pasos seguidos para la Tarea 3

1. **Implementación de `mprotect` y `munprotect` en `sysproc.c`**:
   - Se añadieron las funciones `sys_mprotect` y `sys_munprotect` para modificar los permisos de las páginas.
   - **`sys_mprotect`**: Esta función recibe una dirección base y una longitud en páginas. Marca cada página del rango especificado como de solo lectura, desactivando el bit de escritura (`PTE_W`) en las entradas de la tabla de páginas.
   - **`sys_munprotect`**: Similar a `mprotect`, esta función restaura el permiso de escritura de las páginas en el rango especificado activando el bit de escritura (`PTE_W`) en cada entrada de la tabla de páginas.
   - Ambas funciones usan `sfence_vma()` al final para asegurarse de que los cambios en los permisos de memoria sean efectivos inmediatamente.

2. **Modificación en el Manejador de Excepciones (`trap.c`)**:
   - En el archivo `trap.c`, se añadió un manejo específico para trampas de protección de página (scause 0xf) en la función `usertrap`. Si ocurre un acceso ilegal en una página protegida, el sistema imprime un mensaje de error y marca el proceso para su terminación.

3. **Pruebas para Verificar `mprotect` y `munprotect`**:
   - Se creo archivo de prueba:
     - **`test_mprotect.c`**: Este archivo prueba la funcionalidad de `mprotect` aplicando la protección de solo lectura y verificando que una escritura en la página protegida cause una trampa. Tambien se puede verificar la funcionalidad de `munprotect` si es que se quita el intento de escritura 'ilegal'


4. **Mensajes de Depuración en las Pruebas**:
   - En el archivo de prueba, se añadieron mensajes para confirmar cada paso: si `mprotect` y `munprotect` son exitosos, si la protección de solo lectura está funcionando, y si se permite la escritura tras llamar a `munprotect`.


##Dificultades encontradas y soluciones implementadas.

Al igual que en las demas tareas la principal dificultad fue la poca documentacion que existe o pude encontrar para esta especifica tarea. Ademas de eso no tuve muchas dificultades aparte de la repetitividad de las varias iteraciones que tuve que hacer para poder hacerlo funcionar.
