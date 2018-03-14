#include"SerialPort.h"

int main(int argc, char *argv[])
{
	const static int kControlPeriod = 1000;
	SerialPort aSerialPort("COM4", 115200);
	if (aSerialPort.setPort() == false) {
		return -1;
	}

	std::vector<Servo*> pServo;
	pServo.push_back(new Servo(0, 7500, 0));
	pServo.push_back(new Servo(1, 7500, 0));

	for (int i = 1; i < 3; ++i) {
		boost::posix_time::ptime aBeginTime = boost::posix_time::microsec_clock::local_time();

		short aTargetPos = 7000;
		aTargetPos += i * 500;

		for (auto itr : pServo) {
			itr->setTargetPos(aTargetPos);
			aSerialPort.setAngle(*itr);
		}

		boost::posix_time::ptime aEndTime = boost::posix_time::microsec_clock::local_time();
		boost::posix_time::time_duration aDiffTime = aEndTime - aBeginTime;

		//擬似的に一定周期でサーボに指令を送信するためにwait
		boost::this_thread::sleep(boost::posix_time::milliseconds(kControlPeriod - aDiffTime.total_milliseconds() ));
	}

	return 0;
}