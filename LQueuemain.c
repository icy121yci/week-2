#include "LQueue.h" 
#include "stdio.h"    
#include "stdlib.h"
int main (){
	int menu;
 	int flag=1;
	LQueue Q;	
	while(flag) {

		printf("-------------菜单-------------\n");
		printf("--------1.初始化队列----------\n");
		printf("--------2.入队列--------------\n");
		printf("--------3.出队列--------------\n");
		printf("--------4.打印队列------------\n");
		printf("--------5.判断是否为空队列----\n");	
		printf("--------6.查看队头元素--------\n");
		printf("--------7.确定队列长度--------\n");
		printf("--------8.清空队列------------\n");
		printf("--------9.销毁队列并退出系统--\n");
		
		printf("请输入数字(1~9)：\n");
		scanf("%d",&menu);
		switch(menu){
				case 1: 
					InitLQueue(&Q);
					system("pause");
					system("cls");				 
					break;
				case 2:			 
					EnLQueue(&Q) ;
					system("pause");
					system("cls");
					break;
						
				case 3:
					DeLQueue(&Q);
					system("pause");
					system("cls"); 
					break;
				case 4:
					
					TraverseLQueue( &Q, LPrint);
					system("pause");
					system("cls");
					break;
				case 5:
					IsEmptyLQueue( &Q); 
					system("pause");
					system("cls");
					break;
				case 6:
					GetHeadLQueue(&Q);
					system("pause");
					system("cls"); 
					break;
				case 7:
					menu=LengthLQueue(&Q); 
					printf("长度为：%d\n",menu);
					system("pause");
					system("cls");
					break;
				case 8:
					ClearLQueue(&Q) ;
					system("pause");
					system("cls");
					break;
				case 9:
					DestoryLQueue(&Q);
					flag=0;
					system("pause");
					system("cls");
					break;
				default:
					printf("请输入1~9的数字\n");
					system("pause");
					
					system("cls"); 
		}
	}
	return 0;
}
