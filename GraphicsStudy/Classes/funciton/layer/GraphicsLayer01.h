//
//  GraphicsLayer01.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#ifndef GraphicsLayer01_h
#define GraphicsLayer01_h

#include "Common.h"

// 01 DDA画线
class GraphicsLayer01 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer01);
    virtual bool init() override;
private:
    void btnTestCallbackRandom(cocos2d::Ref* pSender);
    void btnTestCallbackFix(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer01_h */
