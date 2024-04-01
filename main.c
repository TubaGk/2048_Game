#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

int konum[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int randomnum=4,score=0,zerocont=0;
int main(){
    setlocale(LC_ALL, "Turkish");
    label:
	yenisayi();
	yenisayi();
	tablo();
	while(1){
		char yon;
		yon=getche();


		if(yon=='W' || yon=='w'){
			dondurme(1);
			islem();
			yenisayi();
			dondurme(3);
			tablo();


		}
		else if(yon=='A' || yon=='a'){
			islem();
			yenisayi();
			tablo();

		}
		else if(yon=='S'|| yon=='s'){
			dondurme(3);
			islem();
			yenisayi();
			dondurme(1);
			tablo();
		}
		else if(yon=='D'|| yon=='d'){
			dondurme(2);
			islem();
			yenisayi();
			dondurme(2);
			tablo();
		}
		else if(yon=='F' || yon=='f'){
			oyun_bitir();
			return 0;
		}



	}
	return 0;
}


void tablo(){
	int i,j,k,l;
	system("cls");
	printf("                       ** 2048 OYUNU **      \n");
	printf(" OYNANIÞ=\n W(YUKARI),S(AÞAÐI),D(SAÐA),A(SOLA),F(ÇIKIÞ) TUÞLARINI KULLANIN\n_______________________________________________\n\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("   %d  ",konum[i][j]);
		}
		printf("\n\n");
	}
	printf("_______________________________________________\n PUANINIZ: %d\n",score);
}
void contzero(){
	int i,j;
	zerocont=0;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			if(konum[i][j]==0){
				zerocont++;
			}
		}
	}
}




void yenisayi(){
	int i,j,k,l,c;
	srand(time(NULL));
	contzero();
	if(zerocont!=0){
		while(1){
			i=rand()%4;
			j=rand()%4;
			c=1+rand()%2;
 			if(konum[i][j]==0){
                    if(score<=1000){
                            konum[i][j]=2;
                    }
                    else{
                        konum[i][j]=2*c;
                    }

 				break;
 				}
		}
	}
}





void islem(){
	int i,j,k,l,gocount=0;

	for(i=0;i<4;i++){
		for(l=0;l<4;l++){
			for(j=3;0<j;j--){
				if(konum[i][j-1]==0){
					konum[i][j-1]=konum[i][j];
					konum[i][j]=0;
					gocount+=1;
				}
			}
		}


		for(k=1;k<4;k++){
			if(konum[i][k]==konum[i][k-1]){
				konum[i][k-1]=konum[i][k]+konum[i][k-1];
				konum[i][k]=0;
				gocount+=1;
				score+=konum[i][k-1];
			}
		}
		for(l=0;l<4;l++){
			for(j=3;0<j;j--){
				if(konum[i][j-1]==0){
					konum[i][j-1]=konum[i][j];
					konum[i][j]=0;
					gocount+=1;
				}
			}
		}


	}
	if(gocount==0){

		oyun_bitir();
	}

}


void dondurme(turnnum){
	int i,temp=0;
	for(i=0;i<turnnum;i++){

		temp=konum[0][0];
		konum[0][0]=konum[0][3];
		konum[0][3]=konum[3][3];
		konum[3][3]=konum[3][0];
		konum[3][0]=temp;
		temp=0;

		temp=konum[0][1];
		konum[0][1]=konum[1][3];
		konum[1][3]=konum[3][2];
		konum[3][2]=konum[2][0];
		konum[2][0]=temp;
		temp=0;

		temp=konum[0][2];
		konum[0][2]=konum[2][3];
		konum[2][3]=konum[3][1];
		konum[3][1]=konum[1][0];
		konum[1][0]=temp;
		temp=0;

		temp=konum[1][1];
		konum[1][1]=konum[1][2];
		konum[1][2]=konum[2][2];
		konum[2][2]=konum[2][1];
		konum[2][1]=temp;
		temp=0;
	}
}

void oyun_bitir(){
	system("cls");
	printf("OYUN BÝTTÝ \n ");
	printf("PUANINIZ :%d ",score);
	getch();
	return 0;
}
