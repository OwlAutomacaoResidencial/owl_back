#ifndef OCORRENCIA_SERIALIZER
#define OCORRENCIA_SERIALIZER

#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <cppconn/resultset.h>

#include "headers/ocorrencias/ocorrencia.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <vector>

class OcorrenciaSerializer
{
public:
	static OcorrenciaSerializer* getSerializer();
	void serializeOcorrencia(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, Ocorrencia* ocorr);
	void serializeOcorrenciaList(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, std::vector<Ocorrencia*> ocorrs);
private:
	static OcorrenciaSerializer* m_This;
};

#endif