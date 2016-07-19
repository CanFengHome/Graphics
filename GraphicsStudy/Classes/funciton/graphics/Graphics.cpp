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
    m_fillColor = Color4F::BLUE;
}

void Graphics::setCanvas(DrawNode* pCanvas)
{
    resetState();
    m_pCanvas = pCanvas;
}

void Graphics::clearAllGraphics()
{
    if (m_pCanvas)
    {
        m_pCanvas->clear();
    }
}

void Graphics::setPixel(const Vec2& position)
{
    if (m_pCanvas)
    {
        m_pCanvas->drawPoint(position, 1, m_pixelColor);
        CCLOG("draw pixel (%f, %f)", position.x, position.y);
    }
}























