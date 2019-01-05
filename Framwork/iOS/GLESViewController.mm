//
//  GLESViewController.m
//  OpenGLES
//
//  Created by user on 2018/12/5.
//  Copyright © 2018年 user. All rights reserved.
//

#import "GLESViewController.h"

@interface GLESViewController ()

@property (strong, nonatomic) EAGLContext *context;

@end

@implementation GLESViewController

- (id)initWithView:(UIView*)view
{
    if (self = [super init]) {
        
        self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        if (!self.context) {
            NSLog(@"Failed to create ES context");
        }
        
        GLKView *glkView = [[GLKView alloc] initWithFrame:[view bounds] context:self.context];
        glkView.drawableDepthFormat = GLKViewDrawableDepthFormat24;
        glkView.userInteractionEnabled = YES;   //启用视图交互
        glkView.multipleTouchEnabled = YES;     //启用多点触摸
        glkView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        
        self.view = glkView;
        self.preferredFramesPerSecond = 60;
        
        float scale = [[UIScreen mainScreen] scale];
        //NSLog(@"scale: %f", scale);
        [EAGLContext setCurrentContext:self.context];
        surfaceCreated();
        surfaceChanged([view bounds].size.width * scale, [view bounds].size.height * scale);
        
        [view addSubview:self.view];
    }
    return self;
}

- (void)viewWillLayoutSubviews {
    //NSLog(@"view bounds: %@", NSStringFromCGRect([self.view bounds]));
    float scale = [[UIScreen mainScreen] scale];
    surfaceChanged([self.view bounds].size.width * scale, [self.view bounds].size.height * scale);
}

- (void)dealloc
{
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

#pragma mark - GLKView and GLKViewController delegate methods

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    drawFrame();
}

@end
