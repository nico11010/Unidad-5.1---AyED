/*Un archivo de texto contiene información acerca de los productos que se venden en un
almacén. Lo único que se sabe acerca del número de productos es que no puede superar
un cierto valor MaxProductos. De cada producto se guarda información sobre su código
identificador (entero positivo), su precio (real) y el número de unidades existentes (entero
positivo). El formato en el que se guarda la información dentro del archivo es el siguiente:
id1 precio1 unidades1
id2 precio2 unidades2
...
idN precioN unidadesN
‐1
a) Declara un tipo tProducto que represente la información de un producto y
un tipo tLista que mantenga la información de todos los productos.
b) Escribe un subprograma que lea los datos del archivo de texto que almacena
la información, los guarde en la lista y luego los muestre en la pantalla.
c) Escribe un subprograma que encuentre el producto con máximo valor en el
almacén, considerando que el valor del producto i es precioi*unidadesi.
d) Escribe un subprograma que dado un identificador de producto a eliminar
del almacén, lo busque en la lista y lo elimine actualizando la lista como
corresponda.*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;


const int maxProducto = 100;


typedef struct
{

    int codigo;
    float precioProducto;
    int cantidad;
    string nombreProducto;

}tProducto;


typedef struct
{

    tProducto producto[maxProducto];
    int contador = 0;

}tLista;


tLista lista;

void seleccionMenu(int opcion);
void leerArchivo();
void mostrarContenido();
void productoMayorValor();
void eliminarProducto();
void actualizarArchivo();


int main()
{
    int opcion;

    do{
        cout << "\n1 - Leer archivo" << endl;
        cout << "2 - Mostrar contenido" << endl;
        cout << "3 - Producto de mayor valor" << endl;
        cout << "4 - Eliminar producto" << endl;
        cout << "0 - salir" << endl;

        cout <<"\n> ";
        cin >> opcion;

        if (opcion != 0)
        {
            seleccionMenu(opcion);
        }
        
    }while (opcion != 0);
    
    return 0;
}





void seleccionMenu(int opcion)
{
    switch (opcion)
    {
        case 1:
            leerArchivo();
            break;
        
        case 2:
            mostrarContenido();
            break;
        
        case 3:
            productoMayorValor();
            break;

        case 4:
            eliminarProducto();
            actualizarArchivo();
            break;

        default:
            cout << "\n\nOpcion incorrecta.." << endl;
            break;
    }

}





void leerArchivo()
{
    ifstream archivo;
    char aux;


    archivo.open("productos.txt");



    if(!archivo.is_open())
    {
        cout << "\nError al cargar - Archivo no encontrado" << endl;

    }



    lista.contador = 0;



    archivo >> lista.producto[lista.contador].codigo;

    while (lista.producto[lista.contador].codigo != 0)
    {
        archivo >> lista.producto[lista.contador].precioProducto;
        archivo >> lista.producto[lista.contador].cantidad;
        archivo.get(aux);
        getline(archivo, lista.producto[lista.contador].nombreProducto);

        lista.contador++;

        archivo >> lista.producto[lista.contador].codigo;
    }
    
    cout << "\n\nArchivo Cargado..." << endl;

    archivo.close();

}






void mostrarContenido()
{

    if(lista.contador == 0)
    {
        cout << "\nNo hay datos cargados - Por favor, cargue el archivo" << endl;
        return;
    }

    cout << "\n";

    for (int i = 0; i < lista.contador; i++)
    {
        cout << setw(10) << left << lista.producto[i].codigo
             << setw(10) << left << lista.producto[i].precioProducto
             << setw(10) << left << lista.producto[i].cantidad
             << setw(20) << left << lista.producto[i].nombreProducto << endl;
    }
    
    cout << "\nPresione enter para volver al menu.. ";
    cin.ignore();
    cin.get();

}



void productoMayorValor()
{
    if(lista.contador == 0)
    {
        cout << "\nNo hay datos cargados - Por favor, cargue el archivo" << endl;
        return;
    }

    float precioMasAlto = 0;
    int index = 0;

    for (int i = 0; i < lista.contador; i++)
    {
        if (lista.producto[i].precioProducto > precioMasAlto)
        {
            precioMasAlto = lista.producto[i].precioProducto;
            index = i;
        }
        
    }
    
    
    cout << "\n\nEl producto de mayor valor es: " << lista.producto[index].nombreProducto << endl;
    cout << "Su precio es de:  -  $" << lista.producto[index].precioProducto << endl;

    
    cout << "\nPresione enter para volver al menu.. ";
    cin.ignore();
    cin.get();

}







void eliminarProducto()
{
    if(lista.contador == 0)
    {
        cout << "\nNo hay datos cargados - Por favor, cargue el archivo" << endl;
        return;
    }

    int index, identificador;

    cout << "\n - Eliminar producto - " << endl;

    cout << "\nIndetificador de producto: ";
    cin >> identificador;

    for(int i = 0; i < lista.contador; i++)
    {
        if(identificador == lista.producto[i].codigo)
        {
            index = i;
        }
    }

    for(int i = index; i < lista.contador - 1; i++)
    {
        lista.producto[i] = lista.producto[i + 1];
    }

    lista.contador--;

    cout << "\n\nProducto eliminado.." << endl;

}





void actualizarArchivo()
{

    ofstream archivo;

    archivo.open("productos.txt");

    if (!archivo.is_open())
    {
        return;
    }

    for (int i = 0; i < lista.contador; i++)
    {
        archivo << setw(10) << left << lista.producto[i].codigo
             << setw(10) << left << lista.producto[i].precioProducto
             << setw(10) << left << lista.producto[i].cantidad
             << setw(20) << left << lista.producto[i].nombreProducto << endl;
    }

    archivo << 0 << endl;

    archivo.close();
}