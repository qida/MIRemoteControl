//
//  GestureManager.h
//  Wisetv_2x
//
//  Created by ran on 14-7-23.
//  Copyright (c) 2014年 tjgdMobilez. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MonitorResultType) {
    MonitorResultTypeNone = 0,
    MonitorResultTypeLeft,
    MonitorResultTypeRight,
    MonitorResultTypeUpwards,
    MonitorResultTypeDownwards,
    MonitorResultTypeHome,
    MonitorResultTypeMenu,
    MonitorResultTypeBack,
    MonitorResultTypeChosen
};

@protocol MIGestureManagerDelegate;
@interface MIGestureManager : NSObject

@property (nonatomic, weak) id<MIGestureManagerDelegate> delegate;

@property (nonatomic, readonly) UIImageView *upImageView;
@property (nonatomic, readonly) UIImageView *downImageView;
@property (nonatomic, readonly) UIImageView *leftImageView;
@property (nonatomic, readonly) UIImageView *rightImageView;
@property (nonatomic, readonly) UIImageView *homeImageView;
@property (nonatomic, readonly) UIImageView *backImageView;
@property (nonatomic, readonly) UIImageView *menuImageView;
@property (nonatomic, readonly) UIImageView *chosenImageView;

@property (nonatomic, assign, readonly) CGPoint lastPoint;

+ (instancetype)sharedManager;

- (void)preloadResources;
- (void)clearMemory;

- (void)beginMonitorWithPoint:(CGPoint)point;
- (void)updateMonitorWithPoint:(CGPoint)point action:(dispatch_block_t)actionBlock;
- (void)endMonitor;
- (void)endMotion;

- (UIImageView *)dequeueReusableImageView;
- (void)enqueueReusableImageView:(UIImageView *)imageView;

@end

@protocol MIGestureManagerDelegate <NSObject>

@optional
- (void)gestureManagerMonitorResult:(MonitorResultType)resultType;

@end
