#include<vector>

#ifndef _SERVO_H_
#define _SERVO_H_

class Servo {
private:
	short mId;
	short mTargetPos;
	short mRecvPos;

public:
	Servo();
	Servo(short cId, short cTargetPos, short cRecvPos);
	~Servo();
	void convertingForServoWriting(unsigned char (&cTx)[3]);
	void setTargetPos(short cTargetPos);
};

#endif
/*_SERVO_H_*/