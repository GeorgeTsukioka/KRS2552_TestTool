#include "SerialPort.h"

bool SerialPort::setPort() {
	try {
		mPort = new boost::asio::serial_port(mIO, mPortID);
		mPort->set_option(boost::asio::serial_port_base::baud_rate(mBaudRate));
		mPort->set_option(boost::asio::serial_port_base::character_size(8));
		mPort->set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
		mPort->set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::even));
		mPort->set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
		std::cout << "ƒ|[ƒg‚ÌÚ‘±‚ðŠ®—¹‚µ‚Ü‚µ‚½" << std::endl;
		return true;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
}


bool SerialPort::setAngle(Servo aServo) {

	unsigned char aTx[3];
	unsigned char aRx[6];

	aServo.convertingForServoWriting(aTx);

	mPort->write_some(boost::asio::buffer(aTx));
	mPort->read_some(boost::asio::buffer(aRx));

#if DEBUG
	for (int i = 0; i < 6; ++i) {
		std::cout << "rx" << i << ":" << (int)aRx[i] << std::endl;
	}

	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
#endif

	return true;
}