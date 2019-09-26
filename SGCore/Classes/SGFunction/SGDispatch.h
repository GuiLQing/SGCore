//
//  SGDispatch.h
//  Pods-SGCore_Example
//
//  Created by SG on 2019/9/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^sg_dispatch_semaphore_signal)(void);
typedef void(^sg_dispatch_async_block)(sg_dispatch_semaphore_signal _Nullable sg_semaphore_signal);

/**
 并行事务操作，可变参数添加多个事务
 
 @param sg_main_completion_handler 所有并发事务完成主线程回调，每个事务处理完事件后需要手动调用sg_semaphore_signal()，不然会一直处于dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER)等待中
 */
UIKIT_EXTERN void SG_ParallelDispatchMainCompletionHandler(void (^ _Nullable sg_main_completion_handler)(void), sg_dispatch_async_block _Nullable block, ...) NS_REQUIRES_NIL_TERMINATION;

NS_ASSUME_NONNULL_END
