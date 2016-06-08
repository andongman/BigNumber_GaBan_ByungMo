/*
	�⺻ ���̽� ���ο� ����
	*/	
#include <stdio.h>
#include <string.h>
#include <conio.h>
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
void init();	//���� �Ҷ� �ʿ��Ѱ� 

void sendError(int a);	//���� ó��
int input(int a);	// �׽�Ʈ������ ���(���ڹޱ�) 
int getNew();	//���ο� �ӽ� ���� �������� 
int getVarNew(); // ���ο� ���� �������� 
void show(int a);	//�׽�Ʈ�� (���� �����ֱ�) 
int add(int a,int b);//���ϱ� 
int minus(int a);//����(���̳ʽ�) 
int subtract(int a, int b);//���� 
int multiply(int a, int b);//���ϱ� 
int divide(int a, int b);//������ 
int rest(int a, int b);//������ 
int compare(int a, int b);//��(������ ��û) 
void remover(int a);//�ӽú��� ���� 
void transition(int a,int b);	//a�� b�� ����(������ ��û) 
void clear();	//ȭ�� ���� 
void save();	//���� ���� 
void load();	//���� �ҷ����� 
void interpreter();	//���� ������(�̿�) 
void showVAR();	//���� �����ֱ� 
void findVarFromSignal(char c);	// ���ڷ� ���� ã�� 
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
		//�׽�Ʈ
		for(int i = 0 ;i < COMMAND_LENGTH; i++)
			command[i] = 0;
	}
	
}
void clear(){
	printf("�������� ���߿� ����\n"); 
}
void init(){
	for(int i = 0 ; i < VAR_MAX + TVAR_MAX; i++)	// ��ȣ �κ��� -1�̸� ���°� ��� 
		Num[i][0] = -1;
		
	for(int i = 0; i < VAR_MAX; i++)
		signal[i] = 0;
	for(int i = 0 ; i< TOTAL_VAR; i++)
		for(int j = 1; j < CIPHER_MAX; j++)	// 0 ���� ���� ���� 
			Num[i][j] = 0;
			
	Num[TEN][CIPHER_MAX - DECIMAL - 2] = 1;	//10
	Num[ONE][CIPHER_MAX - DECIMAL - 1] = 1;	//1
	
}
int findVarFromSignal(char c){
	int var = -1;
	for(int i = 0; i < VAR_MAX; i++)
		if(signal[i] == c || signal[i] + 32 == c || signal[i] - 32 == c)	//��ҹ��� ���� X �����Ƽ� �̷��� 
			var = TVAR_MAX + i;
	return var;
}
int getNew(){
	int newNum = -1;
	for(int i = 0 ; i < TVAR_MAX; i++)	//����ִ� �ӽú��� ã�� 
		 if(Num[i][0] == -1){
		 	newNum = i;
		 	break;
		 }
	if(newNum == -1)	//���� �߻� 
		sendError(ERROR_TVAR_OVERFLOW);
		
	for(int i = 0; i < CIPHER_MAX; i++)	// �ʱ�ȭ 
		Num[newNum][i] = 0;
	return newNum;
}

int getVarNew(){
	int newNum = -1;
	for(int i = TVAR_MAX ; i < TVAR_MAX + VAR_MAX; i++)	//����ִ� �ӽú��� ã�� 
		 if(Num[i][0] == -1){
		 	newNum = i;
		 	break;
		 }
	if(newNum == -1)	//���� �߻� 
		sendError(ERROR_VAR_OVERFLOW);
		
	for(int i = 0; i < CIPHER_MAX; i++)	// �ʱ�ȭ 
		Num[newNum][i] = 0;
	return newNum;
}

//�׽�Ʈ�� 
void show(int a){
	printf("%c",Num[a][0] ? '-' : '+');
	for(int i = 1; i <= CIPHER_MAX - DECIMAL - 1; i++)
	printf("%d",Num[a][i]);
	printf(".");
	for(int i = CIPHER_MAX - DECIMAL; i < CIPHER_MAX; i++)
	printf("%d",Num[a][i]);
	printf("\n");
}
///�׽�Ʈ�� 
int input(){ 
	char in[100];
	int toPoint = -1;	//������ ���� ����
	int newNum = getNew();
	int isMinus = 0;
	gets(in);
	
	if(in[0] == '-'){
		Num[newNum][0] = 1;
		isMinus = 1;
	}
	
	while(in[++toPoint]!='.' && in[toPoint] != 0);	// �����κ� ���� ã�� (���̳ʽ� ��ȣ ����) 
	
	
	for(int i = CIPHER_MAX - DECIMAL - toPoint +  isMinus , j = isMinus; j < toPoint; i++ , j++)
		Num[newNum][i] = in[j] -'0';	//���ڿ��̹Ƿ� 
	for(int i = CIPHER_MAX - DECIMAL , j = toPoint + 1; j < strlen(in); i++ , j++){
		Num[newNum][i] = in[j] -'0';
	}
	return newNum;
}

int compare(int a,int b){	// 1 : (a �� ũ��) 0  : (����) -1 : (b�� ũ��)
	
	for(int i = 1; i < CIPHER_MAX; i++)
	{
		if(Num[a][i] > Num[b][i])
			return 1;
		else if(Num[a][i] < Num[b][i])
			return -1;
	}
	return 0;
}
void transition(int a, int b){
	for(int i = 0 ; i < CIPHER_MAX; i++)
		Num[a][i] = Num[b][i];
}
void remover(int a){
	if(a < TVAR_MAX)
		Num[a][0] = -1;
}

void load(){
	FILE *fp;
	char varChar;
	char in[CIPHER_MAX];
	
	if((fp = fopen("save","r")) == NULL){
		sendError(ERROR_FILE);
		return;
	}
	while(fscanf(fp,"%c %s\n",&varChar,in) != EOF){
		int varNum = findVarFromSignal(varChar);
		if(varNum == -1){
			varNum = getVarNew();
			signal[varNum - TVAR_MAX] = varChar;
		}
		for(int i = 0 ; i < CIPHER_MAX; i++)
			Num[varNum][i] = in[i] - '0';
	}
	fclose(fp);
}
void save(){
	FILE *fp;
	if((fp = fopen("save","w")) == NULL){
		sendError(ERROR_FILE);
		return;
	}
	for(int i = 0; i < VAR_MAX; i++)
		if(Num[TVAR_MAX + i][0] != -1){
			fprintf(fp,"%c ",signal[i]);
			for(int j = 0 ; j< CIPHER_MAX; j++)
				fprintf(fp,"%d",Num[TVAR_MAX + i][j]);
			fprintf(fp,"\n");
		}
	fclose(fp);
}
void showVAR(){
	for(int i = 0; i < VAR_MAX ; i++)
		if(Num[TVAR_MAX + i][0] != -1){
			printf("%c = ",signal[i]);
			show(TVAR_MAX + i);
		}
}
