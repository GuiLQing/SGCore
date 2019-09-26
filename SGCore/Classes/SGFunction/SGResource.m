//
//  SGResource.m
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import "SGResource.h"
#import "SGUtilsMacros.h"
#import "SGPathMacros.h"

@interface SGBundleResource : NSObject

@end

@implementation SGBundleResource

@end

NSBundle * _Nonnull SG_Bundle(NSString * _Nullable bundleName) {
    NSString *bundle = SG_IsEmptyString(bundleName) ? @"SGBundle" : bundleName;
    return [NSBundle bundleWithPath:[[NSBundle bundleForClass:SGBundleResource.class] pathForResource:bundle ofType:@"bundle"]];
}

NSString * _Nonnull SG_BundlePathForResource(NSString * _Nullable bundleName, NSString * _Nonnull resourceName) {
    return SG_PathAppendComponent(SG_Bundle(bundleName).resourcePath, resourceName);
}

UIImage * _Nonnull SG_ImageNameWithBundleName(NSString * _Nonnull imageName, NSString * _Nullable directory, NSString * _Nullable bundleName) {
    NSString *imagePath = SG_IsEmptyString(directory) ? imageName : SG_PathAppendComponent(directory, imageName);
    return [UIImage imageNamed:SG_BundlePathForResource(bundleName, imagePath)];
}

UIImage * _Nonnull SG_ImageNameWithDir(NSString * _Nonnull imageName, NSString * _Nullable directory) {
    return SG_ImageNameWithBundleName(imageName, directory, nil);
}

UIImage * _Nonnull SG_ImageName(NSString * _Nonnull imageName) {
    return SG_ImageNameWithDir(imageName, nil);
}

UIImage * _Nonnull SG_ImageContentsFileWithBundleName(NSString * _Nonnull imageName, NSString * _Nullable directory, NSString * _Nullable bundleName) {
    NSString *imagePath = SG_IsEmptyString(directory) ? imageName : SG_PathAppendComponent(directory, imageName);
    return [UIImage imageWithContentsOfFile:SG_BundlePathForResource(bundleName, imagePath)];
}

UIImage * _Nonnull SG_ImageContentsFileWithDir(NSString * _Nonnull imageName, NSString * _Nullable directory) {
    return SG_ImageContentsFileWithBundleName(imageName, directory, nil);
}

UIImage * _Nonnull SG_ImageContentsFile(NSString * _Nonnull imageName) {
    return SG_ImageContentsFileWithDir(imageName, nil);
}
