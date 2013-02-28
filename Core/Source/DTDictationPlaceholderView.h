//
//  DTDictationPlaceholderView.h
//  DTRichTextEditor
//
//  Created by Oliver Drobnik on 05.02.13.
//  Copyright (c) 2013 Cocoanetics. All rights reserved.
//

#import "DTCompatibility.h"

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

@interface DTDictationPlaceholderView : DTView

/**
 Creates an appropriately sized DTDictationPlaceholderView with 3 animated purple dots
 */
+ (DTDictationPlaceholderView *)placeholderView;

/**
 The context of the receiver. This can be any object, for example the selection range to replace with the dictation result text
 */
@property (nonatomic, strong) id context;

@end
