# Árbol Binario de Búsqueda (BST) — Organigrama Empresarial en C++

## Objetivo

Implementar en C++ un **Árbol Binario de Búsqueda (BST)** para organizar empleados de una empresa usando un código numérico como clave de búsqueda. El sistema permite insertar, buscar y recorrer empleados de manera eficiente a través de una estructura jerárquica, representando visualmente el organigrama de una organización.

---

## Funcionalidades

| N° | Funcionalidad | Descripción |
|----|---------------|-------------|
| 1 | **Insertar empleado** | Agrega un nuevo empleado (código, nombre, cargo) al árbol |
| 2 | **Buscar por código** | Localiza un empleado específico usando su código numérico |
| 3 | **Mostrar raíz** | Muestra el primer empleado insertado (nodo raíz del árbol) |
| 4 | **Recorrido Inorden** | Lista empleados de menor a mayor código (izq → raíz → der) |
| 5 | **Recorrido Preorden** | Muestra la raíz primero, luego subárboles (raíz → izq → der) |
| 6 | **Recorrido Postorden** | Muestra los hijos antes que el padre (izq → der → raíz) |
| 7 | **Altura del árbol** | Calcula el número de niveles del árbol |
| 8 | **Nodos hoja** | Identifica los empleados sin subordinados (nivel más bajo) |

---

Un **Árbol Binario de Búsqueda (BST)** es una estructura de datos jerárquica donde cada nodo tiene como máximo dos hijos. La regla fundamental es:

```
         50 (Raíz)
        /          \
      30            70
     /  \          /  \
   20    40      60    80
```

-  **Todo número menor** que el nodo va al **subárbol izquierdo**
-  **Todo número mayor** que el nodo va al **subárbol derecho**
-  Esta regla hace que las búsquedas sean muy eficientes

### Conceptos clave

| Término | Definición |
|---------|------------|
| **Raíz** | El primer nodo insertado, en la cima del árbol |
| **Nodo interno** | Nodo que tiene al menos un hijo |
| **Hoja** | Nodo sin hijos (nivel más bajo del árbol) |
| **Altura** | Número de niveles desde la raíz hasta la hoja más profunda |

---

##  Estructura del Proyecto

```
arbol-bst-empresa-cpp/
│
├── src/
│   └── main.cpp         ← Código fuente completo en C++
│
├── capturas/
│   ├── 00_menu.png      ← Captura del menú principal
│   ├── 01_insercion.png ← Captura del proceso de inserción
│   ├── 02_busqueda.png  ← Captura de búsqueda de empleado
|   ├── 03_mostrarRaiz.png  ← Captura de la raiz del arbol
│   ├── 04_inorden.png   ← Captura del recorrido inorden
│   ├── 05_preorden.png  ← Captura del recorrido preorden
│   ├── 06_postorden.png ← Captura del recorrido postorden
│   ├── 07_altura.png    ← Captura de la altura del árbol
│   └── 08_hojas.png     ← Captura de los nodos hoja
│
└── README.md           

---

Cómo Compilar y Ejecutar

### Requisitos
- Tener instalado **g++** (MinGW en Windows)
- Git Bash 

Datos de Prueba Sugeridos

Para probar el árbol con un organigrama completo, ingresar los empleados **en este orden**:

| Código | Nombre | Cargo |
|--------|--------|-------|
| 50 | Empresa UTA | Raíz |
| 30 | Gerente Ventas | Nodo interno |
| 70 | Gerente Finanzas | Nodo interno |
| 20 | Emp 1 | Hoja |
| 40 | Emp 2 | Hoja |
| 60 | Emp 3 | Hoja |
| 80 | Emp 4 | Hoja |

> El **primer empleado insertado** (código 50) siempre será la raíz del árbol.

---
Conclusión

La implementación de un **Árbol Binario de Búsqueda** para representar un organigrama empresarial demuestra cómo las estructuras de datos permiten organizar información jerárquica de forma eficiente. A diferencia de una lista o arreglo lineal, el BST permite realizar búsquedas en **O(log n)** en promedio, lo que significa que con 1000 empleados solo se necesitan aproximadamente 10 comparaciones para encontrar cualquier registro.

Los tres tipos de recorrido (inorden, preorden y postorden) ofrecen distintas perspectivas del organigrama: inorden entrega una lista ordenada por código, preorden refleja la jerarquía de arriba hacia abajo, y postorden es útil para procesar primero a los subordinados antes que sus superiores.

Esta práctica refuerza conceptos fundamentales de la programación orientada a objetos en C++, el uso de estructuras recursivas, punteros y la organización modular del código mediante clases.

---
