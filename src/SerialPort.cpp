#include "SerialPort.h"

void SerialPort::setPort() {
	port.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
	port.set_option(boost::asio::serial_port_base::character_size(8));
	port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
	port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::even));
	port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
}


bool SerialPort::setAngle(Servo aServo) {

	unsigned char tx[3];
	unsigned char rx[6];

	tx[0] = (unsigned char)(0x80 | aServo.mId);
	tx[1] = (unsigned char)((aServo.mTargetPos >> 7) & 0x7F);
	tx[2] = (unsigned char)(aServo.mTargetPos & 0x7F);

	port.write_some(boost::asio::buffer(tx));
	port.read_some(boost::asio::buffer(rx));

	for (int i = 0; i < 5; i++)
	{
		aServo.mTargetPos = (aServo.mTargetPos == 7000 ? 8000 : 7000);
		tx[1] = (unsigned char)((aServo.mTargetPos >> 7) & 0x7F);
		tx[2] = (unsigned char)(aServo.mTargetPos & 0x7F);

		port.write_some(boost::asio::buffer(tx));
		port.read_some(boost::asio::buffer(rx));

		for (int i = 0; i < 6; ++i) {
			std::cout << "rx" << i << ":" << (int)rx[i] << std::endl;
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

	}

	return true;
}