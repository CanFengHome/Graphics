//
//  GraphicsLayer10.h
//  GraphicsStudy
//
//  Created by ccf on 16/8/2.
//
//

#ifndef GraphicsLayer10_h
#define GraphicsLayer10_h

#include "Common.h"

// 10 三次B样条曲线算法
class GraphicsLayer10 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer10);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
    
    void drawPoints();
    void drawSpline();
    
private:
    Vec2 m_pts[5];
};


#endif /* GraphicsLayer10_h */
