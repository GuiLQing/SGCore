//
//  NSString+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/13.
//

#import "NSString+SGCore.h"
#import <CommonCrypto/CommonCrypto.h>

@implementation NSString (SGCore)

- (NSString *)sg_encoding {
    return [self stringByAddingPercentEncodingWithAllowedCharacters:NSCharacterSet.URLQueryAllowedCharacterSet];
}

- (NSString *)sg_decoding {
    return self.stringByRemovingPercentEncoding;
}

- (NSString *)sg_removeWhiteSpaceAndNewline {
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

- (NSString * _Nonnull (^)(NSString * _Nonnull))sg_appendString {
    return ^(NSString *string) {
        return [self stringByAppendingString:string];
    };
}

- (NSString * _Nonnull (^)(NSString * _Nonnull, ...))sg_appendFormat {
    return ^(NSString *format, ...) NS_FORMAT_FUNCTION(1, 2) {
        va_list args;
        va_start(args, format);
        NSString *result = [[NSString alloc] initWithFormat:format arguments:args];
        va_end(args);
        return [self stringByAppendingString:result];
    };
}

- (NSString * _Nonnull (^)(NSString * _Nonnull, NSString * _Nonnull))sg_repleceString {
    return ^(NSString *target, NSString *replacement) {
        return [self stringByReplacingOccurrencesOfString:target withString:replacement];
    };
}

- (NSArray * _Nonnull (^)(NSString * _Nonnull))sg_separatedString {
    return ^(NSString *separator) {
        return [self componentsSeparatedByString:separator];
    };
}

- (NSString *)sg_reversedString {
    NSInteger len = self.length;
    // 给字符串分配一块内存空间
    NSMutableString *reverseString = [NSMutableString stringWithCapacity:len];
    // 对字符串进行反转
    while (len > 0) {
        [reverseString appendString:[NSString stringWithFormat:@"%c",[self characterAtIndex:--len]]];
    }
    return reverseString;
}

@end

@implementation NSString (SGHtml)

- (NSString *)sg_filterHtml {
    NSRegularExpression *regularExpretion = [NSRegularExpression regularExpressionWithPattern:SGRegularExpression_HtmlLabel options:NSRegularExpressionCaseInsensitive error:nil];
    return [regularExpretion stringByReplacingMatchesInString:self options:NSMatchingReportProgress range:NSMakeRange(0, self.length) withTemplate:@""];
}

- (NSString *)sg_insertHtmlHeader {
    NSString *header = @"<header><meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no'><style>img{max-width:100%}</style></header>";
    return [header stringByAppendingString:header];
}

- (NSString *)sg_removeHtmlLinkLabels {
    NSRegularExpression *expression = [NSRegularExpression regularExpressionWithPattern:SGRegularExpression_HtmlLinkLabel options:NSRegularExpressionCaseInsensitive error:nil];
    return [expression stringByReplacingMatchesInString:self options:NSMatchingReportProgress range:NSMakeRange(0, self.length) withTemplate:@""];
}

- (BOOL)sg_isExistsHtmlLinkLabel {
    return self.sg_isExistsHtmlLinkLableInRange(NSMakeRange(0, self.length));
}

- (BOOL (^)(NSRange))sg_isExistsHtmlLinkLableInRange {
    return ^(NSRange range) {
        NSRegularExpression *expression = [NSRegularExpression regularExpressionWithPattern:SGRegularExpression_HtmlLinkLabel options:NSRegularExpressionCaseInsensitive error:nil];
        __block BOOL isExists = NO;
        [expression enumerateMatchesInString:self options:NSMatchingReportCompletion range:range usingBlock:^(NSTextCheckingResult * _Nullable result, NSMatchingFlags flags, BOOL * _Nonnull stop) {
            if (result && NSLocationInRange(range.location, result.range)) {
                isExists = YES;
                *stop = YES;
            }
        }];
        return isExists;
    };
}

- (NSRange (^)(NSString * _Nonnull))sg_rangeOfWord {
    return ^(NSString *word) {
        NSError *error = nil;
        NSString *pattern = [NSString stringWithFormat:SGRegularExpression_WordMatching, word];
        NSRegularExpression *regular = [NSRegularExpression regularExpressionWithPattern:pattern options:NSRegularExpressionCaseInsensitive error:&error];
        __block NSRange range = NSMakeRange(NSNotFound, 0);
        if (!error && regular) {
            [regular enumerateMatchesInString:self options:NSMatchingReportCompletion range:NSMakeRange(0, self.length) usingBlock:^(NSTextCheckingResult * _Nullable result, NSMatchingFlags flags, BOOL * _Nonnull stop) {
                if (!self.sg_isExistsHtmlLinkLableInRange(result.range)) {
                    range = result.range;
                    *stop = YES;
                }
            }];
        }
        return range;
    };
}

@end

@implementation NSString (SGValidate)

- (BOOL)sg_isPureDigital {
    return self.sg_isRegexValidate(SGRegularExpression_PureDigital);
}

- (BOOL)sg_isPureLetters {
    return self.sg_isRegexValidate(SGRegularExpression_PureLetters);
}

- (BOOL)sg_isPureChinese {
    return self.sg_isRegexValidate(SGRegularExpression_PureChinese);
}

- (BOOL (^)(NSInteger, NSInteger))sg_isPassword {
    return ^(NSInteger minNum, NSInteger maxNum) {
        return self.sg_isRegexValidate([NSString stringWithFormat:SGRegularExpression_Password, minNum, maxNum]);
    };
}

- (BOOL)sg_isPhoneNumber {
    return self.sg_isRegexValidate(SGRegularExpression_PhoneNumber);
}

- (BOOL)sg_isMobileOperator {
    return self.sg_isRegexValidate(SGRegularExpression_MobileOperator);
}

- (BOOL)sg_isUnicomOperator {
    return self.sg_isRegexValidate(SGRegularExpression_UnicomOperator);
}

- (BOOL)sg_isTelecomOperator {
    return self.sg_isRegexValidate(SGRegularExpression_TelecomOperator);
}

- (BOOL)sg_isEmail {
    return self.sg_isRegexValidate(SGRegularExpression_Email);
}

- (BOOL)sg_isLicensePlate {
    return self.sg_isRegexValidate(SGRegularExpression_LicensePlate);
}

- (BOOL)sg_isMacAddress {
    return self.sg_isRegexValidate(SGRegularExpression_MacAddress);
}

@end

@implementation NSString (SGRegular)

/** HTML标签 */
NSString * const SGRegularExpression_HtmlLabel = @"</?[^>]+>";
/** HTML超链接标签 */
NSString * const SGRegularExpression_HtmlLinkLabel = @"<a href=(?:.*?)>(.*?)<\\/a>";

/** 单词匹配 */
NSString * const SGRegularExpression_WordMatching = @"(\"|'|\\s|\\b){1}(?<word>%@)(d|ed|s|es|er|ers|ing)?(,|\\.|\\?|'|\"|\\s){1}";

/** 纯数字 */
NSString * const SGRegularExpression_PureDigital = @"[0-9]*";
/** 纯字母 */
NSString * const SGRegularExpression_PureLetters = @"[a-zA-Z]*";
/** 纯中文 */
NSString * const SGRegularExpression_PureChinese = @"[\u4e00-\u9fa5]+";
/** 密码（只能包含“字母”，“数字”，“下划线”），位数传入最小值和最大值 */
NSString * const SGRegularExpression_Password = @"^([a-zA-Z]|[a-zA-Z0-9_]|[0-9]){%zd,%zd}$";
/** 手机号 */
NSString * const SGRegularExpression_PhoneNumber = @"^1(3[0-9]|4[57]|5[0-35-9]|8[0-9]|7[0678])\\d{8}$";
/** 移动运营商 */
NSString * const SGRegularExpression_MobileOperator = @"^((13[4-9])|(147)|(15[0-2,7-9])|(178)|(18[2-4,7-8]))\\d{8}|(1705)\\d{7}$";
/** 联通运营商 */
NSString * const SGRegularExpression_UnicomOperator = @"^((13[0-2])|(145)|(15[5-6])|(176)|(18[5,6]))\\d{8}|(1709)\\d{7}$";
/** 电信运营商 */
NSString * const SGRegularExpression_TelecomOperator = @"(^1(33|53|77|8[019])\\d{8}$)|(^1700\\d{7}$)";
/** 邮箱 */
NSString * const SGRegularExpression_Email = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
/** 车牌 */
NSString * const SGRegularExpression_LicensePlate = @"^[\\u4e00-\\u9fff]{1}[a-zA-Z]{1}[-][a-zA-Z_0-9]{4}[a-zA-Z_0-9_\\u4e00-\\u9fff]$";
/** MAC地址 */
NSString * const SGRegularExpression_MacAddress = @"([A-Fa-f\\\\d]{2}:){5}[A-Fa-f\\\\d]{2}";

- (BOOL (^)(NSString * _Nonnull))sg_isRegexValidate {
    return ^(NSString *regex) {
        return [[NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex] evaluateWithObject:self];
    };
}

@end

@implementation NSString (SGEncrypt)

- (NSString *)sg_md5HashString {
    const char *original_str = self.UTF8String;
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(original_str, (CC_LONG)strlen(original_str), result);
    NSMutableString *hash = [NSMutableString string];
    for (int i = 0; i < 16; i++) {
        [hash appendFormat:@"%02X", result[i]];
    }
    NSString *mdfiveString = hash.lowercaseString;
    return mdfiveString;
}

- (NSString * _Nonnull (^)(NSString * _Nonnull, NSString * _Nonnull))sg_md5Encrypt {
    return ^(NSString *string, NSString *encryptKey) {
        //转化skey
        NSString *keyAfterMD5 = encryptKey.sg_md5HashString;
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
        NSString *reverseStrF = strF.sg_reversedString;
        return reverseStrF;
    };
}

- (NSString * _Nonnull (^)(NSString * _Nonnull, NSString * _Nonnull))sg_md5Decrypt {
    return ^(NSString *string, NSString *encryptKey) {
        //转化skey
        NSString *keyAfterMD5 = encryptKey.sg_md5HashString;
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
    };
}

@end

@implementation NSString (SGDate)

- (NSDate * _Nonnull (^)(NSDateFormatter * _Nonnull))sg_stringToDate {
    return ^(NSDateFormatter *formatter) {
        return [formatter dateFromString:self];
    };
}

@end
