#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*
 * child_process - Función que define el comportamiento de los procesos hijos.
 * 
 * Descripción:
 *   Esta función se encarga de asignar prioridades a los procesos hijos y realizar
 *   una actividad simulada que consiste en imprimir mensajes periódicos durante 60 segundos.
 *
 * Parámetros:
 *   child_num - Número que identifica al proceso hijo.
 *
 * Valor de retorno:
 *   Ninguno.
 */

void child_process(int child_num) {
    // Asignar prioridad basada en el número de orden del hijo.
    set_priority(child_num, getpid());

    // Ciclo para imprimir mensajes periódicos durante 60 segundos.
    for (int j = 1; j <= 60; j++) {
        printf("PID %d: %d\n", getpid(), j);
        sleep(1);
    }
}

/*
 * main - Función principal del programa.
 * 
 * Descripción:
 *   La función principal crea un número específico de procesos hijos, asigna a cada
 *   uno una prioridad y realiza una actividad simulada en cada proceso hijo.
 *   El proceso padre espera a que todos los hijos terminen antes de salir.
 *
 * Parámetros:
 *  Ninguno
 *  
 *
 * Valor de retorno:
 *   Ninguno.
 */
int main() {
    // Número de procesos hijos a crear.
    int num_children = 5;

    // Ciclo para crear procesos hijos.
    for (int i = 0; i < num_children; i++) {
        // Crear un nuevo proceso hijo.
        int pid = fork();

        // Verificar si el fork fue exitoso.
        if (pid < 0) {
            printf("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Código ejecutado por el proceso hijo.
            child_process(i);

            // Salir después de que el proceso hijo ha terminado.
            exit(0);
        }

        // Esperar a que el proceso hijo termine.
        wait(0);
    }

    // Salir después de que todos los procesos hijos han terminado.
    exit(0);
}
