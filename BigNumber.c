/*///////////////////////////////////////////
 
 �⺻ ���̽� 
	������ : ������  

//////////////////////////////////////////////*/
#include <stdio.h>
#define VAR_MAX 10		//������ ���� 
char Num[100][59]; //�ӽ� ���� 
char VAR[VAR_MAX][59];	//����
char VARC[VAR_MAX];	//���� ��ȣ 
char Solving[1000];		//���� ��
char Input[1000]; 	//������ �� 

///������ �κ� 
void add(int a,int b);	//���ϱ� //a,b = �ӽú������� ���ڹ�ȣ		10001���ʹ� ���� ��ȣ README.md �� ���� ���߿� ���� 
void multiply(int a,int b);	//���ϱ� 

///������ �κ� 
void divide(int a,int b);	//������
void rest(int a,int b); //������ 

///������ �κ� 
void solve(void){};	//Input �ǹ� �м�
void save();	//���� 
void load();	//�ҷ�����

///���� �κ� 
void minus(int a);	//����- 
void subtract(int a,int b);	//���� 
void print(); 	//�޸� ���ǿ��°� ��� 


char EndString[] = "end";
int main(void){
	printf("Start....\n");
	
	while(1){
		printf("(Input) ");
		scanf("%s",Input);
		
		//////////////////////////	end ġ�� ������ ���� 
		int end = 1;
		int i = 0; 
		for(i = 0; i < 3; i++)
			if(Input[i] != EndString[i])
				end = 0;
		if(end)
			break;
		///////////////////////////
		
		solve();
		
		
	}
	
	return 0;
}
