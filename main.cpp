#include <iostream>
#include <conio.h>
#include "laboratorio.h"

using namespace std;

int main() {
    Laboratorio lab;
    Computadora com;
    string str;
    size_t n;

    while(true)
    {
        cout << "Actividad 16: vector<Computadora>" << endl << endl;
        cout << "1) Agregar computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Borrar ultimo" << endl;
        cout << "10) Buscar" << endl;
        cout << "0) Salir" << endl;
        cout << "-> Elige una opcion: ";
        getline(cin, str);

        if(str == "1"){
            cin >> com;

            lab.agregar(com);
            cin.sync();
        }
        else if(str == "2"){
            lab.mostrar();
        }
        else if(str == "3"){
            lab.respaldar();
        }
        else if(str == "4"){
            lab.recuperar();
        }
        else if(str == "5"){
            cin >> com;
            cout << "Posicion: ";
            cin >> n;

            cin.sync();

            if(n >= lab.size()){
                cout << "Posicion invalida" << endl;
            }else{
                lab.insertar(com, n);
            }
        }
        else if(str == "6"){
            cin >> com;

            cout << "N: ";
            cin >> n; 

            cin.sync();

            lab.inicializar(com, n);
        }
        else if(str == "7"){
            cout << "Posicion: ";
            cin >> n;

            if(n >= lab.size()){
                cout << "Posicion invalida" << endl;
            }else{
                lab.eliminar(n);
            }
        }
        else if(str == "8"){
            lab.ordenar();
        }
        else if(str == "9"){
            if(lab.size() == 0){
                cout << "El vector esta vacio" << endl;
            }else{
                lab.borrar_ultimo();
            }
        }
        else if(str == "10"){
            cin >> com;
            Computadora *ptr = lab.buscar(com);

            cin.sync();

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }else{
                cout << "Encontrado: " << *ptr << endl;
            }
        }
        else if(str == "0"){
            getch();
            break;
        }
        getch();
        system("cls");
    }
     
    return 0;
}