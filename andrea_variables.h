#ifndef ANDREA_VARIABLES_H
#define ANDREA_VARIABLES_H

#include <stdbool.h>

#define INGRESO_MENSUAL 8700.00
#define CUOTA_AHORRO_BASE 870.00

typedef struct {
    double luz;
    double agua;
    double gas;
    double internet;
    double planCelular;
    double total;
} ServiciosPublicos;

typedef struct {
    double alimentacion;
    double mercado;
    double higiene;
    double limpieza;
    double total;
} ServiciosBasicos;

typedef struct {
    double gasolina;
    double pasajes;
    double parqueos;
    double carWash;
    double total;
} Transporte;

typedef struct {
    double medicinas;
    double seguroMedico;
    double total;
} Salud;

typedef struct {
    double colegiatura;
    double utiles;
    double total;
} Educacion;

typedef struct {
    double spotify;
    double netflix;
    double gemini;
    double cine;
    double paseos;
    double imprevistos;
    double disney;
    double total;
} GastosVariables;

// Variables Globales del Sistema
extern ServiciosPublicos sp;
extern ServiciosBasicos sb;
extern Transporte tr;
extern Salud sl;
extern Educacion ed;
extern GastosVariables gv;

extern double ingresoTotal;
extern double ahorroProyectado;
extern double gastoTotalGeneral;
extern double ahorroReal;
extern double ahorroTotalHistorico;
extern bool ejecutando;

#endif
