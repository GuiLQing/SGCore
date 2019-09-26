//
//  SGSystemMacros.h
//  SGNetworking
//
//  Created by SG on 2019/9/20.
//  Copyright © 2019 SG. All rights reserved.
//

#ifndef SGSystemMacros_h
#define SGSystemMacros_h

//发布版本不输出调试信息
#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#define SGLog(format, ...) NSLog((@"文件名 : %s\n" "函数名 : %s  " "行号 : %d\n" format), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define NSLog(...) {}
#define SGLog(...) {}
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

#endif /* SGSystemMacros_h */
