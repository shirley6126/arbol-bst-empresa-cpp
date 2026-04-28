#include <iostream>   
#include <string>     
#include <algorithm>
using namespace std;


//  STRUCT EMPLEADO
//  Representa los datos de cada persona en el organigrama.

struct Empleado {
    int    codigo;   // Clave del BST: decide a donde va en el arbol
    string nombre;   // Nombre del empleado
    string cargo;    // Cargo dentro de la empresa
};


//  STRUCT NODO
//  Es cada "cajita" del arbol. Guarda un Empleado y dos
//  punteros: uno al hijo izquierdo y otro al hijo derecho.
struct Nodo {
    Empleado dato;       // Los datos del empleado
    Nodo*    izquierdo;  // Puntero al hijo izquierdo
    Nodo*    derecho;    // Puntero al hijo derecho

    // Constructor: cuando se crea un Nodo, sus hijos empiezan vacios
    Nodo(Empleado emp) {
        dato       = emp;
        izquierdo  = nullptr;
        derecho    = nullptr;
    }
};

//  CLASE ARBOLBST
//  Contiene todas las operaciones del arbol
//  Las funciones privadas trabajan con punteros (recursion)
//  Las funciones publicas son las que llama el main
class ArbolBST {

private:
    Nodo* raiz;   // Puntero al nodo raiz del arbol


    // INSERTAR (privado, recursivo)
    //   - codigo menor  -> va al SUBÁRBOL IZQUIERDO
    //   - codigo mayor  -> va al SUBÁRBOL DERECHO
    //   - codigo igual  -> no se inserta (codigo ya existe)
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        // Caso base: llegamos a un lugar vacio -> creamos el nodo aqui
        if (nodo == nullptr) {
            return new Nodo(emp);
        }

        // Comparamos el codigo del nuevo empleado con el del nodo actual
        if (emp.codigo < nodo->dato.codigo) {
            // El codigo es menor: buscamos lugar en el lado izquierdo
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            // El codigo es mayor: buscamos lugar en el lado derecho
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            // El codigo ya existe en el arbol
            cout << "  [!] El codigo " << emp.codigo << " ya existe en el arbol.\n";
        }

        return nodo;   
    }


    // BUSCAR (privado, recursivo)
    // Recorre el arbol comparando codigos hasta encontrar o
    // llegar a un nullptr (no existe)
    Nodo* buscar(Nodo* nodo, int codigo) {
        // Caso base: nodo vacio (no encontrado) o codigo coincide
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }

        // Decidimos en que direccion seguir buscando
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    // RECORRIDO INORDEN: Izquierda -> Raiz -> Derecha
    // Resultado: los empleados salen ORDENADOS de menor a mayor codigo
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);   // 1ro visita la izquierda
            mostrarEmpleado(nodo);      // 2do muestra el actual
            inorden(nodo->derecho);     // 3ro visita la derecha
        }
    }


    // RECORRIDO PREORDEN: Raiz -> Izquierda -> Derecha
    // Resultado: muestra la raiz PRIMERO, luego sus hijos
    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);      // 1ro muestra el actual
            preorden(nodo->izquierdo);  // 2do visita la izquierda
            preorden(nodo->derecho);    // 3ro visita la derecha
        }
    }

    // RECORRIDO POSTORDEN: Izquierda -> Derecha -> Raiz
    // Resultado: los hijos salen ANTES que sus padres
    // Util para eliminar el arbol (liberar memoria)
    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo); // 1ro visita la izquierda
            postorden(nodo->derecho);   // 2do visita la derecha
            mostrarEmpleado(nodo);      // 3ro muestra el actual
        }
    }

 
    // ALTURA (privado, recursivo)
    // La altura es el numero de niveles del arbol.
    // Cuenta el camino mas largo desde la raiz hasta una hoja.
    // Formula: 1 + max(altura_izquierda, altura_derecha)
    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;   // Nodo vacio tiene altura 0
        }
        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);
        return 1 + max(alturaIzq, alturaDer);  // +1 por el nodo actual
    }


    // MOSTRAR HOJAS (privado, recursivo)
    // Una hoja es un nodo que NO tiene hijos (ambos son nullptr).
    // Los nodos hoja son los empleados del nivel mas bajo.
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            // Si no tiene ni hijo izquierdo ni derecho: es hoja
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);  // Revisamos la izquierda
            mostrarHojas(nodo->derecho);    // Revisamos la derecha
        }
    }

 
    // MOSTRAR EMPLEADO (auxiliar)
    // Funcion de ayuda para no repetir el cout en cada funcion.
    void mostrarEmpleado(Nodo* nodo) {
        cout << "  Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: "  << nodo->dato.cargo
             << "\n";
    }

public:

    // CONSTRUCTOR
    // Cuando creamos un ArbolBST, la raiz empieza vacia (nullptr)
    ArbolBST() {
        raiz = nullptr;
    }

    // Funcion publica: llama al insertar privado desde la raiz
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
        cout << "   Empleado insertado correctamente.\n";
    }

    // Funcion publica: busca e imprime el resultado
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\n  Empleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\n  Empleado con codigo " << codigo << " no encontrado.\n";
        }
    }

    // Muestra quien es la raiz del arbol
    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n  Raiz del arbol (primer empleado insertado):\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "\n  El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\n  Recorrido INORDEN (de menor a mayor codigo):\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\n  Recorrido PREORDEN (raiz primero):\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\n  Recorrido POSTORDEN (raiz al final):\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\n  Altura del arbol: " << altura(raiz) << " niveles\n";
    }

    void mostrarNodosHoja() {
        cout << "\n  Nodos HOJA (sin hijos):\n";
        mostrarHojas(raiz);
    }
};


//  FUNCION MAIN
//  Punto de entrada del programa.
//  Muestra el menu y llama a las funciones del arbol.
int main() {
    ArbolBST arbol;  // Creamos el arbol vacio
    int opcion;

    do {
        // Menu principal
        cout << "\n====================================\n";
        cout << "    ARBOL BST - ORGANIGRAMA EMPRESA    \n";
        cout << " ====================================\n";
        cout << "  1. Insertar empleado                 \n";
        cout << "  2. Buscar empleado por codigo        \n";
        cout << "  3. Mostrar raiz                      \n";
        cout << "  4. Recorrido inorden                 \n";
        cout << "  5. Recorrido preorden                \n";
        cout << "  6. Recorrido postorden               \n";
        cout << "  7. Mostrar altura del arbol          \n";
        cout << "  8. Mostrar nodos hoja                \n";
        cout << "  0. Salir                             \n";

        cout << "  Seleccione una opcion: ";
        cin >> opcion;

        cout << "\n";

        if (opcion == 1) {
            Empleado emp;
            cout << "  Ingrese codigo (numero entero): ";
            cin >> emp.codigo;
            cin.ignore();  // Limpia el buffer del teclado antes de leer texto
            cout << "  Ingrese nombre: ";
            getline(cin, emp.nombre);
            cout << "  Ingrese cargo: ";
            getline(cin, emp.cargo);
            arbol.insertarEmpleado(emp);

        } else if (opcion == 2) {
            int codigo;
            cout << "  Ingrese codigo a buscar: ";
            cin >> codigo;
            arbol.buscarEmpleado(codigo);

        } else if (opcion == 3) {
            arbol.mostrarRaiz();

        } else if (opcion == 4) {
            arbol.mostrarInorden();

        } else if (opcion == 5) {
            arbol.mostrarPreorden();

        } else if (opcion == 6) {
            arbol.mostrarPostorden();

        } else if (opcion == 7) {
            arbol.mostrarAltura();

        } else if (opcion == 8) {
            arbol.mostrarNodosHoja();

        } else if (opcion != 0) {
            cout << "   Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);  // El ciclo termina cuando el usuario elige 0

    cout << "\n  Programa finalizado... \n";
    return 0;
}