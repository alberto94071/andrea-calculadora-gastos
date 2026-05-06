# ANDREA — Asistente de Navegación de Datos y Registro de Egresos Automatizado

> Calculadora de gastos personales mensuales desarrollada en C, como proyecto final de Programación I.

---

## 📋 Descripción

**ANDREA** es una aplicación de consola para Windows que permite gestionar y visualizar los gastos mensuales de una persona, organizados en 6 categorías:

- Servicios Públicos (luz, agua, gas, internet, plan celular)
- Servicios Básicos (alimentación, mercado, higiene, limpieza)
- Transporte (gasolina, pasajes, parqueos, car wash)
- Salud y Bienestar (medicinas, seguro médico)
- Educación (colegiatura, útiles)
- Gastos Variables (Spotify, Netflix, Gemini, Disney, cine, paseos, imprevistos)

El sistema calcula automáticamente el ahorro mensual real (`Sueldo - Gastos Totales`) y mantiene un historial de ahorros acumulados mes a mes, con persistencia de datos entre sesiones.

---

## ▶️ Cómo usar (usuario final)

**No necesitas instalar nada.** Solo:

1. Descarga el archivo `andrea-v1.0.zip` desde la sección [Releases](../../releases)
2. Extrae todos los archivos en una carpeta
3. Haz doble clic en `andrea.exe`

> ⚠️ El `.exe` y el archivo `historial_ahorros.txt` deben estar **en la misma carpeta**. No muevas solo el `.exe`.

---

## 🛠️ Cómo compilar (desarrolladores)

### Requisitos
- GCC / MinGW para Windows (recomendado: [WinLibs](https://winlibs.com/))

### Pasos

1. Clona el repositorio:
   ```bash
   git clone https://github.com/TU_USUARIO/andrea-calculadora-gastos.git
   cd andrea-calculadora-gastos
   ```

2. Edita `compilar_con_icono.bat` y cambia `GCC_PATH` a la ruta donde tienes MinGW instalado en tu máquina.

3. Ejecuta el `.bat`:
   ```
   compilar_con_icono.bat
   ```

Esto generará `andrea.exe` con todas las librerías incluidas (compilación estática, no requiere DLLs externas).

### Compilación manual alternativa
```bash
gcc Principal.c -o andrea.exe -static -lm
```

---

## 📁 Estructura del proyecto

```
andrea-calculadora-gastos/
├── Principal.c               # Archivo principal, menú y flujo del programa
├── andrea_variables.h        # Definición de structs y variables globales
├── andrea_logica.h           # Lógica de cálculo y edición de categorías
├── andrea_persistencia.h     # Lectura/escritura de datos (binario + historial)
├── andrea_visuales.h         # Logo ASCII, tablas y separadores visuales
├── andrea_instrucciones.h    # Pantalla de instrucciones de uso
├── resources.rc              # Recurso del ícono de la aplicación
├── andrea.ico                # Ícono de la ventana
├── icon.png                  # Imagen del proyecto
├── compilar_con_icono.bat    # Script de compilación para Windows
├── LEEME.txt                 # Instrucciones para el usuario final
└── .gitignore
```

### Archivos generados en tiempo de ejecución (NO incluidos en el repo)
| Archivo | Descripción |
|---|---|
| `andrea_data.bin` | Estado actual de todos los gastos (se crea al salir) |
| `historial_ahorros.txt` | Registro acumulado de ahorros por mes |

---

## ✨ Funcionalidades

- Sueldo mensual configurable (valor base: Q8,700.00)
- Edición de montos por categoría desde el menú
- Cálculo automático del ahorro mensual real
- Persistencia de datos entre sesiones (archivo binario)
- Historial de ahorros con sumatoria total acumulada
- Cierre de mes con registro en historial
- Interfaz visual con logo ASCII y tablas formateadas

---

## 👨‍💻 Autores

|           Nombre            |     Carné     |
|-----------------------------|---------------|
| Andrea Isabel Godínez Cruz  | 0903-24-25969 |
| Kristel Andrea Mérida Díaz  | 0903-25-23801 |
| Carlos Vallardo Morales G.  | 0903-25-16887 |
| Rony Alberto Méndez Fuentes | 0903-25-29637 |

**Curso:** Programación I  
**Fecha:** Mayo 2026  .
**Universidad:** Universidad Mariano Galvez de Guatemala