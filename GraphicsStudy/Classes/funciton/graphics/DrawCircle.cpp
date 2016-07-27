//
//  DrawCircle.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#include "DrawCircle.h"

#include "Graphics.h"

void drawCirclePoint(float fX, float fY, int circleX, int circleY)
{
    int x = ROUND(fX);
    int y = ROUND(fY);
    
    int arr[8][2] = {
        {x+circleX, y+circleY},   // x, y
        {y+circleX, x+circleY},   // y, x
        {y+circleX, -x+circleY},  // y, -x
        {x+circleX, -y+circleY},  // x, -y
        {-x+circleX, -y+circleY}, // -x, -y
        {-y+circleX, -x+circleY}, // -y, -x
        {-y+circleX, x+circleY},  // -y, x
        {-x+circleX, y+circleY}   // -x, y
    };
    
    for (int i=0; i<8; ++i)
    {
        GRAPHICS->setPixel(arr[i][0], arr[i][1]);
    }
}

void g_drawCircle(int circleX, int circleY, int r)
{
    float x = 0;
    float y = r;
    float d = 1.25f - r;
    for (; x<y; ++x)
    {
        drawCirclePoint(x, y, circleX, circleY);
        if (d<0)
        {
            d = d+2*x+3;
        }
        else
        {
            d = d+2*(x-y)+5;
            --y;
        }
    }
}

















