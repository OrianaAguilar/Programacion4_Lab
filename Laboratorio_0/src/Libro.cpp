#include "../inc/Libro.h"

Libro::Libro(int id, const DTFecha& fecha, string titulo, set<string>& autores, string resumen):Informacion(id, fecha){
	this->titulo = titulo;
	this->autores = autores;
	this->resumen = resumen;
}

string Libro::getTitulo(){
	return this->titulo;
}


set<string> Libro::getAutores(){
	return this->autores;
}

string Libro::getResumen(){
	return this->resumen;
}

string Libro::toString(){
	string autoresStr;
        for (const string& autor : autores) {
            autoresStr += autor + ", ";
        }
        autoresStr.pop_back();
        autoresStr.pop_back();

	return "Libro: " + to_string(getIdentificador()) + "," + getFecha().toString() + "," + this->titulo + "," + autoresStr + "," + this->resumen;
}

Libro :: ~Libro(){
	
}