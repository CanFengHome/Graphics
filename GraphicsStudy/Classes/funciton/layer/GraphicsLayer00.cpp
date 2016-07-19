//
//  GraphicsLayer00.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#include "GraphicsLayer00.h"


bool GraphicsLayer00::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    m_pCanvas = g_createCanvas(this);
    GRAPHICS->setCanvas(m_pCanvas);
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pButton = g_createButton(this, "draw point", Vec2(30.0f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer00::btnTestCallback, this));
    pButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
    
    GRAPHICS->setPixelColor(Color4F::RED);
    
    return true;
}


void GraphicsLayer00::btnTestCallback(cocos2d::Ref* pSender)
{
    Vec2 randomPosition = g_randomPosition();
    GRAPHICS->clearAllGraphics();
    GRAPHICS->setPixel(randomPosition);
}

















