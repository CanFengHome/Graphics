//
//  GraphicsLayer09.h
//  GraphicsStudy
//
//  Created by ccf on 16/8/2.
//
//

#ifndef GraphicsLayer09_h
#define GraphicsLayer09_h

#include "Common.h"

// 09 Bezier曲线算法
class GraphicsLayer09 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer09);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
    
    void drawPoints();
    void drawSpline();
    
private:
    Vec2 m_pts[5];
};


#endif /* GraphicsLayer09_h */
