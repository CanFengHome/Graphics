//
//  GraphicsLayer08.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/29.
//
//

#include "GraphicsLayer08.h"

const float dis = 100.0f;

bool GraphicsLayer08::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    g_createButton(this, "draw Line", Vec2(winSize.width*0.5f, winSize.height - 20.0f), CC_CALLBACK_1(GraphicsLayer08::btnDrawLineCallback, this));
    
    g_createButton(this, "draw clip Line", Vec2(winSize.width*0.5f, winSize.height - 50.0f), CC_CALLBACK_1(GraphicsLayer08::btnDrawClipLineCallback, this));
    
    GRAPHICS->setPixelColor(Color4F::RED);
    GRAPHICS->setLineColor(Color4F::BLUE);
    
    btnDrawLineCallback(nullptr);
    
    return true;
}

void GraphicsLayer08::initData()
{
    m_window[0] = Vec2(-dis, -dis);
    m_window[1] = Vec2(-dis, dis);
    m_window[2] = Vec2(dis, dis);
    m_window[3] = Vec2(dis, -dis);
    
    m_line[0] = Vec2(-dis*0.8f, -dis*1.7f);
    m_line[1] = Vec2(dis*0.4f, dis*1.4f);
}

void GraphicsLayer08::btnDrawLineCallback(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
 
    initData();
    Vec2 centerPoint = Director::getInstance()->getWinSize()*0.5f;
    GRAPHICS->drawPolygon(m_window, 4, centerPoint);
    GRAPHICS->drawPolygon(m_line, 2, centerPoint);
}

void GraphicsLayer08::btnDrawClipLineCallback(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    
    initData();
    Vec2 centerPoint = Director::getInstance()->getWinSize()*0.5f;
    GRAPHICS->drawPolygon(m_window, 4, centerPoint);
    drawClipLine();
    GRAPHICS->drawPolygon(m_line, 2, centerPoint);
}

// 端点编码函数
#define LEFT 1      //代表:0001
#define RIGHT 2     //代表:0010
#define BOTTOM 4    //代表:0100
#define TOP 8       //代表:1000
unsigned int GraphicsLayer08::endpointCode(float ptX, float ptY)
{
    // 顺序左右下上
    unsigned int rc = 0u;
    // 左
    if(ptX < -dis)
    {
        rc = rc | LEFT;
    }
    
    if(ptX > dis)
    {
        rc = rc | RIGHT;
    }
    
    if(ptY < -dis)
    {
        rc = rc | BOTTOM;
    }
    
    if(ptY > dis)
    {
        rc = rc | TOP;
    }
    
    return rc;
}

void GraphicsLayer08::drawClipLine()
{
    unsigned int rc0 = endpointCode(m_line[0].x, m_line[0].y);
    unsigned int rc1 = endpointCode(m_line[1].x, m_line[1].y);
    
    bool change = true;
    while (change)
    {
        change = false;
        if (0 == (rc0 | rc1)) // window内部
        {
            return;
        }
        else if ( 0 != (rc0 & rc1)) // 外部同一侧
        {
            return;
        }
        else
        {
            // 如果P0在窗口内，则交换P0和P1, 保证P0在窗口内部
            if (0 == rc0)
            {
                // 交换点的坐标值
                Vec2 tempPoint = m_line[0];
                m_line[0] = m_line[1];
                m_line[1] = tempPoint;
                // 交换点的编码值
                unsigned int tempCode = rc0;
                rc0 = rc1;
                rc1 = tempCode;
            }
            
            float x = 0.0f;
            float y = 0.0f;
            // 按左、右、下、上的顺序裁剪
            if(rc0 & LEFT ) // P0点位于窗口的左侧
            {
                //求交点y
                x = -dis;
                // y = y0+k*(x-x0);
                y = m_line[0].y + (m_line[1].y - m_line[0].y) * (x-m_line[0].x)/(m_line[1].x-m_line[0].x);
                m_line[0] = Vec2(x, y);
                change = true;
                rc0 = endpointCode(m_line[0].x, m_line[0].y);
                rc1 = endpointCode(m_line[1].x, m_line[1].y);
            }
            
            if(rc0 & RIGHT ) // P0点位于窗口的右侧
            {
                x = dis; // 求交点y
                y = m_line[0].y + (m_line[1].y - m_line[0].y) * (x-m_line[0].x)/(m_line[1].x-m_line[0].x);
                m_line[0] = Vec2(x, y);
                change = true;
                rc0 = endpointCode(m_line[0].x, m_line[0].y);
                rc1 = endpointCode(m_line[1].x, m_line[1].y);
            }
            
            if(rc0 & BOTTOM ) // P0点位于窗口的下侧
            {
                y = -dis; // 求交点x
                x = m_line[0].x + (m_line[1].x - m_line[0].x)*(y-m_line[0].y)/(m_line[1].y - m_line[0].y);
                m_line[0] = Vec2(x, y);
                change = true;
                rc0 = endpointCode(m_line[0].x, m_line[0].y);
                rc1 = endpointCode(m_line[1].x, m_line[1].y);
            }
            
            if(rc0 & TOP )// P0点位于窗口的上侧
            {
                y = dis; // 求交点x
                x = m_line[0].x + (m_line[1].x - m_line[0].x)*(y-m_line[0].y)/(m_line[1].y - m_line[0].y);
                m_line[0] = Vec2(x, y);
                change = true;
                rc0 = endpointCode(m_line[0].x, m_line[0].y);
                rc1 = endpointCode(m_line[1].x, m_line[1].y);
            }
        }
    }
}
























