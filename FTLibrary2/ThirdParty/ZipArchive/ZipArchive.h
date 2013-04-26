//
//  ZipArchive.h
//  
//
//  Created by aish on 08-9-11.
//  acsolu@gmail.com
//  Copyright 2008  Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "minizip/zip.h"
#include "minizip/unzip.h"


@protocol ZipArchiveDelegate <NSObject>
@optional
-(void)ErrorMessage:(NSString*)msg;
-(BOOL) OverWriteOperation:(NSString*)file;
-(void) UnzipProgress:(uLong)myCurrentFileIndex total:(uLong)myTotalFileCount;

@end


@interface ZipArchive : NSObject {
@private
	zipFile		_zipFile;
	unzFile		_unzFile;
	
	NSString*   _password;
	id			_delegate;
	
	unsigned long _totalFileCount;
}

@property (nonatomic, retain) id delegate;

#if NS_BLOCKS_AVAILABLE
@property (nonatomic, copy) void (^progressBlock)(float progress);
#endif

-(BOOL) CreateZipFile2:(NSString*)zipFile;
-(BOOL) CreateZipFile2:(NSString*)zipFile Password:(NSString*)password;
-(BOOL) addFileToZip:(NSString*)file newname:(NSString*)newname;
-(BOOL) CloseZipFile2;

-(BOOL) UnzipOpenFile:(NSString*)zipFile;
-(BOOL) UnzipOpenFile:(NSString*)zipFile Password:(NSString*)password;
-(BOOL) UnzipFileTo:(NSString*)path overWrite:(BOOL) overwrite;
-(BOOL) UnzipCloseFile;
@end