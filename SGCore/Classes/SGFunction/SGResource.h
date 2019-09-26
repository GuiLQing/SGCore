//
//  SGResource.h
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - BUNDLE

UIKIT_EXTERN NSBundle * _Nonnull SG_Bundle(NSString * _Nullable bundleName);

UIKIT_EXTERN NSString * _Nonnull SG_BundlePathForResource(NSString * _Nullable bundleName, NSString * _Nonnull resourceName);

#pragma mark - IMAGE_NAME

UIKIT_EXTERN UIImage * _Nonnull SG_ImageNameWithBundleName(NSString * _Nonnull imageName, NSString * _Nullable directory, NSString * _Nullable bundleName);

UIKIT_EXTERN UIImage * _Nonnull SG_ImageNameWithDir(NSString * _Nonnull imageName, NSString * _Nullable directory);

UIKIT_EXTERN UIImage * _Nonnull SG_ImageName(NSString * _Nonnull imageName);

#pragma mark - IMAGE_CONTENTS_FILE

UIKIT_EXTERN UIImage * _Nonnull SG_ImageContentsFileWithBundleName(NSString * _Nonnull imageName, NSString * _Nullable directory, NSString * _Nullable bundleName);

UIKIT_EXTERN UIImage * _Nonnull SG_ImageContentsFileWithDir(NSString * _Nonnull imageName, NSString * _Nullable directory);

UIKIT_EXTERN UIImage * _Nonnull SG_ImageContentsFile(NSString * _Nonnull imageName);

NS_ASSUME_NONNULL_END
