/*Escribe un programa que lea del teclado una frase y a continuación visualice las palabras de la
frase en columna, seguida cada una del número de letras que la componen.*/

#include<iostream>
#include<string>
#include<sstream> 

using namespace std;

void columnarFrase(const string& frase);

int main()
{
    string frase;

    cout << "Ingrese una frase: ";
    getline(cin, frase);

    columnarFrase(frase);

    return 0;
}

void columnarFrase(const string& frase)
{
    istringstream stream(frase);
    string palabra;
    
    cout << " " << endl;

    while (stream >> palabra) {
        cout << palabra << " - Letras: " << palabra.length() << endl;
    }
}
