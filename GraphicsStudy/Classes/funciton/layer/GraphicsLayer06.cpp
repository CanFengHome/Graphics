//
//  GraphicsLayer06.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/27.
//
//

#include "GraphicsLayer06.h"

bool GraphicsLayer06::init()
{
    if (!LayerColor::initWithColor(Color4B(GRAPHICS->getBgColor())))
    {
        return false;
    }
    
    GRAPHICS->inistallCanvas(this);
    
    Size winSize = Director::getInstance()->getWinSize();
    g_createButton(this, "fill polygon", Vec2(winSize.width*0.5f, winSize.height - 20.0f), CC_CALLBACK_1(GraphicsLayer06::btnTestCallbackFix, this));
    
    GRAPHICS->setPixelColor(Color4F::BLACK);
    GRAPHICS->setLineColor(Color4F::RED);
    
    initPoint();
    
    Vec2 arrPolygonVec2[ARR_LEN];
    for (int i=0; i<ARR_LEN; ++i)
    {
        arrPolygonVec2[i] = Vec2(m_arrPoint[i].x, m_arrPoint[i].y);
    }
    GRAPHICS->drawPolygon(arrPolygonVec2, ARR_LEN);
    
    return true;
}

void GraphicsLayer06::initPoint()
{
    //设置多边形的7个顶点
    m_arrPoint[0]=CPoint(450,200);//P0
    m_arrPoint[1]=CPoint(350,300);//P1
    m_arrPoint[2]=CPoint(250,150);//P2
    m_arrPoint[3]=CPoint(350,60);//P3
    m_arrPoint[4]=CPoint(400,100);//P4
    m_arrPoint[5]=CPoint(500,60);//P5
    m_arrPoint[6]=CPoint(600,250);//P6
}

void GraphicsLayer06::createBucket()
{
    // 确定扫描线最小值和最大值
    int scanYMin, scanYMax;
    scanYMin = m_arrPoint[0].y;
    scanYMax = scanYMin;
    for (int i=1; i<ARR_LEN; ++i)
    {
        scanYMin = MIN(scanYMin, m_arrPoint[i].y);
        scanYMax = MAX(scanYMax, m_arrPoint[i].y);
    }
    
    // 建立桶结点
    for (int i=scanYMin; i<=scanYMax; ++i)
    {
        if (i == scanYMin)
        {
            m_pHeadB = new Bucket;
            m_pCurrentB = m_pHeadB;
            m_pCurrentB->m_iScanLine = scanYMin;
            m_pCurrentB->m_pAET = nullptr;
            m_pCurrentB->m_pNext = nullptr;
        }
        else // 建立桶的其它结点
        {
            m_pCurrentB->m_pNext = new Bucket;
            m_pCurrentB = m_pCurrentB->m_pNext;
            m_pCurrentB->m_iScanLine = i;
            m_pCurrentB->m_pAET = nullptr;//没有连接边链表
            m_pCurrentB->m_pNext = nullptr;
        }
    }
}

// 构造边表
void GraphicsLayer06::constructEdgeTable()
{
    for(int i=0; i < ARR_LEN; i++)//访问每个顶点
    {
        //从桶链表的头结点开始循环
        m_pCurrentB = m_pHeadB;
        // 边的第二个顶点，Point[i]和Point[j]构成边
        int j = i+1;
        // 保证多边形的闭合
        if(j == ARR_LEN)
            j=0;
        
        // 终点比起点高
        if(m_arrPoint[j].y>m_arrPoint[i].y)
        {
            // 在桶内寻找该边的yMin
            while(m_pCurrentB->m_iScanLine != m_arrPoint[i].y)
            {
                m_pCurrentB=m_pCurrentB->m_pNext;
            }
            
            m_AET[i].m_fX = m_arrPoint[i].x; // 计算AET表的值
            m_AET[i].m_iYMax = m_arrPoint[j].y;
            m_AET[i].m_fK=float((m_arrPoint[j].x-m_arrPoint[i].x))/(m_arrPoint[j].y-m_arrPoint[i].y);//代表1/k
            m_AET[i].m_pNext=nullptr;
            m_pCurrentE = m_pCurrentB->m_pAET; // 获得桶上链接边表的地址
            
            if(m_pCurrentB->m_pAET == nullptr)// 当前桶结点上没有链接边结点
            {
                m_pCurrentE= &m_AET[i];// 赋边的起始地址
                m_pCurrentB->m_pAET = m_pCurrentE;// 第一个边结点直接连接到对应的桶中
            }
            else
            {
                while(m_pCurrentE->m_pNext != nullptr)//如果当前边已连有边结点
                {
                    m_pCurrentE = m_pCurrentE->m_pNext;//移动指针到当前边的最后一个边结点
                }
                m_pCurrentE->m_pNext= &m_AET[i];//把当前边接上去
            }
        }
        
        // 终点比起点低
        if(m_arrPoint[j].y<m_arrPoint[i].y)
        {
            while(m_pCurrentB->m_iScanLine!=m_arrPoint[j].y)
            {
                m_pCurrentB=m_pCurrentB->m_pNext;
            }
            
            m_AET[i].m_fX = m_arrPoint[j].x;
            m_AET[i].m_iYMax = m_arrPoint[i].y;
            m_AET[i].m_fK = float((m_arrPoint[i].x-m_arrPoint[j].x))/(m_arrPoint[i].y-m_arrPoint[j].y);
            m_AET[i].m_pNext = nullptr;
            
            m_pCurrentE = m_pCurrentB->m_pAET;
            if(m_pCurrentE == nullptr)
            {
                m_pCurrentE= &m_AET[i];
                m_pCurrentB->m_pAET = m_pCurrentE;
            }
            else
            {
                while(m_pCurrentE->m_pNext != nullptr)
                {
                    m_pCurrentE = m_pCurrentE->m_pNext;
                }
                m_pCurrentE->m_pNext= &m_AET[i];
            }
        }
    }
    
    m_pCurrentB = nullptr;
    m_pCurrentE = nullptr;
}

// 多边形填充
void GraphicsLayer06::fillPolygon()
{
    m_pHeadE = nullptr;
    // 访问所有桶结点
    for(m_pCurrentB = m_pHeadB; m_pCurrentB != NULL; m_pCurrentB = m_pCurrentB->m_pNext)
    {
        // 访问桶中排序前的边结点
        for(m_pCurrentE = m_pCurrentB->m_pAET; m_pCurrentE != NULL; m_pCurrentE = m_pCurrentE->m_pNext)
        {
            AET *pTempEdge = new AET;
            pTempEdge->m_fX = m_pCurrentE->m_fX;
            pTempEdge->m_iYMax = m_pCurrentE->m_iYMax;
            pTempEdge->m_fK = m_pCurrentE->m_fK;
            pTempEdge->m_pNext = NULL;
            // 将该边插入临时Aet表
            addEdge(pTempEdge);
        }
        
        // 使得边表按照x递增的顺序存放
        edgeOrder();
        // 根据ymax抛弃扫描完的边结点
        m_pT1 = m_pHeadE;
        if(m_pT1 == nullptr)
        {
            return;
        }
        
        // 放弃该结点，Aet表指针后移（下闭上开）
        while(m_pCurrentB->m_iScanLine >= m_pT1->m_iYMax)
        {
            m_pHeadE = m_pT1->m_pNext;
            delete m_pT1;
            m_pT1 = m_pHeadE;
            if(m_pHeadE == nullptr)
            {
                return;
            }
        }
        
        if(m_pT1->m_pNext != nullptr)
        {
            m_pT2 = m_pT1;
            m_pT1 = m_pT2->m_pNext;
        }
        
        while(m_pT1 != nullptr)
        {
            // 跳过一个结点
            if(m_pCurrentB->m_iScanLine >= m_pT1->m_iYMax)
            {
                m_pT2->m_pNext = m_pT1->m_pNext;
                m_pT1->m_pNext = nullptr;
                delete m_pT1;
                m_pT1 = m_pT2->m_pNext;
            }
            else
            {
                m_pT2 = m_pT1;
                m_pT1 = m_pT2->m_pNext;
            }
        }
        //----（下闭上开)处理完毕
        
        bool bIn = false;
        // 扫描线的起点和终点
        float xb, xe;
        // 填充扫描线和多边形相交的区间
        for(m_pT1 = m_pHeadE; m_pT1 != nullptr; m_pT1 = m_pT1->m_pNext)
        {
            if(bIn == false)
            {
                xb = m_pT1->m_fX;
                bIn = true; // 每访问一个结点,把In值取反一次
            }
            else // 如果bIn值为真，则填充从当前结点的x值开始到下一结点的x值结束的区间
            {
                // 左闭右开
                xe = m_pT1->m_fX - 1;
                
                for(float x = xb; x <= xe; x++)
                {
                    GRAPHICS->setPixel(ROUND(x), m_pCurrentB->m_iScanLine);
                }
                
                bIn = false;
            }		
        }
        
        // 边连贯性，
        for(m_pT1 = m_pHeadE; m_pT1 != nullptr; m_pT1 = m_pT1->m_pNext)
        {
            m_pT1->m_fX = m_pT1->m_fX + m_pT1->m_fK; // x=x+1/k
        }
    }
    
    clearData();
}

void GraphicsLayer06::clearData()
{
    m_pCurrentB = m_pHeadB;
    if (m_pCurrentB)
    {
        m_pHeadB = m_pCurrentB->m_pNext;
        delete m_pCurrentB;
        m_pCurrentB = m_pHeadB;
    }
    
    m_pT1 = m_pHeadE;
    if (m_pT1 != nullptr)
    {
        m_pT2 = m_pT1->m_pNext;
        delete m_pT1;
        m_pT1 = m_pT2;
    }
    
    m_pHeadE = nullptr;
    m_pCurrentE = nullptr;
    m_pT1 = nullptr;
    m_pT2 = nullptr;
    m_pHeadB = nullptr;
    m_pCurrentB = nullptr;
}

void GraphicsLayer06::addEdge(AET *pNewEdge)
{
    m_pT1 = m_pHeadE;
    // 边表为空,将边表置为TempEdge
    if(m_pT1 == nullptr)
    {
        m_pT1 = pNewEdge;
        m_pHeadE = m_pT1;
    }
    else
    {
        while(m_pT1->m_pNext!= nullptr)//边表不为空,将TempEdge连在该边之后
        {
            m_pT1 = m_pT1->m_pNext;
        }
        m_pT1->m_pNext = pNewEdge;
    }
}

// 对边表进行排序
void GraphicsLayer06::edgeOrder()
{
    m_pT1 = m_pHeadE;
    if(m_pT1 == nullptr)
    {
        return;
    }
    if(m_pT1->m_pNext == nullptr) // 如果该边表没有再连边表
    {
        return; // 桶结点只有一条边，不需要排序
    }
    else
    {
        if(m_pT1->m_pNext->m_fX < m_pT1->m_fX) // 边表按x值排序
        {
            m_pT2 = m_pT1->m_pNext;
            m_pT1->m_pNext = m_pT2->m_pNext;
            m_pT2->m_pNext = m_pT1;
            m_pHeadE = m_pT2;
        }
        
        m_pT2 = m_pHeadE;
        m_pT1 = m_pHeadE->m_pNext;
        // 继续两两比较相连的边表的x值,进行排序
        while(m_pT1->m_pNext != nullptr)
        {
            if(m_pT1->m_pNext->m_fX < m_pT1->m_fX)
            {
                m_pT2->m_pNext = m_pT1->m_pNext;
                m_pT1->m_pNext = m_pT1->m_pNext->m_pNext;
                m_pT2->m_pNext->m_pNext = m_pT1;
                m_pT2 = m_pT2->m_pNext;
            }
            else
            {
                m_pT2 = m_pT1;
                m_pT1 = m_pT1->m_pNext;
            }
        }
    }
}

void GraphicsLayer06::btnTestCallbackFix(cocos2d::Ref* pSender)
{
    GRAPHICS->clearAllGraphics();
    
    Vec2 arrPolygonVec2[ARR_LEN];
    for (int i=0; i<ARR_LEN; ++i)
    {
        arrPolygonVec2[i] = Vec2(m_arrPoint[i].x, m_arrPoint[i].y);
    }

    // 初始化桶
    createBucket();
    // 建立边表
    constructEdgeTable();
    // 多边形填充
    fillPolygon();
}

























