//
//  UIImage+SGCore.h
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (SGCore)

/** 生成一张纯色图片 */
+ (UIImage * (^)(UIColor *color))sg_imageWithColor;
/** 替换图片颜色 */
@property (nonatomic, copy, readonly) UIImage * (^sg_replaceImageColor)(UIColor *color);

@end

NS_ASSUME_NONNULL_END
