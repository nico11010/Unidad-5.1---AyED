#include<iostream>

using namespace std;

int main()
{
    int a, b, contador = 1;

    cout << "\n\nIndique numero de filas: ";
    cin >> a;
    cout << "\nIndique numero de columnas: ";
    cin >> b;

    int matrizA[a][b],matrizB[a][b],matrizC[a][b];

    cout << "\n\nMatriz A: \n" << endl;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cout << "A(" << i << ")(" << j << "): ";
            cin >> matrizA[i][j];  
        }
    }

    cout << "\n\nMatriz B: \n" << endl;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cout << "B(" << i << ")(" << j << "): ";
            cin >> matrizB[i][j];  
        }
    }


    cout << "\n\nMatriz resultado: \n" ;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            matrizC[i][j] = matrizA [i][j] + matrizB[i][j];
            cout << matrizC[i][j];

            contador++;

            if (contador > b)
            {
                cout << "\n";
                contador = 1;
            }
            
        }
        
    }

    return 0;
}