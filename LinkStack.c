#include "../head/LinkStack.h" 
#include<stdlib.h>
#include <stdio.h> 
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{ 
        s->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!s->top)
                return ERROR;
        s->top=NULL;
        s->count=0;
        printf("初始化成功\n");
        return SUCCESS ;
}
//打印栈链 
Status tackTraverse(LinkStack *s){
	if(!(s->count )){
		printf("空栈不可打印\n");
		return ERROR;
	}
	while(s->top ){
		printf("%d->",s->top->data );
		s->top =s->top->next ; 
	} 
	printf("\n");
	return SUCCESS ;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(!(s->count)){
		printf("是空栈\n");
		return SUCCESS ;
	}
	printf("不是空栈\n");
	return SUCCESS ;	
}

//得到栈顶元素
Status getTopLStack(LinkStack *s){
	if(!(s->count )){
		printf("空栈没有栈顶元素\n");
		return ERROR;
	}
 
	printf("栈顶元素为%d\n",s->top->data);
	return SUCCESS; 
}

//清空栈
Status clearLStack(LinkStack *s){
		if(!(s->count )){
			printf("空栈，不需要清空\n");
			return SUCCESS;
		}
		LinkStackPtr p;
		
		while(s->top ){
			p=s->top ;
			s->top=s->top->next ;
			free(p);
			s->count--;
		}	
		printf("成功清空\n");
			return SUCCESS;		
}

//销毁栈
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

//检测栈长度
Status LStackLength(LinkStack *s){
	if(!(s->count )){
		printf("空栈，长度为0。\n");
		return SUCCESS;
	}
		printf("栈长度为%d\n",s->count );
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s,ElemType data){
		
		LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode)); 
	    p->data=data; 
		p->next=s->top;	//栈顶指针上移 
		s->top=p;        
		s->count++;
	    return SUCCESS ;
		
}

//出栈
Status popLStack(LinkStack *s){
	if(!(s->count )){
		printf("空栈不可出栈\n");
		return ERROR;
	}
	LinkStackPtr p; 
	p=s->top ;
	s->top =s->top->next ;//栈顶指针下移 
	s->count --;
	printf("%d成功出栈\n",p->data );//返回出栈数据 
	free (p); 
	return SUCCESS; 
	
}


 
