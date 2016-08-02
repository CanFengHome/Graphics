//
//  GraphicsLayer10.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/8/2.
//
//

#include "GraphicsLayer10.h"

bool GraphicsLayer10::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pButton = g_createButton(this, "draw bezeir", Vec2(30.0f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer10::btnTestCallback, this));
    pButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
    
    GRAPHICS->setPixelColor(Color4F::RED);
    GRAPHICS->setLineColor(Color4F::BLUE);
    
    float midY = winSize.height*0.5f;
    m_pts[0] = Vec2(winSize.width*0.15f, midY-120.0f);
    m_pts[1] = Vec2(winSize.width*0.3f, midY+50.0f);
    m_pts[2] = Vec2(winSize.width*0.4f, midY-200.0f);
    m_pts[3] = Vec2(winSize.width*0.6f, midY+60.0f);
    m_pts[4] = Vec2(winSize.width*0.7f, midY-60.0f);
    
    return true;
}

void GraphicsLayer10::btnTestCallback(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    
    drawSpline();
    drawPoints();
}

void GraphicsLayer10::drawPoints()
{
    GRAPHICS->setPointSize(6.0f);
    for (int i=0; i<5; ++i)
    {
        GRAPHICS->setPixel(m_pts[i]);
    }
}

void GraphicsLayer10::drawSpline()
{
    int rate=10;//rate是平滑程度
    int prevLx = ROUND((m_pts[0].x + 4.0 * m_pts[1].x + m_pts[2].x) / 6.0);//t＝0的起点x坐标
    int prevLy = ROUND((m_pts[0].y + 4.0 * m_pts[1].y + m_pts[2].y) / 6.0);//t＝0的起点y坐标
    int currLx = 0;
    int currLy = 0;
    
    Vec2 arrLinePts[2];
    
    float F03, F13, F23, F33;
    for(int i=1; i<3; ++i) // 2段样条曲线
    {
        for(float t=0; t <= 1.0f; t+=1.0f/rate)
        {
            F03=(-t*t*t+3*t*t-3*t+1)/6; // 计算F0,3(t)
            F13=(3*t*t*t-6*t*t+4)/6; // 计算F1,3(t)
            F23=(-3*t*t*t+3*t*t+3*t+1)/6; // 计算F2,3(t)
            F33=t*t*t/6; // 计算B3,3(t)
            
            currLx = ROUND(m_pts[i-1].x * F03 + m_pts[i].x * F13 + m_pts[i+1].x * F23 + m_pts[i+2].x * F33);
            currLy = ROUND(m_pts[i-1].y * F03 + m_pts[i].y * F13 + m_pts[i+1].y * F23 + m_pts[i+2].y * F33);
            
            arrLinePts[0] = Vec2(prevLx, prevLy);
            arrLinePts[1] = Vec2(currLx, currLy);
            
            GRAPHICS->drawPolyline(arrLinePts, 2);
            
            prevLx = currLx;
            prevLy = currLy;
        }
    }
}





















