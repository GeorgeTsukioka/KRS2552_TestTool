#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "Servo.h"

#ifndef _SERIAL_PORT_H_
#define _SERIAL_PORT_H_

class SerialPort
{
private:
	boost::asio::io_service mIO;
	std::string mPortID;
	int mBaudRate;
	boost::asio::serial_port* mPort;

public:
	SerialPort(std::string cPort, int cBaudRate) : mPortID(cPort), mBaudRate(cBaudRate) {
	};
	~SerialPort(){};

	bool setPort();
	bool setAngle(Servo aServo);
};

#endif
/*_SERIAL_PORT_H_*/