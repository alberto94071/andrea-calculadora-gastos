#include "andrea_variables.h"
#include "andrea_visuales.h"
#include "andrea_logica.h"
#include "andrea_persistencia.h"
#include "andrea_instrucciones.h"
#include <stdio.h>
#include <stdlib.h>

// Definicion de Variables Globales
ServiciosPublicos sp = {120.0, 30.0, 145.0, 250.0, 200.0, 0.0};
ServiciosBasicos sb = {1600.0, 1000.0, 300.0, 250.0, 0.0};
Transporte tr = {600.0, 150.0, 350.0, 120.0, 0.0};
Salud sl = {250.0, 175.0, 0.0};
Educacion ed = {715.0, 185.0, 0.0};
GastosVariables gv = {75.0, 110.0, 160.0, 300.0, 300.0, 400.0, 45.0, 0.0};

double ingresoTotal = INGRESO_MENSUAL;
double ahorroProyectado = CUOTA_AHORRO_BASE;
double gastoTotalGeneral = 0.0;
double ahorroReal = 0.0;
double ahorroTotalHistorico = 0.0;
bool ejecutando = true;

void mostrarResumen() {
    system("cls");
    mostrarLogo();
    printf("\n%-30s %-15s\n", "CATEGORIA", "TOTAL");
    printf("-------------------------------------------------------------\n");
    dibujarTabla("Servicios Publicos", sp.total);
    dibujarTabla("Servicios Basicos", sb.total);
    dibujarTabla("Transporte", tr.total);
    dibujarTabla("Salud y Bienestar", sl.total);
    dibujarTabla("Educacion", ed.total);
    dibujarTabla("Gastos Variables", gv.total);
    printf("-------------------------------------------------------------\n");
    printf("%-27s Q %10.2f\n", "TOTAL GASTOS:", gastoTotalGeneral);
    printf("%-27s Q %10.2f\n", "AHORRO MENSUAL ACTUAL:", ahorroReal);
    printf("=============================================================\n");
    printf("\nPresione ENTER para volver...");
    getchar(); getchar();
}

int main() {
    int opcion;
    char mes[20];
    
    // Configurar titulo de ventana
    system("title Asistente de Navegacion de Datos y Registro de Egresos Automatizado");

    cargarEstado();
    calcularTotales();
    ahorroTotalHistorico = calcularAhorroTotalHistorico();

    while (ejecutando) {
        system("cls");
        mostrarLogo();
        printf("Sueldo: Q %.2f | Ahorro Mes: Q %.2f | Ahorro Total: Q %.2f\n", ingresoTotal, ahorroReal, ahorroTotalHistorico);
        printf("-------------------------------------------------------------\n");
        printf("1. Gestionar Servicios Publicos\n");
        printf("2. Gestionar Servicios Basicos\n");
        printf("3. Gestionar Transporte\n");
        printf("4. Gestionar Salud y Bienestar\n");
        printf("5. Gestionar Educacion\n");
        printf("6. Gestionar Gastos Variables\n");
        printf("7. Modificar Sueldo Mensual\n");
        printf("8. Ver Resumen y Totales\n");
        printf("9. Ver Historial de Ahorros\n");
        printf("10. Cerrar Mes y Guardar Historial\n");
        printf("11. Instrucciones de uso\n");
        printf("0. Salir (Guardar estado actual)\n");
        printf("-------------------------------------------------------------\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: editarServiciosPublicos(); break;
            case 2: editarServiciosBasicos(); break;
            case 3: editarTransporte(); break;
            case 4: editarSalud(); break;
            case 5: editarEducacion(); break;
            case 6: editarVariables(); break;
            case 7: editarIngreso(); break;
            case 8: mostrarResumen(); break;
            case 9: verHistorial(); printf("\nPresione ENTER..."); getchar(); getchar(); break;
            case 10: 
                printf("Ingrese el nombre del mes: ");
                scanf("%s", mes);
                guardarHistorial(mes, ahorroReal);
                ahorroTotalHistorico = calcularAhorroTotalHistorico();
                break;
            case 11: mostrarInstrucciones(); break;
            case 0: 
                guardarEstado();
                ejecutando = false;
                printf("\nDatos guardados. ¡Hasta pronto!\n");
                break;
            default: printf("Opcion no valida.\n");
        }
    }

    return 0;
}
