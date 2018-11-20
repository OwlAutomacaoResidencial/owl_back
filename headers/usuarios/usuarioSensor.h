#ifndef USUARIO_SENSOR
#define USUARIO_SENSOR

#include <string>
#include <stdint.h>

using namespace std;

typedef struct user_sensor_
{
	uint16_t codigo_usuario;
	uint16_t codigo_sensor;
}UsuarioSensor;

#endif