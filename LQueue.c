#include "LQueue.h" 
#include <string.h>
#include "stdio.h"    
#include "stdlib.h"
#include <typeinfo.h> 
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	
	Q->rear=Q->front=(Node*)malloc(sizeof(Node));
		if(!(Q->front))
		exit(1);

	Q->rear->next =NULL;	
	Q->length=0;
	printf("初始化成功!\n");

}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q) ;
	free(Q->front );	
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if(Q->length==0){
		printf("是空队列\n");
		return FALSE ;
	}
	else printf("不是空队列\n");
	return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q){
	if(Q->length==0){
		printf("空栈,无队头元素\n");
		return TRUE;
	}
	
	
		LPrint(Q->front->next->data ,Q->front->next->datatype );

	return TRUE;	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length ;
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q){
	int flag;
/*	float a;
	char b;
	char c[CHAR_MAX];*/
	
	Node*p;
	p=(Node*)malloc(sizeof(Node));
	if(!p) /* 存储分配失败 */
		exit(1);
	
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	Q->length ++;
	
	printf("1.整数\t2.小数\t3.一个字 4.多个字\n");
	printf("请选择要输入的数据(1-4)：\n");
	scanf("%d",&flag);
	switch(flag){
		case 1:
			printf("请输入整数：\n");
			scanf("%d",(int*)p->data);
		/*	if(typeid(flag)==typeid(int))*/
			/*(int*)*/
		//	memcpy(p->data,&flag,sizeof(flag));
			p->datatype=1; 
			break;
		case 2:
			printf("请输入小数：\n");
			scanf("%f",(float*)p->data);
		
			p->datatype=2;
			break;
		case 3:
			printf("请输入一个字：\n");	
			scanf("%c",(char*)p->data);

			p->datatype=3;
			break;
		case 4:
			printf("请输入多个字(最多十个哦~)：\n");
			scanf("%s",(char*)p->data);

			p->datatype=4;
			break;	
		default:
			printf("请选择要输入(1-4)\n");
	}
	
	return TRUE;
		
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node*p;
	if(Q->length==0){
		printf("空栈，不可出栈\n");
		return TRUE;
	}else if(Q->length ==1){
		p=Q->front->next ;
		free(p); 
		Q->rear =Q->front ;
		Q->front->next =NULL;
		printf("出栈了！\n");
		
	}else{
		p=Q->front->next ;		
		Q->front=Q->front->next->next ;
		free(p);
		printf("出栈了！\n");
	}
	
	Q->length --;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){

	Node*q;
	Node*p;
		
	Q->rear =Q->front; //头尾归一	
	p=Q->front->next;
	Q->rear->next=NULL;//下一个是空的，没有
	while(p){
		q=p;
		p=p->next ;
		free(q);	
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q, void (*foo)(void *q,int type)){
	if(Q->length==0){
		printf("空栈，不可打印\n");
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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



