//
//  NSDate+SGCore.h
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSInteger const SGSecond_Minute = 60;
static NSInteger const SGSecond_Hour   = SGSecond_Minute * 60;
static NSInteger const SGSecond_Day    = SGSecond_Hour * 24;
static NSInteger const SGSecond_Week   = SGSecond_Day * 7;
static NSInteger const SGSecond_Year   = SGSecond_Day * 365;

static NSInteger const SG_MilliTimeStamp = 1000;

static NSString * const SGStandardDateFormat = @"yyyy-MM-dd HH:mm:ss";

@interface NSDate (SGCore)

/** 格式化日期 */
+ (NSDateFormatter * _Nonnull (^)(NSString *format))sg_dateFormatter;
/** 时间戳转日期 */
+ (NSDate * (^)(NSInteger timestamp))sg_timestampToDate;
/** 秒数转时分秒 */
+ (NSString * _Nonnull (^)(NSInteger seconds))sg_secondsToHHmmss;
/** 通过日期格式得到时间 */
@property (nonatomic, copy, readonly) NSString * (^sg_dateToString)(NSDateFormatter *formatter);
/** 当前标准时间 */
+ (NSString * _Nonnull)sg_currentStandardDateString;
/** 获取时间戳 */
+ (NSInteger)sg_timestamp;
- (NSInteger)sg_timestamp;
+ (NSInteger)sg_timestampMillisecond;
- (NSInteger)sg_timestampMillisecond;

@end

@interface NSDate (SGCalendar)

/** 两个日期是否在同一天 */
@property (nonatomic, copy, readonly) BOOL (^sg_isSameDayToDate)(NSDate *date);
/** 指定的日期是否在今天 */
- (BOOL)sg_isToday;
/** 指定的日期是否在昨天 */
- (BOOL)sg_isYesterday;
/** 指定的日期是否在明天 */
- (BOOL)sg_isTomorrow;
/** 指定的日期是否在周末 */
- (BOOL)sg_isWeekend;
/** 返回当前时间组件 */
- (NSDateComponents *)sg_dateComponents;

@end

NS_ASSUME_NONNULL_END
