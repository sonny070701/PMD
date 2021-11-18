#include "Set.h"
#include "Romanos.h"
#include <stdio.h>
#include <string.h>

int int_compare(TYPE data1,TYPE data2) {
	int *np1 = data1;
	int *np2 = data2;
	return(*np1 - *np2);
}

int roman_compare(TYPE data1,TYPE data2) {
	char *rom1 = data1;
	char *rom2 = data2;
	int n1 = romtoara(rom1);
	int n2 = romtoara(rom2);
	return(n1 - n2);
}

void int_print(TYPE data){
	printf("%d\n",*((int *)data));
}

void roman_print(TYPE data) {
	printf("%s\n",(char *)data);
}


char *aratorom(int na){
	int u=na%10;
	int d=na/10%10;
	int c=na/100%10;
	int m=na/1000%10;
	
	char *cad = malloc(40);
	
	strcpy(cad,"");	
	
	switch(m){
		case 1:
			strcat(cad,"M");
			break;
		case 2:
			strcat(cad,"MM");
			break;
		case 3:
			strcat(cad,"MMM");
			break;
	}
	
	switch(c){
		case 1:
			strcat(cad,"C");
			break;
		case 2:
			strcat(cad,"CC");
			break;
		case 3:
			strcat(cad,"CCC");
			break;
		case 4:
			strcat(cad,"CD");
			break;
		case 5:
			strcat(cad,"D");
			break;
		case 6:
			strcat(cad,"DC");
			break;
		case 7:
			strcat(cad,"DCC");
			break;
		case 8:
			strcat(cad,"DCCC");
			break;
		case 9:
			strcat(cad,"CM");
			break;
	}

	switch(d){
		case 1:
			strcat(cad,"X");
			break;
		case 2:
			strcat(cad,"XX");
			break;
		case 3:
			strcat(cad,"XXX");
			break;
		case 4:
			strcat(cad,"XL");
			break;
		case 5:
			strcat(cad,"L");
			break;
		case 6:
			strcat(cad,"LX");
			break;
		case 7:
			strcat(cad,"LXX");
			break;
		case 8:
			strcat(cad,"LXXX");
			break;
		case 9:
			strcat(cad,"XC");
			break;
	}

	switch(u){
		case 1:
			strcat(cad,"I");
			break;
		case 2:
			strcat(cad,"II");
			break;
		case 3:
			strcat(cad,"III");
			break;
		case 4:
			strcat(cad,"IV");
			break;
		case 5:
			strcat(cad,"V");
			break;
		case 6:
			strcat(cad,"VI");
			break;
		case 7:
			strcat(cad,"VII");
			break;
		case 8:
			strcat(cad,"VIII");
			break;
		case 9:
			strcat(cad,"IX");
			break;
	}
	return(cad);
}

int romtoara(char *nr){
	int res=0;
	
	// Millares
	if(strncmp(nr,"MMM",3)==0){
		res = 3000;
		nr = nr + 3;
	}
	else if(strncmp(nr,"MM",2)==0){
		res = 2000;
		nr = nr + 2;
	}
	else if(strncmp(nr,"M",1)==0){
		res = 1000;
		nr = nr + 1;
	}
	
	// Centenas
	if(strncmp(nr,"DCCC",4)==0){
		res=res+800;
		nr = nr + 4;
	}
	else if(strncmp(nr,"CCC",3)==0){
		res=res+300;
		nr = nr + 3;
	}
	else if(strncmp(nr,"DCC",3)==0){
		res=res+700;
		nr = nr + 3;
	}
	else if(strncmp(nr,"CC",2)==0){
		res=res+200;
		nr = nr + 2;
	}
	else if(strncmp(nr,"CD",2)==0){
		res=res+400;
		nr = nr + 2;
	}
	else if(strncmp(nr,"DC",2)==0){
		res=res+600;
		nr = nr + 2;
	}
	else if(strncmp(nr,"CM",2)==0){
		res=res+900;
		nr = nr + 2;
	}
	else if(strncmp(nr,"C",1)==0){
		res=res+100;
		nr = nr + 1;
	}
	else if(strncmp(nr,"D",1)==0){
		res=res+500;
		nr = nr + 1;
	}

	// Decenas
	if(strncmp(nr,"LXXX",4)==0){
		res=res+80;
		nr = nr + 4;
	}
	else if(strncmp(nr,"XXX",3)==0){
		res=res+30;
		nr = nr + 3;
	}
	else if(strncmp(nr,"LXX",3)==0){
		res=res+70;
		nr = nr + 3;
	}
	else if(strncmp(nr,"XX",2)==0){
		res=res+20;
		nr = nr + 2;
	}
	else if(strncmp(nr,"XL",2)==0){
		res=res+40;
		nr = nr + 2;
	}
	else if(strncmp(nr,"LX",2)==0){
		res=res+60;
		nr = nr + 2;
	}
	else if(strncmp(nr,"XC",2)==0){
		res=res+90;
		nr = nr + 2;
	}
	else if(strncmp(nr,"X",1)==0){
		res=res+10;
		nr = nr + 1;
	}
	else if(strncmp(nr,"L",1)==0){
		res=res+50;
		nr = nr + 1;
	}

	// Unidades
	if(strncmp(nr,"VIII",4)==0){
		res=res+8;
		nr = nr + 4;
	}
	else if(strncmp(nr,"III",3)==0){
		res=res+3;
		nr = nr + 3;
	}
	else if(strncmp(nr,"VII",3)==0){
		res=res+7;
		nr = nr + 3;
	}
	else if(strncmp(nr,"II",2)==0){
		res=res+2;
		nr = nr + 2;
	}
	else if(strncmp(nr,"IV",2)==0){
		res=res+4;
		nr = nr + 2;
	}
	else if(strncmp(nr,"VI",2)==0){
		res=res+6;
		nr = nr + 2;
	}
	else if(strncmp(nr,"IX",2)==0){
		res=res+9;
		nr = nr + 2;
	}
	else if(strncmp(nr,"I",1)==0){
		res=res+1;
		nr = nr + 1;
	}
	else if(strncmp(nr,"V",1)==0){
		res=res+5;
		nr = nr + 1;
	}
	return(res);
}