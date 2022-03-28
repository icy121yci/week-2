#include "../head/LinkStack.h" 
#include<stdlib.h>
#include <stdio.h> 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{ 
        s->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!s->top)
                return ERROR;
        s->top=NULL;
        s->count=0;
        printf("��ʼ���ɹ�\n");
        return SUCCESS ;
}
//��ӡջ�� 
Status tackTraverse(LinkStack *s){
	if(!(s->count )){
		printf("��ջ���ɴ�ӡ\n");
		return ERROR;
	}
	while(s->top ){
		printf("%d->",s->top->data );
		s->top =s->top->next ; 
	} 
	printf("\n");
	return SUCCESS ;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(!(s->count)){
		printf("�ǿ�ջ\n");
		return SUCCESS ;
	}
	printf("���ǿ�ջ\n");
	return SUCCESS ;	
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s){
	if(!(s->count )){
		printf("��ջû��ջ��Ԫ��\n");
		return ERROR;
	}
 
	printf("ջ��Ԫ��Ϊ%d\n",s->top->data);
	return SUCCESS; 
}

//���ջ
Status clearLStack(LinkStack *s){
		if(!(s->count )){
			printf("��ջ������Ҫ���\n");
			return SUCCESS;
		}
		LinkStackPtr p;
		
		while(s->top ){
			p=s->top ;
			s->top=s->top->next ;
			free(p);
			s->count--;
		}	
		printf("�ɹ����\n");
			return SUCCESS;		
}

//����ջ
Status destroyLStack(LinkStack *s){
		if(!(s->count )){
			return SUCCESS;
		}
		LinkStackPtr p;
		
		while(s->top ){
			p=s->top ;
			s->top=s->top->next ;
			free(p);
			s->count--;
		}	
			return SUCCESS;			
}

//���ջ����
Status LStackLength(LinkStack *s){
	if(!(s->count )){
		printf("��ջ������Ϊ0��\n");
		return SUCCESS;
	}
		printf("ջ����Ϊ%d\n",s->count );
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s,ElemType data){
		
		LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode)); 
	    p->data=data; 
		p->next=s->top;	//ջ��ָ������ 
		s->top=p;        
		s->count++;
	    return SUCCESS ;
		
}

//��ջ
Status popLStack(LinkStack *s){
	if(!(s->count )){
		printf("��ջ���ɳ�ջ\n");
		return ERROR;
	}
	LinkStackPtr p; 
	p=s->top ;
	s->top =s->top->next ;//ջ��ָ������ 
	s->count --;
	printf("%d�ɹ���ջ\n",p->data );//���س�ջ���� 
	free (p); 
	return SUCCESS; 
	
}


 
