#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int respuesta = 0;
    int contador_sushi = 0, contar_anterior = 0;
    int tipo, anterior = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> tipo;

        if (i == 0)
        {
            // tomamos el primer tipo
            anterior = tipo;
            contador_sushi = 1;
        }
        else if (tipo == anterior)
        {
            // Es el mismo tipo y amenta el contador
            contador_sushi++;
        }
        else
        {
            // Si cambia el tipo, utilizamos el contador nuevo con el viejo
            if (respuesta <= min(contar_anterior, contador_sushi) * 2)
                respuesta = min(contar_anterior, contador_sushi) * 2;

            // cambiamos el tipo por el nuevo encontrado y actualizamos las variables
            contar_anterior = contador_sushi;
            contador_sushi = 1;
            anterior = tipo;
        }
    }

    if (respuesta <= min(contar_anterior, contador_sushi) * 2)
        respuesta = min(contar_anterior, contador_sushi) * 2;

    cout << respuesta << endl;

    return 0;
}
