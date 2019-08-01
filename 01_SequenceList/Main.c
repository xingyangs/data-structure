//
// Created by Administrator on 2019/6/30.
//

#include <stdio.h>
#include "SequenceList.h"

/* Compare��Visit */
Status Compare(LElemType_Sq e, LElemType_Sq e2);
void Visit(LElemType_Sq e);

int main(int argc, char** argv) {
    SqList L;
    int i;
    LElemType_Sq  e;

    printf("Function InitList_Sq()...\n");
    {
        printf("��ʼ��˳�����Ա�...\n");
        InitList_Sq(&L);
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_Sq()...\n");
    {
        printf("�ж�˳�����Ա��Ƿ�Ϊ��...\n");
        TRUE == ListEmpty_Sq(L) ? printf("˳�����Ա�Ϊ��!\n") : printf("˳�����Ա�Ϊ��!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListInsert_Sq()...\n");
    {
        printf("��˳�����Ա��в���Ԫ��...\n");
        for (int j = 0; j < 5; ++j) {
            printf("��˳�����Ա�ĵ�%dλ�ò���Ԫ��\"%d\"...\n", j, 2 * j);
            ListInsert_Sq(&L, j, 2 * j);
        }
        printf("\n");
    }
    PressEnter();
    printf("Function ListTraverse_Sq()...\n");
    {
        printf("����˳�����Ա��е�Ԫ��...\n");
        ListTraverse_Sq(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function ListLength_Sq()...\n");
    {
        i = ListLength_Sq(L);
        printf("˳�����Ա�ĳ���Ϊ \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function ListDelete_Sq()...\n");
    {
        ListDelete_Sq(&L, 2, &e);
        printf("ɾ��˳�����Ա��еĵ�2��λ�õ�Ԫ�� \"%d\"...\n", e);
        ListTraverse_Sq(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function GetElem_Sq()...\n");
    {
        GetElem_Sq(L, 3, &e);
        printf("�õ�˳�����Ա��еĵ�4��λ�õ�Ԫ��Ϊ \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function LocateElem_Sq()...\n");
    {
        i = LocateElem_Sq(L, 6, Compare);
        printf("˳�����Ա��е�һ����6��ȵ�Ԫ�ص�λ��Ϊ \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function PriorElem_Sq()...\n");
    {
        PriorElem_Sq(L, 6, &e);
        printf("˳�����Ա���Ԫ��6��ǰ��Ϊ \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function NextElem_Sq()...\n");
    {
        NextElem_Sq(L, 6, &e);
        printf("˳�����Ա���Ԫ��6�ĺ��Ϊ \"%d\"...\n", e);
        printf("\n");
    }
    PressEnter();
    printf("Function ClearList_Sq()...\n");
    {
        printf("���ǰ...");
        ListEmpty_Sq(L) ? printf("˳�����Ա�Ϊ��!\n") : printf("˳�����Ա�Ϊ��!\n");
        ClearList_Sq(&L);
        printf("��պ�...");
        ListEmpty_Sq(L) ? printf("˳�����Ա�Ϊ��!\n") : printf("˳�����Ա�Ϊ��!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function DestroyList_Sq()...\n");
    {
        printf("����ǰ...");
        L.elem ? printf("˳�����Ա����!\n") : printf("˳�����Ա�����!\n");
        DestroyList_Sq(&L);
        printf("���ٺ�...");
        L.elem ? printf("˳�����Ա����!\n") : printf("˳�����Ա�����!\n");
        printf("\n");
    }
    PressEnter();
    printf("���Խ���!");
}

Status Compare(LElemType_Sq e, LElemType_Sq e2) {
    return e2 == e ? TRUE : FALSE;
}

void Visit(LElemType_Sq e) {
    printf("%d ",e);
}