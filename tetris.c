#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
void clearscreen(){ //This function clears the screen for Windows. You can modify for your OS.
	system("cls");
}

int main(){
//First of all creating the game table..

int table[50][50],i,j,q,m,N,M,symbolRand,symbol[3][3],temp,mostleft=2,mostright=0,num1,num2,num3,fallrow=3,state,game,avaible=1,fall,countright=1,score=0,highscore=0,playagain=1,scoreshow=0;
char rotate,entry;
printf("Enter the number of rows on your game board : "); scanf("%d",&N);
while(N<3){
	printf("It is too small to play, try again :");
	scanf("%d",&N);
}
printf("Enter the number of columns on your game board : "); scanf("%d",&M);
while(M<4){
	printf("It is too small to play, try again :");
	scanf("%d",&M);
}
while(playagain==1){
	score=0;
	for(i=5;i<5+N;i++){    
		for(j=1;j<1+M;j++){ 
			table[i][j]=0;	
		}
	}
//Our tables outlines. Those lines invisible to user.
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
		table[i][j]=4; //Top outline specifies whether, game lose or not.
	}
	i=3;
	for(j=0;j<2+M;j++){
		table[i][j]=0; //It is where elements starts to fall down.
	}
	i=5+N;              
	for(j=0;j<2+M;j++){
		table[i][j]=1; //Bottom outline determines where the table finish.
	}

	for(i=0;i<3;i++){
		for(j=0;j<2+M;j++){
			table[i][j]=0;
		}
	}	
	game=1;
	//Table is ready for start.
	
	//Creating elements and giving rules.
	
	printf("\n\n");
	printf("\n--RULES and SCORING--");
	printf("\n..When a row is completed by elements indexes,that row pops and above of that row starts to fall down.");
	printf("\n..The popped row gains 100 scores.");
	printf("\n..5 scores for every index you put in to game.");
	printf("\n..You can press 'x' whenever you want to quit.");
	printf("\n..Who gains more score is the winner GOOD LUCK !!\n\n");
	printf("\n\n");
	printf("Press anything to continue.\n");
	
	getch("%c",&entry);

	clearscreen();
	

	while (game==1){ // All functions is working if 'game lose' command not reach.
		changecolor(1);
		scoreshow=score; //We want to show new score after elements motion so thats the trick.
		rotate='p'; // Random char to start rotate part.
		fall = 1;  
		fallrow=3;
		countright=1;
		state=2;
		for(i=0;i<3;i++){
			for(j=1;j<1+M;j++){ 
				table[i][j]=0;
			}
		}
	// Picking elements randomly.
	srand(time(NULL));
	symbolRand=rand()%7+1;
	printf("\n\n   ~SETTLING ELEMENT~\n");
	// Defining elements in to symbol matrix.
	switch (symbolRand){
		case 1 :
		symbol[0][0]=1;
		symbol[1][0]=1;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=0;
		symbol[2][1]=0;
		symbol[0][2]=0;
		symbol[1][2]=0;
		symbol[2][2]=0;
		score+=15;
		break ;
		
		case 2 :
		symbol[0][0]=0;
		symbol[1][0]=1;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=1;
		symbol[2][1]=1;
		symbol[0][2]=0;
		symbol[1][2]=0;
		symbol[2][2]=0;
		score+=20;
		break ;
		
		case 3 :
		symbol[0][0]=0;
		symbol[1][0]=1;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=0;
		symbol[2][1]=0;
		symbol[0][2]=0;
		symbol[1][2]=0;
		symbol[2][2]=0;
		score+=10;
		break ;
		
		case 4 :
		symbol[0][0]=0;
		symbol[1][0]=0;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=0;
		symbol[2][1]=0;
		symbol[0][2]=0;
		symbol[1][2]=0;
		symbol[2][2]=0;
		score+=5;
		break ;
		
		case 5 :
		symbol[0][0]=0;
		symbol[1][0]=0;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=1;
		symbol[2][1]=1;
		symbol[0][2]=0;
		symbol[1][2]=1;
		symbol[2][2]=0;
		score+=20;
		break ;
		
		case 6 :
		symbol[0][0]=0;
		symbol[1][0]=0;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=0;
		symbol[2][1]=1;
		symbol[0][2]=0;
		symbol[1][2]=1;
		symbol[2][2]=1;
		score+=20;
		break ;
		
		case 7 :
		symbol[0][0]=0;
		symbol[1][0]=0;
		symbol[2][0]=1;
		symbol[0][1]=0;
		symbol[1][1]=1;
		symbol[2][1]=1;
		symbol[0][2]=0;
		symbol[1][2]=0;
		symbol[2][2]=1;
		score+=20;
		break ;
		}
	changecolor(4);
	printf("\n--To rotate press 'r'.\n--'d' moves right and 'a' moves left.\n--To settle press 'y'.\n\n");
	
	for(i=0;i<3;i++){
		num3=0;
		for(j=1;j<4;j++){
			table[i][j]=symbol[i][num3];
			num3++;
		}
	}
	changecolor(2);
	for(i=0;i<3;i++){            
		for(j=1;j<1+M;j++){      	
			if(table[i][j]==0)
				printf("    |");
			else
				printf(" #  |");
		}
		if(i==1)
			printf("\t\t--score : %d--",scoreshow);
		printf("\n");
		for(j=1;j<1+M;j++){ 
			printf(" --- ");
		}
		printf("\n\n");
	}
	changecolor(3);
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
		if(rotate== 'r'){ // This function rotates symbol counterclockwise 90 degrees.
			for(i=0;i<3/2;i++){
				for(j=i;j<3-i-1;j++){
					temp=symbol[i][j];
					symbol[i][j]=symbol[j][2-i];
					symbol[j][2-i]=symbol[2-i][2-j];        //It is happening in symbol matrix.
					symbol[2-i][2-j]=symbol[2-j][i];
					symbol[2-j][i]=temp;	
			}
		}
		
		for(i=0;i<3;i++){
			for(j=1;j<1+M;j++){
				table[i][j]=0;
			}
		}
		for(i=0;i<3;i++){
			num3=0;
			for(j=countright;j<countright+3;j++){
				table[i][j]=symbol[i][num3];
				num3++;
				}
			}
		clearscreen();
		changecolor(4);
		printf("\n--To rotate press 'r'.\n--'d' moves right and 'a' moves left.\n--To settle press 'y'.\n\n");
		changecolor(2);
		for(i=0;i<3;i++){             
			for(j=1;j<1+M;j++){     
				if(table[i][j]==0)
					printf("    |");
				else
					printf(" #  |");
		}
		if(i==1)
			printf("\t\t--score : %d--",scoreshow);
		printf("\n");
		for(j=1;j<1+M;j++){      
			printf(" --- ");
		}
		printf("\n\n");

		}
		changecolor(3);
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
	
		// FOR MOVING LEFT
		
		else if (rotate=='a'){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(symbol[i][j]==1){
						if(j<mostleft){
							mostleft=j;
						}
					}
				}
			}
			if(mostleft>0){
				for(i=0;i<3;i++){
					for(j=1;j<3;j++){
						symbol[i][j-1]=symbol[i][j];
						symbol[i][j]=0;
					}
				}
				
				for(i=0;i<3;i++){
					num3=0;
					for(j=countright;j<countright+3;j++){
						table[i][j]=symbol[i][num3];
						num3++;
					}
				}
				
			}
			else{
				mostleft=2;
				if(countright>1){ // It actives if symbol has credit to move right.
					state--;		// Matrix moved.
					countright--; // Losing the closeness to the right.
					for(i=0;i<3;i++){
						for(j=1;j<1+M;j++){
							table[i][j]=0;
						}
					}
					for(i=0;i<3;i++){
						num3=0;
						for(j=countright;j<countright+3;j++){
							table[i][j]=symbol[i][num3];
							num3++;
						}
					}
				}
			}
			clearscreen(); 
			changecolor(4);
			printf("\n--To rotate press 'r'.\n--'d' moves right and 'a' moves left.\n--To settle press 'y'.\n\n");	
			changecolor(2);
			for(i=0;i<3;i++){             
				for(j=1;j<1+M;j++){     
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
				}
			if(i==1)
				printf("\t\t--score : %d--",scoreshow);	
			printf("\n");
			for(j=1;j<1+M;j++){     
				printf(" --- ");
			}
			printf("\n\n");
			}
			changecolor(3);
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
		// FOR MOVING RIGHT
		else if (rotate=='d'){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(symbol[i][j]==1){
						if(j>mostright){
							mostright=j;
						}
					}
				}
			}
			if(mostright<2){
				for(i=0;i<3;i++){
					for(j=1;j>=0;j--){
						symbol[i][j+1]=symbol[i][j];
						symbol[i][j]=0;
					}
				}
				for(i=0;i<3;i++){
					for(j=1;j<1+M;j++){
						table[i][j]=0;
					}
				}
				for(i=0;i<3;i++){
					num3=0;
					for(j=countright;j<countright+3;j++){
						table[i][j]=symbol[i][num3];
						num3++;
					}
				}
			}
			else{
				mostright=0;
				if(countright<M-2){       
					state++;
					countright++;
					for(i=0;i<3;i++){
						for(j=1;j<1+M;j++){ 
							table[i][j]=0;
						}
					}
					for(i=0;i<3;i++){
						num3=0;
						for(j=countright;j<countright+3;j++){
							table[i][j]=symbol[i][num3];
							num3++;
						}
					}
				}
			}
			clearscreen();
			changecolor(4);
			printf("\n--To rotate press 'r'.\n--'d' moves right and 'a' moves left.\n--To settle press 'y'.\n\n");	
			changecolor(2);
			for(i=0;i<3;i++){             
				for(j=1;j<1+M;j++){       
					if(table[i][j]==0)
						printf("    |");
					else
						printf(" #  |");
				}
			if(i==1)
				printf("\t\t--score : %d--",scoreshow);
			printf("\n");
			for(j=1;j<1+M;j++){  
				printf(" --- ");
			}
			printf("\n\n");
			}
			changecolor(3);
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
		game=0;
	}	
	//SETTLING PART..
	clearscreen();
	if(rotate != 'x'){	
	while(fall==1){
		avaible=1;
		num1=0;
		for(i=(fallrow-1);i<(fallrow+2);i++){
			num2=0;
			for(j=(state-1);j<(state+2);j++){
				if(avaible!=2){
					avaible=table[i+1][j]+symbol[num1][num2];	
				}
				num2++;
			}
			num1++;
		}
		if(avaible==2){
			num1=0;
			for(i=(fallrow-1);i<(fallrow+2);i++){
				num2=0;
				for(j=(state-1);j<(state+2);j++){			
					table[i][j]=table[i][j]+symbol[num1][num2];
					num2++;
				}
				num1++;
			}
			fall=0;
		}
		else{
			fallrow++;
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
						
						// Original tetris logic.
						table[m+1][j]=table[m][j]; 
						table[m][j]=0;
						
						/*		// This part activates ; all above elements fall down as every index can.			
						q=m;
						while(table[q+1][j]!=1){ 
							q++;
						}
						table[q][j]=table[m][j]; //moving the indexes down.
						table[m][j]=0;
						*/
					}
				}	
			}
		}
		j=1;
	}
	
	//After settling part if the symbol reached top of the table, it releases game lose info.
	i=4;
	for(j=0;j<2+M;j++){ 
		if(table[i][j]==5){
			game=0;
		}
	}	
	}
	}//game=1
	//Score board for user.
	changecolor(15);
	if(scoreshow>highscore){
		highscore=scoreshow;
		printf("\n\n\t\tNEW HIGHSCORE..CONGRATS !!\n");
	}
	else{
		printf("\n\t\tYOU ARE NOT THE BEST :/ ");
	}
	printf("\n\t\tYOUR SCORE : %d\n",scoreshow);
	printf("\t\tHIGHSCORE : %d\n",highscore);
	printf("\n\t\tPRESS '1' TO PLAY AGAIN.. OK OR CONTINUE ?  ;)\n\t\t");
	scanf("%d",&playagain);
	clearscreen();
}
return 0;
}

void changecolor(int ForgC){
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
 	
	 if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    	SetConsoleTextAttribute(hStdOut, wColor);
	}
	
 return;
}

