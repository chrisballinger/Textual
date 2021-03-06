/* ********************************************************************* 
                  _____         _               _
                 |_   _|____  _| |_ _   _  __ _| |
                   | |/ _ \ \/ / __| | | |/ _` | |
                   | |  __/>  <| |_| |_| | (_| | |
                   |_|\___/_/\_\\__|\__,_|\__,_|_|

 Copyright (c) 2008 - 2010 Satoshi Nakagawa <psychs AT limechat DOT net>
 Copyright (c) 2010 - 2015 Codeux Software, LLC & respective contributors.
        Please see Acknowledgements.pdf for additional information.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Textual and/or "Codeux Software, LLC", nor the 
      names of its contributors may be used to endorse or promote products 
      derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

 *********************************************************************** */

#import "TextualApplication.h"

NS_ASSUME_NONNULL_BEGIN

/* Properties to configure the renderer and provide additional
 context so that it can provide the best possible results. */
/* These properties do not apply to attributed strings */
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationRenderLinksAttribute; // BOOL
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationLineTypeAttribute; // TVCLogLineType
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationMemberTypeAttribute; // TVCLogMemberType
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationHighlightKeywordsAttribute; // NSArray<NSString *>
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationExcludedKeywordsAttribute; // NSArray<NSString *>
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationDoNotEscapeBodyAttribute; // BOOL

/* These properties apply to attributed strings */
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationAttributedStringPreferredFontAttribute; // NSFont
TEXTUAL_EXTERN NSString * const TVCLogRendererConfigurationAttributedStringPreferredFontColorAttribute; // NSColor

/* Properties that are returned in the outputDictionary of a render */
/* The output dictionary is not guaranteed to contain any key. */
TEXTUAL_EXTERN NSString * const TVCLogRendererResultsListOfLinksInBodyAttribute; // NSArray<AHHyperlinkScannerResult *>
TEXTUAL_EXTERN NSString * const TVCLogRendererResultsListOfLinksMappedInBodyAttribute; // NSDictionary<NSString *, NSString *>
TEXTUAL_EXTERN NSString * const TVCLogRendererResultsKeywordMatchFoundAttribute; // BOOL
TEXTUAL_EXTERN NSString * const TVCLogRendererResultsListOfUsersFoundAttribute; // NSSet<IRCChannelUser *>
TEXTUAL_EXTERN NSString * const TVCLogRendererResultsOriginalBodyWithoutEffectsAttribute; // NSString

@interface TVCLogRenderer : NSObject
+ (NSString *)escapeString:(NSString *)string;

+ (nullable NSColor *)mapColor:(id)color;
+ (NSColor *)mapColorCode:(NSUInteger)colorCode;

+ (nullable NSString *)renderTemplateNamed:(NSString *)templateName;
+ (nullable NSString *)renderTemplateNamed:(NSString *)templateName attributes:(nullable NSDictionary<NSString *, id> *)templateTokens;

+ (nullable NSString *)renderTemplate:(GRMustacheTemplate *)template;
+ (nullable NSString *)renderTemplate:(GRMustacheTemplate *)template attributes:(nullable NSDictionary<NSString *, id> *)templateTokens;

+ (NSAttributedString *)renderBodyAsAttributedString:(NSString *)body withAttributes:(NSDictionary<NSString *, id> *)inputDictionary;

+ (NSString *)renderBody:(NSString *)body
	   forViewController:(TVCLogController *)viewController
		  withAttributes:(NSDictionary<NSString *, id> *)inputDictionary
			  resultInfo:(NSDictionary<NSString *, id> * _Nullable * _Nullable)outputDictionary;
@end

NS_ASSUME_NONNULL_END
