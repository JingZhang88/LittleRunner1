#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

class Player : public Entity {
public:
	Player();
	~Player();
	CREATE_FUNC(Player);
	virtual bool init();
public:
	void jump();	//��Ծ����
	void hit();     //������˺�
	int getiHP();
private:
	void resetData();
	bool m_isJumping;	//��������Ƿ�������Ծ
	int m_iHP;          //����Ѫ��
};

#endif

//test test