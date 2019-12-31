#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
void ekranitemizle(){ //windows icin ekrani temizle ayarinda. Kendi OS'inize gore modifiye edebilirsiniz.
	system("cls");
}

int main(){
//Tetris alanimizi olusturalim..

int table[50][50],i,j,q,m,N,M,sembolRand,sembol[3][3],temp,ensol=2,ensag=0,say1,say2,say3,dusmesatir=3,yer,oyun,musait=1,dusme,countsag=1,score=0,highscore=0,tekraroyna=1,scoreyansit=0;
char rotate,girdi;
printf("Oyun tahtanizin satir sayisini giriniz : "); scanf("%d",&N);
while(N<3){
	printf("Oyun oynamak icin fazla kucuk,bir daha dene en iyisi");
	scanf("%d",&N);
}
printf("Oyun tahtanizin sutun sayisini giriniz : "); scanf("%d",&M);
while(M<4){
	printf("Oyun oynamak icin fazla kucuk,bir daha dene en iyisi");
	scanf("%d",&M);
}
while(tekraroyna==1){
	score=0;
	for(i=5;i<5+N;i++){    
		for(j=1;j<1+M;j++){ 
			table[i][j]=0;	
		}
	}
//Masamizin dis sinirini ciziyoruz.
	j=0;
	for(i=0;i<6+N;i++){  
		table[i][j]=1;
	}
	j=1+M;               
	for(i=0;i<6+N;i++){ 
		table[i][j]=1;
	}
	
	i=4;
	for(j=0;j<2+M;j++){  
		table[i][j]=4; //Masanin ust siniri oyunun bitip bitmemesini belirliyor.
	}
	i=3;
	for(j=0;j<2+M;j++){
		table[i][j]=0; //Dusmeye baslama satiri.
	}
	i=5+N;              
	for(j=0;j<2+M;j++){
		table[i][j]=1; //Table'imizin sonuna geldigimizde altta tabaka oldugunu belirtiyor.
	}

	for(i=0;i<3;i++){
		for(j=0;j<2+M;j++){
			table[i][j]=0;
		}
	}	
	oyun=1;
	// Masa baslangic icin tamamlandi.
	//Sembol tablosunu hazir edelim.
	
	printf("\n\n");
	printf("\n--KURALLAR ve PUANLAMA--");
	printf("\n..Tamamladiginiz her satir patlar ve ustteki taslar asagi hareketlenir.");
	printf("\n..Patlayan her satir 100 puan kazandirir.");
	printf("\n..Oyuna yerlestirdiginiz her kare icin de 5 puan kazanirsiniz.");
	printf("\n..Oyundan cikmak istediginizde 'x' tuslayiniz.");
	printf("\n..En yuksek puani yapan kazanir BOL SANS !!\n\n");
	printf("\n\n");
	printf("Devam etmek icin herhangi bir girdi yapiniz.\n");
	scanf("%c",&girdi);

	ekranitemizle();
	

	while (oyun==1){ // Oyunun kayip komutu gelmedigi surece oyunun butun fonksiyonlarini tekrar calistiracaktir.
		renkdegis(1);
		scoreyansit=score; //Score'un gecikmeli yansimasi icin parametreyi burda degistiriyoruz.
		rotate='p'; // Kullanicidan basta rotate isteyen donguye girebilmek icin rastgele atanmis char.
		dusme = 1;  
		dusmesatir=3;
		countsag=1;
		yer=2;
		for(i=0;i<3;i++){
			for(j=1;j<1+M;j++){ 
				table[i][j]=0;
			}
		}
	// Random sekilde sembol seciyoruz.
	srand(time(NULL));
	sembolRand=rand()%7+1;
	printf("\n\n   ~YERLESTIRILECEK SEMBOL~\n");
	// Secilen random sembole gore sembol tablomuzu olusturuyoruz.
	switch (sembolRand){
		case 1 :
		sembol[0][0]=1;
		sembol[1][0]=1;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=0;
		sembol[2][1]=0;
		sembol[0][2]=0;
		sembol[1][2]=0;
		sembol[2][2]=0;
		score+=15;
		break ;
		
		case 2 :
		sembol[0][0]=0;
		sembol[1][0]=1;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=1;
		sembol[2][1]=1;
		sembol[0][2]=0;
		sembol[1][2]=0;
		sembol[2][2]=0;
		score+=20;
		break ;
		
		case 3 :
		sembol[0][0]=0;
		sembol[1][0]=1;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=0;
		sembol[2][1]=0;
		sembol[0][2]=0;
		sembol[1][2]=0;
		sembol[2][2]=0;
		score+=10;
		break ;
		
		case 4 :
		sembol[0][0]=0;
		sembol[1][0]=0;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=0;
		sembol[2][1]=0;
		sembol[0][2]=0;
		sembol[1][2]=0;
		sembol[2][2]=0;
		score+=5;
		break ;
		
		case 5 :
		sembol[0][0]=0;
		sembol[1][0]=0;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=1;
		sembol[2][1]=1;
		sembol[0][2]=0;
		sembol[1][2]=1;
		sembol[2][2]=0;
		score+=20;
		break ;
		
		case 6 :
		sembol[0][0]=0;
		sembol[1][0]=0;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=0;
		sembol[2][1]=1;
		sembol[0][2]=0;
		sembol[1][2]=1;
		sembol[2][2]=1;
		score+=20;
		break ;
		
		case 7 :
		sembol[0][0]=0;
		sembol[1][0]=0;
		sembol[2][0]=1;
		sembol[0][1]=0;
		sembol[1][1]=1;
		sembol[2][1]=1;
		sembol[0][2]=0;
		sembol[1][2]=0;
		sembol[2][2]=1;
		score+=20;
		break ;
		}
	renkdegis(4);
	printf("\n--Dondurmek icin 'r' tuslayiniz.\n--Saga suruklemek icin'd'sola suruklemek icin'a' tuslayiniz.\n--Yerlestirmek istiyorsaniz 'y' tuslayiniz.\n\n");
	
	for(i=0;i<3;i++){
		say3=0;
		for(j=1;j<4;j++){
			table[i][j]=sembol[i][say3];
			say3++;
		}
	}
	renkdegis(2);
	for(i=0;i<3;i++){            
		for(j=1;j<1+M;j++){      	
			if(table[i][j]==0)
				printf("    |");
			else
				printf(" #  |");
		}
		if(i==1)
			printf("\t\t--score : %d--",scoreyansit);
		printf("\n");
		for(j=1;j<1+M;j++){ 
			printf(" --- ");
		}
		printf("\n\n");
	}
	renkdegis(3);
	for(j=0;j<M;j++){
	printf("-----");
	}
	printf("\n");
	for(i=5;i<5+N;i++){            
		for(j=1;j<1+M;j++){         
			if(table[i][j]==0)
				printf("    |");
			else
				printf(" #  |");
		}
		printf("\n");
		for(j=1;j<1+M;j++){  
			printf(" --- ");
		}
		printf("\n\n");
	}

	while(rotate!= 'y' && rotate!= 'x'){
	
		scanf("%c",&rotate);
		if(rotate== 'r'){ //SAAT YONUNUN TERSINDE 90 DERECE CEVIRMEK ICIN YAPILAN HAREKET
			for(i=0;i<3/2;i++){
				for(j=i;j<3-i-1;j++){
					temp=sembol[i][j];
					sembol[i][j]=sembol[j][2-i];
					sembol[j][2-i]=sembol[2-i][2-j];        //SEMBOL MATRISI ICINDE TASIMIZ DONUSUYOR
					sembol[2-i][2-j]=sembol[2-j][i];
					sembol[2-j][i]=temp;	
			}
		}
		
		for(i=0;i<3;i++){
			for(j=1;j<1+M;j++){
				table[i][j]=0;
			}
		}
		for(i=0;i<3;i++){
			say3=0;
			for(j=countsag;j<countsag+3;j++){
				table[i][j]=sembol[i][say3];
				say3++;
				}
			}
		ekranitemizle();
		renkdegis(4);
		printf("\n--Dondurmek icin 'r' tuslayiniz.\n--Saga suruklemek icin'd'sola suruklemek icin'a' tuslayiniz.\n--Yerlestirmek istiyorsaniz 'y' tuslayiniz.\n\n");
		renkdegis(2);
		for(i=0;i<3;i++){             
			for(j=1;j<1+M;j++){     
				if(table[i][j]==0)
					printf("    |");
				else
					printf(" #  |");
		}
		if(i==1)
			printf("\t\t--score : %d--",scoreyansit);
		printf("\n");
		for(j=1;j<1+M;j++){      
			printf(" --- ");
		}
		printf("\n\n");

		}
		renkdegis(3);
		for(j=0;j<M;j++){
			printf("-----");
		}
		printf("\n");
		for(i=5;i<5+N;i++){          
			for(j=1;j<1+M;j++){     
				if(table[i][j]==0)
					printf("    |");
				else
					printf(" #  |");
		}
		printf("\n");
		for(j=1;j<1+M;j++){
			printf(" --- ");
		}
		printf("\n\n");
		}
		}
	
		// SOLA HAREKET ETTIREBILMEK ICIN
		
		else if (rotate=='a'){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(sembol[i][j]==1){
						if(j<ensol){
							ensol=j;
						}
					}
				}
			}
			if(ensol>0){
				for(i=0;i<3;i++){
					for(j=1;j<3;j++){
						sembol[i][j-1]=sembol[i][j];
						sembol[i][j]=0;
					}
				}
				
				for(i=0;i<3;i++){
					say3=0;
					for(j=countsag;j<countsag+3;j++){
						table[i][j]=sembol[i][say3];
						say3++;
					}
				}
				
			}
			else{
				ensol=2;
				if(countsag>1){ // saga gitme hakkim var ise devreye giriyor.
					yer--;		// matrisimiz yer degistirdi.
					countsag--; // saga yakinligi kaybetmek.
					for(i=0;i<3;i++){
						for(j=1;j<1+M;j++){
							table[i][j]=0;
						}
					}
					for(i=0;i<3;i++){
						say3=0;
						for(j=countsag;j<countsag+3;j++){
							table[i][j]=sembol[i][say3];
							say3++;
						}
					}
				}
			}
			ekranitemizle(); 
			renkdegis(4);
			printf("\n--Dondurmek icin 'r' tuslayiniz.\n--Saga suruklemek icin'd'sola suruklemek icin'a' tuslayiniz.\n--Yerlestirmek istiyorsaniz 'y' tuslayiniz.\n\n");	
			renkdegis(2);
			for(i=0;i<3;i++){             
				for(j=1;j<1+M;j++){     
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
				}
			if(i==1)
				printf("\t\t--score : %d--",scoreyansit);	
			printf("\n");
			for(j=1;j<1+M;j++){     
				printf(" --- ");
			}
			printf("\n\n");
			}
			renkdegis(3);
			for(j=0;j<M;j++){
				printf("-----");
			}
			printf("\n");
			for(i=5;i<5+N;i++){          
				for(j=1;j<1+M;j++){      
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
			}
			printf("\n");
			for(j=1;j<1+M;j++){			
				printf(" --- ");
			}
			printf("\n\n");
			}
		}
		// SAGA HAREKET ETTIREBILMEK ICIN
		else if (rotate=='d'){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(sembol[i][j]==1){
						if(j>ensag){
							ensag=j;
						}
					}
				}
			}
			if(ensag<2){
				for(i=0;i<3;i++){
					for(j=1;j>=0;j--){
						sembol[i][j+1]=sembol[i][j];
						sembol[i][j]=0;
					}
				}
				for(i=0;i<3;i++){
					for(j=1;j<1+M;j++){
						table[i][j]=0;
					}
				}
				for(i=0;i<3;i++){
					say3=0;
					for(j=countsag;j<countsag+3;j++){
						table[i][j]=sembol[i][say3];
						say3++;
					}
				}
			}
			else{
				ensag=0;
				if(countsag<M-2){       
					yer++;
					countsag++;
					for(i=0;i<3;i++){
						for(j=1;j<1+M;j++){ 
							table[i][j]=0;
						}
					}
					for(i=0;i<3;i++){
						say3=0;
						for(j=countsag;j<countsag+3;j++){
							table[i][j]=sembol[i][say3];
							say3++;
						}
					}
				}
			}
			ekranitemizle();
			renkdegis(4);
			printf("\n--Dondurmek icin 'r' tuslayiniz.\n--Saga suruklemek icin'd'sola suruklemek icin'a' tuslayiniz.\n--Yerlestirmek istiyorsaniz 'y' tuslayiniz.\n\n");	
			renkdegis(2);
			for(i=0;i<3;i++){             
				for(j=1;j<1+M;j++){       
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
				}
			if(i==1)
				printf("\t\t--score : %d--",scoreyansit);
			printf("\n");
			for(j=1;j<1+M;j++){  
				printf(" --- ");
			}
			printf("\n\n");
			}
			renkdegis(3);
			for(j=0;j<M;j++){
				printf("-----");
			}
			printf("\n");
			for(i=5;i<5+N;i++){           
				for(j=1;j<1+M;j++){       
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
				}
			printf("\n");
			for(j=1;j<1+M;j++){    
				printf(" --- ");
			}
			printf("\n\n");
			}
		}
		
	}
	if(rotate=='x'){
		oyun=0;
	}	
	//YERLESTIRME ASAMASINA GECIYORUZ..
	ekranitemizle();
	if(rotate != 'x'){	
	while(dusme==1){
		musait=1;
		say1=0;
		for(i=(dusmesatir-1);i<(dusmesatir+2);i++){
			say2=0;
			for(j=(yer-1);j<(yer+2);j++){
				if(musait!=2){
					musait=table[i+1][j]+sembol[say1][say2];	
				}
				say2++;
			}
			say1++;
		}
		if(musait==2){
			say1=0;
			for(i=(dusmesatir-1);i<(dusmesatir+2);i++){
				say2=0;
				for(j=(yer-1);j<(yer+2);j++){			
					table[i][j]=table[i][j]+sembol[say1][say2];
					say2++;
				}
				say1++;
			}
			dusme=0;
		}
		else{
			dusmesatir++;
		}	
	}
	j=1;
	for(i=5;i<5+N;i++){   
		while(table[i][j]!=0 && j<1+M){ 
			j++;
		}
		if(j==1+M){ 
			score+=100;
			for(j=1;j<1+M;j++){ 
				table[i][j]=0;
			}
			for(m=i-1;m>4;m--){
				for(j=1;j<1+M;j++){ 
					if(table[m][j]==1){
						
						// Orijinal tetris mantigi
						table[m+1][j]=table[m][j]; 
						table[m][j]=0;
						
						/*		// Birlesen parcalari ayri ayri hepsini inebildigi en asagi kadar indirmek icin.			
						q=m;
						while(table[q+1][j]!=1){ //patlayan satirdan sonra yukarisindaki tum kareleri,baska bir engelle karsilasana kddar dusuruyoruz.
							q++;
						}
						table[q][j]=table[m][j]; //inmesi gereken kareleri asagi tasiyoruz.
						table[m][j]=0;
						*/
					}
				}	
			}
		}
		j=1;
	}
	
	//Sembol yerlestirilmeye calisirken yukarida tasiyorsa oyunu bitiriyoruz.
	i=4;
	for(j=0;j<2+M;j++){ 
		if(table[i][j]==5){
			oyun=0;
		}
	}	
	}
	}//oyun=1
	//KULLANICI ICIN OYUN SONU SKOR TABLOSU SUNUYORUZ.
	renkdegis(15);
	if(scoreyansit>highscore){
		highscore=scoreyansit;
		printf("\n\n\t\tYENI BIR HIGHSCORE BELIRLEDINIZ..TEBRIKLER !!\n");
	}
	else{
		printf("\n\t\tHALA EN IYISI SIZ DEGILSINIZ :/ "); // KULLANICIYI OYUNUMUZUN BAGIMLISI YAPMAK ICIN TESVIK EDIYORUZ.
	}
	printf("\n\t\tSKORUNUZ : %d\n",scoreyansit);
	printf("\t\tHIGHSCORE : %d\n",highscore);
	printf("\n\t\tTEKRAR OYNAMAK ISTERSENIZ 1'i TUSLAYINIZ.. TAMAM MI ? DEVAM MI ? ;)\n\t\t");
	scanf("%d",&tekraroyna);
	ekranitemizle();
}
return 0;
}

void renkdegis(int ForgC){
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
 	
	 if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    	SetConsoleTextAttribute(hStdOut, wColor);
	}
	
 return;
}
