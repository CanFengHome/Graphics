//
//  GraphicsLayer07.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/28.
//
//

#include "GraphicsLayer07.h"


bool GraphicsLayer07::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    Size winSize = Director::getInstance()->getWinSize();
    
    int btnCount = 15;
    string btnTitle[] = {"left", "right", "up", "down",
        "rt+", "rt-",
        "s+", "s-",
        "x/", "y/", "O/",
        "skX+", "skX-", "skY+", "skY-"
    };
    float initX = 40.0f;
    float step = 100.0f;
    float initHeight = 50.0f;
    int stepIndex = 0;
    for (int i=0; i<btnCount; ++i, ++stepIndex)
    {
        if (i == 8)
        {
            stepIndex = 0;
            initHeight += 50.0f;
        }
        
        Button* pButton = g_createButton(this, btnTitle[i], Vec2(initX, winSize.height - initHeight), CC_CALLBACK_1(GraphicsLayer07::btnTestCallback, this));
        pButton->setPositionX(initX+stepIndex*step);
        pButton->setTag(i+1);
    }
    
    GRAPHICS->setPixelColor(Color4F::RED);
    GRAPHICS->setLineColor(Color4F::BLUE);
    
    btnTestCallback(nullptr);
    
    return true;
}

void GraphicsLayer07::resetPoints()
{
    float dis = 50.0f;
    m_graphicPoints[0] = Vec2(- dis, -dis*0.4f);
    m_graphicPoints[1] = Vec2(dis, m_graphicPoints[0].y);
    m_graphicPoints[2] = Vec2(0.0f, dis*0.6f);
    m_graphicPoints[3] = m_graphicPoints[0];
}

void GraphicsLayer07::btnTestCallback(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    static int selIndex = -1;
    
    Button* pBtn = dynamic_cast<Button*>(pSender);
    int currSelIndex = !pBtn ? 0 : pBtn->getTag();
    
    CMatrix3 transformMt;
    if (selIndex != currSelIndex)
    {
        // points 恢复原状
        resetPoints();
        selIndex = currSelIndex;
    }
    else
    {
        switch (selIndex)
        {
            case 1: // left move
            {
                transformMt = CMatrix3::getMoveMatrix(-10.0f, 0.0f);
            }
                break;
            case 2: // right move
            {
                transformMt = CMatrix3::getMoveMatrix(10.0f, 0.0f);
            }
                break;
            case 3: // up move
            {
                transformMt = CMatrix3::getMoveMatrix(0.0f, 10.0f);
            }
                break;
            case 4: // down move
            {
                transformMt = CMatrix3::getMoveMatrix(0.0f, -10.0f);
            }
                break;
            case 5: // rotate+
            {
                transformMt = CMatrix3::getRotateMatrix(15.0f);
            }
                break;
            case 6: // rotate-
            {
                transformMt = CMatrix3::getRotateMatrix(-15.0f);
            }
                break;
            case 7: // s+
            {
                transformMt = CMatrix3::getScaleMatrix(2.0f, 2.0f);
            }
                break;
            case 8: // s-
            {
                transformMt = CMatrix3::getScaleMatrix(0.5f, 0.5f);
            }
                break;
            case 9: // x/
            {
                transformMt = CMatrix3::getFlectMatrix(1.0f, -1.0f);
            }
                break;
            case 10: // y/
            {
                transformMt = CMatrix3::getFlectMatrix(-1.0f, 1.0f);
            }
                break;
            case 11: // O/
            {
                transformMt = CMatrix3::getFlectMatrix(-1.0f, -1.0f);
            }
                break;
                
            case 12: // skX+
            {
                transformMt = CMatrix3::getSkewMatrix(0.0f, 1.0f);
            }
                break;
            case 13: // skX-
            {
                transformMt = CMatrix3::getSkewMatrix(0.0f, -1.0f);
            }
                break;
            case 14: // skY+
            {
                transformMt = CMatrix3::getSkewMatrix(1.0f, 0.0f);
            }
                break;
            case 15: // skY-
            {
                transformMt = CMatrix3::getSkewMatrix(-1.0f, 0.0f);
            }
                break;
            default:
                break;
        }
    }
    
    CMatrix3::pointDotMatrix(m_graphicPoints, 4, transformMt);
    drawGraphics();
}

void GraphicsLayer07::drawGraphics()
{
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 centerPt = winSize*0.5f;
    
    Vec2 points[4];
    for (int i=0; i<4; ++i)
    {
        points[i] = m_graphicPoints[i] + centerPt;
    }
    GRAPHICS->drawPolygon(points, 4);
}



























