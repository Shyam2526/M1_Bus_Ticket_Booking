#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "header.h"
struct bus{
  char code[21];
  char pp[21];
  char des[21];
  int cost;
  int seat_no[30];
  int total_seat;
}bu;
int a=0;
char p,m;
void admin(){
  int s;
  printf("\n\t\t\tONLY FOR ADMIN USERS\n");
  printf("\n\t\t\tEnter UserName\n\t\t\t");
  scanf("%20s", ad_user);
  if(strcmp("shyam",ad_user)==0){
    printf("\n\t\t\tENTER PASSWORD\n\t\t\t");
    while((p=getch())!=13){
          ad_pass[a++]=p;
          printf("%c",'*');
        }

    if(strcmp("ram",ad_pass)==0){
      z:
      system("cls");
      printf("\n\t\t\tEnter >1< To View Passengers History ");
	    printf("\n\t\t\tEnter >2< To Insect Route");
      printf("\n\t\t\tEnter >0< Go To Main Menu");
      printf("\n\t\t\tENTER THE CHOICE :: ");
      scanf("%d",&s);
      switch (s){
        case 1:
    		travel_histroy();
        goto z;
   	  	break;
		    case 2:
		    insect_route();
        goto z;
		    break;
        case 0:
    		call();
    		break;
        default:
        printf("WRONG CHOICE");
        goto z;
        break;
        }
      }
  }
}
void insect_route()
{
  FILE *log;
  if(log == NULL){
    log=fopen("project.txt", "w");
    goto b;
  }
  else{
    log = fopen("project.txt", "a");
    goto b;
  }
  b:
  printf("\n\t\tEnter the Route Code\n\t\t");
  scanf("%20s",bu.code);
  printf("\n\t\tEnter the departure place\n\t\t");
  scanf("%20s", bu.pp);
  printf("\n\t\tEnter the arriving place\n\t\t");
  scanf("%20s", bu.des);
  printf("\n\t\tEnter the Ticket Price\n\t\t");
  scanf("\t\t%d", &bu.cost);
  if(log == NULL){
    printf("FIle not Found");
	}
	else{
	  fprintf(log, "%s %s %s %d \n", bu.code, bu.pp, bu.des, bu.cost);
	  printf("Recorded Successfully");
	}
	printf("\n");
	fclose(log);
  getch();
	system("cls");
}
void travel_histroy(){
	FILE *fp;
  system("clear");
	fp = fopen("histroy.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
  }
	else
	{	
		system("cls");
		while( ( m = fgetc(fp) ) != EOF )
   		printf("%c",m);
	}
	fclose(fp);
  getch();
  system("cls");
}
