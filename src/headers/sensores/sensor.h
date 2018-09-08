#ifndef SENSOR
#define SENSOR

#include <stdlib.h>

typedef struct t_sensor
{
	uint16_t codigo;
	std::string descricao;
}TipoSensor;

typedef struct sensor
{
	uint16_t codigo;
	std::string nome;
	uint16_t codigoComodo;
	std::string ip;
	t_sensor* tipo;
	uint8_t index;
}Sensor;

#endif