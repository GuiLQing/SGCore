//
//  SGColorMacros.h
//  SGNetworking
//
//  Created by SG on 2019/9/20.
//  Copyright © 2019 SG. All rights reserved.
//

#ifndef SGColorMacros_h
#define SGColorMacros_h

#define SG_RGB_A(r, g, b, a) SG_RgbA(r, g, b, a);
static inline UIColor * _Nonnull SG_RgbA(NSInteger r, NSInteger g, NSInteger b, CGFloat a) {
    return [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a];
}

#define SG_RGB(r, g, b) SG_Rgb(r, g, b)
static inline UIColor * _Nonnull SG_Rbg(NSInteger r, NSInteger g, NSInteger b) {
    return SG_RgbA(r, g, b, 1.0f);
}

#define SG_HEX_COLOR_A(c, a) SG_HexColorA(c, a)
static inline UIColor * _Nonnull SG_HexColorA(NSInteger c, CGFloat a) {
    return [UIColor colorWithRed:((c>>16)&0xFF)/255.0f green:((c>>8)&0xFF)/255.0f blue:(c&0xFF)/255.0f alpha:a];
}

#define SG_HEX_COLOR(c) SG_HexColor(c)
static inline UIColor * _Nonnull SG_HexColor(NSInteger c) {
    return SG_HexColorA(c, 1.0f);
}

#define SG_HEX_COLOR_STRING(rgbVaule) SG_HexColorString(rgbValue)
static inline UIColor * _Nonnull SG_HexColorString(NSString * _Nonnull rgbValue) {
    rgbValue = [rgbValue stringByReplacingOccurrencesOfString:@"#" withString:@""];
    return [UIColor colorWithRed:((float)((strtoul(rgbValue.UTF8String, 0, 16) & 0xFF0000) >> 16))/255.0 green:((float)((strtoul((rgbValue).UTF8String, 0, 16) & 0xFF00) >> 8))/255.0 blue:((float)(strtoul((rgbValue).UTF8String, 0, 16) & 0xFF))/255.0 alpha:1.0];
}

#endif /* SGColorMacros_h */
