/*///////////////////////////////////////////
 
 �⺻ ���̽� 
	������ : ������  

//////////////////////////////////////////////*/
#include <stdio.h>
#define VAR_MAX 10	//���� �ִ밹�� 
#define CIPHER_MAX 60	//��ȣ + 50 + 9 
#define NUM_MAX 100		//�ӽú��� 
#define FLOAT 9			//�Ҽ� �ڸ��� 
int Num[NUM_MAX][CIPHER_MAX]; //�ӽ� ���� 
int VAR[VAR_MAX][CIPHER_MAX];	//����
char VARC[VAR_MAX];	//���� ��ȣ 
char Solving[1000];		//���� ��
char Input[1000]; 	//������ �� 
int one[CIPHER_MAX];	//��꿡 ��������Ҽ�1 
int two[CIPHER_MAX];	//��꿡 ��������Ҽ�2 

void remover(int,int);
void numberResgister(int,int);//��� 
int add(int,int);	//���ϱ� 
int subtract(int,int);	//���� 
int multiply(int,int);	//���ϱ� 
int divide(int,int);	//������
void rest(int a,int b); //������ 
void solve(void){};	//Input �ǹ� �м�
void save();	//���� 
void load();	//�ҷ����� 

int minus(int);	//����- 
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



/*
numberResgister
	�Է¹��� ������ȣ a,b�� �ؼ� 
	one �� a  , two�� b �Լ� ���� (��������ϱ�) 
*/
void numberResgister(int a,int b){ 
	int i;
	if(a >= 10000){
		int t = a - 10000;
		for(i = 0 ;i < CIPHER_MAX; i++)
			one[i] = VAR[t][i];
		VAR[t][0] = -1;
		}
	else{
		for(i = 0; i < CIPHER_MAX; i++)
			one[i] = Num[a][i];
	}
	if(b >= 10000){
		int t = b - 10000;
		for( i = 0 ;i < CIPHER_MAX; i++)
			two[i] = VAR[t][i];
		VAR[t][0] = -1;
		}
	else{
		for(i = 0; i < CIPHER_MAX; i++)
			two[i] = Num[b][i];
	}
	
/*	printf("one :\n");	//�׽�Ʈ
	if(one[0] == 1)
		putchar('-');
	else
		putchar(' ');
	for(i = 1 ; i < CIPHER_MAX; i++)
		printf("%d",one[i]);
	putchar('\n');
	printf("two :\n");
	if(two[0] == 1)
		putchar('-');
	else
		putchar(' ');
	for(i = 1 ; i < CIPHER_MAX; i++)
		printf("%d",two[i]);
	putchar('\n');	//�׽�Ʈ ���� */
} 
/*getNew
	����ִ� �ӽú����� ã�Ƽ� ������ȣ ��ȯ*/ 
int getNew(void){
	int new;
	int i;
	for(i = 0; i < NUM_MAX; i ++)	//����մ� �ӽ� ���� ã�� 
		if(Num[i][0] == -1){
			new = i;
			break;
		}
	for(i = 0; i < CIPHER_MAX; i++)	//����Һ��� �����ϰ� 
		Num[new][0]  = 0;
	return new;
}
/*remover
	����� �ӽú����� �����ϴ� �������� 
	*/ 
void remover(int a,int b){
	Num[a][0] = -1;
	Num[b][0] = -1;
}
