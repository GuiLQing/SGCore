//
//  SGUtilsMacros.h
//  Pods
//
//  Created by SG on 2019/9/25.
//

#ifndef SGUtilsMacros_h
#define SGUtilsMacros_h

static inline BOOL SG_IsEmptyString(NSString * _Nullable string) {
    return (string == nil || [string isKindOfClass:NSNull.class] || [string isEqual:NSNull.null] || [string isEqualToString:@""]);
}

static inline BOOL SG_IsEmptyArray(NSArray * _Nullable array) {
    return (array == nil || [array isKindOfClass:NSNull.class] || [array isEqual:NSNull.null] || array.count == 0);
}

static inline BOOL SG_IsEmptyDictionary(NSDictionary * _Nullable dic) {
    return (dic == nil  || [dic isKindOfClass:NSNull.class]|| [dic isEqual:NSNull.null]);
}

static inline BOOL SG_IsEmptyObject(id _Nullable obj) {
    return (obj == nil || [obj isKindOfClass:NSNull.class] || [obj isEqual:NSNull.null]);
}

#endif /* SGUtilsMacros_h */
