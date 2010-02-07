/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2010 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import "TiProxy.h"
#import "Bridge.h"
#import "TiEvaluator.h"

@interface TiHost : NSObject 
{
	NSMutableDictionary *modules;
	NSMutableDictionary *proxies;
	NSMutableDictionary *contexts;
	NSURL *startURL;
	NSURL *baseURL;
}

-(NSString*)appID;
-(NSURL*)baseURL;
-(NSURL*)startURL;

-(id)moduleNamed:(NSString*)name;

-(void)fireEvent:(id)listener withObject:(id)obj remove:(BOOL)remove context:(id<TiEvaluator>)context thisObject:(TiProxy*)thisObject_;
-(void)removeListener:(id)listener context:(id<TiEvaluator>)context;
-(void)evaluateJS:(NSString*)js context:(id<TiEvaluator>)context;

-(void)registerProxy:(TiProxy*)proxy;
-(void)unregisterProxy:(NSString*)proxyid;
-(TiProxy*)proxyForId:(NSString*)proxyid;

-(void)registerContext:(id<TiEvaluator>)context forToken:(NSString*)token;
-(void)unregisterContext:(id<TiEvaluator>)context forToken:(NSString*)token;
-(id<TiEvaluator>)contextForToken:(NSString*)token;

@end