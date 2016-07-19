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

// 01 
class GraphicsLayer01 : public Layer
{
public:
    CREATE_FUNC(GraphicsLayer01);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
};

#endif /* GraphicsLayer01_h */
