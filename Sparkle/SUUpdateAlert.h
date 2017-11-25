//
//  SUUpdateAlert.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/12/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUUPDATEALERT_H
#define SUUPDATEALERT_H

#import <Cocoa/Cocoa.h>
#import "SUVersionDisplayProtocol.h"

@protocol SUUpdateAlertDelegate;

typedef NS_ENUM(NSInteger, SUUpdateAlertChoice) {
    SUInstallUpdateChoice,
    SURemindMeLaterChoice,
    SUSkipThisVersionChoice,
    SUOpenInfoURLChoice
};

@class SUAppcastItem, SUHost;
@interface SUUpdateAlert : NSWindowController

@property (weak) id<SUVersionDisplay> versionDisplayer;

- (instancetype)initWithAppcastItem:(SUAppcastItem *)item host:(SUHost *)host completionBlock:(void(^)(SUUpdateAlertChoice))c;

- (IBAction)installUpdate:sender;
- (IBAction)skipThisVersion:sender;
- (IBAction)remindMeLater:sender;
- (void)disableKeyboardShortcutForInstallButton;

#pragma mark - StatusController

@property (weak) IBOutlet NSView *downloadView;
@property (weak) IBOutlet NSButton *actionButton;
@property (weak) IBOutlet NSProgressIndicator *progressBar;
@property (weak) IBOutlet NSTextField *statusTextField;

@property (copy) NSString *statusText;
@property double progressValue;
@property (nonatomic) double maxProgressValue;
@property (getter=isButtonEnabled) BOOL buttonEnabled;

// Pass 0 for the max progress value to get an indeterminate progress bar.
// Pass nil for the status text to not show it.
- (void)beginActionWithTitle:(NSString *)title maxProgressValue:(double)maxProgressValue statusText:(NSString *)statusText;

// If isDefault is YES, the button's key equivalent will be \r.
- (void)setButtonTitle:(NSString *)buttonTitle target:(id)target action:(SEL)action isDefault:(BOOL)isDefault;


@end

#endif
