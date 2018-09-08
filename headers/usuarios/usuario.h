#ifndef USUARIO
#define USUARIO

#include <string>

typedef struct usr
{
	int codigo;
	std::string login;
	std::string senha;
	std::string perfil;
	std::string nome;
	std::string cpf;
	std::string rg;
	std::string dataNascimento;
	std::string email;
}Usuario;

#endif