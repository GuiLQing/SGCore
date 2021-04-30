//
//  NSDate+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/14.
//

#import "NSDate+SGCore.h"

@implementation NSDate (SGCore)

+ (NSDateFormatter * (^)(NSString *))sg_dateFormatter {
    return ^(NSString *format) {
        static NSDateFormatter *_dateFormatter;
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            _dateFormatter = NSDateFormatter.new;
        });
        _dateFormatter.dateFormat = format;
        return _dateFormatter;
    };
}

+ (NSDate * (^)(NSInteger))sg_timestampToDate {
    return ^(NSInteger timestamp) {
        if (@(timestamp).stringValue.length == @(self.sg_timestampMillisecond).stringValue.length) {
            timestamp = timestamp / 1000;
        }
        return [NSDate dateWithTimeIntervalSince1970:timestamp];
    };
}

+ (NSString * (^)(NSInteger))sg_secondsToHHmmss {
    return ^(NSInteger seconds) {
        if (isnan(seconds) || seconds == NSNotFound || seconds <= 0) return @"00:00";
        
        NSInteger hours = seconds / SGSecond_Hour;
        NSInteger minutes = seconds / 60 % SGSecond_Minute;
        NSInteger second = seconds % SGSecond_Minute;
        if (hours <= 0) {
            return [NSString stringWithFormat:@"%02zd:%02zd", minutes, second];
        } else {
            return [NSString stringWithFormat:@"%02zd:%02zd:%02zd", hours, minutes, second];
        }
    };
}

- (NSString * (^)(NSDateFormatter *))sg_dateToString {
    return ^(NSDateFormatter *formatter) {
        return [formatter stringFromDate:self];
    };
}

+ (NSString *)sg_currentStandardDateString {
    return NSDate.date.sg_dateToString(NSDate.sg_dateFormatter(SGStandardDateFormat));
}

+ (NSInteger)sg_timestamp {
    return NSDate.date.timeIntervalSince1970;
}

- (NSInteger)sg_timestamp {
    return self.timeIntervalSince1970;
}

+ (NSInteger)sg_timestampMillisecond {
    return self.sg_timestamp * SG_MilliTimeStamp;
}

- (NSInteger)sg_timestampMillisecond {
    return self.sg_timestamp * SG_MilliTimeStamp;
}

@end

@implementation NSDate (SGCalendar)

- (BOOL (^)(NSDate *))sg_isSameDayToDate {
    return ^(NSDate *date) {
        return [NSCalendar.currentCalendar isDate:self inSameDayAsDate:date];
    };
}

- (BOOL)sg_isToday {
    return [NSCalendar.currentCalendar isDateInToday:self];
}

- (BOOL)sg_isYesterday {
    return [NSCalendar.currentCalendar isDateInYesterday:self];
}

- (BOOL)sg_isTomorrow {
    return [NSCalendar.currentCalendar isDateInTomorrow:self];
}

- (BOOL)sg_isWeekend {
    return [NSCalendar.currentCalendar isDateInWeekend:self];
}

- (NSDateComponents *)sg_dateComponents {
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond;
    return [NSCalendar.currentCalendar components:unit fromDate:self];
}

@end
