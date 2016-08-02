//
//  GraphicsLayer09.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/8/2.
//
//

#include "GraphicsLayer09.h"

bool GraphicsLayer09::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pButton = g_createButton(this, "draw bezeir", Vec2(30.0f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer09::btnTestCallback, this));
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

void GraphicsLayer09::btnTestCallback(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    GRAPHICS->setPixelColor(Color4F::RED);
    
    drawSpline();
    drawPoints();
}

void GraphicsLayer09::drawPoints()
{
    GRAPHICS->setPixelColor(Color4F::BLUE);
    GRAPHICS->setPointSize(6.0f);
    for (int i=0; i<5; ++i)
    {
        GRAPHICS->setPixel(m_pts[i]);
    }
}

int Factorial(int m)//阶乘函数
{
    int f=1;
    for(int i=1;i<=m;i++)
        f*=i;
    return f;
}

// Bernstein第一项
double Cnk(const int &n, const int &i)
{
    return double(Factorial(n)/(Factorial(i)*Factorial(n-i)));
}

void GraphicsLayer09::drawSpline()
{
    int rate = 800;
    int n = 4;
    for(float t=0; t <= 1; t += 1.0f/rate)
    {
        float x=0;
        float y=0;
        for(int i=0;i <= n; ++i)
        {
            // Cnk是二项式系数，其值为 n! / ( i! * ( n - i )! )
            x += m_pts[i].x * Cnk(n,i) * pow(t,i) * pow(1-t, n-i);
            y += m_pts[i].y * Cnk(n,i) * pow(t,i) * pow(1-t, n-i);
        }
        GRAPHICS->setPixel(ROUND(x),ROUND(y));
    }
}





















