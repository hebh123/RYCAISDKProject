//
//  ViewController.m
//  RYCAISDKProject
//
//  Created by deayou on 2018/12/10.
//  Copyright © 2018 deayou. All rights reserved.
//

#import "ViewController.h"
#import <RYCAIFramework/RYCAIFramework.h>
#define memberId @"您的商户号"
#define RYCPrivateKey  @"您的私钥"

@interface ViewController ()<RYCAIDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *snapImageView;

@property (nonatomic,strong) RycAIControlModel *RcyControlModel;
@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
}
- (IBAction)livingAction:(id)sender {
    
    self.RcyControlModel =[[RycAIControlModel alloc]initWithMerId:memberId RycPrivateKey:RYCPrivateKey environmentUrl:0];
    /*
     可选配置
     [self.RcyControlModel setPictureNumber:1];
     [self.RcyControlModel setTypeWithAction:RYCACTION_ALL];
     [self.RcyControlModel setLivingTitleTxt:@"活体检测"];
     [self.RcyControlModel setSelfieTitleTxt:@"环境检测"];
     */
    self.RcyControlModel.delegate =self;
    [self.RcyControlModel show:self];
    
}
-(void)RYCOnOKResult:(BOOL)Result images:(NSArray *)images{
    
    NSLog(@"活体检测结果%d images =%@",Result,images);
    if (Result) {
        
        self.snapImageView.image = images[0];
        
    }
}

-(void)RYCOnBack:(id)result{
    
    NSLog(@"%@",result);
   
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}


@end
