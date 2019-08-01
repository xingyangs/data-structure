//
// Created by xingyang on 2019/7/20.
//

#ifndef DATASTRUCT_SEQUENCELIST_H
#define DATASTRUCT_SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 Status/Status.h"

/*
 * 顺序线性表所需的宏定义
 */
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

/*
 * 顺序线性表的元素类型
 */
typedef int LElemType_Sq;

/*
 * 顺序线性表的结点的数据结构
 */
typedef struct {
    LElemType_Sq *elem; //存储空间的基址
    int length; //顺序表长度
    int listsize; //顺序表当前分配的大小
} SqList;

/*
 * 结果: 顺序线性表的初始化，类似于面向对象的构造函数
 */
void InitList_Sq(SqList *L);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 销毁顺序线性表
 */
void DestroyList_Sq(SqList *L);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 将顺序线性表置为空表
 */
void ClearList_Sq(SqList *L);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 若为空表，则返回 TRUE, 否则返回 FALSE
 */
Status ListEmpty_Sq(SqList L);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 返回顺序线性表中数据元素的个数
 */
int ListLength_Sq(SqList L);

/*
 * 初始条件: 顺序线性表存在， 1 <= i <= ListLength_Sq(L)
 * 结果: 用 e 返回顺序线性表中第 i 个数据元素的值
 */
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

/*
 * 初始条件: 顺序线性表存在, compare() 是数据元素判定函数
 * 结果: 返回线性顺序表中第一个与 e 满足关系 compare() 的数据元素的位序。若无这样的元素，则返回 0
 */
int LocateElem_Sq(SqList  L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

/*
 * 初始条件: 顺序线性表存在
 * 结果: 若 cur_e 是顺序线性表的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败
 */
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

/*
 * 初始条件: 书匈奴线性表存在
 * 结果:  * 结果: 若 cur_e 是顺序线性表的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败
 */
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

/*
 * 初始条件: 顺序线性表存在，0 <= i <= ListLength_Sq()
 * 结果: 在顺序线性表的第 i 个位置之后插入新的元素 e ，顺序线性表的长度加 1 (这里和书上有点不同， 我懒得改了...)
 */
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

/*
 * 初始条件: 顺序线性表存在且非空, 0 <= i < ListLength_Sq()
 * 结果: 删除顺序线性表的第 i 个数据元素，并用 e 返回其值，顺序线性表的长度减 1
 */
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

/*
 * 初始条件: 顺序线性表存在
 * 结果: 依次对顺序线性表的每个数据元素调用函数 Visit()。一旦 Visit() 失败，则操作失败
 */
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));

#endif //DATASTRUCT_SEQUENCELIST_H
