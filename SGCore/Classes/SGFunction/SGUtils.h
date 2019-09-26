//
//  SGUtils.h
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 处理带有中文的图片链接utf8编码，使用了正则表达式判断，如果没有中文则原样返回 */
UIKIT_EXTERN NSString * _Nonnull SG_HandleImageUrl(NSString * _Nonnull urlString);

/** 判断链接资源类型 */
UIKIT_EXTERN void SG_GetVideoMIMITypeFromNSULRSession(NSURL * _Nonnull url, void (^ _Nullable callback)(NSString * _Nonnull MIMEType));

/** 绘制一张纯色图片 */
UIKIT_EXTERN UIImage * _Nonnull SG_ImageWithFillColor(UIColor * _Nullable fillColor);

/** 绘制渐变图片 */
UIImage * _Nonnull SG_GradientImage(NSArray<UIColor *> * _Nonnull colors, NSArray<NSNumber *> * _Nullable locations, CGPoint startPoint, CGPoint endPoint);
UIImage * _Nonnull SG_HorizontalGradientImage(NSArray<UIColor *> * _Nonnull colors);
UIImage * _Nonnull SG_VerticalGradientImage(NSArray<UIColor *> * _Nonnull colors);

UIKIT_EXTERN NSString * _Nullable SG_JsonString(id object);

UIKIT_EXTERN id SG_JsonObject(id object);

NS_ASSUME_NONNULL_END
