//
//  GraphicsLayer05.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef GraphicsLayer05_h
#define GraphicsLayer05_h

#include "Common.h"

// 距离加权反走样直线
class GraphicsLayer05 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer05);
    virtual bool init() override;
private:
    void btnTestCallbackRandom(cocos2d::Ref* pSender);
    void btnTestCallbackFix(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer05_h */
