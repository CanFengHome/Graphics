//
//  Common.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#include "Common.h"

DrawNode* g_createCanvas(Node* pParentNode)
{
    DrawNode* pDrawNode = nullptr;
    if (pParentNode)
    {
        pDrawNode = DrawNode::create();
        pParentNode->addChild(pDrawNode, TEST_DRAW_NODE_TAG);
    }
    return pDrawNode;
}

Button* g_createButton(Node* pParentNode, const string& strTitle, const Vec2& position, const Widget::ccWidgetClickCallback &callback)
{
    Button* pBtn = Button::create();
    pBtn->setPressedActionEnabled(true);
    pBtn->addClickEventListener(callback);
    pBtn->setTitleText(strTitle);
    pBtn->setPosition(position);
    pBtn->setTitleFontSize(40.0f);
    pBtn->setTitleColor(Color3B::BLUE);
    pParentNode->addChild(pBtn);
    return pBtn;
}

Vec2 g_randomPosition()
{
    return g_randomPosition(Vec2(50.0f, 100.0f));
}

Vec2 g_randomPosition(const Vec2& posStart)
{
    Size winSize = Director::getInstance()->getWinSize();
    Rect canvasRect(0.0f, 0.0f, winSize.width-100.0f, winSize.height-200.0f);
    return g_randomPosition(posStart, canvasRect);
}

Vec2 g_randomPosition(const Vec2& posStart, const Rect& rect)
{
    float randomX = RandomHelper::random_real(rect.getMinX(), rect.getMaxX());
    float randomY = RandomHelper::random_real(rect.getMinY(), rect.getMaxY());
    
    return posStart + Vec2(randomX, randomY);
}






















