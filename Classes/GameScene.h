#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
USING_NS_CC;
#include "Player.h"

class GameScene :public Layer
{
public:

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

	virtual void update(float delta);
private:
	void initBG();
	void loadUI();
private:
	Sprite* m_bgSprite1;
	Sprite* m_bgSprite2;

	Player* m_player;

};


#endif