//
//  Common.h
//  GraphicsStudy
//
//  Created by ccf on 16/7/19.
//
//

#ifndef Common_h
#define Common_h

#include <string>
using namespace std;

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

#include "Graphics.h"
#define GRAPHICS Graphics::getInstance()

const int TEST_DRAW_NODE_TAG = 1001;
DrawNode* g_createCanvas(Node* pParentNode);

Button* g_createButton(Node* pParentNode, const string& strTitle, const Vec2& position, const Widget::ccWidgetClickCallback &callback);

Vec2 g_randomPosition();
Vec2 g_randomPosition(const Vec2& posStart);
Vec2 g_randomPosition(const Vec2& posStart, const Rect& rect);

#endif /* Common_h */
