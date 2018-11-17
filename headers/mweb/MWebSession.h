#ifndef MWEBSESSION_H
#define MWEBSESSION_H

#include "headers/usuarios/usuario.h"

typedef struct mweb_session
{
	std::string token;
	Usuario* usuario;
}MWebSession;

#endif // MWEBSESSION_H
