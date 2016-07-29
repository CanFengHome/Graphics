//
//  GraphicsLayer08.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/29.
//
//

#ifndef GraphicsLayer08_h
#define GraphicsLayer08_h

#include "Common.h"

// 08 Cohen-Sutherland直线裁剪算法
class GraphicsLayer08 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer08);
    virtual bool init() override;
private:
    void initData();
    // 端点编码函数
    unsigned int endpointCode(float ptX, float ptY);
    void drawClipLine();
    
    void btnDrawLineCallback(cocos2d::Ref* pSender);
    void btnDrawClipLineCallback(cocos2d::Ref* pSender);
    
private:
    Vec2 m_window[4];
    Vec2 m_line[2];
};


#endif /* GraphicsLayer08_h */
