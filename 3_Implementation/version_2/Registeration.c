#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
char checker[31],check[21]; 
static int z=0;
int ch;
char x;
char c;
char uname[31], upass[21]; 
int checku,checkp;
struct detail
{
char name[31],pass[31];
}w;
void reg(){
  int i=0;
    FILE *fp;
    if(fp == NULL){
      fp=fopen("Web_reg.txt", "w");
      goto a;
    }
    else{
      fp=fopen("Web_reg.txt", "a");
      goto a;
    }
    a:
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\t\t\t\tWELCOME TO THE REGISTERATION");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i;i<100;i++){
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%20s",checker);
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      scanf("%20s",check);
      strcpy(w.name,checker);
      strcpy(w.pass, check);      
      fprintf(fp,"\t%s %s\n", w.name, w.pass);
      fclose(fp);
      printf("\n\t\t\tSUCCESSFULLY REGISTERED");
      login();
        break;
      }
  }
void login(){
  FILE *fp;
  fp=fopen("Web_reg.txt", "r+");
  if(fp == NULL){
    printf("\t\t\tfile does not found !");
    exit(1);
  } 
  else{
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n\t\t\t\tWELCOME TO LOG IN ZONE\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%30s",uname);
    printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
    scanf("%20s",upass);
    checku=checking(uname);
    checkp=checkpass(upass);
    }
if(checku==0 && checkp==0){
  printf("\n\n\n\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
  printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
}
else if(checku==0&&checkp!=0){
  printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",uname);
  printf("\n\n\t\t\t\t  (Press 'y' to re-enter password)");
  login();
}
else if(checku!=0){
  printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
    reg();
}
}
char checking(char id[]){
  FILE *fp;
  fp=fopen("Web_reg.txt", "r+");
while( (c = fgetc(fp)) != EOF){
      fscanf(fp,"%30s %30s",w.name,w.pass);
      if(strcmp(w.name, id) == 0){
        return 0;
      }
}
}
char checkpass(char pa[]){
  FILE *fp;
  fp=fopen("Web_reg.txt", "r");
while( (c = fgetc(fp)) != EOF){
      fscanf(fp,"%30s %30s",w.name, w.pass);
      if(strcmp(w.pass,pa) == 0){
        return 0;
      }
}
}