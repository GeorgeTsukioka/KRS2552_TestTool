#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "Servo.h"

class SerialPort
{
public:
	boost::asio::io_service io;
	const char *PORT;
	int baud_rate;
	boost::asio::serial_port port;

public:
	SerialPort(const char* cPort, int cbaud_rate) : PORT(cPort), port(io, PORT), baud_rate(cbaud_rate) {
		setPort();
	};
	~SerialPort(){};

	void setPort();
	bool setAngle(Servo aServo);
};

