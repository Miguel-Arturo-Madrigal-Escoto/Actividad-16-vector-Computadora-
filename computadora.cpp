#include "computadora.h"

using namespace std;

Computadora::Computadora(){}

Computadora::Computadora(const string& nombreEquipo, const string& sistemaOperativo, const string& procesador, unsigned int ram){
    this->sistemaOperativo = sistemaOperativo;
    this->nombreEquipo = nombreEquipo;
    this->procesador = procesador;
    this->ram = ram;
}

void Computadora::setNombreEquipo(const string& v){
    this->nombreEquipo = v;
}
void Computadora::setSistemaOperativo(const string& v){
    this->sistemaOperativo = v;
}
void Computadora::setProcesador(const string& v){
    this->procesador = v;
}
void Computadora::setRam(unsigned int v){
    this->ram = v;
}

string Computadora::getNombreEquipo(){
    return this->nombreEquipo;
}
string Computadora::getSistemaOperativo(){
    return this->sistemaOperativo;
}
string Computadora::getProcesador(){
    return this->procesador;
}
unsigned int Computadora::getRam(){
    return this->ram;
}

Computadora::~Computadora(){}