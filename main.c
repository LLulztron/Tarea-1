#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Función para limpiar la pantalla
void limpiarPantalla()
{ 
  system("clear");
}

void presioneTeclaParaContinuar()
{
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

typedef struct
{
  int prioridad;
  char nombre[50];
  int edad;
  char sintoma[100];
  int hora;
  int minuto;
}tipoPaciente;

// Menú principal
void ordenar(List *pacientes, tipoPaciente *paciente) {
  tipoPaciente *current = (tipoPaciente *) list_first(pacientes);

  if (current == NULL || current -> prioridad > paciente -> prioridad) {
    list_pushFront(pacientes, paciente);
    return;
  }

  tipoPaciente *anterior = NULL;
  while (current != NULL && current -> prioridad >= paciente -> prioridad) {
    anterior = current;
    current = (tipoPaciente *) list_next(pacientes);
    if (current == NULL) {
      list_pushBack(pacientes, paciente);
      return;
    }
  }

  if (anterior == NULL) {
    list_pushFront(pacientes, paciente);
  } else {
    current = list_first(pacientes);
    while (current != anterior) {
      list_next(pacientes);
    }
    list_pushCurrent(pacientes, paciente);
  }
  
}

void mostrarMenuPrincipal()
{
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_paciente(List *pacientes) {
  tipoPaciente *paciente = (tipoPaciente*) malloc(sizeof(tipoPaciente));
  
  printf("=========================================\n");
  printf("Ingrese el nombre del paciente: ");
  scanf(" %s", paciente -> nombre);
  printf("Ingrese la edad del paciente: ");
  scanf("%d", &paciente -> edad);
  printf("Ingrese el síntoma del paciente: ");
  scanf("%s", paciente -> sintoma);
  printf("Ingrese la hora de llegada del paciente: ");
  scanf("%d %d", &paciente -> hora, &paciente -> minuto);
  paciente -> prioridad = 3;

  list_pushBack(pacientes, paciente);
  printf("====== Paciente registrado con éxito ======\n\n");
  printf("---- ¿Desae registrar nuevo paciente? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");

  int alternativa;
  scanf("%d", &alternativa);
  
  if (alternativa == 1) {
    registrar_paciente(pacientes);
  } else {
    mostrarMenuPrincipal();
  }
}

void asignar_prioridad(List *pacientes) {
  void *current = list_first(pacientes);
  char nombre[100];
  int nuevaPrioridad;
  int contador = 0;

  printf("=========================================\n");
  printf("Ingrese el nombre del paciente: ");
  scanf(" %s", nombre);
  printf("\n");
  printf("Ingrese la prioridad del paciente: ");
  scanf("%d", &nuevaPrioridad);
  getchar();
  printf("=========================================\n");

  while (current != NULL) {
    tipoPaciente *p = (tipoPaciente*) current;
    if (strcmp(p -> nombre,nombre) == 0) { 
      contador = 1;
      list_popCurrent(pacientes);
      p -> prioridad = nuevaPrioridad;
      ordenar(pacientes, p);
      printf("Prioridad asignada con éxito.\n\n");
      break;
    }
    current = list_next(pacientes);
  }
  
  if (!contador) {
    printf("Paciente no encontrado.\n");
  }
}

void mostrar_lista_pacientes(List *pacientes) {
  if (list_first(pacientes) == NULL) {
    printf("No hay pacientes en lista de espera.\n");
    return;
  }
  
  printf("Pacientes en espera: \n");
  printf("=========================================\n");
  tipoPaciente *current = (tipoPaciente *) list_first(pacientes);
  while (current != NULL)
    {
      printf("Nombre: %s\n", current -> nombre);
      printf("Edad: %d\n", current -> edad);
      printf("Síntoma: %s\n", current -> sintoma);
      printf("Prioridad: %d\n", current -> prioridad);
      printf("Hora: %d:%d\n", current -> hora, current -> minuto);
      printf("=========================================\n");
      current = list_next(pacientes);
    }
}

void siguiente_paciente(List *pacientes) {
  if (list_first(pacientes) == NULL) {
    printf("No hay pacientes en lista de espera.\n");
    return;
  }

  tipoPaciente *paciente = (tipoPaciente *) list_popFront(pacientes);
  printf("Atendiendo al siguiente paciente:\n");
  printf("=========================================\n");
  printf("Nombre: %s\n", paciente->nombre);
  printf("Edad: %d\n", paciente->edad);
  printf("Síntoma: %s\n", paciente->sintoma);
  printf("Prioridad: %d\n", paciente->prioridad);
  printf("Hora: %d:%d\n", paciente->hora, paciente->minuto);
  printf("=========================================\n");

  free(paciente);
  
}

void mostrar_por_prioridad(List *pacientes)
{
  int seleccionarPrioridad;
  printf("Introducir prioridad: ");
  scanf("%d", &seleccionarPrioridad);
  getchar();
  printf("=========================================\n");
  tipoPaciente *current = (tipoPaciente *) list_first(pacientes);
  int contador = 0;
  
  printf("Pacientes con prioridad %d:\n", seleccionarPrioridad);
  while (current != NULL) {
    if (current -> prioridad == seleccionarPrioridad) {
      printf("=========================================\n");
      printf("Nombre: %s\n", current -> nombre);
      printf("Edad: %d\n", current -> edad);
      printf("Síntoma: %s\n", current -> sintoma);
      printf("Hora: %d:%d\n", current -> hora, current -> minuto);
      contador = 1;
    }
    current = list_next(pacientes);
  }
  if (!contador) {
    printf("\nNo hay pacientes con prioridad %d:\n", seleccionarPrioridad);
  }
}


int main()
{
  char opcion;
  List *pacientes = list_create(); // puedes usar una lista para gestionar los pacientes



  do
  {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion)
    {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
      asignar_prioridad(pacientes);
      break;
    case '3':
      mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      siguiente_paciente(pacientes);
      break;
    case '5':
      mostrar_por_prioridad(pacientes);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  }while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}