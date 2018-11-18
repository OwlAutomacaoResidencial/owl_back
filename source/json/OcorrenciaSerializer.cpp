#include "headers/json/serializer/OcorrenciaSerializer.h"
#include "headers/logging/Logger.h"

OcorrenciaSerializer* OcorrenciaSerializer::m_This = NULL;

OcorrenciaSerializer* OcorrenciaSerializer::getSerializer()
{
	if(m_This == NULL)
		m_This = new OcorrenciaSerializer();
		
	return m_This;
}

void OcorrenciaSerializer::serializeOcorrencia(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, Ocorrencia* ocorr)
{
	if(ocorr == 0x00 || ocorr == NULL)
		return;
	
	writer->StartObject();
	writer->Key("idOcorrencia");
	writer->Uint(ocorr->codigo);
	writer->Key("sensor");
	writer->String(ocorr->sensor.c_str());
	writer->Key("comodo");
	writer->String(ocorr->comodo.c_str());
	writer->Key("dataHora");
	writer->String(ocorr->dataHora.c_str());
	writer->Key("observacao");
	writer->String("");
	
	writer->EndObject();
}

void OcorrenciaSerializer::serializeOcorrenciaList(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, std::vector<Ocorrencia*> ocorrs)
{
	writer->StartArray();
	
	for(auto const& value: ocorrs) 
		serializeOcorrencia(writer, (Ocorrencia*) value);

	writer->EndArray();
}