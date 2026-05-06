#ifndef ANDREA_INSTRUCCIONES_H
#define ANDREA_INSTRUCCIONES_H

#include <stdio.h>

void mostrarInstrucciones() {
    printf("\n=============================================================\n");
    printf("              INSTRUCTIVO DE USO - ANDREA                    \n");
    printf("=============================================================\n");
    printf("1. EL INGRESO: El sistema inicia con tu sueldo de Q8700.00.\n");
    printf("2. SECCIONES: Puedes navegar por las 6 secciones de gastos.\n");
    printf("3. MODIFICACION: Dentro de cada seccion, puedes cambiar el\n");
    printf("   monto de un gasto si este aumento o disminuyo.\n");
    printf("4. AHORROS: ANDREA calcula automaticamente cuanto puedes\n");
    printf("   ahorrar basado en (Sueldo - Gastos Totales).\n");
    printf("5. PERSISTENCIA: Al salir, tus cambios se guardan para que\n");
    printf("   puedas consultarlos en el proximo inicio del mes.\n");
    printf("6. REPORTE: Usa la opcion 'Ver Resumen' para un desglose\n");
    printf("   completo y profesional de tus finanzas.\n");
    printf("=============================================================\n");
    printf("Presione ENTER para continuar...");
    getchar(); getchar();
}

#endif
