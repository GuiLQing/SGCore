//
//  SGUtils.m
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import "SGUtils.h"
#import "SGUtilsMacros.h"

NSString * _Nonnull SG_HandleImageUrl(NSString * _Nonnull urlString) {
    NSError *error = nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"[\u4e00-\u9fa5]" options:NSRegularExpressionCaseInsensitive error:&error];
    if (!error) {
        NSArray *resultArray = [regex matchesInString:urlString options:0 range:NSMakeRange(0, urlString.length)];
        resultArray = [resultArray reverseObjectEnumerator].allObjects;
        for (NSTextCheckingResult *result in resultArray) {
            NSString *resultString = [urlString substringWithRange:result.range];
            urlString = [urlString stringByReplacingCharactersInRange:result.range withString:[resultString stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]]];
        }
    }
    return urlString;
}

void SG_GetVideoMIMITypeFromNSULRSession(NSURL * _Nonnull url, void (^ _Nullable callback)(NSString * _Nonnull MIMEType)) {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"HEAD"];
    [[NSURLSession.sharedSession downloadTaskWithRequest:request completionHandler:^(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (callback) callback(response.MIMEType);
    }] resume];
}

UIImage * _Nonnull SG_ImageWithFillColor(UIColor * _Nullable fillColor) {
    CGSize size = CGSizeMake(1.0f, 1.0f);
    CGRect rect = CGRectMake(0.0f, 0.0f, size.width, size.height);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [fillColor CGColor]);
    CGContextFillRect(context, rect);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

UIImage * _Nonnull SG_GradientImage(NSArray<UIColor *> * _Nonnull colors, NSArray<NSNumber *> * _Nullable locations, CGPoint startPoint, CGPoint endPoint) {
    NSMutableArray *colorsM = [NSMutableArray array];
    for (UIColor *color in colors) {
        [colorsM addObject:(__bridge id)color.CGColor];
    }
    CGFloat locationsM[locations.count];
    for (NSInteger i = 0; i < locations.count; i ++) {
        NSNumber *number = locations[i];
        locationsM[i] = number.floatValue;
    }
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(1, 1), YES, 0);
    // 创建Quartz上下文
    CGContextRef context = UIGraphicsGetCurrentContext();
    // 创建色彩空间对象
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    // 创建颜色数组
    CFArrayRef colorArray = (__bridge_retained CFArrayRef)colorsM;
    // 创建渐变对象
    CGGradientRef gradientRef = CGGradientCreateWithColors(colorSpaceRef, colorArray, locations ? locationsM : nil);
    // 释放颜色数组
    CFRelease(colorArray);
    // 释放色彩空间
    CGColorSpaceRelease(colorSpaceRef);
    CGContextDrawLinearGradient(context, gradientRef, startPoint, endPoint, 0);
    // 释放渐变对象
    CGGradientRelease(gradientRef);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

UIImage * _Nonnull SG_GradientHorizontalImage(NSArray<UIColor *> * _Nonnull colors) {
    return SG_GradientImage(colors, nil, CGPointMake(0, 1), CGPointMake(1, 1));
}

UIImage * _Nonnull SG_GradientVerticalImage(NSArray<UIColor *> * _Nonnull colors) {
    return SG_GradientImage(colors, nil, CGPointMake(1, 0), CGPointMake(1, 1));
}

NSString * _Nullable SG_ConvertToJsonString(id object) {
    if (SG_IsEmptyObject(object)) return nil;
    NSError *error;
    NSData *jsonData;
    if (@available(iOS 11.0, *)) {
        jsonData = [NSJSONSerialization dataWithJSONObject:object options:NSJSONWritingSortedKeys error:&error];
    } else {
        jsonData = [NSJSONSerialization dataWithJSONObject:object options:NSJSONWritingPrettyPrinted error:&error];
    }
    if (error) return nil;
    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}

id SG_ConvertToJsonObject(id object) {
    if (SG_IsEmptyObject(object)) return nil;
    if ([NSJSONSerialization isValidJSONObject:object]) return object;
    NSError *error;
    NSData *jsonData;
    if ([object isKindOfClass:NSString.class]) {
        jsonData = [object dataUsingEncoding:NSUTF8StringEncoding];
    } else {
        jsonData = object;
    }
    id obj = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error];
    if (error) return nil;
    return obj;
}
