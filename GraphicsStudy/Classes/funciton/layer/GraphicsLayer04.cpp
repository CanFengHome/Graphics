//
//  GraphicsLayer04.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#include "GraphicsLayer04.h"



bool GraphicsLayer04::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    g_createButton(this, "draw ellipse Bresenham fix", Vec2(winSize.width*0.5f, winSize.height - 20.0f), CC_CALLBACK_1(GraphicsLayer04::btnTestCallbackFix, this));
    
    g_createButton(this, "draw ellipse Bresenham random", Vec2(winSize.width*0.5f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer04::btnTestCallbackRandom, this));
    
    GRAPHICS->setPixelColor(Color4F::RED);
    
    return true;
}

void GraphicsLayer04::btnTestCallbackFix(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 centerPt = winSize*0.5f;
    
    g_drawEllipse((int)centerPt.x, (int)centerPt.y, 100, 60);
}

void GraphicsLayer04::btnTestCallbackRandom(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    Size winSize = Director::getInstance()->getWinSize();
    float randomX = RandomHelper::random_real(-100.0f, 100.0f);
    float randomY = RandomHelper::random_real(-100.0f, 100.0f);
    
    Vec2 centerPt = winSize*0.5f;
    Vec2 randomPt = centerPt + Vec2(randomX, randomY);
    
    int randomA = RandomHelper::random_int(30, 100);
    int randomB = RandomHelper::random_int(40, 70);

    g_drawEllipse((int)randomPt.x, (int)randomPt.y, randomA, randomB);
}




































