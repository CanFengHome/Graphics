//
//  CMatrix3.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/28.
//
//

#ifndef CMatrix3_h
#define CMatrix3_h

#include "cocos2d.h"
USING_NS_CC;

class CMatrix3
{
public:
    CMatrix3();
    static CMatrix3 getMoveMatrix(float moveX, float moveY);
    static CMatrix3 getRotateMatrix(float rotateAngle);
    static CMatrix3 getScaleMatrix(float scaleX, float scaleY);
    static CMatrix3 getFlectMatrix(float flectX, float flectY);
    static CMatrix3 getSkewMatrix(float skewX, float skewY);
    
    static void pointDotMatrix(Vec2 arrPoints[], int arrLen, const CMatrix3& matrix);
    
private:
    float m_arrMatrix[3][3];
};

#endif /* CMatrix3_h */
