//
//  GameLayer.cpp
//  HOTS
//
//  Created by Tin on 6/14/16.
//
//

#include <stdio.h>
#include "GameLayer.h"
#include "HelloWorldScene.h"

GameLayer::GameLayer()
{
    array = NULL;
}

GameLayer::~GameLayer()
{
    array->release();
}

bool GameLayer::init()
{
    if (Layer::init()) {
        
        array = __Array::create();
        array->retain();
        
        __Dictionary* tempDict = __Dictionary::createWithContentsOfFile("myplist.plist");
        tempDict->objectForKey("maxVelocity");


        
        // TODO: read plist
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size screenSize = Director::getInstance()->getVisibleSize();
        
        // Label.
        Label* label = Label::createWithTTF("Hello world!", "fonts/Marker Felt.ttf", 13);
        label->setPosition(Vec2(origin.x + screenSize.width/2, origin.y + screenSize.height / 2));
//        label->setAnchorPoint(Vec2(1,1));
        label->setColor(Color3B::WHITE);
        this->addChild(label, 1);
        
        // Menu items.
        MenuItemImage* button = MenuItemImage::create("test.jpg", "bc003_02.png", CC_CALLBACK_0(GameLayer::changeScene,this));
        button->setPosition(Vec2(0,0));
        
        // Menu.
        Menu* menu = Menu::create(button, NULL);
        menu->setPosition(Vec2(origin.x + screenSize.width/2, origin.y + screenSize.height / 2));
        this->addChild(menu);
        
        tempDict->setObject(label, "hello_world_label");
        
        array->addObject(label);
        
        
        
        
        
        
        
        
        
        
        
        
        
        Label *templabel = (Label*)tempDict->objectForKey("hello_world_label");
        
        return true;
    }
    
    return false;
}

void GameLayer::changeScene()
{
    
    Label* label = (Label*)array->getObjectAtIndex(0);
    
    
    auto scene = Scene::create();
    scene->addChild(HelloWorld::create());
    Director::getInstance()->replaceScene(scene);
}

/*
 
 0. Object hierarchy
 1. create and init
 2. anchor point and position
  6. z order
 3. retain/release
 4. Resources by reference
 5. Naming convention

 
 */