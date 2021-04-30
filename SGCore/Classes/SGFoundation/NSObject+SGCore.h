//
//  NSObject+SGCore.h
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (SGCore)

@end

@interface NSObject (SGSwizzle)

/** 置换实例方法 */
+ (void (^)(SEL originSel, SEL swizzledSel))swizzleInstanceMethod;
/** 置换类方法 */
+ (void (^)(SEL originSel, SEL swizzledSel))swizzleClassMethod;

@end

NS_ASSUME_NONNULL_END
