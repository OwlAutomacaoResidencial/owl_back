#pragma once
#ifndef SERVERPACKETS_H
#define SERVERPACKETS_H

#include "Packet.h"

#define WELCOME_PACKET							0x0001
#define SIMPLE_ACTION_PACKET					0x00C8
#define LIGHT_SWITCH_PACKET					0x000B
#define TEMP_HUMIDITY_REQUEST_PACKET	0x000C
#define LDR_REQUEST_PACKET					0x000D
#define MQ2_REQUEST_PACKET					0x000E
#define MQ6_REQUEST_PACKET					0x000F
#define USOLO_REQUEST_PACKET				0x0010

#define PING_PACKET 									0x00FE

namespace ServerPackets
{
	Packet* Welcome(Packet *packet)
	{
		const uint8_t* welcome_packet = new uint8_t[4] {WELCOME_PACKET, 0x04, 0x06, 0x08};
		packet->body_length(4);
		
		memcpy(packet->body(), welcome_packet, 4);
		
		return packet;
	}	
	
	Packet* Ping(Packet *packet)
	{
		const uint8_t* ping_packet = new uint8_t[2] {PING_PACKET, 0x00};
		packet->body_length(2);
		
		memcpy(packet->body(), ping_packet, 2);
		
		return packet;
	}
	
	Packet* SimpleAction(Packet *packet, uint8_t value)
	{
		const uint8_t* ping_packet = new uint8_t[2] {SIMPLE_ACTION_PACKET, value};
		packet->body_length(2);
		
		memcpy(packet->body(), ping_packet, 2);
		
		return packet;
	}
	
	Packet* LightSwitch(Packet *packet, uint8_t index)
	{
		const uint8_t packet_size = 0x0002;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {LIGHT_SWITCH_PACKET, index};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
	
	Packet* TempHumidityRequest(Packet *packet)
	{
		const uint8_t packet_size = 0x0001;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {TEMP_HUMIDITY_REQUEST_PACKET};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
	
	Packet* LdrRequest(Packet *packet)
	{
		const uint8_t packet_size = 0x0001;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {LDR_REQUEST_PACKET};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
	
	Packet* MQ2Request(Packet *packet)
	{
		const uint8_t packet_size = 0x0001;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {MQ2_REQUEST_PACKET};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
	
	Packet* MQ6Request(Packet *packet)
	{
		const uint8_t packet_size = 0x0001;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {MQ6_REQUEST_PACKET};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
	
	Packet* USoloRequest(Packet *packet)
	{
		const uint8_t packet_size = 0x0001;
		
		const uint8_t* lswitch_packet = new uint8_t[packet_size] {USOLO_REQUEST_PACKET};
		packet->body_length(packet_size);
		
		memcpy(packet->body(), lswitch_packet, packet_size);
		
		return packet;
	}
}

#endif