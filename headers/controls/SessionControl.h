#ifndef SESSION_CONTROL
#define SESSION_CONTROL

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class SessionControl
{
public:
	static SessionControl* GetControl();
	crow::response Login(const crow::request* request_, crow::response* response_);
private:
	static SessionControl* m_This;
};

#endif