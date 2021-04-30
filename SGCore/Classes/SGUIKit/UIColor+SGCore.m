//
//  UIColor+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import "UIColor+SGCore.h"
#import "NSString+SGCore.h"

@implementation UIColor (SGCore)

+ (UIColor * _Nonnull (^)(NSInteger, CGFloat))sg_hexColorA {
    return ^(NSInteger c, CGFloat a) {
        return [UIColor colorWithRed:((c>>16)&0xFF)/255.0f green:((c>>8)&0xFF)/255.0f blue:(c&0xFF)/255.0f alpha:a];
    };
}

+ (UIColor * _Nonnull (^)(NSInteger))sg_hexColor {
    return ^(NSInteger c) {
        return UIColor.sg_hexColorA(c, 1.0f);
    };
}

+ (UIColor * _Nonnull (^)(NSInteger, NSInteger, NSInteger, CGFloat))sg_rbgA {
    return ^(NSInteger r, NSInteger g, NSInteger b, CGFloat a) {
        return [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a];
    };
}

+ (UIColor * _Nonnull (^)(NSInteger, NSInteger, NSInteger))sg_rbg {
    return ^(NSInteger r, NSInteger g, NSInteger b) {
        return UIColor.sg_rbgA(r, g, b, 1.0f);
    };
}

+ (UIColor * _Nonnull (^)(NSString * _Nonnull, CGFloat))sg_hexColorStringA {
    return ^(NSString *value, CGFloat a) {
        value = value.sg_repleceString(@"#", @"").sg_repleceString(@"0X", @"").sg_repleceString(@"0x", @"");
        return [UIColor colorWithRed:((float)((strtoul(value.UTF8String, 0, 16) & 0xFF0000) >> 16))/255.0 green:((float)((strtoul((value).UTF8String, 0, 16) & 0xFF00) >> 8))/255.0 blue:((float)(strtoul((value).UTF8String, 0, 16) & 0xFF))/255.0 alpha:a];
    };
}

+ (UIColor * _Nonnull (^)(NSString * _Nonnull))sg_hexColorString {
    return ^(NSString *value) {
        return UIColor.sg_hexColorStringA(value, 1.0f);
    };
}

+ (UIColor *)sg_randomColor {
    return UIColor.sg_rbg(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256));
}

- (NSString *)sg_hexColorString {
    //颜色值个数，rgb和alpha
    NSInteger cpts = CGColorGetNumberOfComponents(self.CGColor);
    const CGFloat *components = CGColorGetComponents(self.CGColor);
    CGFloat r = components[0];//红色
    CGFloat g = components[1];//绿色
    CGFloat b = components[2];//蓝色
    if (cpts == 4) {
        CGFloat a = components[3];//透明度
        return [NSString stringWithFormat:@"#%02lX%02lX%02lX%02lX", lroundf(r * 255), lroundf(g * 255), lroundf(b * 255), lroundf(a * 255)];
    } else {
        return [NSString stringWithFormat:@"#%02lX%02lX%02lX", lroundf(r * 255), lroundf(g * 255), lroundf(b * 255)];
    }
}

@end
