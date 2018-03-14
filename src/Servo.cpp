#include"Servo.h"

Servo::Servo() 
{

}

Servo::Servo(short cId, short cTargetPos, short cRecvPos) : mId(cId), mTargetPos(cTargetPos), mRecvPos(cRecvPos)
{

}

Servo::~Servo()
{

}

void Servo::convertingForServoWriting(unsigned char(&cTx)[3])
{
	cTx[0] = (unsigned char)(0x80 | mId);
	cTx[1] = (unsigned char)((mTargetPos >> 7) & 0x7F);
	cTx[2] = (unsigned char)(mTargetPos & 0x7F);
}

void Servo::setTargetPos(short cTargetPos) {
	this->mTargetPos = cTargetPos;
}