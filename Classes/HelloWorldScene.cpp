/**
Made by Samvid
**/

#include "HelloWorldScene.h"
#include "Location_Node_Class.h"
#include "Node_Class.h"
#include <iostream>
#include "cocos2d.h"
#include <queue>
#include <math.h>
#include <string>
#include "queue"

int i=0;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	*/

	label = Label::createWithTTF("Path not found", "fonts/Marker Felt.ttf", 24);
	this->addChild(label, 2);
	label->setVisible(false);


	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	auto listner = EventListenerTouchOneByOne::create();


	listner->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
	listner->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
	listner->setSwallowTouches(true);

	background=Sprite::create("Grid.png");
	background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(background,0);


	checker = true;
	obstacle_selector=true;

	noder = Node_Class::create();
	noder->empty_square_array();

	//noder->squares[4][2] = 1;
	//noder->squares[4][3] = 1;
	//noder->squares[4][4] = 1;
	//noder->squares[4][4] = 1;
	//noder->squares[3][6] = 1;
	//noder->squares[1][4] = 1;
	//noder->squares[6][5] = 1;

	//int z=0;
	//

	//#define NUMOBSTACLES 3
	//obstacle = new Vector<Sprite*>(NUMOBSTACLES);
	//
	//for(int j = 0; j < JDIM; j++) {
 //       for(int i = 0; i < IDIM; i++)
	//	{
	//		if(noder->squares[i][j]==1)
	//		{
	//			Sprite *Obstacle_image = Sprite::create("My_Obstacle.png");
	//			//vecObstacle->pushBack(obstacle);
	//			Obstacle_image->setPosition(Vec2((i*100)-50,(j*100)-50));
	//			this->addChild(Obstacle_image,1);
	//			obstacle->pushBack(Obstacle_image);
	//			z++;
	//		}
	//	}
	//}
	//
	/*
	box=Sprite::create("My_box.png");

	int iStart = 5,jStart = 1;
	box=Sprite::create("My_box.png");
	box->setPosition(Vec2((iStart*100)-50,(jStart*100)-50));
	this->addChild(box,1);

	int iEnd = 4 ,jEnd = 3;
	path1 = noder->pathFind(Location_Node_Class(iStart, jStart), Location_Node_Class(iEnd, jEnd));

	char * path = new char [path1.length() + 1];
	strcpy(path,path1.c_str());

	int j = strtol(path1.c_str(),NULL,10);
	//CCLOG("The value is %d",j);
	////CCLOG("You are here");
	// map of directions (0: East, 1: North, 2: West, 3: South)
	//CCLOG("Path = %s",path1.c_str());

	#define NUMOFACTIONS 20
	actions = new Vector<FiniteTimeAction*>(NUMOFACTIONS);

	auto action0 = MoveBy::create(1,Vec2(100,0));
	auto action1 = MoveBy::create(1,Vec2(0,100));
	auto action2 = MoveBy::create(1,Vec2(-100,0));
	auto action3 = MoveBy::create(1,Vec2(0,-100));



	for(int i=0;i<=path1.length();i++)
	{
		////CCLOG("This is outside the if part, %c",path[i]);
		if(path[i] == '0' )
		{
			////CCLOG("You are here 0 ");
			actions->pushBack(action0);

		}
		else if(path[i] == '1' )
		{
			////CCLOG("You are here 1");
			actions->pushBack(action1);

		}
		else if(path[i] == '2' )
		{
			////CCLOG("You are here 2");
			actions->pushBack(action2);

		}
		else if(path[i] == '3' )
		{
			////CCLOG("You are here 3");
			actions->pushBack(action3);

			//auto action3 = MoveBy::create(1,Vec2(0,-100));
			//box->runAction(action3);

		}
	}


	const Vector<FiniteTimeAction*> xyz = *actions;
	auto sequence = Sequence::create(xyz);
	box->runAction(sequence);
	*/
    return true;
}


bool HelloWorld::onTouchBegan(cocos2d::Touch *stouch,cocos2d::Event *sevent)
{
	if(obstacle_selector==true)
	{
		location_obstacle = stouch->getLocation();
		i3 = (location_obstacle.x/100) + 1;
		j3 = (location_obstacle.y/100) + 1;
		if(noder->squares[i3][j3]==0)
		{
			createobstacleImage(i3,j3);
			noder->squares[i3][j3] = 1;
			//CCLOG("sqares %d %d ",i3,j3);
		}
		else
		{
			obstacle_selector=false;
			//CCLOG("You are coming here");
		}
	}
	else
	{
	i++;
	//CCLOG("Value of checker is %d",checker);
	if(i==1)
	{
		location_start = stouch->getLocation();
		//CCLOG("%f and %f",location_start.x,location_start.y);
		i1= (location_start.x/100) + 1;
		j1= (location_start.y/100) + 1;
		//CCLOG("This is istart = %d and jstart = %d ",i1,j1);
		createstartImage(i1,j1);
	}
	if(i==2)
	{
		location_end = stouch->getLocation();
		i2= (location_end.x/100) + 1;
		j2= (location_end.y/100) + 1;
		CCLOG("This is istrat = %d and jstart = %d and iend = %d and jend = %d ",i1,j1,i2,j2);
		if(checker == true)
		{
			//CCLOG("Outside the visible checking part");
			if(label->isVisible())
			{
				CCLOG("It is visible");
				label->setVisible(false);
			}
			checker=workingallaone(i1,j1,i2,j2);
			//CCLOG("Value of checker is %d inside the while",checker);
		}
		//CCLOG("Value of checker is %d outside the while",checker);
		////CCLOG("This is istrat = %d and jstart = %d and iend = %d and jend = %d ",i1,j1,i2,j2);
		/*i1=i2;
		j1=j2;*/
	}
	if(i >= 3)
	{
		location_end = stouch->getLocation();
		i2= (location_end.x/100) + 1;
		j2= (location_end.y/100) + 1;
		//CCLOG("This is istrat = %d and jstart = %d and iend = %d and jend = %d ",i1,j1,i2,j2);
		if(checker == true)
		{

			if(label->isVisible())
			{
				CCLOG("It is visible");
				label->setVisible(false);
			}
			checker=workingallaone(i1,j1,i2,j2);
			//CCLOG("Value of checker is %d inside the while",checker);
		}

		//CCLOG("Value of checker is %d outside the while",checker);
		/*i1=i2;
		j1=j2;*/
	}
	}

	return true;
}

void HelloWorld::createstartImage(int istart,int jstart)
{
	box=Sprite::create("My_box.png");
	box->setPosition(Vec2((istart*100)-50,(jstart*100)-50));
	this->addChild(box,1);
}

void HelloWorld::createobstacleImage(int i3,int j3)
{
	obstacle1=Sprite::create("My_Obstacle.png");
	obstacle1->setPosition(Vec2((i3*100)-50,(j3*100)-50));
	this->addChild(obstacle1,1);
}

void HelloWorld::onTouchEnded(cocos2d::Touch *stouch,cocos2d::Event *sevent)
{
	this->setSwallowsTouches(false);
}


bool HelloWorld::workingallaone(int istart,int jstart,int iend,int jend)
{


	path1 = noder->pathFind(Location_Node_Class(istart, jstart), Location_Node_Class(iend, jend));

	char * path = new char [path1.length() + 1];
	strcpy(path,path1.c_str());

	int j = strtol(path1.c_str(),NULL,10);
	////CCLOG("The value is %d",j);
	////CCLOG("You are here");
	// map of directions (0: East, 1: North, 2: West, 3: South)
	////CCLOG("Path = %s",path1.c_str());

	#define NUMOFACTIONS 20
	actions = new Vector<FiniteTimeAction*>(NUMOFACTIONS);

	auto action0 = MoveBy::create(0.5,Vec2(100,0));
	auto action1 = MoveBy::create(0.5,Vec2(0,100));
	auto action2 = MoveBy::create(0.5,Vec2(-100,0));
	auto action3 = MoveBy::create(0.5,Vec2(0,-100));
	auto callback = CallFunc::create( this, callfunc_selector(HelloWorld::something) );

	if(path1 == "")
	{
		////CCLOG("No path found block");
		//label->setOpacity(255);
		label->setVisible(true);
		label->setColor(ccc3(255,255,0));
		label->setPosition(Vec2(400,300));

		i1=istart;
		j1=jstart;
		return true;
	}
	else
	{
	for(int i=0;i<=path1.length();i++)
	{
		////CCLOG("This is outside the if part, %c",path[i]);
		if(path[i] == '0' )
		{
			////CCLOG("You are here 0 ");
			actions->pushBack(action0);

		}
		else if(path[i] == '1' )
		{
			////CCLOG("You are here 1");
			actions->pushBack(action1);

		}
		else if(path[i] == '2' )
		{
			////CCLOG("You are here 2");
			actions->pushBack(action2);

		}
		else if(path[i] == '3' )
		{
			////CCLOG("You are here 3");
			actions->pushBack(action3);

		}
	}
	////CCLOG("This is istrat = %d and jstart = %d and iend = %d and jend = %d inside workingallalonefunction",i1,j1,i2,j2);
	actions->pushBack(callback);
	const Vector<FiniteTimeAction*> xyz = *actions;
	auto sequence = Sequence::create(xyz);
	box->runAction(sequence);
	i1=iend;
	j1=jend;

	}
	return false;
}

void HelloWorld::something(void)
{
	checker = true;
	////CCLOG("You are coming here & This is istrat = %d and jstart = %d and iend = %d and jend = %d ",i1,j1,i2,j2);
	/*i1=i2;
	j1=j2;
	////CCLOG("You are coming here & This is istrat = %d and jstart = %d ",i1,j1);*/
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
