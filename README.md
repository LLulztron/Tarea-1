
# **Tarea 1**
---
**Cómo compilar y ejecutar**

* Importe el repositorio desde su cuenta en repl.it (si no tiene siga [este tutorial](https://chartreuse-goal-d5c.notion.site/C-mo-comenzar-con-los-labs-b4dd8c7abc5a425d8f25e2eaa060e5b5?pvs=4))
* Create una cuenta o si tienes una utiliza la tuya en caso de que tengas
* Una vez en tu dashboard, selecciona "New Repl" y elige "Import from GitHub"
* Pega la URL del repositorio: https://github.com/LLulztron/Tarea-1.git
* Presiona el botón "Run" para compilar y ejecutar la aplicación.
---
**Funcionalidades**
**Funcionando correctamente**
* Registrar pacientes con sus datos básicos y una prioridad inicial.
* Asignar o modificar la prioridad de los pacientes.
* Ver la lista de espera de pacientes, ordenada por prioridad
* Atender al siguiente paciente, respetando el orden de prioridad.
* Mostrar pacientes por prioridad

**Problemas conocidos**
* En la funcion de registrar paciente, la hora se registra diferente (en los ejemplos se muestra)
* En la funcion atender al siguiente paciente, no se puede mostrar por orden de llegada
* En la funcion de mostrar pacientes por prioridad, no se puede mostrar por orden de llegada

---
**Ejemplos**  
*Paso 1) Registrar paciente*

Se comienza registrando un nuevo paciente que acaba de llegar al hospital.
````c  
  Opción seleccionada: 1) Registrar paciente
  Ingrese el nombre del paciente: Kevin_Alvarez
  Ingrese la edad del paciente: 19
  Ingrese el síntoma del paciente: fiebre_dolor_de_espalda
  Ingrese la hora de llegada: 21 15
````
El sistema registra al paciente y asi asignandole la prioridad mas baja que es 3.

*Paso 2) Asignar prioridad nueva al paciente*

Tras una evaluación inicial, el médico determina que el estado.
````c
Opción seleccionada: 2) Asignar prioridad a paciente
Ingrese el nombre del paciente: Kevin_Alvarez
Seleccione el nuevo nivel de prioridad (1, 2, 3): 1
````
El sistema registra la nueva prioridad del paciente dependiendo de sus sintomas.

*Paso 3) Ver la Lista de Espera*
````c
Opción seleccionada: 3) Mostrar lista de espera
````
La lista muestra al paciente respectivamente en orden de prioridad.

*Paso 4) Atender al Siguiente Paciente*

El paciente es llamado basandose de su prioridad.
````c
Opción seleccionada: 4) Atender al siguiente paciente
````
El sistema muestra al paciente atendido y lo elimina.

*Paso 5) Mostrar pacientes por prioridad*

````c
Opción seleccionada: 5) Mostrar pacientes por prioridad
````
El sistema muestra los pacientes que tienen tal prioridad para asi atenderlos 
