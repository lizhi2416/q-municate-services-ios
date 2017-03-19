#import "CDAttachment.h"

@implementation CDAttachment

- (QBChatAttachment *)toQBChatAttachment {
    
    QBChatAttachment *attachment = [[QBChatAttachment alloc] init];
    
    attachment.name = self.name;
    attachment.ID = self.id;
    attachment.url = self.url;
    attachment.type = self.mimeType;
    attachment.data = self.data;
   
    return attachment;
}

- (void)updateWithQBChatAttachment:(QBChatAttachment *)attachment {
    
    self.name = attachment.name;
    self.id = attachment.ID;
    self.url = attachment.url;
    self.mimeType = attachment.type;
    self.data = attachment.data;
}

@end
