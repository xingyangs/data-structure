//
// Created by xingyang on 2019/6/30.
//
#ifndef DATASTRUCT_SINGLELINKLIST_H
#define DATASTRUCT_SINGLELINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 Status/Status.h"

#ifndef DATASTRUCT_BANKSIMULATION_H
typedef int LElemType_L;

/* 单链表的结点 */
typedef struct LNode {
    LElemType_L data;
    struct LNode* next;
} LNode;

typedef LNode* LinkList;
#endif

//typedef enum
//{
//    Arrive,Leave_1,Leave_2,Leave_3,Leave_4
//}EventType;								//事件类型，0代表到达事件，1至4表示四个窗口的离开事件
//typedef struct         					//事件链表
//{
//    int OccurTime;						//事件发生时刻
//    EventType NType;					//事件类型
//}Event;
//typedef Event LElemType_L;				//事件链表元素
//typedef struct LNode
//{
//    LElemType_L data;
//    struct LNode *next;
//}LNode;
//typedef LNode* LinkList;
//typedef LinkList EventList;											//事件链表类型，定义为有序链表

/*
 * 结果: 构造一个空的单链表
 */
Status InitList_L(LinkList *L);

/*
 * 初始条件: 单链表存在
 * 结果: 销毁单链表
 */
Status DestroyList_L(LinkList *L);

/*
 * 初始条件: 单链表存在
 * 结果: 将单链表置为空表
 */
Status ClearList_L(LinkList *L);

/*
 * 初始条件: 单链表存在
 * 结果: 若单链表为空表，则返回TRUE，否则返回FALSE
 */
Status ListEmpty_L(LinkList L);

/*
 * 初始条件: 单链表存在
 * 结果: 返回单链表中数据元素的个数
 */
int ListLength_L(LinkList L);

/*
 * 初始条件: 单链表存在
 * 结果: 用 e 返回单链表中第 i 个数据元素的值
 */
Status GetElem_L(LinkList L, int i, LElemType_L *e);

/*
 * 初始条件: 单链表存在, compare() 是数据元素判定函数
 * 结果: 返回单链表中第一个与 e 满足关系 compare() 的数据元素的位序。若无这样的元素，则返回 0
 */
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));

/*
 * 初始条件: 单链表存在
 * 结果: 若 cur_e 是单链表的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败
 */
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);

/*
 * 初始条件: 单链表存在
 * 结果:  * 结果: 若 cur_e 是单链表的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败
 */
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);

/*
 * 初始条件: 单链表存在，1 <= i <= ListLength_Sq() - 1
 * 结果: 在单链表的第 i 个位置之后插入新的元素 e ，顺序线性表的长度加 1 (这里和书上有点不同， 我懒得改了...)
 */
Status ListInsert_L(LinkList *L, int i, LElemType_L e);

/*
 * 初始条件: 单链表存在且非空, 0 <= i < ListLength_Sq()
 * 结果: 删除单链表的第 i 个数据元素，并用 e 返回其值，顺序线性表的长度减 1
 */
Status ListDelete_L(LinkList *L, int i, LElemType_L *e);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 依次对顺序线性表的每个数据元素调用函数 Visit()。一旦 Visit() 失败，则操作失败
 */
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));

/*
 * 头插法
 */
Status ListInsert_L_Head(LinkList *L, LElemType_L e);

/*
 * 尾插法
 */
Status ListInsert_L_Tail(LinkList *L, LElemType_L e);


#endif //DATASTRUCT_SINGLELINKLIST_H
