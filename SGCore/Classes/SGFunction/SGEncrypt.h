//
//  SGEncrypt.h
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * _Nonnull SG_ReverseString(NSString * _Nonnull string);

UIKIT_EXTERN NSString * _Nonnull SG_MD5HashString(NSString * _Nonnull string);

UIKIT_EXTERN NSString * _Nonnull SG_EncryptString(NSString * _Nonnull string, NSString * _Nonnull encryptKey);

UIKIT_EXTERN NSString * _Nonnull SG_DecryptString(NSString * _Nonnull string, NSString * _Nonnull encryptKey);

NS_ASSUME_NONNULL_END
