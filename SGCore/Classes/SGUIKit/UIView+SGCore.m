//
//  UIView+SGCore.m
//  Pods-SGCore_Example
//
//  Created by SG on 2020/1/13.
//

#import "UIView+SGCore.h"

@implementation UIView (SGCore)

#pragma mark - getter

- (CGSize)sg_size
{
    return self.frame.size;
}

- (CGPoint)sg_origin
{
    return self.frame.origin;
}

- (CGFloat)sg_x
{
    return self.sg_origin.x;
}

- (CGFloat)sg_y
{
    return self.sg_origin.y;
}

- (CGFloat)sg_width
{
    return self.sg_size.width;
}

- (CGFloat)sg_height
{
    return self.sg_size.height;
}

- (CGFloat)sg_centerX
{
    return self.center.x;
}

- (CGFloat)sg_centerY
{
    return self.center.y;
}

- (CGFloat)sg_top
{
    return self.sg_y;
}

- (CGFloat)sg_left
{
    return self.sg_x;
}

- (CGFloat)sg_bottom
{
    return CGRectGetMaxY(self.frame);
}

- (CGFloat)sg_right
{
    return CGRectGetMaxX(self.frame);
}

#pragma mark - setter

- (void)setSg_size:(CGSize)size
{
    CGRect frame = self.frame;
    frame.size = size;
    self.frame = frame;
}

- (void)setSg_origin:(CGPoint)origin
{
    CGRect frame = self.frame;
    frame.origin = origin;
    self.frame = frame;
}

- (void)setSg_x:(CGFloat)x
{
    self.sg_origin = CGPointMake(x, self.sg_y);
}

- (void)setSg_y:(CGFloat)y
{
    self.sg_origin = CGPointMake(self.sg_x, y);
}

- (void)setSg_width:(CGFloat)width
{
    self.sg_size = CGSizeMake(width, self.sg_height);
}

- (void)setSg_height:(CGFloat)height
{
    self.sg_size = CGSizeMake(self.sg_width, height);
}

- (void)setSg_centerX:(CGFloat)centerX
{
    self.center = CGPointMake(centerX, self.sg_centerY);
}

- (void)setSg_centerY:(CGFloat)centerY
{
    self.center = CGPointMake(self.sg_centerX, centerY);
}

- (void)setSg_top:(CGFloat)top
{
    self.sg_y = top;
}

- (void)setSg_left:(CGFloat)left
{
    self.sg_x = left;
}

- (void)setSg_bottom:(CGFloat)bottom
{
    CGFloat offsetY = bottom - self.sg_bottom;
    self.sg_y += offsetY;
}

- (void)setSg_right:(CGFloat)right
{
    CGFloat offsetX = right - self.sg_right;
    self.sg_x += offsetX;
}

#pragma mark - Set AnchorPoint

- (void)sg_setPosition:(CGPoint)point anchorPoint:(CGPoint)anchorPoint
{
    CGFloat x = point.x - anchorPoint.x * self.sg_width;
    CGFloat y = point.y - anchorPoint.y * self.sg_height;
    self.sg_origin = CGPointMake(x, y);
}

@end

@implementation UIView (SGClipsBounds)

- (UIView * _Nonnull (^)(UIRectCorner, CGFloat))sg_clipsToBounds {
    return ^(UIRectCorner corners, CGFloat cornerRadius) {
        UIBezierPath *bezierPath = [UIBezierPath bezierPathWithRoundedRect:self.bounds byRoundingCorners:corners cornerRadii:CGSizeMake(cornerRadius, cornerRadius)];
        CAShapeLayer *maskLayer = CAShapeLayer.layer;
        maskLayer.frame = self.bounds;
        maskLayer.path = bezierPath.CGPath;
        self.layer.mask = maskLayer;
        return self;
    };
}

@end
