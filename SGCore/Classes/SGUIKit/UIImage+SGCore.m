//
//  UIImage+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import "UIImage+SGCore.h"

@implementation UIImage (SGCore)

+ (UIImage * _Nonnull (^)(UIColor * _Nonnull))sg_imageWithColor {
    return ^(UIColor *color) {
        CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
        UIGraphicsBeginImageContext(rect.size);
        CGContextRef context = UIGraphicsGetCurrentContext();
        CGContextSetFillColorWithColor(context, [color CGColor]);
        CGContextFillRect(context, rect);
        UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        return image;
    };
}

- (UIImage * _Nonnull (^)(UIColor * _Nonnull))sg_replaceImageColor {
    return ^(UIColor *color) {
        UIGraphicsBeginImageContextWithOptions(self.size, NO, self.scale);
        CGContextRef context = UIGraphicsGetCurrentContext();
        CGContextTranslateCTM(context, 0, self.size.height);
        CGContextScaleCTM(context, 1.0, -1.0);
        CGContextSetBlendMode(context, kCGBlendModeNormal);
        CGRect rect = CGRectMake(0, 0, self.size.width, self.size.height);
        CGContextClipToMask(context, rect, self.CGImage);
        [color setFill];
        CGContextFillRect(context, rect);
        UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        return newImage;
    };
}

@end
