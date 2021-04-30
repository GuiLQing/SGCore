//
//  SGCore.h
//  Pods
//
//  Created by SG on 2019/9/25.
//

#ifndef SGCore_h
#define SGCore_h

#import "NSObject+SGCore.h"
#import "NSString+SGCore.h"
#import "NSArray+SGCore.h"
#import "NSDictionary+SGCore.h"
#import "NSDate+SGCore.h"

#import "UIView+SGCore.h"
#import "UIColor+SGCore.h"
#import "UIImage+SGCore.h"

//发布版本不输出调试信息
#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#define SGLog(format, ...) NSLog((@"文件名 : %s\n" "函数名 : %s  " "行号 : %d\n" format), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define NSLog(...) {}
#define SGLog(...) {}
#endif

#ifndef SG_weakify
#if __has_feature(objc_arc)
#define SG_weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
@autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \
_Pragma("clang diagnostic pop")
#else

#define SG_weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
@autoreleasepool{} __block __typeof__(x) __block_##x##__ = x; \
_Pragma("clang diagnostic pop")
#endif
#endif

#ifndef SG_strongify
#if __has_feature(objc_arc)
#define SG_strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
@try{} @finally{} __typeof__(x) x = __weak_##x##__; \
_Pragma("clang diagnostic pop")
#else

#define SG_strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
@try{} @finally{} __typeof__(x) x = __block_##x##__; \
_Pragma("clang diagnostic pop")
#endif
#endif

/** 判断iPhone X系列手机 */
#define SG_IS_IPHONE_X SG_IsIphoneX()
static inline BOOL SG_IsIphoneX(void) {
    if (UIDevice.currentDevice.userInterfaceIdiom != UIUserInterfaceIdiomPhone) return NO;
    if (@available(iOS 11.0, *)) {
        UIWindow *mainWindow = [[[UIApplication sharedApplication] delegate] window];
        if (mainWindow.safeAreaInsets.bottom > 0.0) {
            return YES;
        }
    }
    return NO;
}

#pragma mark - EMPTY

static inline BOOL SG_IsEmptyString(NSString * _Nullable string) {
    return (string == nil || [string isKindOfClass:NSNull.class] || [string isEqual:NSNull.null] || [string isEqualToString:@""]);
}

static inline BOOL SG_IsEmptyArray(NSArray * _Nullable array) {
    return (array == nil || [array isKindOfClass:NSNull.class] || [array isEqual:NSNull.null] || array.count == 0);
}

static inline BOOL SG_IsEmptyDictionary(NSDictionary * _Nullable dic) {
    return (dic == nil  || [dic isKindOfClass:NSNull.class]|| [dic isEqual:NSNull.null]);
}

static inline BOOL SG_IsEmptyObject(id _Nullable obj) {
    return (obj == nil || [obj isKindOfClass:NSNull.class] || [obj isEqual:NSNull.null]);
}

#pragma mark - FONT

#define SG_FONT_SIZE(size) SG_FontSize(size)
static inline UIFont * _Nonnull SG_FontSize(CGFloat size) {
    return [UIFont systemFontOfSize:size];
}

#define SG_BOLD_FONT_SIZE SG_BoldFontSize(size)
static inline UIFont * _Nonnull SG_BoldFontSize(CGFloat size) {
    return [UIFont boldSystemFontOfSize:size];
}

#pragma mark - COLOR

#define SG_RGB_A(r, g, b, a) SG_RgbA(r, g, b, a);
static inline UIColor * _Nonnull SG_RgbA(NSInteger r, NSInteger g, NSInteger b, CGFloat a) {
    return [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a];
}

#define SG_RGB(r, g, b) SG_Rgb(r, g, b)
static inline UIColor * _Nonnull SG_Rbg(NSInteger r, NSInteger g, NSInteger b) {
    return SG_RgbA(r, g, b, 1.0f);
}

#define SG_HEX_COLOR_A(c, a) SG_HexColorA(c, a)
static inline UIColor * _Nonnull SG_HexColorA(NSInteger c, CGFloat a) {
    return [UIColor colorWithRed:((c>>16)&0xFF)/255.0f green:((c>>8)&0xFF)/255.0f blue:(c&0xFF)/255.0f alpha:a];
}

#define SG_HEX_COLOR(c) SG_HexColor(c)
static inline UIColor * _Nonnull SG_HexColor(NSInteger c) {
    return SG_HexColorA(c, 1.0f);
}

#define SG_HEX_COLOR_STRING(rgbVaule) SG_HexColorString(rgbValue)
static inline UIColor * _Nonnull SG_HexColorString(NSString * _Nonnull rgbValue) {
    rgbValue = [rgbValue stringByReplacingOccurrencesOfString:@"#" withString:@""];
    return [UIColor colorWithRed:((float)((strtoul(rgbValue.UTF8String, 0, 16) & 0xFF0000) >> 16))/255.0 green:((float)((strtoul((rgbValue).UTF8String, 0, 16) & 0xFF00) >> 8))/255.0 blue:((float)(strtoul((rgbValue).UTF8String, 0, 16) & 0xFF))/255.0 alpha:1.0];
}

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
    return SG_TableViewHeight() - SG_TabbarHeight();
}

#pragma mark - PATH

/** 路径拼接 */
#define SG_PATH_APPEND_COMPONENT(path, lastPathComponent) SG_PathAppendComponent(path, lastPathComponent)
static inline NSString * _Nonnull SG_PathAppendComponent(NSString * _Nonnull path, NSString * _Nullable lastPathComponent) {
    if (!path && !lastPathComponent) return @"";
    if (lastPathComponent && ![lastPathComponent isEqualToString:@""]) {
        if ([lastPathComponent hasPrefix:@"/"]) {
            path = [path stringByAppendingString:lastPathComponent];
        } else {
            path = [path stringByAppendingPathComponent:lastPathComponent];
        }
    }
    return path;
}

#define SG_PATH_HOME_APPEND(lastPathComponent) SG_PathHomeAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathHomeAppend(NSString * _Nullable lastPathComponent) {
    NSString *homeTemp = NSHomeDirectory();
    return SG_PathAppendComponent(homeTemp, lastPathComponent);
}

#define SG_PATH_TEMP_APPEND(lastPathComponent) SG_PathTempAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathTempAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathTemp = NSTemporaryDirectory();
    return SG_PathAppendComponent(pathTemp, lastPathComponent);
}

#define SG_PATH_DOCUMENT_APPEND(lastPathComponent) SG_PathDocumentAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathDocumentAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathDocument = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathDocument, lastPathComponent);
}

#define SG_PATH_CACHE_APPEND(lastPathComponent) SG_PathCacheAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathCacheAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathCache = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathCache, lastPathComponent);
}

#define SG_PATH_LIBRARY_APPEND(lastPathComponent) SG_PathLibraryAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathLibraryAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathLibrary = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathLibrary, lastPathComponent);
}

#define SG_PATH_HOME SG_PathHome()
static inline NSString * _Nonnull SG_PathHome(void) {
    return SG_PathHomeAppend(nil);
}

#define SG_PATH_TEMP SG_PathTemp()
static inline NSString * _Nonnull SG_PathTemp(void) {
    return SG_PathTempAppend(nil);
}

#define SG_PATH_DOCUMENT SG_PathDocument()
static inline NSString * _Nonnull SG_PathDocument(void) {
    return SG_PathDocumentAppend(nil);
}

#define SG_PATH_CACHE SG_PathCache()
static inline NSString * _Nonnull SG_PathCache(void) {
    return SG_PathCacheAppend(nil);
}

#define SG_PATH_LIBRARY SG_PathLibrary()
static inline NSString * _Nonnull SG_PathLibrary(void) {
    return SG_PathLibraryAppend(nil);
}

#pragma mark - RADIANS

static inline CGFloat SG_DegreesToRadians(CGFloat degrees) {
    return degrees * M_PI / 180;
}
static inline CGFloat SG_RadiansToDegrees(CGFloat radians) {
    return radians * 180 / M_PI;
}

#endif /* SGCore_h */
