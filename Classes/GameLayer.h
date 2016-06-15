//
//  GameScene.h
//  HOTS
//
//  Created by Tin on 6/14/16.
//
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"

USING_NS_CC;

class GameLayer : public Layer
{
private:
    __Array* array;
    
public:
    GameLayer();
    ~GameLayer();
    
    CREATE_FUNC(GameLayer);
    
    virtual bool init() override;
    
    void changeScene();
};


#endif /* GameScene_h */
