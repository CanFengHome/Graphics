//
//  Graphics.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#include "Graphics.h"

Graphics::Graphics()
{
    resetState();
}

void Graphics::resetState()
{
    m_pCanvas = nullptr;
    m_pixelColor = Color4F::RED;
    m_bgColor = Color4F::GRAY;
    m_lineColor = Color4F::BLUE;
    m_fPointSize = 1.0f;
}

void Graphics::clearAllGraphics()
{
    if (m_pCanvas)
    {
        m_pCanvas->clear();
    }
}

void Graphics::setPixel(int x, int y)
{
    setPixel(Vec2(x, y));
}

void Graphics::setPixel(const Vec2& position)
{
    if (m_pCanvas)
    {
        m_pCanvas->drawPoint(position, m_fPointSize, m_pixelColor);
        CCLOG("draw pixel (%f, %f)", position.x, position.y);
    }
}

DrawNode* Graphics::inistallCanvas(Node* pParentNode)
{
    resetState();
    if (pParentNode)
    {
        m_pCanvas = DrawNode::create();
        pParentNode->addChild(m_pCanvas);
    }
    return m_pCanvas;
}

void Graphics::drawPolyline(Vec2 arrPoints[], int arrLen)
{
    m_pCanvas->drawPoly(arrPoints, arrLen, false, m_lineColor);
}

void Graphics::drawPolygon(Vec2 arrPoints[], int arrLen)
{
    m_pCanvas->drawPoly(arrPoints, arrLen, true, m_lineColor);
}

void Graphics::drawPolygon(Vec2 arrPoints[], int arrLen, const Vec2& centerPt)
{
    Vec2* pArr = new Vec2[arrLen];
    for (int i=0; i<arrLen; ++i)
    {
        pArr[i] = arrPoints[i] + centerPt;
    }
    drawPolygon(pArr, arrLen);
    delete []pArr;
}






































