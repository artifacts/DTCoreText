//
//  DTHTMLWriter.h
//  DTCoreText
//
//  Created by Oliver Drobnik on 23.12.12.
//  Copyright (c) 2012 Drobnik.com. All rights reserved.
//

/**
 Class to generate HTML from `NSAttributedString` instances.
 */
@interface DTHTMLWriter : NSObject {
	NSMutableDictionary *_styleLookup;
}

/**
 @name Creating an HTML Writer
 */

/**
 Creates a writer with a given `NSAttributedString` as input
 @param attributedString An attributed string
 */
- (id)initWithAttributedString:(NSAttributedString *)attributedString;

/**
 Creates a writer with a given `NSAttributedString` as input
 @param attributedString An attributed string
 @param CSSPrefix All generated CSS styles will be prefixed by this string
 */
- (id)initWithAttributedString:(NSAttributedString *)attributedString CSSPrefix:(NSString*)theCSSPrefix;

/**
 @name Generating HTML
 */

/**
 Generates a HTML representation of the attributed string
 @returns The generated string
 */
- (NSString *)HTMLString;

/**
 Generates a HTML representation of the attributed string by taking an existing style lookup map into account
 @param styleLookupMap An existing style lookup to give the developer the change to render multiple strings in one pass using the same CSS
 @param textProcessBlock A Block where you can change the generated Text before the tag is closed (e.g. to add characters before closing a paragraph)
 @returns The generated string
 */
- (NSString *)HTMLStringWithStyleLookupMap:(NSMutableDictionary*)styleLookupMap	textProcessBlock:(NSString*(^)(NSString *processedString, NSString *plainSubString, NSString *tag))updateStringBlock;

/**
 Generates a HTML fragment representation of the attributed string including inlined styles and no html or head elements
 @returns The generated string
 */
- (NSString *)HTMLFragment;

/**
 @name Properties
 */

/**
 If specified then all absolute font sizes (px) will be divided by this value. This is useful if you specified a text size multiplicator when converting HTML to the attributed string you are processing.
 */
@property (nonatomic, assign) CGFloat textScale;

/**
 If YES, preserve whitespaces in HTML by using "Apple-converted-space". Default YES.
 */
@property (nonatomic, assign) BOOL useAppleConvertedSpace;

/**
 The attributed string that the writer is processing.
 */
@property (nonatomic, readonly) NSAttributedString *attributedString;

/**
 The style lookup map.
 */
@property (nonatomic, readonly) NSMutableDictionary *styleLookup;

@end
