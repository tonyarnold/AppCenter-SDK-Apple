// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import "MSHttpClient.h"
#import <Foundation/Foundation.h>

@class MS_Reachability;

@interface MSHttpClient ()

/**
 * The HTTP session object.
 */
@property(nonatomic) NSURLSession *session;

/**
 * Reachability library object, which listens for changes in the network state.
 */
@property(nonatomic) MS_Reachability *reachability;

/**
 * Pending http calls.
 */
@property(nonatomic) NSMutableSet *pendingCalls;

/**
 * Time intervals between each retry, in seconds.
 */
@property(nonatomic) NSArray *retryIntervals;

/**
 * A boolean value set to YES if the client is paused or NO otherwise. While paused, the client will store new calls but not send them until
 * resumed.
 */
@property(nonatomic, getter=isPaused) BOOL paused;

/**
 * A boolean value set to YES if the client is enabled or NO otherwise. While disabled, the client will not store any calls.
 */
@property(nonatomic, getter=isEnabled) BOOL enabled;

/**
 * A boolean value set to YES if payload compression is enabled or NO otherwise.
 */
@property(nonatomic, getter=isCompressionEnabled) BOOL compressionEnabled;

/**
 * Configuration object for the NSURLSession. Need to store this because the session will need to be re-created after re-enabling the
 * client.
 */
@property(nonatomic) NSURLSessionConfiguration *sessionConfiguration;

@end
