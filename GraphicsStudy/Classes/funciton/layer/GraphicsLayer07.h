//
//  GraphicsLayer07.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/28.
//
//

#ifndef GraphicsLayer07_h
#define GraphicsLayer07_h

#include "Common.h"

// 07 二维基本几何变换算法
class GraphicsLayer07 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer07);
    virtual bool init() override;
private:
    void resetPoints();
    void drawGraphics();
    
    void btnTestCallback(cocos2d::Ref* pSender);
    
private:
    Vec2 m_graphicPoints[4];
    
};


#endif /* GraphicsLayer07_h */
