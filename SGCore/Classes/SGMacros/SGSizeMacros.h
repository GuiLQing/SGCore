//
//  SGSizeMacros.h
//  SGNetworking
//
//  Created by SG on 2019/9/20.
//  Copyright © 2019 SG. All rights reserved.
//

#ifndef SGSizeMacros_h
#define SGSizeMacros_h

#import "SGSystemMacros.h"

#pragma mark - SCREEN

/** 屏幕比例 */
#define SG_SCREEN_SCALE SG_ScreenScale()
static inline CGFloat SG_ScreenScale(void) {
    return UIScreen.mainScreen.scale;
}

/** 屏幕宽度 */
#define SG_SCREEN_WIDTH SG_ScreenWidth()
static inline CGFloat SG_ScreenWidth(void) {
    return CGRectGetWidth(UIScreen.mainScreen.bounds);
}

/** 屏幕高度 */
#define SG_SCREEN_HEIGHT SG_ScreenHeight()
static inline CGFloat SG_ScreenHeight(void) {
    return CGRectGetHeight(UIScreen.mainScreen.bounds);
}

#pragma mark - NAVIGATION

/** 状态栏高度 */
#define SG_STATUS_BAR_HEIGHT SG_StatusBarHeight()
static inline CGFloat SG_StatusBarHeight(void) {
    return CGRectGetHeight(UIApplication.sharedApplication.statusBarFrame);
}

/** 导航栏高度 */
#define SG_NAVIGATION_BAR_HEIGHT SG_NavigationBarHeight()
static inline CGFloat SG_NavigationBarHeight(void) {
    return 44.0f;
}

/** 导航栏总高度 */
#define SG_NAVIGATION_HEIGHT SG_NavigationHeight()
static inline CGFloat SG_NavigationHeight(void) {
    return SG_StatusBarHeight() + SG_NavigationBarHeight();
}

#pragma mark - TABBAR

/** 标签栏高度 */
#define SG_TABBAR_BAR_HEIGHT SG_TabbarBarHeight()
static inline CGFloat SG_TabbarBarHeight(void) {
    return 49.0f;
}

/** IPHONE_X系列HOME键高度 */
#define SG_BOTTOM_HOME_HEIGHT SG_BottonHomeHeight()
static inline CGFloat SG_BottonHomeHeight(void) {
    return SG_IsIphoneX() ? 10.0f : 0.0f;
}

/** 底部安全区除去HOME键的高度 */
#define SG_BOTTOM_SAFE_HEIGHT SG_BottomSafeHeight()
static inline CGFloat SG_BottomSafeHeight(void) {
    return SG_IsIphoneX() ? 24.0f : 0.0f;
}

/** 底部安全区域包括HOME键的高度 */
#define SG_BOTTOM_SAFE_AND_HOME_HEIGHT SG_BottonSafeAndHomeHeight()
static inline CGFloat SG_BottonSafeAndHomeHeight(void) {
    return SG_BottonHomeHeight() + SG_BottomSafeHeight();
}

/** 标签栏总高度 */
#define SG_TABBAR_HEIGHT SG_TabbarHeight()
static inline CGFloat SG_TabbarHeight(void) {
    return SG_BottonSafeAndHomeHeight() + SG_TabbarBarHeight();
}

#pragma mark - TABLEVIEW

/** 表视图高度 */
#define SG_TABLE_VIEW_HEIGHT SG_TableViewHeight()
static inline CGFloat SG_TableViewHeight(void) {
    return SG_ScreenHeight() - SG_NavigationHeight() - SG_BottonHomeHeight();
}

/** 带有标签栏的表视图高度 */
#define SG_TABLE_VIEW_WITH_TABBAR_HEIGHT SG_TableViewWithTabbarHeight()
static inline CGFloat SG_TableViewWithTabbarHeight(void) {
    return SG_ScreenHeight() - SG_NavigationHeight() - SG_TabbarHeight();
}

#endif /* SGSizeMacros_h */
