//
//  CPoint.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/28.
//
//

#ifndef CPoint_h
#define CPoint_h

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

#endif /* CPoint_h */
