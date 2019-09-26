//
//  SGEncrypt.m
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import "SGEncrypt.h"
#import <CommonCrypto/CommonCrypto.h>

NSString * _Nonnull SG_ReverseString(NSString * _Nonnull string) {
    NSMutableString *reverseString;
    NSInteger len = string.length;
    // 给字符串分配一块内存空间
    reverseString = [NSMutableString stringWithCapacity:len];
    // 对字符串进行反转
    while (len > 0) {
        [reverseString appendString:[NSString stringWithFormat:@"%c",[string characterAtIndex:--len]]];
    }
    return reverseString;
}

NSString * _Nonnull SG_MD5HashString(NSString * _Nonnull string) {
    const char *original_str = [string UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(original_str, (CC_LONG)strlen(original_str), result);
    NSMutableString *hash = [NSMutableString string];
    for (int i = 0; i < 16; i++) {
        [hash appendFormat:@"%02X", result[i]];
    }
    NSString *mdfiveString = [hash lowercaseString];
    return mdfiveString;
}

NSString * _Nonnull SG_EncryptString(NSString * _Nonnull string, NSString * _Nonnull encryptKey) {
    //转化skey
    NSString *keyAfterMD5 = SG_MD5HashString(encryptKey);
    NSData *keyData = [keyAfterMD5 dataUsingEncoding:NSUTF8StringEncoding];
    Byte *keyByte = (Byte *)[keyData bytes];
    Byte key_S = keyByte[keyData.length-1];//skey
    
    //转化加密字符串
    NSData *strData = [string dataUsingEncoding:NSUTF8StringEncoding];
    Byte *strByte = (Byte *)[strData bytes];
    //遍历数组并异或
    NSMutableString *strF = [NSMutableString stringWithCapacity:5];
    for(int i = 0;i < [strData length] ; i++){
        strByte[i] = strByte[i]^key_S;
        [strF appendFormat:@"%03d",strByte[i]];
    }
    //逆序输出
    NSString *reverseStrF = SG_ReverseString(strF);
    return reverseStrF;
}

NSString * _Nonnull SG_DecryptString(NSString * _Nonnull string, NSString * _Nonnull encryptKey) {
    //转化skey
    NSString *keyAfterMD5 = SG_MD5HashString(encryptKey);
    NSData *keyData = [keyAfterMD5 dataUsingEncoding: NSUTF8StringEncoding];
    Byte *keyByte = (Byte *)[keyData bytes];
    Byte key_S = keyByte[keyData.length-1];//skey
    
    //字符串逆序
    int temp;
    NSMutableString *strRerverse = [NSMutableString stringWithCapacity:5];
    for(int i = (int)string.length-1 ; i>= 0; i--){
        temp = [string characterAtIndex:i];
        [strRerverse appendFormat:@"%c",temp];
    }
    //分割字符串
    Byte value[strRerverse.length/3];//定义字节数组
    
    for (int i=0, k=0; i<strRerverse.length; i+=3,k++) {
        NSRange range = NSMakeRange(i, 3);//i为开始点，3为取多少位
        temp = [[strRerverse substringWithRange:range]intValue];
        value[k] = temp ^ key_S;
    }
    NSData *adata = [[NSData alloc] initWithBytes:value length:strRerverse.length/3];
    NSString *strFin = [[NSString alloc] initWithData:adata encoding:NSUTF8StringEncoding];
    return strFin;
}
