//
//  UIColor+SGCore.h
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (SGCore)

+ (UIColor * _Nonnull (^)(NSInteger c, CGFloat a))sg_hexColorA;

+ (UIColor * _Nonnull (^)(NSInteger c))sg_hexColor;

+ (UIColor * _Nonnull (^)(NSInteger r, NSInteger g, NSInteger b, CGFloat a))sg_rbgA;

+ (UIColor * _Nonnull (^)(NSInteger r, NSInteger g, NSInteger b))sg_rbg;

+ (UIColor * _Nonnull (^)(NSString *value, CGFloat a))sg_hexColorStringA;

+ (UIColor * _Nonnull (^)(NSString *value))sg_hexColorString;

+ (UIColor *)sg_randomColor;

- (NSString * _Nonnull)sg_hexColorString;

@end

NS_ASSUME_NONNULL_END
