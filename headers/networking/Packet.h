#pragma once
#ifndef S_PACKET
#define S_PACKET

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "CSClientConnectionInfo.h"

class Packet
{
public:
  enum { header_length = 4 };
  enum { max_body_length = 512 };

  Packet(CSClientConnectionInfo* info)
    : body_length_(0)
  {
	  memcpy(data_, &info->timestamp, sizeof(uint16_t));
	  memcpy(data_ + sizeof(uint16_t), &info->timestamp, sizeof(uint16_t));
  }

  const char* data() const
  {
    return data_;
  }

  char* data()
  {
    return data_;
  }

  std::size_t length() const
  {
    return header_length + body_length_;
  }

  const char* body() const
  {
    return data_ + header_length;
  }

  char* body()
  {
    return data_ + header_length;
  }

  std::size_t body_length() const
  {
    return body_length_;
  }

  void body_length(std::size_t new_length)
  {
    body_length_ = new_length;
    if (body_length_ > max_body_length)
      body_length_ = max_body_length;
  }

private:
  char data_[header_length + max_body_length];
  std::size_t body_length_;
};



#endif