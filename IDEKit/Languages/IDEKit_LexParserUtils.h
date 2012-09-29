//
//  IDEKit_LexParserUtils.h
//  IDEKit
//
//  Created by Glenn Andreas on 9/6/04.
//  Copyright (c) 2004 by Glenn Andreas
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Library General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Library General Public License for more details.
//  
//  You should have received a copy of the GNU Library General Public
//  License along with this library; if not, write to the Free
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#import "IDEKit_LexParser.h"


@interface IDEKit_LexToken : NSObject {
    NSString *mySource;
    NSRange myRange;
    NSInteger myKind;
}
- (NSString *) tokenStr;
- (NSInteger) token;
- (NSRange) range;
- (NSInteger) operator;
- (NSInteger) keyword;
- (NSInteger) preprocessor;
@end

@interface IDEKit_LexTokenEnumerator : NSEnumerator {
    NSString *mySource;
    IDEKit_LexParser *myLexer;
    BOOL myIgnoreWS;
}
+ (IDEKit_LexTokenEnumerator *) tokenEnumeratorForSource: (NSString *)source range: (NSRange) range lexer: (IDEKit_LexParser *)lexer ignoreWhiteSpace: (BOOL) ignoreWS;
@end;

@interface IDEKit_LexParser(Utils)
- (IDEKit_LexTokenEnumerator *) tokenEnumeratorForSource: (NSString *)source;
- (IDEKit_LexTokenEnumerator *) tokenEnumeratorForSource: (NSString *)source range: (NSRange) range ignoreWhiteSpace: (BOOL) ignoreWS;
@end
