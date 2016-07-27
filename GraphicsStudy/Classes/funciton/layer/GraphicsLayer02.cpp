//
//  GraphicsLayer02.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/26.
//
//

#include "GraphicsLayer02.h"

bool GraphicsLayer02::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    g_createButton(this, "draw Line Bresenham fix", Vec2(winSize.width*0.5f, winSize.height - 20.0f), CC_CALLBACK_1(GraphicsLayer02::btnTestCallbackFix, this));
    
    g_createButton(this, "draw Line Bresenham random", Vec2(winSize.width*0.5f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer02::btnTestCallbackRandom, this));
    
    GRAPHICS->setPixelColor(Color4F::RED);
    
    return true;
}

void GraphicsLayer02::btnTestCallbackFix(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 centerPt = Vec2::ZERO;//winSize*0.5f;
    Vec2 targetPt = centerPt + Vec2(100.0f, 100.0f);
    g_drawLineBresenham((int)centerPt.x, (int)centerPt.y, (int)targetPt.x, (int)targetPt.y);
}

void GraphicsLayer02::btnTestCallbackRandom(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    Size winSize = Director::getInstance()->getWinSize();
    float randomX = RandomHelper::random_real(-100.0f, 100.0f);
    float randomY = RandomHelper::random_real(-100.0f, 100.0f);
    
    Vec2 centerPt = winSize*0.5f;
    Vec2 randomPt = centerPt + Vec2(randomX, randomY);
    g_drawLineBresenham((int)centerPt.x, (int)centerPt.y, (int)randomPt.x, (int)randomPt.y);
}

