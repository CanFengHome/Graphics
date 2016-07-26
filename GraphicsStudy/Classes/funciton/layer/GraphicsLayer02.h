//
//  GraphicsLayer02.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/26.
//
//

#ifndef GraphicsLayer02_h
#define GraphicsLayer02_h

#include "Common.h"

// 中点Bresenham算法
class GraphicsLayer02 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer02);
    virtual bool init() override;
private:
    void btnTestCallbackRandom(cocos2d::Ref* pSender);
    void btnTestCallbackFix(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer02_h */
