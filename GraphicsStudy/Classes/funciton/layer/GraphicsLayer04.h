//
//  GraphicsLayer04.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef GraphicsLayer04_h
#define GraphicsLayer04_h

#include "Common.h"

// 椭圆中点Bresenham算法
class GraphicsLayer04 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer04);
    virtual bool init() override;
private:
    void btnTestCallbackRandom(cocos2d::Ref* pSender);
    void btnTestCallbackFix(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer04_h */
