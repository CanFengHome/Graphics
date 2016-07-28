//
//  CMatrix3.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/28.
//
//

#include "CMatrix3.h"

#define PI 3.1415926f

CMatrix3::CMatrix3()
{
    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            m_arrMatrix[i][j] = 0;
            if (i == j)
            {
                m_arrMatrix[i][j] = 1;
            }
        }
    }
}

CMatrix3 CMatrix3::getMoveMatrix(float moveX, float moveY)
{
    CMatrix3 resultMt;
    resultMt.m_arrMatrix[2][0] = moveX;
    resultMt.m_arrMatrix[2][1] = moveY;
    return resultMt;
}

CMatrix3 CMatrix3::getRotateMatrix(float rotateAngle)
{
    CMatrix3 resultMt;
    float arcAngle = rotateAngle * PI / 180.0f;
    resultMt.m_arrMatrix[0][0] = cos(arcAngle);
    resultMt.m_arrMatrix[0][1] = sin(arcAngle);
    resultMt.m_arrMatrix[1][0] = -sin(arcAngle);
    resultMt.m_arrMatrix[1][1] = cos(arcAngle);
    
    return resultMt;
}

CMatrix3 CMatrix3::getScaleMatrix(float scaleX, float scaleY)
{
    CMatrix3 resultMt;
    resultMt.m_arrMatrix[0][0] = scaleX;
    resultMt.m_arrMatrix[1][1] = scaleY;
    return resultMt;
}

CMatrix3 CMatrix3::getFlectMatrix(float flectX, float flectY)
{
    CMatrix3 resultMt;
    resultMt.m_arrMatrix[0][0] = flectX;
    resultMt.m_arrMatrix[1][1] = flectY;
    return resultMt;
}

CMatrix3 CMatrix3::getSkewMatrix(float skewX, float skewY)
{
    CMatrix3 resultMt;
    resultMt.m_arrMatrix[0][1]=skewX;
    resultMt.m_arrMatrix[1][0]=skewY;
    return resultMt;
}

void CMatrix3::pointDotMatrix(Vec2 arrPoints[], int arrLen, const CMatrix3& matrix)
{
    for (int i=0; i<arrLen; ++i)
    {
        Vec2 srcPt = arrPoints[i];
        Vec2 resultPt;
        resultPt.x = srcPt.x*matrix.m_arrMatrix[0][0] + srcPt.y*matrix.m_arrMatrix[1][0]+matrix.m_arrMatrix[2][0];
        resultPt.y = srcPt.x*matrix.m_arrMatrix[0][1] + srcPt.y*matrix.m_arrMatrix[1][1]+matrix.m_arrMatrix[2][1];
        resultPt.x *= matrix.m_arrMatrix[2][2];
        resultPt.y *= matrix.m_arrMatrix[2][2];
        arrPoints[i] = resultPt;
    }
}
























