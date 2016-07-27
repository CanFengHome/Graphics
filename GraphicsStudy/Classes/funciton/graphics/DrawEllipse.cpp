//
//  DrawEllipse.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#include "DrawEllipse.h"

#include "Graphics.h"

void drawEllipsePoint(float fX, float fY, int centerX, int centerY)
{
    int x = ROUND(fX);
    int y = ROUND(fY);
    
    int arr[4][2] = {
        {x+centerX, y+centerY},   // x, y
        {-x+centerX, y+centerY},   // -x, y
        {x+centerX, -y+centerY},  // x, -y
        {-x+centerX, -y+centerY}  // -x, -y
    };
    
    for (int i=0; i<4; ++i)
    {
        GRAPHICS->setPixel(arr[i][0], arr[i][1]);
    }
}

void g_drawEllipse(int centerX, int centerY, int a, int b)
{
    float x = 0;
    float y = b;
    float d1 = b*b+a*a*(-b+0.25f);
    
    // 椭圆AC弧段
    drawEllipsePoint(x, y, centerX, centerY);
    while (b*b*(x+1)<a*a*(y-0.5f))
    {
        if (d1<0)
        {
            d1 = d1 + b*b*(2*x+3);
        }
        else
        {
            d1 = d1 + b*b*(2*x+3)+a*a*(-2*y+2);
            --y;
        }
        ++x;
        drawEllipsePoint(x, y, centerX, centerY);
    }
    
    // 椭圆CB弧段
    float d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>0)
    {
        if (d2<0)
        {
            d2 = d2 + b*b*(2*x+2)+a*a*(-2*y+3);
            x++;
        }
        else
        {
            d2 = d2 + a*a*(-2*y+3);
        }
        y--;
        drawEllipsePoint(x, y, centerX, centerY);
    }
}




















