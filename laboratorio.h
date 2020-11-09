#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <vector>
#include "computadora.h"

class Laboratorio{
private:
    std::vector <Computadora> computadoras;
public:
    Laboratorio();

    void agregar(const Computadora& c);
    void mostrar();
    void respaldar();
    void recuperar();

    size_t size();

    void insertar(const Computadora& com, size_t pos);
    void inicializar(const Computadora& com, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    void borrar_ultimo();

    Computadora* buscar(const Computadora& com);

    friend Laboratorio& operator<<(Laboratorio& lab, const Computadora& com){
        lab.agregar(com);
        
        return lab;
    }
};

#endif