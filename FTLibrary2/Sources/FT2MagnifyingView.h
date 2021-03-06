//
//  FT2MagnifyingView.h
//  FT2Library2
//
//  Created by Baldoph Pourprix on 12/02/2012.
//  Copyright (c) 2012 Fuerte International All rights reserved.
//


/* Based on Apple's code in the PhotoScroller & TapToZoom Projects */

#import <UIKit/UIKit.h>

@protocol FT2MagnifyingViewDelegate;

@interface FT2MagnifyingView : UIScrollView <UIScrollViewDelegate>

/* magnifiedView is the view you want to see magnified */
@property (nonatomic, strong) UIView *magnifiedView;
@property (nonatomic, strong) UITapGestureRecognizer *doubleTapRecognizer;
@property (nonatomic, weak) id <FT2MagnifyingViewDelegate> magnifyingViewDelegate;
- (CGPoint)pointToCenterAfterRotation;
- (CGFloat)scaleToRestoreAfterRotation;
- (void)restoreCenterPoint:(CGPoint)oldCenter scale:(CGFloat)oldScale;

- (void)setMaxMinZoomScalesForCurrentBounds;

- (void)zoomOutAnimated:(BOOL)animated animationsOptions:(UIViewAnimationOptions)options completionBlock:(void (^)(void))didZoomOut;

@end

@protocol FT2MagnifyingViewDelegate <NSObject>

@optional
- (void)magnifyingViewDidZoomIn:(FT2MagnifyingView *)magnifyingView;

@end
