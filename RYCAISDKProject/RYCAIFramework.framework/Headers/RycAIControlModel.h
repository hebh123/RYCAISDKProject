//
//  RycAIControlModel.h
//  FrameworkProject
//
//  Created by deayou on 2018/12/10.
//  Copyright © 2018 deayou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//动作类型选择
enum RYCActionType
{
    RYCACTION_EYE = 1<<0,  //眨眼
    RYCACTION_MOUTH = 1<<1,  //张嘴
    RYCACTION_HEAD_TOP = 1<<2,  //抬头
    
    RYCACTION_ALL = (RYCACTION_EYE | RYCACTION_MOUTH | RYCACTION_HEAD_TOP),  //三个动作全选
};
@protocol RYCAIDelegate <NSObject>

@optional

////////////////////////////////////////////////////////////////////////
//回调                                                                //
///////////////////////////////////////////////////////////////////////

//回调函数 活体检测完成  Result=1 成功 =0 失败 images: 抓拍图片数组
-(void)RYCOnOKResult:(BOOL)Result images:(NSArray *)images;

//回调函数  授权失败回调
-(void)RYCOnBack:(id)result;

@end
@interface RycAIControlModel : NSObject

//代理指针
@property (nonatomic,weak) id<RYCAIDelegate> delegate;

/**
 *
 *  @param merId 商户号
 *  @param RycPrivateKey 私钥
 *  @param environmentUrl 环境 0:测试环境 1:正式环境
 *
 */
-(instancetype)initWithMerId:(NSString *)merId RycPrivateKey:(NSString *)RycPrivateKey environmentUrl:(NSInteger)environmentUrl;

//开始活体 CurrentVC:当前控制器
-(void)show:(id)CurrentVC;

//设定照片张数。范围在1-3 默认1
-(void)setPictureNumber:(int)number;

//设置动作 (参数详情见RYCActionType枚举类型,默认3个全选)
-(BOOL)setTypeWithAction:(int)action;

//设置活体检测标题文字
-(void)setLivingTitleTxt:(NSString*)text;

//设置环境检测标题文字
-(void)setSelfieTitleTxt:(NSString *)text;


@end
