//
//  DrawLine.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/21.
//
//

#include "DrawLine.h"

#include "Graphics.h"

void g_drawLineHorizontal(int x1, int y1, int x2, int y2)
{
    assert(y1 == y2);
    
    int step = 1;
    if (x1 > x2)
    {
        step = -1;
    }
    
    for (int x = x1; x!=x2+step; x+=step)
    {
        GRAPHICS->setPixel(x, y1);
    }
}

void g_drawLineVertical(int x1, int y1, int x2, int y2)
{
    assert(x1 == x2);
    
    int step = 1;
    if (y1 > y2)
    {
        step = -1;
    }
    
    for (int y = y1; y!=y2+step; y+=step)
    {
        GRAPHICS->setPixel(x1, y);
    }
}

void g_drawLineDDA(int x1, int y1, int x2, int y2)
{
    int dy = y2 - y1;
    int dx = x2 - x1;
    int maxLen = MAX(abs(dy), abs(dx));
    float yStep = static_cast<float>(dy)/static_cast<float>(maxLen);
    float xStep = static_cast<float>(dx)/static_cast<float>(maxLen);
    
    float x = x1 + 0.5f;
    float y = y1 + 0.5f;
    
    for (int i=0; i < maxLen; ++i)
    {
        GRAPHICS->setPixel(floor(x), floor(y));
        x += xStep;
        y += yStep;
    }
}
































