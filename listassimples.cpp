#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaCircularSimple {
private:
    Nodo* ultimo;
public:
    // Constructor
    ListaCircularSimple() : ultimo(nullptr) {}

    // Métodos para agregar nodos
    void agregarAlInicio(int valor);
    void agregarAlFinal(int valor);
    void agregarEnMedio(int valor, int posicion);
    void imprimirLista();
};

// Método para agregar un nodo al inicio
void ListaCircularSimple::agregarAlInicio(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;

    if (ultimo == nullptr) {  // Si la lista está vacía
        nuevo->siguiente = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
}

// Método para agregar un nodo al final
void ListaCircularSimple::agregarAlFinal(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;

    if (ultimo == nullptr) {  // Si la lista está vacía
        nuevo->siguiente = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

// Método para agregar un nodo en medio (en una posición específica)
void ListaCircularSimple::agregarEnMedio(int valor, int posicion) {
    if (ultimo == nullptr || posicion == 1) {  // Si la lista está vacía o la posición es la primera
        agregarAlInicio(valor);
        return;
    }

    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;

    Nodo* actual = ultimo->siguiente;
    for (int i = 1; i < posicion - 1 && actual != ultimo; i++) {
        actual = actual->siguiente;
    }
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

// Método para imprimir la lista
void ListaCircularSimple::imprimirLista() {
    if (ultimo == nullptr) {
        cout << "La lista está vacía.\n";
        return;
    }

    Nodo* actual = ultimo->siguiente;
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != ultimo->siguiente);
    cout << "(circular)\n";
}

// Función principal para probar la lista circular
int main() {
    ListaCircularSimple lista;

    // Agregamos nodos a la lista
    lista.agregarAlFinal(10);
    lista.agregarAlInicio(5);
    lista.agregarAlFinal(15);
    lista.agregarEnMedio(12, 3);

    // Imprimimos la lista
    lista.imprimirLista();

    return 0;
}
