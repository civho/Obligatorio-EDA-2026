# Estructuras de Datos y Algoritmos
## Obligatorio 2026 - Procesador de Textos

Simulador de un **editor de textos** con capacidad de manejo de líneas y palabras, integrado con funcionalidades de un **diccionario ortográfico**. El sistema actúa a nivel de memoria no persistente y no contempla el desarrollo de interfaces gráficas.

---

## 📌 Características Generales

*   **Líneas:** El texto está compuesto por 0 o más líneas sin límite en la cantidad total.
*   **Palabras:** Cada línea contiene de 0 o más palabras, delimitadas por una constante máxima del sistema (`MAX_CANT_PALABRAS_X_LINEA`).
*   **Restricciones de Formato:** 
    *   Las palabras no deben contener espacios en blanco.
    *   Deben ocupar posiciones consecutivas desde la posición 1 (no se permiten huecos entre palabras).
*   **Sensibilidad a Mayúsculas:** Se ignoran para la lógica interna (búsquedas, diccionarios), pero los comandos que muestran texto deben respetar el formato tal como fue ingresado originalmente.
*   **Estado Inicial:** Al iniciar el sistema, el texto se encuentra vacío (0 líneas) y el diccionario ortográfico no contiene palabras.

---

## 💻 Tipos de Datos Principales

```cpp
// Cadenas de caracteres básicas
typedef char * Cadena;

// Retornos estándar del sistema
enum _retorno {
    OK, 
    ERROR, 
    NO_IMPLEMENTADA
};
typedef enum _retorno TipoRetorno;

// Definición de posiciones indexadas
typedef unsigned int Posicion;
```
*Nota: Se pueden (y deben) definir tipos de datos auxiliares según el diseño modular adoptado.*

---

## 🛠️ Especificación de Operaciones

### 📂 Operaciones Relativas a las Líneas (Al Documento)

#### 1. `InsertarLinea`
Inserta una nueva línea vacía al final del texto. **Restricción:** Debe resolverse en \(O(1)\) en el peor caso.
```cpp
TipoRetorno InsertarLinea(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

#### 2. `InsertarLineaEnPosicion`
Inserta una línea vacía en la posición indicada y desplaza las siguientes una posición hacia adelante. Válida si `posicionLinea >= 1` y `posicionLinea <= cantidad de líneas + 1`.
```cpp
TipoRetorno InsertarLineaEnPosicion(editor &e, Posicion posicionLinea);
```
*   **Retornos:** `OK`, `ERROR` (posición inválida), `NO_IMPLEMENTADA`

#### 3. `BorrarLinea`
Borra la línea en la posición indicada y desplaza las posteriores una posición hacia arriba. Válida si la línea existe.
```cpp
TipoRetorno BorrarLinea(editor &e, Posicion posicionLinea);
```
*   **Retornos:** `OK`, `ERROR` (posición inválida), `NO_IMPLEMENTADA`

#### 4. `BorrarTodo`
Limpia por completo el documento dejándolo vacío.
```cpp
TipoRetorno BorrarTodo(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

#### 5. `BorrarOcurrenciasPalabraEnTexto`
Borra todas las apariciones de una palabra en todo el documento, desplazando las palabras restantes de cada línea para evitar huecos.
```cpp
TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor &e, Cadena palabraABorrar);
```
*   **Retornos:** `OK` (incluso si no se encontró ninguna coincidencia), `NO_IMPLEMENTADA`

#### 6. `ImprimirTexto`
Muestra todo el texto por consola con su respectivo número de línea. Si está vacío, imprime `"Texto vacio"`.
```cpp
TipoRetorno ImprimirTexto(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

#### 7. `ComprimirTexto` *(Opcional)*
Reubica las palabras para llenar al máximo la capacidad de cada línea (`MAX_CANT_PALABRAS_X_LINEA`), manteniendo el orden posicional original. No deben quedar líneas vacías. No genera un nuevo documento.
```cpp
TipoRetorno ComprimirTexto(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

---

### 🔤 Operaciones Relativas a las Palabras

#### 8. `InsertarPalabra`
Inserta una palabra en una línea y posición específicas. Desplaza las palabras siguientes. Si se supera el máximo por línea, el desplazamiento afecta en cascada a las líneas posteriores (pudiendo crear una nueva al final si es necesario).
```cpp
TipoRetorno InsertarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
```
*   **Retornos:** `OK`, `ERROR` (línea o posición de palabra inválida), `NO_IMPLEMENTADA`

#### 9. `BorrarPalabra`
Borra la palabra en la posición e índice indicados, desplazando las siguientes hacia adelante.
```cpp
TipoRetorno BorrarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra);
```
*   **Retornos:** `OK`, `ERROR` (línea o palabra inválida), `NO_IMPLEMENTADA`

#### 10. `BorrarOcurrenciasPalabraEnLinea`
Elimina todas las ocurrencias de una palabra específica dentro de una sola línea determinada.
```cpp
TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor &e, Posicion posicionLinea, Cadena palabraABorrar);
```
*   **Retornos:** `OK`, `ERROR` (línea inválida), `NO_IMPLEMENTADA`

#### 11. `ImprimirLinea`
Muestra una única línea por pantalla anteponiendo su número identificador.
```cpp
TipoRetorno ImprimirLinea(editor &e, Posicion posicionLinea);
```
*   **Retornos:** `OK`, `ERROR` (línea inválida), `NO_IMPLEMENTADA`

---

### 📖 Operaciones Relativas al Diccionario

#### 12. `IngresarPalabraDiccionario`
Agrega una palabra al diccionario si esta no existía previamente. **Restricción:** Debe realizarse en un promedio máximo de \(O(\log_2 n)\).
```cpp
TipoRetorno IngresarPalabraDiccionario(editor &e, Cadena palabraAIngresar);
```
*   **Retornos:** `OK`, `ERROR` (si la palabra ya existe), `NO_IMPLEMENTADA`

#### 13. `BorrarPalabraDiccionario`
Elimina la palabra seleccionada del diccionario de términos.
```cpp
TipoRetorno BorrarPalabraDiccionario(Cadena palabraABorrar);
```
*   **Retornos:** `OK`, `ERROR` (si la palabra no existe), `NO_IMPLEMENTADA`

#### 14. `ImprimirDiccionario`
Muestra el diccionario ordenado alfabéticamente de menor a mayor. Si no posee elementos, imprime `"Diccionario vacio"`. **Restricción:** Peor caso en \(O(n)\).
```cpp
TipoRetorno ImprimirDiccionario(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

#### 15. `ImprimirTextoIncorrecto`
Muestra todo el documento imprimiendo únicamente aquellas palabras que **no** se encuentran registradas en el diccionario ortográfico.
```cpp
TipoRetorno ImprimirTextoIncorrecto(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

#### 16. `ImprimirUltimasPalabras` *(Opcional)*
Imprime un historial de las últimas palabras ingresadas al texto (definido por `MAX_CANT_ULTIMAS_PALABRAS`), en orden de la más reciente a la más antigua. **Restricción:** Debe ejecutarse de manera eficiente agregando solo un costo constante \(O(1)\) a la operación de inserción (Operación 8).
```cpp
TipoRetorno ImprimirUltimasPalabras(editor &e);
```
*   **Retornos:** `OK`, `NO_IMPLEMENTADA`

---

## 📊 Prioridad de Implementación

| Categoría | Operaciones Incluidas | Importancia |
| :--- | :--- | :--- |
| 🔴 **TIPO 1** | 1, 2, 5, 6, 8, 9, 10, 11, 12, 14 | **Imprescindibles** para habilitar la corrección del obligatorio. |
| 🟡 **TIPO 2** | 3, 4, 13, 15 | Importantes. Se prueban de forma independiente tras validar Tipo 1. |
| 🟢 **OPCIONAL**| 7, 16 | Opcionales. Suman hasta **10 puntos adicionales** si están correctas. |

---

## 🚀 Requisitos de Entrega

1.  **Metodología:** Desarrollo estructurado basado en módulos (visto en el curso) utilizando **C/C++**.
2.  **Documentación:** Código completamente comentado incluyendo **pre-condiciones** y **pos-condiciones** para cada operación.
3.  **Compilación:** Entrega estricta de archivos `.c`, `.h` y un archivo `makefile` funcional.
4.  **Hitos Críticos:**
    *   📅 **Control Intermedio:** Operaciones de la 1 a la 11 (Semana del 25 de Octubre de 2026).
    *   📅 **Entrega Final:** Operaciones completas de la 1 a la 16 (Límite: 18 de Noviembre de 2026 23:59 UYT).
