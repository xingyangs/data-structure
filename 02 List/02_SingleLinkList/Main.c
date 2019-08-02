//
// Created by Administrator on 2019/7/1.
//

#include "SingleLinkList.h"

Status Compare(LElemType_L e, LElemType_L e2);
void Visit(LElemType_L e);

int main(int argc, char** argv) {
    LinkList L;
    int i;
    LElemType_L *e;

    printf("Function InitList_L()...\n");
    {
        printf("初始化单链表...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_L()...\n");
    {
        printf("单链表是否为空: ");
        ListEmpty_L(L) ? printf("为空\n") : printf("不为空\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListInsert_L()...\n");
    {
        for (int j = 1; j < 6; ++j) {
            printf("在单链表的第%d个位置插入元素 \"%d\"...\n", j, 2*j);
//            ListInsert_L(&L, j, 2 * j);
//            ListInsert_L_Head(&L, 2 * j);
            ListInsert_L_Tail(&L, 2 * j);
        }
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_L()...\n");
    {
        printf("单链表是否为空: ");
        ListEmpty_L(L) ? printf("为空\n") : printf("不为空\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListTraverse_L()...\n");
    {
        printf("单链表中的元素为: ");
        ListTraverse_L(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function ListLength_L()...\n");
    {
        printf("单链表的长度为 \"%d\"...\n", ListLength_L(L));
        printf("\n");
    }
    PressEnter();
    printf("Function ListDelete_L()...\n");
    {
        ListDelete_L(&L, 2, e);
        printf("删除单链表中的第2个元素\"%d\"...\n", *e);
        printf("单链表中的元素为：");
        ListTraverse_L(L, Visit);
        printf("\n\n");
    }
    PressEnter();
    printf("Function GetElem_L()...\n");
    {
        GetElem_L(L, 2, e);
        printf("单链表中的第2个位置的元素为 \"%d\"...\n", *e);
        printf("\n");
    }
    PressEnter();
    printf("Function LocateElem_L()...\n");
    {
        i = LocateElem_L(L, 2, Compare);
        printf("单链表中第一个等于2的元素位置为 \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function PriorElem_L()...\n");
    {
        PriorElem_L(L, 6, e);
        printf("单链表中元素6的前驱为 \"%d\"...\n", *e);
        printf("\n");
    }
    PressEnter();
    printf("Function NextElem_L()...\n");
    {
        NextElem_L(L, 6, e);
        printf("单链表中元素6的后继为 \"%d\"...\n", *e);
        printf("\n");
    }

    PressEnter();
    printf("Function ClearList_L()...\n");
    {
        printf("清空前...");
        ListEmpty_L(L) ? printf("单链表为空!\n") : printf("单链表不为空!\n");
        ClearList_L(&L);
        printf("清空后...");
        ListEmpty_L(L) ? printf("单链表为空!\n") : printf("单链表不为空!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function DestroyList_Sq()...\n");
    {
        printf("销毁前...");
        L ? printf("单链表存在!\n") : printf("单链表不存在!\n");
        DestroyList_L(&L);
        printf("销毁后...");
        L ? printf("单链表存在!\n") : printf("单链表不存在!\n");
        printf("\n");
    }
    PressEnter();
    printf("测试结束!");
}

Status Compare(LElemType_L e, LElemType_L e2) {
    return e == e2 ? TRUE : FALSE;
}

void Visit(LElemType_L e) {
    printf("%d ", e);
}