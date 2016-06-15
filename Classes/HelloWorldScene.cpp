#include "HelloWorldScene.h"

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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    
    auto label2 = Label::createWithTTF("mmmmmmmmm", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
   // label2->setPosition(Vec2(origin.x + visibleSize.width/2,
            //                origin.y + visibleSize.height - label2->getContentSize().height));
    
    // add the label as a child to this layer
    //this->addChild(label2, 1);
    auto add_label = MenuItemLabel::create(label2, CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    auto menu2 = Menu::create();
    menu2->addChild(add_label);
    menu2->setPosition(Vec2(origin.x , origin.y ));
    this->addChild(menu2,10);
    
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
    
    auto label = Label::createWithTTF("Hello Label1", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("free-wallpaper-backgrounds-20.jpg");

    auto sprite2 = Sprite::create("bc003_02.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite2->setPosition(Vec2(visibleSize.width/4 + origin.x, visibleSize.height/4 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    this->addChild(sprite2, 0);
    
    
    
    auto layer1 = LayerGradient::create(Color4B(255, 0, 0, 255), Color4B(255, 0, 255, 255));
    layer1->setContentSize(Size(80, 80));
    layer1->setPosition(Vec2(50, 50));
    addChild(layer1);
    
    auto layer2 = LayerGradient::create(Color4B(0, 0, 0, 127), Color4B(255, 255, 255, 127));
    layer2->setContentSize(Size(80, 80));
    layer2->setPosition(Vec2(100,90));
    addChild(layer2);
    
    auto layer3 = LayerGradient::create();
    layer3->setContentSize(Size(80, 80));
    layer3->setPosition(Vec2(150,140));
    layer3->setStartColor(Color3B(255, 0, 0));
    layer3->setEndColor(Color3B(255, 0, 255));
    layer3->setStartOpacity(255);
    layer3->setEndOpacity(255);
    BlendFunc blend;
    blend.src = GL_SRC_ALPHA;
    blend.dst = GL_ONE_MINUS_SRC_ALPHA;
    layer3->setBlendFunc(blend);
    addChild(layer3);
    
    
        return true;
}




void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
