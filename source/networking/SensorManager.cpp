#include "headers/sensores/SensorManager.h"
#include "headers/networking/ClientManager.h"

bool HandleNewAction(int codigoSensor, int action)
{
	shared_ptr<CSClient> client = ClientManager::GetManager()->GetClient(codigoSensor);
	
	if(client == NULL)
		return false;
	else
	{
		client->SendSimpleAction(action);	
		return true;
	}
}