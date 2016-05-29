/*
	�⺻ ���̽� ���ο� ����
	*/	
#include <stdio.h>
#include <string.h>
#define CIPHER_MAX 60	// ���ڹ迭�� �ѱ��� 0 : ��ȣ 1 ~ 50 : ���� 51 ~ 59 �Ҽ� 
#define DECIMAL 9	//�Ҽ� �κ� 
#define VAR_MAX 10	//����
#define TVAR_MAX 100 //�ӽú���
#define SVAR_MAX 3	//Ư���� ����
#define ONE	VAR_MAX + TVAR_MAX + 1
#define TEN VAR_MAX + TVAR_MAX + 2
#define ZERO VAR_MAX + TVAR_MAX + 3
#define TOTAL_VAR (VAR_MAX+TVAR_MAX+SVAR_MAX)
#define COMMAND_LENGTH 20
char Num[TOTAL_VAR][CIPHER_MAX];	//0 ~ TVAR_MAX - 1 : (�ӽú���) ��Ÿ����
char signal[VAR_MAX];	//���� ��ȣ 
char command[COMMAND_LENGTH];	//��� 
void init();

void sendError(int a);	//���� ó��
int input(int a);
int getNew();
int getVarNew();
void show(int a);
int add(int a,int b);
int minus(int a);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int rest(int a, int b);
int compare(int a, int b);
void remover(int a);
void transition(int a,int b);	//a�� b�� ����(����)
void clear();
void save();
void load();
void interpreter();
void showVAR();
int main(void){
	init();

	while(1){
		printf("�Է��ϼ��� : "); 
		gets(command);
		if(strcmp(command,"end") == 0)
			break;
		else if(strcmp(command,"clear") == 0)
			clear();
		else if(strcmp(command,"save") == 0)
			save();
		else if(strcmp(command,"load") == 0)
			load();
		else if(strcmp(command,"var") == 0)
			showVAR();
		else
			interpreter();

		for(int i = 0 ;i < COMMAND_LENGTH; i++)
			command[i] = 0;
	}
	
}

