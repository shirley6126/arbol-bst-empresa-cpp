# Árbol Binario de Búsqueda (BST) — Organigrama Empresarial en C++
## Autor
Shirley Amaguaña
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

Cómo Compilar 

Requisitos
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

> El primer empleado insertado (código 50) siempre será la raíz del árbol.
```
## 📸 Capturas de Ejecución
 
### 0. Menú Principal
<img width="379" height="337" alt="00_menu" src="https://github.com/user-attachments/assets/c66eab8c-aa32-4f6b-981b-afdafee0e4a1" />
 
### 1. Inserción de Empleados
<img width="370" height="821" alt="01_insercion" src="https://github.com/user-attachments/assets/8d8b281d-eb11-417b-9184-100e0bea73e0" />

### 2. Búsqueda de Empleado
<img width="476" height="818" alt="02_busqueda" src="https://github.com/user-attachments/assets/91b5d846-04a8-48b1-8b0d-7d6b27e00803" />

### 3. Mostrar Raiz
<img width="477" height="395" alt="03_mostrarRaiz" src="https://github.com/user-attachments/assets/7a56b997-cff4-44d2-8efe-26d27c3f6f4c" />


### 4. Recorrido Inorden
<img width="594" height="535" alt="04_inorden" src="https://github.com/user-attachments/assets/f4251427-aecc-46d4-9c15-a835b5562faf" />

### 5. Recorrido Preorden
<img width="575" height="531" alt="05_preorden" src="https://github.com/user-attachments/assets/1c871c4d-40d7-48eb-8d05-da6ddd021cf9" />

 
### 6. Recorrido Postorden
<img width="579" height="529" alt="06_postorden" src="https://github.com/user-attachments/assets/d8b329a5-8a4e-46db-b815-5a6f5fd9403d" />

 
### 7. Altura del Árbol
<img width="401" height="380" alt="07_altura" src="https://github.com/user-attachments/assets/80024c47-41f4-4cf2-890f-f67da7a1082b" />

 
### 8. Nodos Hoja
<img width="476" height="465" alt="08_hojas" src="https://github.com/user-attachments/assets/cf5b66ed-31f6-457f-8b01-bee5e8bde331" />

 
---
## Conclusión
La implementación de un Árbol Binario de Búsqueda para representar un organigrama empresarial demuestra cómo las estructuras de datos permiten organizar información jerárquica de forma eficiente. A diferencia de una lista o arreglo lineal, el BST permite realizar búsquedas en O(log n) en promedio, lo que significa que con 1000 empleados solo se necesitan aproximadamente 10 comparaciones para encontrar cualquier registro.

Los tres tipos de recorrido (inorden, preorden y postorden) ofrecen distintas perspectivas del organigrama: inorden entrega una lista ordenada por código, preorden refleja la jerarquía de arriba hacia abajo, y postorden es útil para procesar primero a los subordinados antes que sus superiores.

Esta práctica refuerza conceptos fundamentales de la programación orientada a objetos en C++, el uso de estructuras recursivas, punteros y la organización modular del código mediante clases.
