#include "LQueue.h" 
#include <string.h>
#include "stdio.h"    
#include "stdlib.h"
#include <typeinfo.h> 
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	
	Q->rear=Q->front=(Node*)malloc(sizeof(Node));
		if(!(Q->front))
		exit(1);

	Q->rear->next =NULL;	
	Q->length=0;
	printf("��ʼ���ɹ�!\n");

}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q) ;
	free(Q->front );	
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if(Q->length==0){
		printf("�ǿն���\n");
		return FALSE ;
	}
	else printf("���ǿն���\n");
	return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q){
	if(Q->length==0){
		printf("��ջ,�޶�ͷԪ��\n");
		return TRUE;
	}
	
	
		LPrint(Q->front->next->data ,Q->front->next->datatype );

	return TRUE;	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length ;
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q){
	int flag;
/*	float a;
	char b;
	char c[CHAR_MAX];*/
	
	Node*p;
	p=(Node*)malloc(sizeof(Node));
	if(!p) /* �洢����ʧ�� */
		exit(1);
	
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	Q->length ++;
	
	printf("1.����\t2.С��\t3.һ���� 4.�����\n");
	printf("��ѡ��Ҫ���������(1-4)��\n");
	scanf("%d",&flag);
	switch(flag){
		case 1:
			printf("������������\n");
			scanf("%d",(int*)p->data);
		/*	if(typeid(flag)==typeid(int))*/
			/*(int*)*/
		//	memcpy(p->data,&flag,sizeof(flag));
			p->datatype=1; 
			break;
		case 2:
			printf("������С����\n");
			scanf("%f",(float*)p->data);
		
			p->datatype=2;
			break;
		case 3:
			printf("������һ���֣�\n");	
			scanf("%c",(char*)p->data);

			p->datatype=3;
			break;
		case 4:
			printf("����������(���ʮ��Ŷ~)��\n");
			scanf("%s",(char*)p->data);

			p->datatype=4;
			break;	
		default:
			printf("��ѡ��Ҫ����(1-4)\n");
	}
	
	return TRUE;
		
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node*p;
	if(Q->length==0){
		printf("��ջ�����ɳ�ջ\n");
		return TRUE;
	}else if(Q->length ==1){
		p=Q->front->next ;
		free(p); 
		Q->rear =Q->front ;
		Q->front->next =NULL;
		printf("��ջ�ˣ�\n");
		
	}else{
		p=Q->front->next ;		
		Q->front=Q->front->next->next ;
		free(p);
		printf("��ջ�ˣ�\n");
	}
	
	Q->length --;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){

	Node*q;
	Node*p;
		
	Q->rear =Q->front; //ͷβ��һ	
	p=Q->front->next;
	Q->rear->next=NULL;//��һ���ǿյģ�û��
	while(p){
		q=p;
		p=p->next ;
		free(q);	
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q, void (*foo)(void *q,int type)){
	if(Q->length==0){
		printf("��ջ�����ɴ�ӡ\n");
		return TRUE;
}
	Node*p;
	p=Q->front->next;
	
	while(p ) {		
		foo(p->data,p->datatype );
		p=p->next;	
	}
	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
 void LPrint(void *q,int type) {

	if(type==1)
		printf("%d\t",(int*)q);
		
	if(type==2)
		printf("%f\t",(float*)q);
		
	if(type==3)
		printf("%c\t",(char*)q);
		
	if(type==4)
		printf("%s\t",(char*)q);
	
	
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



