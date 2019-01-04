//
//  ViewController.m
//  OpenGLES
//
//  Created by jaccen on 2018/12/4.
//  Copyright © 2018年 user. All rights reserved.
//

#import "ViewController.h"
#import "GLESViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIView *showView;
@property (strong, nonatomic) GLESViewController *glesViewController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // 创建GLES视图并添加
    self.glesViewController = [[GLESViewController alloc] initWithView:self.showView];
    [self addChildViewController:self.glesViewController];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
