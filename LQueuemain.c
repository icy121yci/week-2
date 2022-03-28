#include "LQueue.h" 
#include "stdio.h"    
#include "stdlib.h"
int main (){
	int menu;
 	int flag=1;
	LQueue Q;	
	while(flag) {

		printf("-------------�˵�-------------\n");
		printf("--------1.��ʼ������----------\n");
		printf("--------2.�����--------------\n");
		printf("--------3.������--------------\n");
		printf("--------4.��ӡ����------------\n");
		printf("--------5.�ж��Ƿ�Ϊ�ն���----\n");	
		printf("--------6.�鿴��ͷԪ��--------\n");
		printf("--------7.ȷ�����г���--------\n");
		printf("--------8.��ն���------------\n");
		printf("--------9.���ٶ��в��˳�ϵͳ--\n");
		
		printf("����������(1~9)��\n");
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
					printf("����Ϊ��%d\n",menu);
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
					printf("������1~9������\n");
					system("pause");
					
					system("cls"); 
		}
	}
	return 0;
}
