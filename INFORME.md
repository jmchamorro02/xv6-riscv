
##Pasos seguidos para la Tarea 2


0. Para comenzar la tarea tuve que volver al estado inicial del repositorio original, dado que me surgieron errores al momento de intentar inicializar qemu
1. Luego de 'empezar de cero' tuve que definir las variables que ibamos a utilizar para el manejo de prioridades, es decir, defini las variables: prioridad y boost, acordemente en el archivo proc.h
2. Despues de haber definido correctamente las variables, tuve que editar el archivo proc.c para que las funciones ya existentes de allocproc() y scheduler() contemplaran los cambios que pretendia hacer dentro de xv6. En allocproc() tuve que simplemente agregar dos punteros a las variables previamentes definidas en proc.h, tal como muestra en la siguiente imagen:
   
![image](https://github.com/user-attachments/assets/5dbbe08b-eb10-4f5d-adf2-72259e88e8d3)


En cambio, en la funcion scheduler tuve que hacer un cambio completo de las reglas de procesamiento del sistema opertativo, para poder asi cumplir con lo solicitado, asi terminaba quedando parte el codigo dentro de la funcion.


![image](https://github.com/user-attachments/assets/34605754-15f9-4ab8-93cc-75bda6ae2d42)


4. Ya habiendo hecho estos cambios recien pude empezar a crear un archivo test_prioridad.c para poder testear estos cambios y obtener los resultados esperados. Para cumplir los requisitos pedidos por la tarea, se creo un simple bucle que creara veinte procesos para asi asignarles distintas prioridades y entregar en la consola con sus respectivos valores de prioridad. Aqui se ve el codigo creado.

   
![image](https://github.com/user-attachments/assets/56ce3066-4e78-4934-bb82-22c2c73a6454)



##Problemas y Soluciones

Un gran problema que tuve, como mencione previamente, tuve que empezar de cero ya que estaba teniendo errores constantemente al momento de inciar qemu antes de siquiera agregar o alterar cualquier archivo. Despues de varios intentos tratando de arreglarlo, pude volver a comenzar a empezar la tarea de manera correcta. Otro problema que tuve, fueron las instrucciones vagas de la tarea y la poca documentacion para solucionar mis problemas los cuales iba enfrentando. Estos problemas me dificultaron bastante el desarrollo de esta tarea, teniendo que pasar varias horas desarrollando y balanceando con las demas responsabilidades de los otros ramos. Ya habiendo superado estos 'pequeños' percances, pude completar de manera satisfactoria para mi, la tarea.    


![Screenshot 2024-10-14 204542](https://github.com/user-attachments/assets/0eaeefef-fb02-4b01-bb2d-4df058bfe214)

