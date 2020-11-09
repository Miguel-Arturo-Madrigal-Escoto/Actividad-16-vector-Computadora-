#include "laboratorio.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

Laboratorio::Laboratorio(){}

void Laboratorio::agregar(const Computadora& c){
    computadoras.push_back(c);
}

void Laboratorio::mostrar(){
    cout << "- - Computadoras - -" << endl << endl;

    cout << left;
    cout << setw(20) << "Nombre equipo";
    cout << setw(30) << "Sistema operativo";
    cout << setw(20) << "Procesador";
    cout << setw(10) << "Ram";
    cout << endl;
    
    for(size_t i(0); i < computadoras.size(); ++i){
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::respaldar(){
    
    ofstream archivo("computadoras.txt");
    if(archivo.is_open()){

        for(size_t i(0); i < computadoras.size(); ++i){
            Computadora &c = computadoras[i];
            archivo << c.getNombreEquipo() << endl;
            archivo << c.getSistemaOperativo() << endl;
            archivo << c.getProcesador() << endl;
            archivo << c.getRam() << endl;
        }
        
    }
    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("computadoras.txt");

    if(archivo.is_open()){
        Computadora c;
        string temp;
        //this->cont = 0;

        while(true)
        {
            getline(archivo, temp);

            if(archivo.eof()) { break; }

            c.setNombreEquipo(temp);

            getline(archivo, temp);
            c.setSistemaOperativo(temp);

            getline(archivo, temp);
            c.setProcesador(temp);

            getline(archivo, temp);
            c.setRam(stoi(temp));

            agregar(c);
        }
    }
    archivo.close();
}

size_t Laboratorio::size(){
    return computadoras.size();
}

void Laboratorio::insertar(const Computadora& com, size_t pos){
    computadoras.insert(computadoras.begin() + pos, com);
}

void Laboratorio::inicializar(const Computadora& com, size_t n){
    computadoras = vector<Computadora>(n, com);
}

void Laboratorio::eliminar(size_t pos){
    computadoras.erase(computadoras.begin() + pos);
}

void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

void Laboratorio::borrar_ultimo(){
    computadoras.pop_back();
}
Computadora* Laboratorio::buscar(const Computadora& com){
   // vector<Computadora>::iterator it = find(computadoras.begin(), computadoras.end(), com);
   // con auto no escribimos todo el iterador
   auto it =  find(computadoras.begin(), computadoras.end(), com);

   if(it == computadoras.end()){
       return nullptr;
   }else{
       return &(*it); // accede al contenido y con & direccion de memoria
   }
}