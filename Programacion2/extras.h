#include "lista.h"
#include "pila.h"
#include "cola.h"


Lista< Lista<int> > compacta(Lista<int> list){
    Lista<Lista<int>> compact;
    Lista<int> sub;
    int cont = 0, num = 0;
    
    if(list.getLength() > 1){
        while(!list.esVacia()){
            num = list.consultar(0);
            cont++;
            list.eliminar(0);
            if(list.esVacia()){
                sub.insertar(num,0);
                sub.insertar(cont,1);
                compact.insertar(sub, compact.getLength());
            }else{
                if(num != list.consultar(0)){
                    sub.insertar(num,0);
                    sub.insertar(cont,1);
                    compact.insertar(sub, compact.getLength());
                    sub.vaciar();
                    cont = 0;
                }
            }
        }
    }else{
        if(list.getLength() == 1){
            sub.insertar(list.consultar(0), 0);
            sub.insertar(1,1);
            compact.insertar(sub, compact.getLength());
        }
    }
    
    return compact;
}

Lista< Lista<string> > leerListasVertical() {
    string linea;
    int n;

    cin >> n; // Lee la cantidad de números

    Lista<int> listaNumeros;
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        listaNumeros.insertarUltimo(valor);
    }

    getline(cin, linea); // Consumir el salto de línea después de los números

    Lista< Lista<string> > contenedor;

    while (getline(cin, linea)) {
        Lista<string> listaNombres;
        string nombre = "";
        for (size_t i = 0; i <= linea.size(); i++) {
            if (i == linea.size() || linea[i] == ' ') {
                if (!nombre.empty()) {
                    listaNombres.insertarUltimo(nombre);
                    nombre = "";
                }
            } else {
                if (linea[i] != '\n' && linea[i] != '\r' && linea[i] != ' ') {
                    nombre += linea[i];
                }
            }
        }
        contenedor.insertarUltimo(listaNombres);
    }
    return contenedor;
}

void mostrarColumnas(Lista< Lista<string> >& contenedor) {
    int maxCols = 0;
    for (int i = 0; i < contenedor.getLength(); i++) {
        Lista<string> fila = contenedor.consultar(i);
        if (fila.getLength() > maxCols)
            maxCols = fila.getLength();
    }

    for (int col = 0; col < maxCols; col++) {
        Lista<string> columna;
        for (int row = 0; row < contenedor.getLength(); row++) {
            Lista<string> fila = contenedor.consultar(row);
            if (fila.getLength() > col) {
                columna.insertarUltimo(fila.consultar(col));
            }
        }
        cout << "Valores de la columna " << col + 1 << ": ";
        columna.mostrar();
    }
}

Lista<string> obtenerColumna(Lista< Lista<string> >& contenedor, int columna) {
    Lista<string> resultado;
    if (columna < 0) return resultado;

    for (int i = 0; i < contenedor.getLength(); i++) {
        Lista<string> fila = contenedor.consultar(i);
        if (fila.getLength() > columna) {
            resultado.insertarUltimo(fila.consultar(columna));
        }
    }
    return resultado;
}