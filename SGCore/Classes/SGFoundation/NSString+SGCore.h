//
//  NSString+SGCore.h
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (SGCore)

/** 字符串编码 */
- (NSString *)sg_encoding;
/** 字符串解码 */
- (NSString *)sg_decoding;
/** 去除首尾空格和换行 */
- (NSString *)sg_removeWhiteSpaceAndNewline;
/** 拼接字符串 */
@property (nonatomic, copy, readonly) NSString *(^sg_appendString)(NSString *string);
/** 拼接可变字符串 */
@property (nonatomic, copy, readonly) NSString *(^sg_appendFormat)(NSString *string, ...);
/** 替换字符串 */
@property (nonatomic, copy, readonly) NSString *(^sg_repleceString)(NSString *target, NSString *replacement);
/** 分割字符串 */
@property (nonatomic, copy, readonly) NSArray *(^sg_separatedString)(NSString *separator);
/** 反转字符串 */
- (NSString *)sg_reversedString;

@end

@interface NSString (SGHtml)

/** 过滤HTML标签 */
- (NSString *)sg_filterHtml;
/** 插入HTML移动端适配头部 */
- (NSString *)sg_insertHtmlHeader;
/** 移除HTML超链接标签 */
- (NSString *)sg_removeHtmlLinkLabels;
/** 判断当前是否存在超链接标签 */
- (BOOL)sg_isExistsHtmlLinkLabel;
/** 判断range范围内是否存在超链接标签 */
@property (nonatomic, copy, readonly) BOOL (^sg_isExistsHtmlLinkLableInRange)(NSRange range);
/** 匹配单词，获取单词范围 */
@property (nonatomic, copy, readonly) NSRange (^sg_rangeOfWord)(NSString *word);

@end

@interface NSString (SGValidate)

/** 判断是否为纯数字 */
- (BOOL)sg_isPureDigital;
/** 判断是否为纯字母 */
- (BOOL)sg_isPureLetters;
/** 判断是否为纯汉字 */
- (BOOL)sg_isPureChinese;
/** 判断minNum~maxNum位字母开头，只能包含“字母”，“数字”，“下划线” */
- (BOOL (^)(NSInteger minNum, NSInteger maxNum))sg_isPassword;
/** 验证手机号 */
- (BOOL)sg_isPhoneNumber;
/** 验证运营商:移动 */
- (BOOL)sg_isMobileOperator;
/** 验证运营商:联通 */
- (BOOL)sg_isUnicomOperator;
/** 验证运营商:电信 */
- (BOOL)sg_isTelecomOperator;
/** 验证邮箱 */
- (BOOL)sg_isEmail;
/** 验证车牌号 */
- (BOOL)sg_isLicensePlate;
/** 验证MAC地址 */
- (BOOL)sg_isMacAddress;

@end

@interface NSString (SGRegular)

/** HTML标签 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_HtmlLabel;
/** HTML超链接标签 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_HtmlLinkLabel;

/** 单词匹配，传入需要匹配的单词 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_WordMatching;

/** 纯数字 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_PureDigital;
/** 纯字母 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_PureLetters;
/** 纯中文 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_PureChinese;
/** 密码（只能包含“字母”，“数字”，“下划线”），位数传入最小值和最大值 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_Password;
/** 手机号 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_PhoneNumber;
/** 移动运营商 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_MobileOperator;
/** 联通运营商 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_UnicomOperator;
/** 电信运营商 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_TelecomOperator;
/** 邮箱 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_Email;
/** 车牌 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_LicensePlate;
/** MAC地址 */
FOUNDATION_EXTERN NSString * _Nonnull const SGRegularExpression_MacAddress;

/** 使用谓词匹配验证 */
@property (nonatomic, copy, readonly) BOOL (^sg_isRegexValidate)(NSString *regex);

@end

@interface NSString (SGEncrypt)

/** Hash序列 */
- (NSString *)sg_md5HashString;
/** MD5加密 */
@property (nonatomic, copy, readonly) NSString * (^sg_md5Encrypt)(NSString *string, NSString *encryptKey);
/** MD5解密 */
@property (nonatomic, copy, readonly) NSString * (^sg_md5Decrypt)(NSString *string, NSString *encryptKey);

@end

@interface NSString (SGDate)

@property (nonatomic, copy, readonly) NSDate * (^sg_stringToDate)(NSDateFormatter *formatter);

@end

NS_ASSUME_NONNULL_END
