#ifndef ANDREA_LOGICA_H
#define ANDREA_LOGICA_H

#include "andrea_variables.h"
#include <stdio.h>

void calcularTotales() {
    sp.total = sp.luz + sp.agua + sp.gas + sp.internet + sp.planCelular;
    sb.total = sb.alimentacion + sb.mercado + sb.higiene + sb.limpieza;
    tr.total = tr.gasolina + tr.pasajes + tr.parqueos + tr.carWash;
    sl.total = sl.medicinas + sl.seguroMedico;
    ed.total = ed.colegiatura + ed.utiles;
    gv.total = gv.spotify + gv.netflix + gv.gemini + gv.cine + gv.paseos + gv.imprevistos + gv.disney;
    
    gastoTotalGeneral = sp.total + sb.total + tr.total + sl.total + ed.total + gv.total;
    ahorroReal = ingresoTotal - gastoTotalGeneral;
}

void editarServiciosPublicos() {
    int op;
    printf("\n--- Editar Servicios Publicos ---\n");
    printf("1. Luz (Q%.2f)\n2. Agua (Q%.2f)\n3. Gas (Q%.2f)\n4. Internet (Q%.2f)\n5. Plan Celular (Q%.2f)\n0. Volver\nOpcion: ", sp.luz, sp.agua, sp.gas, sp.internet, sp.planCelular);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &sp.luz); break;
        case 2: scanf("%lf", &sp.agua); break;
        case 3: scanf("%lf", &sp.gas); break;
        case 4: scanf("%lf", &sp.internet); break;
        case 5: scanf("%lf", &sp.planCelular); break;
    }
    calcularTotales();
}

void editarServiciosBasicos() {
    int op;
    printf("\n--- Editar Servicios Basicos ---\n");
    printf("1. Alimentacion (Q%.2f)\n2. Mercado (Q%.2f)\n3. Higiene (Q%.2f)\n4. Limpieza (Q%.2f)\n0. Volver\nOpcion: ", sb.alimentacion, sb.mercado, sb.higiene, sb.limpieza);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &sb.alimentacion); break;
        case 2: scanf("%lf", &sb.mercado); break;
        case 3: scanf("%lf", &sb.higiene); break;
        case 4: scanf("%lf", &sb.limpieza); break;
    }
    calcularTotales();
}

void editarTransporte() {
    int op;
    printf("\n--- Editar Transporte ---\n");
    printf("1. Gasolina (Q%.2f)\n2. Pasajes (Q%.2f)\n3. Parqueos (Q%.2f)\n4. Car Wash (Q%.2f)\n0. Volver\nOpcion: ", tr.gasolina, tr.pasajes, tr.parqueos, tr.carWash);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &tr.gasolina); break;
        case 2: scanf("%lf", &tr.pasajes); break;
        case 3: scanf("%lf", &tr.parqueos); break;
        case 4: scanf("%lf", &tr.carWash); break;
    }
    calcularTotales();
}

void editarSalud() {
    int op;
    printf("\n--- Editar Salud ---\n");
    printf("1. Medicinas (Q%.2f)\n2. Seguro (Q%.2f)\n0. Volver\nOpcion: ", sl.medicinas, sl.seguroMedico);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &sl.medicinas); break;
        case 2: scanf("%lf", &sl.seguroMedico); break;
    }
    calcularTotales();
}

void editarEducacion() {
    int op;
    printf("\n--- Editar Educacion ---\n");
    printf("1. Colegiatura (Q%.2f)\n2. Utiles (Q%.2f)\n0. Volver\nOpcion: ", ed.colegiatura, ed.utiles);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &ed.colegiatura); break;
        case 2: scanf("%lf", &ed.utiles); break;
    }
    calcularTotales();
}

void editarVariables() {
    int op;
    printf("\n--- Editar Gastos Variables ---\n");
    printf("1. Spotify (Q%.2f)\n2. Netflix (Q%.2f)\n3. Gemini (Q%.2f)\n4. Cine (Q%.2f)\n5. Paseos (Q%.2f)\n6. Imprevistos (Q%.2f)\n7. Disney (Q%.2f)\n0. Volver\nOpcion: ", gv.spotify, gv.netflix, gv.gemini, gv.cine, gv.paseos, gv.imprevistos, gv.disney);
    scanf("%d", &op);
    if (op == 0) return;
    printf("Ingrese nuevo monto: Q");
    switch(op) {
        case 1: scanf("%lf", &gv.spotify); break;
        case 2: scanf("%lf", &gv.netflix); break;
        case 3: scanf("%lf", &gv.gemini); break;
        case 4: scanf("%lf", &gv.cine); break;
        case 5: scanf("%lf", &gv.paseos); break;
        case 6: scanf("%lf", &gv.imprevistos); break;
        case 7: scanf("%lf", &gv.disney); break;
    }
    calcularTotales();
}

void editarIngreso() {
    printf("\n--- Editar Sueldo Mensual ---\n");
    printf("Sueldo actual: Q%.2f\n", ingresoTotal);
    printf("Ingrese nuevo sueldo: Q");
    scanf("%lf", &ingresoTotal);
    calcularTotales();
    printf("\nSueldo actualizado correctamente.\n");
    printf("Presione ENTER para continuar...");
    getchar(); getchar();
}

#endif
