/*
 * Copyright (c) Microsoft Corporation. All rights reserved.
 */

#import "AVAEventLog.h"

static NSString *const kAVATypeEvent = @"event";

static NSString *const kAVAId = @"id";
static NSString *const kAVAName = @"name";

@implementation AVAEventLog

- (instancetype)init {
  if (self = [super init]) {
    self.type = kAVATypeEvent;
  }
  return self;
}

- (void)write:(NSMutableDictionary *)dic {
  [super write:dic];
  
  if (self.eventId)
    dic[kAVAId] = [self.eventId UUIDString];
  
  if (self.name)
    dic[kAVAName] = self.name;
}

- (void)read:(NSDictionary *)obj {
  [super read:obj];
  
  // Set properties
  self.name = obj[kAVAName];
  self.eventId = [[NSUUID alloc] initWithUUIDString:obj[kAVAId]];
}

- (BOOL)isValid {
  return [super isValid];
}

@end