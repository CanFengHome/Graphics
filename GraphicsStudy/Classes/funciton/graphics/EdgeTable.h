//
//  EdgeTable.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef EdgeTable_h
#define EdgeTable_h

struct CPoint
{
    CPoint()
    :x(0), y(0)
    {
        
    }
    
    CPoint(int ix, int iy)
    :x(ix), y(iy)
    {
        
    }
    
    int x;
    int y;
};

//struct Edge
//{
//    float m_fX;
//    int m_iYMax;
//    float m_fK;
//    Edge* m_pNext;
//};

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
