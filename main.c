#include "../head/LinkStack.h" 
#include<stdio.h>
#include <iostream> 
int main (){
	int menu,flag2=1;
	ElemType flag; 
	LinkStackPtr L;
	LinkStack s; 
	while(flag2){
	
		printf("-----------菜单---------\n");
		printf("-------1.初始化栈-------\n") ;
		printf("-------2.入栈-----------\n") ;
		printf("-------3.出栈-----------\n") ;
		printf("-------4.打印栈---------\n") ;
		printf("-------5.判断栈是否为空-\n") ;
		printf("-------6.得到栈顶元素---\n") ;
		printf("-------7.检测栈长度-----\n") ;
		printf("-------8.清空栈---------\n") ;
		printf("-------9.退出系统-------\n") ;
		
		printf("请输入数字(1~9)：\n");
		scanf("%d",&menu);
		switch(menu){
			case 1: 
				initLStack(&s); 
				system("pause");
				system("cls");				 
				break; 
			case 2:
				printf("请输入数据：\n");
				scanf("%d",&flag);
				pushLStack(&s,flag); 
				system("pause");
				system("cls");	
				break;
			case 3:
				popLStack(&s)	;
				system("pause");
				system("cls");	
				break;
			case 4:
				tackTraverse(&s) ;
				system("pause");
				system("cls");	
				break;
			case 5:
				isEmptyLStack(&s);
				system("pause");
				system("cls");	
				break;	
			case 6:
				getTopLStack(&s);
				system("pause");
				system("cls");	
				break;
			case 7:
				LStackLength(&s); 
				system("pause");
				system("cls");	
				break;
			case 8:
				clearLStack(&s);
				system("pause");
				system("cls");	
				break;
			case 9:
				destroyLStack(&s);
				flag2=0;
				system("pause");
				system("cls");	
				break;
			default:
				printf("请输入数字(1~9)\n");
				system("pause");
				system("cls");	
					
			}
	}
	return 0;
} 
