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
        printf("��ʼ��������...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_L()...\n");
    {
        printf("�������Ƿ�Ϊ��: ");
        ListEmpty_L(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListInsert_L()...\n");
    {
        for (int j = 1; j < 6; ++j) {
            printf("�ڵ�����ĵ�%d��λ�ò���Ԫ�� \"%d\"...\n", j, 2*j);
//            ListInsert_L(&L, j, 2 * j);
//            ListInsert_L_Head(&L, 2 * j);
            ListInsert_L_Tail(&L, 2 * j);
        }
        printf("\n");
    }
    PressEnter();
    printf("Function ListEmpty_L()...\n");
    {
        printf("�������Ƿ�Ϊ��: ");
        ListEmpty_L(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
        printf("\n");
    }
    PressEnter();
    printf("Function ListTraverse_L()...\n");
    {
        printf("�������е�Ԫ��Ϊ: ");
        ListTraverse_L(L, Visit);
        printf("\n");
    }
    PressEnter();
    printf("Function ListLength_L()...\n");
    {
        printf("������ĳ���Ϊ \"%d\"...\n", ListLength_L(L));
        printf("\n");
    }
    PressEnter();
    printf("Function ListDelete_L()...\n");
    {
        ListDelete_L(&L, 2, e);
        printf("ɾ���������еĵ�2��Ԫ��\"%d\"...\n", *e);
        printf("�������е�Ԫ��Ϊ��");
        ListTraverse_L(L, Visit);
        printf("\n\n");
    }
    PressEnter();
    printf("Function GetElem_L()...\n");
    {
        GetElem_L(L, 2, e);
        printf("�������еĵ�2��λ�õ�Ԫ��Ϊ \"%d\"...\n", *e);
        printf("\n");
    }
    PressEnter();
    printf("Function LocateElem_L()...\n");
    {
        i = LocateElem_L(L, 2, Compare);
        printf("�������е�һ������2��Ԫ��λ��Ϊ \"%d\"...\n", i);
        printf("\n");
    }
    PressEnter();
    printf("Function PriorElem_L()...\n");
    {
        PriorElem_L(L, 6, e);
        printf("��������Ԫ��6��ǰ��Ϊ \"%d\"...\n", *e);
        printf("\n");
    }
    PressEnter();
    printf("Function NextElem_L()...\n");
    {
        NextElem_L(L, 6, e);
        printf("��������Ԫ��6�ĺ��Ϊ \"%d\"...\n", *e);
        printf("\n");
    }

    PressEnter();
    printf("Function ClearList_L()...\n");
    {
        printf("���ǰ...");
        ListEmpty_L(L) ? printf("������Ϊ��!\n") : printf("������Ϊ��!\n");
        ClearList_L(&L);
        printf("��պ�...");
        ListEmpty_L(L) ? printf("������Ϊ��!\n") : printf("������Ϊ��!\n");
        printf("\n");
    }
    PressEnter();
    printf("Function DestroyList_Sq()...\n");
    {
        printf("����ǰ...");
        L ? printf("���������!\n") : printf("����������!\n");
        DestroyList_L(&L);
        printf("���ٺ�...");
        L ? printf("���������!\n") : printf("����������!\n");
        printf("\n");
    }
    PressEnter();
    printf("���Խ���!");
}

Status Compare(LElemType_L e, LElemType_L e2) {
    return e == e2 ? TRUE : FALSE;
}

void Visit(LElemType_L e) {
    printf("%d ", e);
}