//
//  QMLinkPreviewManager.h
//  Pods
//
//  Created by Vitaliy Gurkovsky on 4/3/17.
//
//

#import "QMMemoryStorageProtocol.h"

@class QMLinkPreview;
@class QMLinkPreviewMemoryStorage;

@protocol QMLinkPreviewManagerDelegate;

typedef void(^QMLinkPreviewCompletionBlock)(BOOL sucess);


NS_ASSUME_NONNULL_BEGIN

@interface QMLinkPreviewManager : NSObject <QMMemoryStorageProtocol>

/**
 Memory storage for QMLinkPreview
 */
@property (nonatomic, strong) QMLinkPreviewMemoryStorage *memoryStorage;

/**
 Delegate
 */
@property (nonatomic, weak) id <QMLinkPreviewManagerDelegate> delegate;

/**
 Download,create and cache QMLinkPreview instance

 @param message message
 @param completion completion
 */
- (void)downloadLinkPreviewForMessage:(QBChatMessage *)message
                       withCompletion:(nullable QMLinkPreviewCompletionBlock)completion;

/**
 Method returns cached instance of QMLinkPreview class

 @param message message
 @return cached instance of QMLinkPreview class
 */
- (QMLinkPreview *)linkPreviewForMessage:(QBChatMessage *)message;

@end

@protocol QMLinkPreviewManagerDelegate <NSObject>

- (void)linkPreviewManager:(QMLinkPreviewManager *)linkPreview didAddLinkPreviewToMemoryStorage:(QMLinkPreview *)linkPreview;

- (QMLinkPreview *)cachedLinkPreviewForURLKey:(NSString *)urlKey;

@end

NS_ASSUME_NONNULL_END
