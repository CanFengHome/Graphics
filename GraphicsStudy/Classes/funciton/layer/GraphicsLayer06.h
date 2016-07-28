//
//  GraphicsLayer06.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#ifndef GraphicsLayer06_h
#define GraphicsLayer06_h

#include "Common.h"

#define ARR_LEN 7//N为闭合多边形顶点数，顶点存放在整型二维数组Point[N]中

// 多边形有效边表填充算法
class GraphicsLayer06 : public LayerColor
{
public:
    CREATE_FUNC(GraphicsLayer06);
    virtual bool init() override;
private:
    void initPoint();
    void createBucket();
    void constructEdgeTable();
    void fillPolygon();
    void addEdge(AET *pNewEdge);
    // 对边表进行排序
    void edgeOrder();
    
    void clearData();
    
    void btnTestCallbackFix(cocos2d::Ref* pSender);
private:
    // 定义多边形
    CPoint m_arrPoint[ARR_LEN];
    // 桶的头结点和当前结点
    Bucket *m_pHeadB = nullptr, *m_pCurrentB;
    // 有效边表的结点
    AET m_AET[ARR_LEN];
    AET* m_pHeadE = nullptr;
    AET* m_pCurrentE;
    AET* m_pT1;
    AET* m_pT2;
};

#endif /* GraphicsLayer06_h */
