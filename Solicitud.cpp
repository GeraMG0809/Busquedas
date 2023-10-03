#include"Solicitud.h"


void Solicitud::setNombre(std::string nom){Nombre= nom;}

void Solicitud::setCarrera(std::string carr){Carrera = carr;}

void Solicitud::setMaterias(int mat){Materias = mat;}

void Solicitud::setPromedio(float prom){Promedio = prom;}

std::string Solicitud::getNombre(){return Nombre;}

std::string Solicitud::getCarrera(){return Carrera;}

int Solicitud::getMaterias(){return Materias;}

float Solicitud::getPromedio(){return Promedio;}

Solicitud::Solicitud(){}
 
Solicitud::Solicitud(std::string nom,std::string carr,int mat,float prom){
    Nombre = nom;
    Carrera = carr;
    Materias = mat;
    Promedio = Promedio;
}

bool Solicitud::operator==(const Solicitud& other)const{
    return Nombre == other.Nombre;
}