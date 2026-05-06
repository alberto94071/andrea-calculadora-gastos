#ifndef ANDREA_VISUALES_H
#define ANDREA_VISUALES_H

#include <stdio.h>

void mostrarLogo() {
    printf("===============================================================================\n");
    printf("      ___      .__   __.  _______  .______       _______      ___      \n");
    printf("     /   \\     |  \\ |  | |       \\ |   _  \\     |   ____|    /   \\     \n");
    printf("    /  ^  \\    |   \\|  | |  .--.  ||  |_)  |    |  |__      /  ^  \\    \n");
    printf("   /  /_\\  \\   |  . `  | |  |  |  ||      /     |   __|    /  /_\\  \\   \n");
    printf("  /  _____  \\  |  |\\   | |  '--'  ||  |\\  \\----.|  |____  /  _____  \\  \n");
    printf(" /__/     \\__\\ |__| \\__| |_______/ | _| `._____||_______|/__/     \\__\\ \n");
    printf("                                                                       \n");
    printf("                     ANDREA: Asistente de Navegacion de Datos y                     \n");
    printf("                       Registro de Egresos Automatizado                          \n");
    printf("=================================================================================\n");
    printf("                   \"Andrea, tu asistente de gastos mensuales\"             \n");
    printf("==================================================================================\n\n");
}

void mostrarSeparador(char* titulo) {
    printf("\n--- %s ---\n", titulo);
}

void dibujarTabla(char* cat, double monto) {
    printf("| %-25s | Q %10.2f |\n", cat, monto);
}

#endif
