//
//  MessagesBottomView.h
//  Messenger for Telegram
//
//  Created by Dmitry Kondratyev on 3/7/14.
//  Copyright (c) 2014 keepcoder. All rights reserved.
//

#import "TMView.h"
#import "TGImageAttachmentsController.h"
#import "TGInputMessageTemplate.h"
typedef enum {
    MessagesBottomViewNormalState,
    MessagesBottomViewActionsState,
    MessagesBottomViewBlockSecretState,
    MessagesBottomViewBlockChat
} MessagesBottomViewState;

@class MessagesViewController;

@interface MessagesBottomView : BTRControl<TMGrowingTextViewDelegate, NSMenuDelegate>


@property (nonatomic,strong) NSString *botStartParam;
@property (nonatomic, strong) RBLPopover *smilePopover;

@property (nonatomic) BOOL forwardEnabled;
@property (nonatomic) MessagesBottomViewState stateBottom;
@property (nonatomic, weak) MessagesViewController *messagesViewController;
@property (nonatomic, strong) TL_conversation *dialog;

@property (nonatomic,copy) dispatch_block_t onClickToLockedView;

@property (nonatomic, strong) MessageInputGrowingTextView *inputMessageTextField;

- (void)smileButtonClick:(BTRButton *)button;

- (void)setState:(MessagesBottomViewState)state animated:(BOOL)animated;
- (void)setSelectedSmileButton:(BOOL)selected;

- (void)setContextBotString:(NSString *)bot;

-(void)setTemplate:(TGInputMessageTemplate *)inputTemplate;
-(void)setTemplate:(TGInputMessageTemplate *)inputTemplate checkElements:(BOOL)checkElements;
-(void)updateText;

- (void)setInputMessageString:(NSString *)message disableAnimations:(BOOL)disableAnimations;
- (NSString *)inputMessageString;
- (void)setSectedMessagesCount:(NSUInteger)count enable:(BOOL)enable;

-(void)closeEmoji;
-(void)setProgress:(BOOL)progress;
-(void)updateReplayMessage:(BOOL)updateHeight animated:(BOOL)animated;
-(void)updateFwdMessage:(BOOL)updateHeight animated:(BOOL)animated;

-(void)updateWebpage:(BOOL)animated;

-(void)addAttachment:(TGImageAttachment *)attachment;

-(BOOL)sendMessageAsAdmin;

-(NSUInteger)attachmentsCount;

-(void)selectInputTextByText:(NSString *)text;

-(void)startOrStopQuickRecord;

- (void)insertEmoji:(NSString *)emoji;

-(BOOL)removeQuickRecord;
-(void)showQuickRecordedPreview:(NSString *)file audioAttr:(TL_documentAttributeAudio *)audioAttr;

-(void)paste:(id)sender;

@end
