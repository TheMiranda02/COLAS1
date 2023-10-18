// COLAS1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#define MaxTamC 10

typedef int TipoDato;
using namespace std;
int main()
{
    int frente = 0, final = 0;
    TipoDato A[MaxTamC];
    int contador = 0;

    //INICIAR LA COLA
    frente = 0;
    final = 0;
    cout << " Desea agregar elementos a la cola? (S/N)";
    char respuesta;
    cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'n') && contador < 10) {
        if ((final + 1) % MaxTamC == frente) {
            cout << "Desbordaniemto de la cola" << endl;
            return 1;
        }

        cout << " Ingrese un elemnto de la cola ";
        TipoDato elemento;
        cin >> elemento;
        final = (final + 1) & MaxTamC;
        A[final] = elemento;

        contador++;
        cout << " Elemento " << contador << " agregado a la cola " << elemento << endl;

        if (contador < 10) {
            cout << " Desaea agregar mas elementos a la cola? (s/n):";
                cin >> respuesta;
        }
    }

    //VALIDAR SI LA COLA ESTA VACIA
    if (frente == final) {
        cout << " La cola esta vacia" << endl;
        return 1;
    }

    //obtener el primer elemnto de la cola
    TipoDato primerElemento = A[(frente + 1) % MaxTamC];
    cout << " El primer elemto de la cola es: " << primerElemento << endl;

    //Elaborar un elemento de la cola 
    frente = (frente + 1) % MaxTamC;

    //Imprimir elementos de la cola en el orden en que fue ingresada 
    cout << " Elementos de la cola  en el orden de ingreso " << endl;
    for (int i = frente + 1; i <= final; i = (i + 1) & MaxTamC) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
