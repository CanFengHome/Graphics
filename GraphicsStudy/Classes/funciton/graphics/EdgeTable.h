//
//  EdgeTable.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef EdgeTable_h
#define EdgeTable_h

#include "CPoint.h"

struct AET
{
    float m_fX;
    int m_iYMax;
    float m_fK;
    AET* m_pNext;
};

struct Bucket
{
    int m_iScanLine;
    AET* m_pAET;
    Bucket* m_pNext;
};

#endif /* EdgeTable_h */
