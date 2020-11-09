#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>

class Computadora{
private:
    std::string nombreEquipo;
    std::string sistemaOperativo;
    std::string procesador;
    unsigned int ram;
public:
    Computadora();
    Computadora(const std::string& nombreEquipo, const std::string& sistemaOperativo, const std::string& procesador, unsigned int ram);

    void setSistemaOperativo(const std::string& v);
    void setNombreEquipo(const std::string& v);
    void setProcesador(const std::string& v);
    void setRam(unsigned int v);

    std::string getSistemaOperativo();
    std::string getNombreEquipo();
    std::string getProcesador();
    unsigned int getRam();

    friend std::ostream& operator<<(std::ostream& out, const Computadora& c){
        out << std::left;
        out << std::setw(20) << c.nombreEquipo;
        out << std::setw(30) << c.sistemaOperativo;
        out << std::setw(20) << c.procesador;
        out << std::setw(10) << c.ram;
        out << std::endl;
        
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Computadora& c){

        std::cin.sync();
        
        std::cout << "Nombre equipo: ";
        getline(std::cin, c.nombreEquipo);

        std::cout << "Sistema operativo: ";
        getline(std::cin, c.sistemaOperativo);

        std::cout << "Procesador: ";
        getline(std::cin, c.procesador);

        std::cout << "Ram: ";
        std::cin >> c.ram;

        return in;
    }

    bool operator == (const Computadora& c){
        return nombreEquipo == c.nombreEquipo;
    }

    bool operator == (const Computadora& c) const {
        return nombreEquipo == c.nombreEquipo;
    }

    bool operator < (const Computadora& c){
        return nombreEquipo < c.nombreEquipo;
    }

    bool operator < (const Computadora& c) const {
        return nombreEquipo < c.nombreEquipo;
    }

    ~Computadora();
    
};
    
#endif