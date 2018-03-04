#include"SerialPort.h"
#if 0
int main(int argc, char *argv[])
{
	SerialPort aSerialPort("COM4");

	short pos = 7500;
	unsigned char id, tx[3], rx[6];
	id = 1;

	tx[0] = (unsigned char)(0x80 | id);
	tx[1] = (unsigned char)((pos >> 7) & 0x7F);
	tx[2] = (unsigned char)(pos & 0x7F);

	aSerialPort.setAngle(id, *tx, *rx);

	return 0;
}

#elif 0
int main(int argc, char *argv[])
{
	boost::asio::io_service io;
	std::string PORT = "COM4";

	boost::asio::serial_port port(io, PORT);

	port.set_option(boost::asio::serial_port_base::baud_rate(115200));
	port.set_option(boost::asio::serial_port_base::character_size(8));
	port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
	port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::even));
	port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

	short pos = 7500;
	unsigned char id = 0;
	unsigned char tx[3];
	unsigned char rx[6];

	tx[0] = (unsigned char)(0x80 | id);
	tx[1] = (unsigned char)((pos >> 7) & 0x7F);
	tx[2] = (unsigned char)(pos & 0x7F);

	port.write_some(boost::asio::buffer(tx));
	port.read_some(boost::asio::buffer(rx));

	for (int i = 0; i < 5; i++)
	{
		pos = (pos == 7000 ? 8000 : 7000);
		tx[1] = (unsigned char)((pos >> 7) & 0x7F);
		tx[2] = (unsigned char)(pos & 0x7F);

		port.write_some(boost::asio::buffer(tx));
		port.read_some(boost::asio::buffer(rx));
		
		for (int i = 0; i < 6; ++i) {
			std::cout << "rx" << i << ":" << (int)rx[i] << std::endl;
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

	}
	return 0;
}

#else
int main(int argc, char *argv[])
{
	SerialPort aSerialPort("COM4", 115200);

	std::vector<Servo*> pServo;
	pServo.push_back(new Servo(0, 7500, 0));
	pServo.push_back(new Servo(1, 7500, 0));

	for (auto itr : pServo) {
		aSerialPort.setAngle(*itr);
	}

	/*
	Servo aServo1(0, 7500, 0);
	Servo aServo2(1, 7500, 0);

	aSerialPort.setAngle(aServo1);
	aSerialPort.setAngle(aServo2);
	*/

	return 0;
}
#endif