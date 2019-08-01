//
// Created by xingyang on 2019/7/20.
//

#ifndef DATASTRUCT_STATUS_H
#define DATASTRUCT_STATUS_H

/*
 * 本书中所需的状态码
 * 或许有些用不到，但是相同的处理方式尽量使用相同的宏定义
 */
#define TRUE 1 //真
#define FALSE 0 //假
#define YES 1 //是
#define NO 0 //否
#define OK 1 //通过
#define ERROR 0 //错误
#define SUCCESS 1 //成功
#define UNSUCCESS 0 //失败
#define INFEASIBLE -1 //不可行
#define OVERFLOW -2 //堆栈上溢
#define UNDERFLOW -3 //

//#define NULL ((void*)0)

typedef int Status;

//函数暂停一段时间
#define Wait(x)\
{\
  double _Loop_Num_;\
  for (_Loop_Num_ = 0.01; _Loop_Num_ <= 100000.0 * x; _Loop_Num_ += 0.01);\
}

//回车继续
#define PressEnter()\
 {\
	printf("please press enter!");\
    while(getchar()!='\n')\
    continue;\
 }

#endif //DATASTRUCT_STATUS_H
