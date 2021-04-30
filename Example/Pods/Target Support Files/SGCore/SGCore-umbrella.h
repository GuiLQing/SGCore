#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SGCore.h"
#import "NSArray+SGCore.h"
#import "NSDate+SGCore.h"
#import "NSDictionary+SGCore.h"
#import "NSObject+SGCore.h"
#import "NSString+SGCore.h"
#import "UIColor+SGCore.h"
#import "UIImage+SGCore.h"
#import "UIView+SGCore.h"

FOUNDATION_EXPORT double SGCoreVersionNumber;
FOUNDATION_EXPORT const unsigned char SGCoreVersionString[];

