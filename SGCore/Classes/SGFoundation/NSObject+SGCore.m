//
//  NSObject+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import "NSObject+SGCore.h"
#import <objc/runtime.h>

@implementation NSObject (SGCore)

@end

@implementation NSObject (SGSwizzle)

+ (void (^)(SEL originSel, SEL swizzledSel))swizzleInstanceMethod {
    return ^(SEL originSel, SEL swizzledSel) {
        Class class = self.class;
        Method originalMethod = class_getInstanceMethod(class, originSel);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSel);
        // 若已经存在，则添加会失败
        BOOL didAddMethod = class_addMethod(class,
                                            originSel,
                                            method_getImplementation(swizzledMethod),
                                            method_getTypeEncoding(swizzledMethod));
        // 若原来的方法并不存在，则添加即可
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSel,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    };
}

+ (void (^)(SEL originSel, SEL swizzledSel))swizzleClassMethod {
    return ^(SEL originSel, SEL swizzledSel) {
        Class class = self.class;
        Method originalMethod = class_getClassMethod(class, originSel);
        Method swizzledMethod = class_getClassMethod(class, swizzledSel);
        // 若已经存在，则添加会失败
        BOOL didAddMethod = class_addMethod(class,
                                            originSel,
                                            method_getImplementation(swizzledMethod),
                                            method_getTypeEncoding(swizzledMethod));
        // 若原来的方法并不存在，则添加即可
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSel,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    };
}

@end
