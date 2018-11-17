#ifndef JWT_VALIDATOR
#define JWT_VALIDATOR

#include "jwt/jwt.hpp"

#define JWT_SECRET "zanão@mamador@de@rola"

auto generateToken(MWebSession* session)
{
	using namespace jwt::params;
  
	//Create JWT object
	jwt::jwt_object obj{algorithm("HS256"), payload({{"user", session->usuario->email}}), secret(JWT_SECRET)};

	obj.add_claim("iss", "owl.webrouter")
		   .add_claim("sub", "OWL_APP_LOGIN")
		   .add_claim("iat", std::chrono::system_clock::now())
		   .add_claim("exp", std::chrono::system_clock::now() + std::chrono::minutes{15});

	//Get the encoded string/assertion
	return obj.signature();
}

bool tokenExpired(MWebSession* session)
{
	using namespace jwt::params;
		
	std::error_code ec;
	
	auto dec_obj = jwt::decode(session->token, algorithms({"hs256"}), ec, secret(JWT_SECRET), verify(true));
	
	return (ec.value() == static_cast<int>(jwt::VerificationErrc::TokenExpired));
}

#endif