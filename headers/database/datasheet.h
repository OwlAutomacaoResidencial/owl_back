#ifndef DATA_SHEET_
#define DATA_SHEET_

#include <stdlib.h>
#include <stdint.h>

class DATA_SHEET
{
public:
	static DATA_SHEET* GetDataSheet();
	
	uint8_t usolo;
	uint8_t temp;
	uint8_t humidity;
	uint8_t luminosity;
	bool mq2_presence;
	bool mq6_presence;
private:
	static DATA_SHEET* m_This;
};

#endif 