//
// Created by xingyang on 2019/7/20.
//

#ifndef DATASTRUCT_SEQUENCELIST_C
#define DATASTRUCT_SEQUENCELIST_C

#include "SequenceList.h"

void InitList_Sq(SqList *L) {
    (*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if (!(*L).elem) {  // 内存分配失败
        exit(OVERFLOW);
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
}

void DestroyList_Sq(SqList *L) {
    if ((*L).elem) {
        free((*L).elem);
        (*L).elem = NULL; //这一步并非必须，但养成这样的意识是必要的，原因在于C中没有类似于JAVA中的内存自动回收机制
        (*L).length = 0;
        (*L).listsize = 0;
    }
}

void ClearList_Sq(SqList *L) {
    if ((*L).elem) {
        (*L).length = 0;
    }
}

Status ListEmpty_Sq(SqList L) {
    return 0 == L.length ? TRUE : FALSE;
}

int ListLength_Sq(SqList L) {
    if (L.elem) {
        return L.length;
    }
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e) {
    if (L.elem) {
        if (i < 0 || i > L.length - 1) {
            return ERROR; // 索引越界
        } else {
            *e = L.elem[i];
            return OK;
        }
    }
}

int LocateElem_Sq(SqList  L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq)) {
    int  i = 0;

    if (L.elem) {
        while (i < L.length && !Compare(e, L.elem[i])) {
            i ++;
        }
        if (i < L.length) {
            return i;
        } else {
            return -1; //-1代表未找到结果
        }
    }
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e) {
    int i = 0;

    if (L.elem) {
        while (i < L.length && cur_e != L.elem[i]) {
            i ++;
        }
        if (0 == i) {
            return OVERFLOW; //第一个结点没有前驱
        } else if (i < L.length) {
            *pre_e = L.elem[i - 1];
            return OK;
        } else {
            return ERROR;
        }
    }
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e) {
    int i = 0;

    if (L.elem) {
        while (i < L.length && cur_e != L.elem[i]) {
            i ++;
        }
        if (i < L.length - 1) {
            *next_e = L.elem[i + 1];
            return OK;
        } else {
            return ERROR;
        }
    }
}

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e) {
    LElemType_Sq *newbase;
    LElemType_Sq *p, *q;

    if ((*L).elem) {
        if (i < 0 || i > (*L).length) {
            return ERROR; //越界
        }
        if ((*L).length >= (*L).listsize) {
            // 存储空间已满
            newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(LElemType_Sq));
            if (!newbase) {
                exit(OVERFLOW);
            }
            (*L).elem = newbase;
            (*L).listsize += LISTINCREMENT;
        }
        p = &(*L).elem[i];
        for (q = &(*L).elem[(*L).length - 1]; q >= p; -- q) {
            *(q + 1) = (*q);
        }
        (*p) = e;
        (*L).length ++;
        return OK;
    }

}

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e) {
    int j;
    LElemType_Sq *p, *q;

    if ((*L).elem) {
        if (i < 0 || i >= (*L).length) {
            return ERROR; //越界
        }
        p = &(*L).elem[i];
        *e = *p;
        q = &(*L).elem[(*L).length - 1];
        for (++p; p <= q; p ++) {
            *(p - 1) = *p;
        }
        (*L).length --;
        return OK;
    }
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq)) {
    if (L.elem) {
        for (int i = 0; i < L.length; ++i) {
            Visit(L.elem[i]);
        }
        return OK;
    }
}

#endif
