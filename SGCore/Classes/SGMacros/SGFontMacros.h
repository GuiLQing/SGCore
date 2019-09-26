//
//  SGFontMacros.h
//  SGNetworking
//
//  Created by SG on 2019/9/20.
//  Copyright © 2019 SG. All rights reserved.
//

#ifndef SGFontMacros_h
#define SGFontMacros_h

#define SG_FONT_SIZE(size) SG_FontSize(size)
static inline UIFont * _Nonnull SG_FontSize(CGFloat size) {
    return [UIFont systemFontOfSize:size];
}

#define SG_BOLD_FONT_SIZE SG_BoldFontSize(size)
static inline UIFont * _Nonnull SG_BoldFontSize(CGFloat size) {
    return [UIFont boldSystemFontOfSize:size];
}

#endif /* SGFontMacros_h */
