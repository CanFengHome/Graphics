//
//  Graphics.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#ifndef Graphics_h
#define Graphics_h

#include "cocos2d.h"
USING_NS_CC;

#include "SingletonTemplate.h"

#define GRAPHICS Graphics::getInstance()

#define   ROUND(a) int(a+0.5) //四舍五入

class Graphics : public SingletonTemplate<Graphics>
{
private:
    Graphics();
    virtual ~Graphics(){};
    friend class SingletonTemplate<Graphics>;
public:
    DrawNode* inistallCanvas(Node* pParentNode);
    
    void clearAllGraphics();
    void setPixel(int x, int y);
    void setPixel(const Vec2& position);
    
    void drawPolyline(Vec2 arrPoints[], int arrLen);
    
    void drawPolygon(Vec2 arrPoints[], int arrLen);
    void drawPolygon(Vec2 arrPoints[], int arrLen, const Vec2& centerPt);
private:
    void resetState();
private:
    DrawNode* m_pCanvas = nullptr;
    CC_SYNTHESIZE(Color4F, m_pixelColor, PixelColor);
    CC_SYNTHESIZE(Color4F, m_bgColor, BgColor)
    CC_SYNTHESIZE(Color4F, m_lineColor, LineColor);
    CC_SYNTHESIZE(float, m_fPointSize, PointSize);
};

#endif /* Graphics_h */
