
##Pasos seguidos para la Tarea 4


0.Al igual que con todas las otras tareas, tuve que volver al estado original de xv6 para que no hubieran conflictos que no fueran faciles de arreglar.

1. Luego de confirmar que el sistema estaba en un estado funcional, edite la estructura inode en el archivo fs.h para agregar un nuevo campo permissions que manejaría los permisos básicos de los archivos (lectura, escritura, ambos). Inicialmente, todos los archivos se configuraron con permisos 3 (lectura/escritura).
![image](https://github.com/user-attachments/assets/8b80fccb-ae52-4056-a41f-5d005c443074)


2. Despues, modifiqué las funciones principales relacionadas con la apertura, lectura y escritura de archivos, ubicadas en sysfile.c y file.c. Estas funciones fueron ajustadas para verificar y respetar los permisos configurados en el inode. Esto incluyo agregar condiciones para evitar operaciones no permitidas, como intentar escribir en un archivo marcado como solo lectura.

3. Implemente la llamada al sistema chmod, añadiendo su definicion en los archivos correspondientes (syscall.h, syscall.c, y user.h). Esta llamada permite cambiar los permisos de un archivo a través de su nombre y un modo numérico (0, 1, 2 o 3). Una vez realizados estos cambios, creé un programa de prueba chmod.c . Este programa realiza operaciones básicas como crear un archivo, escribir en él, cambiar sus permisos, verificar restricciones y restaurar permisos. Este paso permitió validar que las modificaciones funcionaran correctamente.

4. Finalmente, agregué el permiso especial "inmutable" (5) al sistema. Este permiso, una vez aplicado a un archivo, impide tanto su modificación como cualquier cambio en sus permisos. Se ajustó la llamada a chmod para manejar este caso especial. También se actualizó el programa de prueba para validar esta funcionalidad.

Aqui se puede ver los resultados de cada una de estas funcionalidades implementadas
![Screenshot 2024-11-29 204803](https://github.com/user-attachments/assets/3b1e56aa-598d-44f4-bd4c-7853f4cf7d87)

##Problemas y Soluciones

Similarmente a las demas tareas, mis problemas siempre fueron la poca documentacion sobre xv6 y como utilizarlo correctamente y hacer debugging sea necesario. Ademas de tener que siempre volver a frustrarme cuando se empiezan a cruzar los cables y comienza a fallar incluso las funcionalidades mas minimas de xv6 y qemu.



