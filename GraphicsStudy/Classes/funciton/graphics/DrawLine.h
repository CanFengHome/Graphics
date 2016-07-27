//
//  DrawLine.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/21.
//
//

#ifndef DrawLine_h
#define DrawLine_h

void g_drawLineHorizontal(int x1, int y1, int x2, int y2);
void g_drawLineVertical(int x1, int y1, int x2, int y2);
// DDA 数字微分分析器
void g_drawLineDDA(int x1, int y1, int x2, int y2);

// 中点Bresenham算法
void g_drawLineBresenham(int x1, int y1, int x2, int y2);

// 距离加权反走样直线
void g_drawLineAnti(int x1, int y1, int x2, int y2);

#endif /* DrawLine_h */
