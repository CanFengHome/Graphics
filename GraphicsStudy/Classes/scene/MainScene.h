//
//  MainScene.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "BaseDataListLayer.h"

class MainScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(MainScene);
    virtual bool init() override;
};

class LayerMainDataList : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerMainDataList);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

class BaseBackLayer : public cocos2d::Layer
{
protected:
    virtual bool init() override;
    void btnBackCallback(cocos2d::Ref* pSender);
protected:
    virtual void gotoNextScene()=0;
};

class CloseBackLayer : public BaseBackLayer
{
public:
    CREATE_FUNC(CloseBackLayer);
    
protected:
    virtual void gotoNextScene() override;
};

class FunctionBackLayer : public BaseBackLayer
{
public:
    CREATE_FUNC(FunctionBackLayer);
    
protected:
    virtual void gotoNextScene() override;
};

#endif /* MainScene_h */
