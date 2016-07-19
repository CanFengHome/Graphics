//
//  GraphicsLayer00.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#ifndef GraphicsLayer00_h
#define GraphicsLayer00_h

#include "Common.h"

// 00 绘制随机点
class GraphicsLayer00 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer00);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
    
private:
    DrawNode* m_pCanvas = nullptr;
};

#endif /* GraphicsLayer00_h */
