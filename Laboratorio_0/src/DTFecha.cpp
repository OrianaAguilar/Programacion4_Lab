#include "../inc/DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

string DTFecha::toString(){
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}
