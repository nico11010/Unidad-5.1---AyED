/*Implementa un programa que permita realizar operaciones sobre matrices de NxN. El programa
debe permitir al usuario la selección de alguna de las siguientes operaciones:
a) Sumar 2 matrices.
b) Restar 2 matrices.
c) Multiplicar 2 matrices.
d) Trasponer una matriz.
e) Mostrar una matriz señalando cuáles son los puntos de silla (los puntos de silla de una matriz
son aquellos elementos de la misma que cumplen ser el mínimo de su fila y el máximo de su
columna).
Habrá también dos subprogramas para leer del teclado o mostrar en la pantalla una matriz.*/


#include <iostream>

using namespace std;

const int MAX = 100; // Definimos un tamaño máximo para las matrices

// Prototipos de funciones
void leerMatriz(int matriz[][MAX], int n);
void mostrarMatriz(const int matriz[][MAX], int n);
void sumarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]);
void restarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]);
void multiplicarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]);
void trasponerMatriz(const int matriz[][MAX], int n, int resultado[][MAX]);
void encontrarPuntosDeSilla(const int matriz[][MAX], int n);

int main() {
    int n;
    cout << "Ingrese la dimension (N) de las matrices NxN: ";
    cin >> n;

    int matriz1[MAX][MAX];
    int matriz2[MAX][MAX];

    cout << "Ingrese la primera matriz:\n";
    leerMatriz(matriz1, n);

    cout << "Ingrese la segunda matriz:\n";
    leerMatriz(matriz2, n);

    // Menú de operaciones
    char opcion;
    cout << "\nElija una operacion:\n";
    cout << "1 - Sumar 2 matrices.\n";
    cout << "2 - Restar 2 matrices.\n";
    cout << "3 - Multiplicar 2 matrices.\n";
    cout << "4 - Trasponer una matriz.\n";
    cout << "5 - Mostrar una matriz con puntos de silla.\n";
    cout << "\n> ";
    cin >> opcion;

    int resultado[MAX][MAX]; // Matriz para almacenar el resultado de las operaciones

    switch(opcion) {
        case 1:
            sumarMatrices(matriz1, matriz2, n, resultado);
            cout << "\nLa suma de las matrices es:\n";
            mostrarMatriz(resultado, n);
            break;
        case 2:
            restarMatrices(matriz1, matriz2, n, resultado);
            cout << "\nLa resta de las matrices es:\n";
            mostrarMatriz(resultado, n);
            break;
        case 3:
            multiplicarMatrices(matriz1, matriz2, n, resultado);
            cout << "\nEl producto de las matrices es:\n";
            mostrarMatriz(resultado, n);
            break;
        case 4: {
            trasponerMatriz(matriz1, n, resultado);
            cout << "\nLa matriz transpuesta es:\n";
            mostrarMatriz(resultado, n);
            break;
        }
        case 5: {
            cout << "\nPuntos de silla de la primera matriz:\n";
            encontrarPuntosDeSilla(matriz1, n);
            break;
        }
        default:
            cout << "Opcion no valida.\n";
    }

    return 0;
}

// Función para leer una matriz desde el teclado
void leerMatriz(int matriz[][MAX], int n) {
    cout << "Ingrese los elementos de la matriz por filas:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Fila " << (i + 1) << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }
}

// Función para mostrar una matriz en la pantalla
void mostrarMatriz(const int matriz[][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

// Función para sumar dos matrices
void sumarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Función para restar dos matrices
void restarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(const int matriz1[][MAX], const int matriz2[][MAX], int n, int resultado[][MAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

// Función para transponer una matriz
void trasponerMatriz(const int matriz[][MAX], int n, int resultado[][MAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[j][i] = matriz[i][j];
        }
    }
}

// Función para encontrar puntos de silla en una matriz
void encontrarPuntosDeSilla(const int matriz[][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        int minFila = matriz[i][0];
        int colMin = 0;
        // Encontrar el mínimo de la fila i
        for (int j = 1; j < n; ++j) {
            if (matriz[i][j] < minFila) {
                minFila = matriz[i][j];
                colMin = j;
            }
        }
        // Verificar si es máximo en su columna
        bool puntoDeSilla = true;
        for (int k = 0; k < n; ++k) {
            if (matriz[k][colMin] > minFila) {
                puntoDeSilla = false;
                break;
            }
        }
        if (puntoDeSilla) {
            cout << "Punto de silla encontrado en (" << i << ", " << colMin << "): " << minFila << "\n";
        }
    }
}
