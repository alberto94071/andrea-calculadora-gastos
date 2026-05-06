#ifndef ANDREA_PERSISTENCIA_H
#define ANDREA_PERSISTENCIA_H

#include <stdio.h>
#include <string.h>
#include "andrea_variables.h"

void guardarEstado() {
    FILE *f = fopen("andrea_data.bin", "wb");
    if (f == NULL) return;
    fwrite(&sp, sizeof(ServiciosPublicos), 1, f);
    fwrite(&sb, sizeof(ServiciosBasicos), 1, f);
    fwrite(&tr, sizeof(Transporte), 1, f);
    fwrite(&sl, sizeof(Salud), 1, f);
    fwrite(&ed, sizeof(Educacion), 1, f);
    fwrite(&gv, sizeof(GastosVariables), 1, f);
    fwrite(&ingresoTotal, sizeof(double), 1, f);
    fclose(f);
}

void cargarEstado() {
    FILE *f = fopen("andrea_data.bin", "rb");
    if (f == NULL) return;
    fread(&sp, sizeof(ServiciosPublicos), 1, f);
    fread(&sb, sizeof(ServiciosBasicos), 1, f);
    fread(&tr, sizeof(Transporte), 1, f);
    fread(&sl, sizeof(Salud), 1, f);
    fread(&ed, sizeof(Educacion), 1, f);
    fread(&gv, sizeof(GastosVariables), 1, f);
    if (fread(&ingresoTotal, sizeof(double), 1, f) != 1) {
        // Si no se encuentra el dato (archivo viejo), usar el valor base
        ingresoTotal = INGRESO_MENSUAL;
    }
    fclose(f);
}

void guardarHistorial(char* mes, double ahorro) {
    FILE *f = fopen("historial_ahorros.txt", "a");
    if (f == NULL) return;
    fprintf(f, "Mes: %-15s | Ahorro: Q %10.2f\n", mes, ahorro);
    fclose(f);
    printf("\n[SISTEMA] Historial actualizado correctamente.\n");
}

void verHistorial() {
    char linea[100];
    double totalAcumulado = 0.0;
    double ahorroMes = 0.0;
    FILE *f = fopen("historial_ahorros.txt", "r");
    printf("\n--- HISTORIAL DE AHORROS ---\n");
    if (f == NULL) {
        printf("Aun no hay registros.\n");
        return;
    }
    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
        // Extraer el monto para la sumatoria
        char *ptr = strstr(linea, "Q");
        if (ptr != NULL) {
            sscanf(ptr + 1, "%lf", &ahorroMes);
            totalAcumulado += ahorroMes;
        }
    }
    printf("-------------------------------------------------------------\n");
    printf("AHORRO TOTAL ACUMULADO:       Q %10.2f\n", totalAcumulado);
    printf("-------------------------------------------------------------\n");
    fclose(f);
}

double calcularAhorroTotalHistorico() {
    char linea[100];
    double total = 0.0;
    double ahorroMes = 0.0;
    FILE *f = fopen("historial_ahorros.txt", "r");
    if (f == NULL) return 0.0;

    while (fgets(linea, sizeof(linea), f)) {
        char *ptr = strstr(linea, "Q");
        if (ptr != NULL) {
            sscanf(ptr + 1, "%lf", &ahorroMes);
            total += ahorroMes;
        }
    }
    fclose(f);
    return total;
}

#endif
