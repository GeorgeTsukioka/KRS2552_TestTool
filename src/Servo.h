#include<vector>

class Servo {
//private:
public:
	short mId;
	short mTargetPos;
	short mRecvPos;

public:
	Servo() {};
	Servo(short cId, short cTargetPos, short cRecvPos) : mId(cId), mTargetPos(cTargetPos), mRecvPos(cRecvPos){}
	~Servo() {};
};