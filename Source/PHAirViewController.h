//
//  PHAirViewController.h
//  PHAirTransaction
//
//  Created by Ta Phuoc Hai on 1/7/14.
//  Copyright (c) 2014 Phuoc Hai. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PHSessionView.h"
#import "PHMenuItemView.h"

@protocol PHAirMenuDelegate <NSObject>
@optional
- (BOOL)shouldSelectRowAtIndex:(NSIndexPath*)indexPath;
- (void)didSelectRowAtIndex:(NSIndexPath*)indexPath;

- (void)willShowAirViewController;
- (void)willHidenAirViewController;
- (void)didHidenAirViewController;
@end

@protocol PHAirMenuDataSource <NSObject>
@required
- (NSInteger)numberOfSession;
- (NSInteger)numberOfRowsInSession:(NSInteger)sesion;
- (NSString*)titleForRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSString*)titleForHeaderAtSession:(NSInteger)session;
@optional
- (NSIndexPath*)indexPathForRootViewController;
- (UIImage*)thumbnailImageAtIndexPath:(NSIndexPath*)indexPath;
- (NSString*)segueForRowAtIndexPath:(NSIndexPath*)indexPath;
- (UIViewController*)viewControllerForIndexPath:(NSIndexPath*)indexPath;
@end

@interface PHAirViewController : UIViewController <PHAirMenuDelegate, PHAirMenuDataSource, UIGestureRecognizerDelegate>

@property (nonatomic, strong) UIColor * titleNormalColor;
@property (nonatomic, strong) UIColor * titleHighlightColor;

@property (nonatomic, assign) id <PHAirMenuDelegate>   delegate;
@property (nonatomic, assign) id <PHAirMenuDataSource> dataSource;

@property (nonatomic, readonly) UIViewController * fontViewController;
@property (nonatomic, readonly) NSIndexPath      * currentIndexPath;

- (id)initWithRootViewController:(UIViewController*)viewController;

- (void)reloadData;
- (void)showAirViewFromViewController:(UIViewController*)controller complete:(void (^)(void))complete;

@end

#pragma mark - PHAirViewControllerDelegate Protocol

@protocol PHAirViewControllerDelegate<NSObject>
@optional
@end


#pragma mark - UIViewController(PHAirViewController) Category

// We add a category of UIViewController to let childViewControllers easily access their parent PHAirViewController
@interface UIViewController(PHAirViewController)
- (PHAirViewController*)airViewController;
@end


// This will allow the class to be defined on a storyboard
#pragma mark - PHAirViewControllerSegue

@interface PHAirViewControllerSegue : UIStoryboardSegue
@property (strong) void(^performBlock)( PHAirViewControllerSegue * segue, UIViewController * svc, UIViewController * dvc );
@end