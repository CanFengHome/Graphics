//
//  MainScene.cpp
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#include "MainScene.h"

USING_NS_CC;
using namespace ui;

#include "GraphicsHeader.h"

bool MainScene::init()
{
    addChild(LayerMainDataList::create());
    addChild(CloseBackLayer::create());
    
    return true;
}

void LayerMainDataList::initFunNames()
{
    m_arrFunName.clear();
    m_arrFunName.push_back("00 绘制随机点");
    m_arrFunName.push_back("01 DDA画线");
    m_arrFunName.push_back("02 中点Bresenham算法");
    m_arrFunName.push_back("03 圆中点Bresenham算法");
    m_arrFunName.push_back("04 椭圆中点Bresenham算法");
    m_arrFunName.push_back("05 距离加权反走样直线");
    m_arrFunName.push_back("06 多边形有效边表填充算法");
    
}

void LayerMainDataList::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex)
    {
        case 0:
            pLyrTest = GraphicsLayer00::create();
            break;
        case 1:
            pLyrTest = GraphicsLayer01::create();
            break;
        case 2:
            pLyrTest = GraphicsLayer02::create();
            break;
        case 3:
            pLyrTest = GraphicsLayer03::create();
            break;
        case 4:
            pLyrTest = GraphicsLayer04::create();
            break;
        case 5:
            pLyrTest = GraphicsLayer05::create();
            break;
        case 6:
            pLyrTest = GraphicsLayer06::create();
            break;
        default:
            pLyrTest = nullptr;
            break;
    }
    if (pLyrTest != nullptr)
    {
        pSceneFunction->addChild(pLyrTest);
    }
    pSceneFunction->addChild(FunctionBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}


#pragma mark BaseBackLayer

bool BaseBackLayer::init()
{
    if (!Layer::create())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pBtnBack = Button::create();
    pBtnBack->setPressedActionEnabled(true);
    pBtnBack->addClickEventListener(CC_CALLBACK_1(BaseBackLayer::btnBackCallback, this));
    pBtnBack->setTitleText("Back");
    addChild(pBtnBack);
    pBtnBack->setTitleFontSize(40.0f);
    pBtnBack->setTitleColor(Color3B::BLUE);
    pBtnBack->setPosition(Vec2(winSize.width-pBtnBack->getContentSize().width*0.5f,
                               pBtnBack->getContentSize().height*0.5f));
    
    return true;
}

void BaseBackLayer::btnBackCallback(Ref* pSender)
{
    gotoNextScene();
}


#pragma mark CloseBackLayer
void CloseBackLayer::gotoNextScene()
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

#pragma mark FunctionBackLayer
void FunctionBackLayer::gotoNextScene()
{
    Director::getInstance()->replaceScene(MainScene::create());
}










