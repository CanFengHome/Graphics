//
//  GraphicsLayer03.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef GraphicsLayer03_h
#define GraphicsLayer03_h

#include "Common.h"

// 圆中点Bresenham算法
class GraphicsLayer03 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer03);
    virtual bool init() override;
private:
    void btnTestCallbackRandom(cocos2d::Ref* pSender);
    void btnTestCallbackFix(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer03_h */
