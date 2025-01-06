#include "../inc/Biblioteca.h"

Biblioteca :: Biblioteca(){
    set<Informacion*> infos;
    this->InformacionesGuardadas = infos;
}

set<Informacion*> Biblioteca:: getInformacionesGuardadas(){
    return this->InformacionesGuardadas;
}


void Biblioteca :: insertarInformacion(Informacion *Informacion){
    this->InformacionesGuardadas.insert(Informacion);
}

void Biblioteca::eliminarInformacion(int id) {
    for (auto it = InformacionesGuardadas.begin(); it != InformacionesGuardadas.end(); it++) {
        if ((*it)->getIdentificador() == id){ 
            vector<int> C_I;
            for (auto e : (*it)->getInformacionGuardadaPor()) {
                C_I.push_back(e->getCi()); 
                e->eliminarLinkInformacion(id); 
            }

            (*it)->getInformacionGuardadaPor().clear();
            
            InformacionesGuardadas.erase(it);
            break;
        }
    }
}

vector<DTInfoEstudiante> Biblioteca :: buscarTermino(string clave){
    vector<DTInfoEstudiante> estudiantesConTermino;
    vector<Informacion*>aux;

    for (const auto& info : InformacionesGuardadas) {
        string infoString = info->toString();
        if (infoString.find(clave) != string::npos) {
                aux.push_back(info);
        }
    }

    for (const auto& info : aux) {
        vector<Estudiante*> est = info->getInformacionGuardadaPor();
        for (const auto& e : est) {
            DTInfoEstudiante estu = DTInfoEstudiante(e->getCi(), info->getIdentificador(), e->getNombre());
            estudiantesConTermino.push_back(estu);
        }
    }    

    return estudiantesConTermino;
}

Biblioteca :: ~Biblioteca(){

}
