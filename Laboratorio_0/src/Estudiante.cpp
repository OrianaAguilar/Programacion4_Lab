#include "../inc/Estudiante.h"

Estudiante::Estudiante(string nombre, int ci, string email){
	this->ci = ci;
	this->nombre = nombre;
	this->email = email;
}

Estudiante::~Estudiante(){

}
string Estudiante::getNombre(){
	return this->nombre;
}

void Estudiante::setNombre(string nombre){
	this->nombre = nombre;
}

int Estudiante::getCi(){
	return this->ci;
}

void Estudiante::setCi(int ci){
	this->ci = ci;
}

string Estudiante::getEmail(){
	return this->email;
}

void Estudiante::setEmail(string email){
	this->email = email;
}

string Estudiante::toString(){
	return "Nombre: " + nombre + ", CI: " + to_string(ci) + ", Email: " + email;
}

void Estudiante::guardarInformacion(Informacion *info){
	InformacionGuardada.push_back(info);
	info->guardadoPor(this);
}

void Estudiante::eliminarLinkInformacion(int id){
	for(auto it = InformacionGuardada.begin(); it != InformacionGuardada.end(); it++){
		if((*it)->getIdentificador() == id){
			InformacionGuardada.erase(it);
			break;
		}
}
}
set<string> Estudiante::listarInfo(DTFecha Desde){
	set<string> infoStrings;
    for (const auto& info : InformacionGuardada) {
		DTFecha fecha = info->getFecha();
         if ((fecha.anio > Desde.anio) || (fecha.anio == Desde.anio && fecha.mes > Desde.mes) ||
                (fecha.anio == Desde.anio && fecha.mes == Desde.mes && fecha.dia >= Desde.dia)) {
                infoStrings.insert(info->toString());
            }
        }
    return infoStrings;
}
