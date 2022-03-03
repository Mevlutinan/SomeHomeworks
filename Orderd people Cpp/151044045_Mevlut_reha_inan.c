#include <stdio.h>
#include <string.h>
#define PEOPLES 200
#define WORD_SIZE 50
#define SENT_SIZE 200

struct PeopleID{

    char name[25];
    char surname[50];
    char mail[100];
    int ID;
};

int fixarray(char words[PEOPLES][4][WORD_SIZE],struct PeopleID records[PEOPLES],int size);/*arraydekileri ayırıp structın içine attım*/
int ReadFile();/*dosya okuma*/
int writefile(struct PeopleID records[PEOPLES],int size);/*dosyaya yazma*/
int main() {

   ReadFile();
   return 0;
}

int fixarray(char words[PEOPLES][4][WORD_SIZE],struct PeopleID records[PEOPLES],int size){

	int i=0,j=0,k=0,flag=0;
	int temp;

	while(i<size){
		j=0;
		while(j<4){
				while(words[i][j][k]!='\0'){/*eğer nokta görürse flag 1 yapıyorum*/
					if(words[i][j][k]=='.'){
						flag=1;
				}
				k++;
			}
			k=0;
			if((words[i][j][0]>='A' && words[i][j][0]<='Z') && (words[i][j][1]>='a' && words[i][j][1]<='z') && (flag==0)){/*isimleri structın içine atıyorum*/
				strcpy(records[i].name,words[i][j]);
			}
			else if((words[i][j][0]>='A' && words[i][j][0]<='Z') && (words[i][j][1]>='A' && words[i][j][1]<='Z') && (flag==0)){/*soyadları structın içine attım*/
				strcpy(records[i].surname,words[i][j]);
			}
			else if((words[i][j][0]>='0' && words[i][j][0]<='9') && (flag==0)){/*numaraları structın içine attım*/
				//temp=atoi(words[i][j]);
				sscanf(words[i][j],"%d",&temp);
				records[i].ID=temp;
			}
			else if(flag==1){
				strcpy(records[i].mail,words[i][j]);/*maili structın içine attım*/
				flag=0;
			}
			j++;
		}
		i++;
	}
/*	for(i=0;i<size-1;i++){
		printf("0:%s 1:%s 2:%s 3:%d\n",records[i].name,records[i].surname,records[i].mail,records[i].ID);	
	}
*/
}
int writefile(struct PeopleID records[PEOPLES],int size){

	FILE *fp;
	fp=fopen("Ordered_People","w");

	for(int i=0;i<size-1;i++)
		fprintf(fp,"%s %s %s %d\n",records[i].name,records[i].surname,records[i].mail,records[i].ID);/*dosyaya yazma*/
	fclose(fp);
}

int ReadFile(){

	struct PeopleID records[PEOPLES];
    FILE *fp;
    fp=fopen("Disordered_People.txt","r");
    char word[200],c;
	char bigarray[PEOPLES][4][WORD_SIZE];
	int i=0,j,linesize=0;

	while(fgets(word,SENT_SIZE,fp)!=NULL){/*doyanın içindekileri arraye attım*/
		sscanf(word,"%s %s %s %s\n",bigarray[i][0],bigarray[i][1],bigarray[i][2],bigarray[i][3]);
		i++;
	}
	fclose(fp);
	fp=fopen("Disordered_People.txt","r");
	while((c=getc(fp))!=EOF)if(c=='\n')linesize++;/*dosyadaki satır sayısı*/
	fixarray(bigarray,records,linesize);
	writefile(records,linesize);

    return 0;
}
