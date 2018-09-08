#ifndef COMODO
#define COMODO

#include <string>
#include <stdint.h>

using namespace std;

typedef struct comod_
{
	uint16_t codigo;
	std::string nome;
	uint16_t tipo;
	bool externo;
}Comodo;

#endif