//
//  SGPathMacros.h
//  SGNetworking
//
//  Created by SG on 2019/9/20.
//  Copyright © 2019 SG. All rights reserved.
//

#ifndef SGPathMacros_h
#define SGPathMacros_h

/** 路径拼接 */
#define SG_PATH_APPEND_COMPONENT(path, lastPathComponent) SG_PathAppendComponent(path, lastPathComponent)
static inline NSString * _Nonnull SG_PathAppendComponent(NSString * _Nonnull path, NSString * _Nullable lastPathComponent) {
    if (!path && !lastPathComponent) return @"";
    if (lastPathComponent && ![lastPathComponent isEqualToString:@""]) {
        if ([lastPathComponent hasPrefix:@"/"]) {
            path = [path stringByAppendingString:lastPathComponent];
        } else {
            path = [path stringByAppendingPathComponent:lastPathComponent];
        }
    }
    return path;
}

#define SG_PATH_HOME_APPEND(lastPathComponent) SG_PathHomeAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathHomeAppend(NSString * _Nullable lastPathComponent) {
    NSString *homeTemp = NSHomeDirectory();
    return SG_PathAppendComponent(homeTemp, lastPathComponent);
}

#define SG_PATH_TEMP_APPEND(lastPathComponent) SG_PathTempAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathTempAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathTemp = NSTemporaryDirectory();
    return SG_PathAppendComponent(pathTemp, lastPathComponent);
}

#define SG_PATH_DOCUMENT_APPEND(lastPathComponent) SG_PathDocumentAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathDocumentAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathDocument = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathDocument, lastPathComponent);
}

#define SG_PATH_CACHE_APPEND(lastPathComponent) SG_PathCacheAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathCacheAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathCache = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathCache, lastPathComponent);
}

#define SG_PATH_LIBRARY_APPEND(lastPathComponent) SG_PathLibraryAppend(lastPathComponent)
static inline NSString * _Nonnull SG_PathLibraryAppend(NSString * _Nullable lastPathComponent) {
    NSString *pathLibrary = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject;
    return SG_PathAppendComponent(pathLibrary, lastPathComponent);
}

#define SG_PATH_HOME SG_PathHome()
static inline NSString * _Nonnull SG_PathHome(void) {
    return SG_PathHomeAppend(nil);
}

#define SG_PATH_TEMP SG_PathTemp()
static inline NSString * _Nonnull SG_PathTemp(void) {
    return SG_PathTempAppend(nil);
}

#define SG_PATH_DOCUMENT SG_PathDocument()
static inline NSString * _Nonnull SG_PathDocument(void) {
    return SG_PathDocumentAppend(nil);
}

#define SG_PATH_CACHE SG_PathCache()
static inline NSString * _Nonnull SG_PathCache(void) {
    return SG_PathCacheAppend(nil);
}

#define SG_PATH_LIBRARY SG_PathLibrary()
static inline NSString * _Nonnull SG_PathLibrary(void) {
    return SG_PathLibraryAppend(nil);
}

#endif /* SGPathMacros_h */
