//
// Created by Administrator on 2019/6/30.
//

#include <stdio.h>
#include "SequenceList.h"

/* Compare和Visit */
Status Compare(LElemType_Sq e, LElemType_Sq e2);
void Visit(LElemType_Sq e);

int main(int argc, char** argv) {
    SqList L;
    int i;
    LElemType_Sq  e;

    printf("Function InitList_Sq()...\n");
    {
        printf("初始化顺序线性表...\n");
        InitList_Sq(&L);
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_Sq()...\n");
    {
        printf("判断顺序线性表是否为空...\n");
        TRUE == ListEmpty_Sq(L) ? printf("顺序线性表为空!\n") : printf("顺序线性表不为空!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListInsert_Sq()...\n");
    {
        printf("向顺序线性表中插入元素...\n");
        for (int j = 0; j < 5; ++j) {
            printf("向顺序线性表的第%d位置插入元素\"%d\"...\n", j, 2 * j);
            ListInsert_Sq(&L, j, 2 * j);
        }
        printf("\n");
    }
    PressEnter();
    printf("Function ListTraverse_Sq()...\n");
    {
        printf("遍历顺序线性表中的元素...\n");
        ListTraverse_Sq(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function ListLength_Sq()...\n");
    {
        i = ListLength_Sq(L);
        printf("顺序线性表的长度为 \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function ListDelete_Sq()...\n");
    {
        ListDelete_Sq(&L, 2, &e);
        printf("删除顺序线性表中的第2个位置的元素 \"%d\"...\n", e);
        ListTraverse_Sq(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function GetElem_Sq()...\n");
    {
        GetElem_Sq(L, 3, &e);
        printf("得到顺序线性表中的第4个位置的元素为 \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function LocateElem_Sq()...\n");
    {
        i = LocateElem_Sq(L, 6, Compare);
        printf("顺序线性表中第一个与6相等的元素的位置为 \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function PriorElem_Sq()...\n");
    {
        PriorElem_Sq(L, 6, &e);
        printf("顺序线性表中元素6的前驱为 \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function NextElem_Sq()...\n");
    {
        NextElem_Sq(L, 6, &e);
        printf("顺序线性表中元素6的后继为 \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function ClearList_Sq()...\n");
    {
        printf("清空前...");
        ListEmpty_Sq(L) ? printf("顺序线性表为空!\n") : printf("顺序线性表不为空!\n");
        ClearList_Sq(&L);
        printf("清空后...");
        ListEmpty_Sq(L) ? printf("顺序线性表为空!\n") : printf("顺序线性表不为空!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function DestroyList_Sq()...\n");
    {
        printf("销毁前...");
        L.elem ? printf("顺序线性表存在!\n") : printf("顺序线性表不存在!\n");
        DestroyList_Sq(&L);
        printf("销毁后...");
        L.elem ? printf("顺序线性表存在!\n") : printf("顺序线性表不存在!\n");
        printf("\n");
    }
    PressEnter();
    printf("测试结束!");
}

Status Compare(LElemType_Sq e, LElemType_Sq e2) {
    return e2 == e ? TRUE : FALSE;
}

void Visit(LElemType_Sq e) {
    printf("%d ",e);
}