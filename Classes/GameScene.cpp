#include "GameScene.h"
#include "cocos2d.h"
using namespace cocos2d;
#include "cocos2d\cocos\ui\CocosGUI.h"
#include "cocos2d\cocos\editor-support\cocostudio\CCSGUIReader.h"
using namespace cocos2d::ui;
using namespace cocostudio;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}
bool GameScene::init()
{
	

	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = CCDirector::getInstance()->getVisibleSize();

	/* 游戏标题图片 */
	Sprite* titleSprite = CCSprite::create("title.png");
	titleSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height - 50));
	this->addChild(titleSprite, 2);

	/* 创建主角 */
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("sprite.png"));
	m_player->setPosition(Point(200, visibleSize.height / 8));
	this->addChild(m_player, 3);

	/* 初始化背景图片 */
	initBG();
	loadUI();
	this->scheduleUpdate();
	this->schedule();
	return true;
}
void GameScene::initBG()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	m_bgSprite1 = Sprite::create("gameBG.jpg");
	m_bgSprite2 = Sprite::create("gameBG.jpg");

	m_bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2->setPosition(Point(visibleSize.width+visibleSize.width / 2, visibleSize.height / 2));
	m_bgSprite2->setFlippedX(true);
	this->addChild(m_bgSprite2, 0);

}
void GameScene::update(float delta)
{
	int pos1 = m_bgSprite1->getPositionX();
	int pos2 = m_bgSprite2->getPositionX();

	Size mapSize = m_bgSprite1->getContentSize();

	if (pos1 < -mapSize.width / 2)
	{
		pos1 = mapSize.width+mapSize.width / 2;
	}
	if (pos2 < -mapSize.width / 2)
	{
		pos2 = mapSize.width+mapSize.width / 2;
	}
	int speed = 1;

	pos1 -= speed;
	pos2 -= speed;

	m_bgSprite1->setPositionX(pos1);
	m_bgSprite2->setPositionX(pos2);

}
void GameScene::loadUI()
{
	auto ui = GUIReader::getInstance()->widgetFromJsonFile("LitterRunnerUI_1.ExportJson");
	this->addChild(ui);
	Button* jumpBtn = (Button*)Helper::seekWidgetByName(ui, "JumpBtn");

	jumpBtn->addTouchEventListener([&](Ref* ref,Widget::TouchEventType type){
		switch(type)
		{
		case Widget::TouchEventType::ENDED:
			m_player->jump();

			break;
		}

	});

	//jumpBtn->addTouchEventListener(jumpAction);
}
