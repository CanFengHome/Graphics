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

class Graphics : public SingletonTemplate<Graphics>
{
private:
    Graphics();
    virtual ~Graphics(){};
    friend class SingletonTemplate<Graphics>;
public:
    void setCanvas(DrawNode* pCanvas);
    void clearAllGraphics();
    void setPixel(const Vec2& position);
private:
    void resetState();
    
private:
    DrawNode* m_pCanvas = nullptr;
    CC_SYNTHESIZE(Color4F, m_pixelColor, PixelColor);
    CC_SYNTHESIZE(Color4F, m_bgColor, BgColor)
    CC_SYNTHESIZE(Color4F, m_fillColor, FillColor);
};

#endif /* Graphics_h */
