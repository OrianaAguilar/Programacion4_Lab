#ifndef ISUSCRIPTOR_H
#define ISUSCRIPTOR_H

#include <set>
#include "DTNotificacion.h"

class iSuscriptor{
    public:
        virtual void notificar(DTNotificacion notificacion) = 0;
        virtual string getNicknameSuscriptor() = 0;
};

#endif // ISUSCRIPTOR_H
