#include "../head/LinkStack.h" 
#include<stdio.h>
#include <iostream> 
int main (){
	int menu,flag2=1;
	ElemType flag; 
	LinkStackPtr L;
	LinkStack s; 
	while(flag2){
	
		printf("-----------�˵�---------\n");
		printf("-------1.��ʼ��ջ-------\n") ;
		printf("-------2.��ջ-----------\n") ;
		printf("-------3.��ջ-----------\n") ;
		printf("-------4.��ӡջ---------\n") ;
		printf("-------5.�ж�ջ�Ƿ�Ϊ��-\n") ;
		printf("-------6.�õ�ջ��Ԫ��---\n") ;
		printf("-------7.���ջ����-----\n") ;
		printf("-------8.���ջ---------\n") ;
		printf("-------9.�˳�ϵͳ-------\n") ;
		
		printf("����������(1~9)��\n");
		scanf("%d",&menu);
		switch(menu){
			case 1: 
				initLStack(&s); 
				system("pause");
				system("cls");				 
				break; 
			case 2:
				printf("���������ݣ�\n");
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
				printf("����������(1~9)\n");
				system("pause");
				system("cls");	
					
			}
	}
	return 0;
} 
