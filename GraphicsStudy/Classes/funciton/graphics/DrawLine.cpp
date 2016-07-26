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

void g_drawLineBresenham(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        g_drawLineVertical(x1, y1, x2, y2);
        return;
    }
    
    float x = x1;
    float y = y1;
    float xEnd = x2;
    float k = (float)(y2-y1) / (float)(x2-x1);
    if (x1 > x2)
    {
        x = x2;
        y = y2;
        xEnd = x1;
        k = (float)(y1-y2) / (float)(x1-x2);
    }
    
    float d = 0.5f-k;
    for (; x<=xEnd; ++x)
    {
        GRAPHICS->setPixel(floor(x+0.5f), floor(y+0.5f));
        if (d<0)
        {
            ++y;
            d = d+1-k;
        }
        else
        {
            d = d-k;
        }
    }
    
    
}






























