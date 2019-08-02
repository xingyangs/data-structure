//
// Created by xingyang on 2019/6/30.
//
#ifndef DATASTRUCT_SINGLELINKLIST_C
#define DATASTRUCT_SINGLELINKLIST_C

#include "SingleLinkList.h"

Status InitList_L(LinkList *L) {
    (*L) = (LinkList)malloc(sizeof(LNode));
    if (!(*L)) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    return OK;
}


Status DestroyList_L(LinkList *L) {
    LinkList p;
    p = *L;

    if (!(*L)) {
        return ERROR;
    }
    while (p) {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
    return OK;
}

Status ClearList_L(LinkList *L) {
    LinkList pre, p;
    pre = (*L)->next;

    if (ListEmpty_L(*L)) {
        return ERROR;
    }
    while (pre) {
        p = pre->next;
        free(pre);
        pre = p;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListEmpty_L(LinkList L) {
    if(L) {
        return (NULL != L && NULL == L->next) ? TRUE : FALSE;
    }
}

int ListLength_L(LinkList L) {
    LinkList p;
    p = L->next;
    int length = 0;

    if (L) {
        while (p) {
            p = p->next;
            length ++;
        }
        return length;
    }
}

Status GetElem_L(LinkList L, int i, LElemType_L *e){
    LinkList p;
    p = L->next;
    int j = 1;

    if (L) {
        while (p && j < i) {
            p = p->next;
            ++j;
        }
        if (!p || j > i) {
            return ERROR;
        }
        *e = p->data;
        return OK;
    }
}

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)) {
    LinkList p;
    p = L->next;
    int i = -1;
    int j = 1;

    if (L) {
        while (p) {
            if (!Compare(e, p->data)) {
                p = p->next;
                ++ j;
            } else {
                i = j;
                break;
            }
        }
        if (1 > i || ListLength_L(L) < i) {
            return ERROR;
        } else {
            return i;
        }
    }
}

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e) {
    LinkList p, q;
    p = L->next;

//    if (cur_e.OccurTime == p->data.OccurTime && cur_e.NType == p->data.NType) {
//        //无前驱
//        return ERROR;
//    }
	if (L) {
        if (cur_e == p->data) {
            return ERROR;
        }

        while (p->next) {
            q = p->next;
            if (cur_e == q->data) {
                *pre_e = p->data;
                return OK;
            }
            p = q;
        }
	}
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e) {
    LinkList p, q;
    p = L->next;

    while (p->next) {
        if (cur_e == p->data) {
            q = p->next;
            if (q) {
                *next_e = q->data;
                return OK;
            } else {
                return ERROR;
            }
        }
        p = p->next;
    }
}

Status ListInsert_L(LinkList *L, int i, LElemType_L e) {
    LinkList p, s;
    p = *L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        ++ j;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList *L, int i, LElemType_L *e) {
    LinkList p, q;
    p = *L;
    int j = 0;

    while (p->next && j < i - 1) {
        p = p->next;
        ++ j;
    }
    if (!(p->next) || j > i - 1) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)) {
    while (L->next) {
        L = L->next;
        Visit(L->data);
    }
    return OK;
}

Status ListInsert_L_Head(LinkList *L, LElemType_L e) {
    if (*L) {
        ListInsert_L(L, 1, e);
        return OK;
    }
}

Status ListInsert_L_Tail(LinkList *L, LElemType_L e) {
    if (*L) {
        ListInsert_L(L, ListLength_L(*L) + 1, e);
        return OK;
    }
}

#endif
