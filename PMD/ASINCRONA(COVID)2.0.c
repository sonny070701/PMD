//Laura Patricia Garcia Reyes
//Sonny Dominique Ceja Celis

 #include <stdio.h> //para funciones basicas
#include <stdlib.h> // para el rand
#include <time.h> // para el time
#include <windows.h> //para los colores

typedef enum {
	SANO, ENFERMO, RECUPERADO   //tipo de datos status (0,1,2)
} STATUS;

typedef enum{
	CON, SIN     ///tipo de datos de cubrebocas (0, 1)
}MASCARA;

typedef enum{
    LIBRE, OCUPADO    ///tipo de datos de las celdas (0, 1)
}CELSTAT;

typedef struct {
	STATUS status;
	MASCARA cubrebocas;
    CELSTAT celstat;     ///estructura con los datos
	int dias;
	int edad;
	int identificador;
} CELDA;

void Inicio(CELDA* a) {   ///funcion de inicio, inicializa la matriz

	int vacio = 20, id = 1, anios;

	for (int y = 0; y < 1600; y++) {    //recorre los espacios de la matriz
		((a+y))->dias = 0;   			//inicializa en 0 los dias
		int paciente = rand() % 101;    //genera aleatoriamente a la gente
		if (paciente >= vacio) {        //si no esta vacio
			((a+y))->status = SANO;     //si esta ocupado es s
      ((a+y))->celstat = OCUPADO;
		}
		else
			(a+y)->celstat= LIBRE;      //si esta libre " "
			(a+y)->identificador = id;
			id++; 						//aumenta el numero del identificador

			anios = rand() & 91;        // edad aleatoria
			(a+y)->edad = anios;
			(a+y)->cubrebocas = rand() % 2;  //genera la mitad con cubrebocas y la mitad sin
	}

	    int y = 1 +rand() % 1600; // generamos un paciente enfermo en y

	    (a+y)->status = ENFERMO;

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //para poner color a las personas
  		for(int i = 0; i < 40; i++){
  			for(int j = 0; j < 40; j++){

  			if((a+(i*40)+j)->celstat == LIBRE) {
  			printf("  "); 						     //un espacio en las celdas vacias
  			}
  			else{
  			if((a+(i*40)+j)->status == SANO){
  				if((a+(i*40)+j)->cubrebocas == CON){
  					SetConsoleTextAttribute(hConsole, 2); //sano y con cubrebocas s
  					printf(" s");
  				}
  			else{
  				SetConsoleTextAttribute(hConsole, 10);    //sin cubrebocas y sano S
  				printf(" S");
  					}
  				}
  			else if((a+(i*40)+j)->status == ENFERMO){
  				if((a+(i*40)+j)->cubrebocas == CON){
  					SetConsoleTextAttribute(hConsole, 6); //enfermo y con cubrebocas e
  					printf(" e");
  				}
  			else{
  				SetConsoleTextAttribute(hConsole, 4);     //enfermo y sin cubrebocas E
  				printf(" E");
  					}
  				}
  			else{
  				if((a+(i*40)+j)->cubrebocas == CON) {
  					SetConsoleTextAttribute(hConsole, 11); //recuperado y con cubrebocas r
  					printf(" r");
  				}
  			else{
  				SetConsoleTextAttribute(hConsole, 3);	   //recuperado y sin cubrebocas R
  				printf(" R");
  						}
  					}
  				}
  			}
  		printf("\n");	//imprimir matriz
  	}
 }

void Interaciones(CELDA *a, CELDA *b) { 		//matriz orginal y la que muestra cambios

	int xder, xizq, ysup, yinf;  				//para visitar cada celda y comparar
	for (int y = 0; y < 40; y++) {
		for (int x = 0; x < 40; x++) {
			int prob;							//para definir la probabilidad
			int enfermo = 0;					//genera enfermos
			int reinfectado = 0;				//genera reinfectados
			xder = x + 1;						//visitamos el eje x y aumentamos 1 por ciclo
			xizq = x - 1;						//visitamos el eje x y disminuyemos 1 por ciclo
			ysup = y - 1;						//visitamos el eje y y disminuyemos 1 por ciclo
			yinf = y + 1;						//visitamos el eje y y aumentamos 1 por ciclo

			if (((a+ysup*40)+xizq)->status == ENFERMO) {
				if(((a+ysup*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				} //ambos sin cubrebocas, probabilidad del 80%
				else if(((a+ysup*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25; //uno con cubrebocas, probabilidad del 25%
				}
				else if(((a+ysup*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7; //ambos con cubrebocas, probabilidad del 7%
				}
				if(rand() %101 < prob){
				enfermo++; //si sobrepasa la probabilidad se infecta
				}
			}
			if (((a+y*40)+xizq)->status == ENFERMO) {
				if(((a+y*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+y*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+y*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+yinf*40)+xizq)->status == ENFERMO) {
				if(((a+yinf*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+yinf*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+yinf*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+ysup*40)+x)->status == ENFERMO) {
				if(((a+ysup*40)+x)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+ysup*40)+x)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+ysup*40)+x)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+yinf*40)+x)->status == ENFERMO) {
				if(((a+yinf*40)+x)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+yinf*40)+x)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+yinf*40)+x)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+ysup*40)+xder)->status == ENFERMO) {
				if(((a+ysup*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+ysup*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+ysup*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+y*40)+xder)->status == ENFERMO) {
				if(((a+y*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+y*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+y*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}
			if (((a+yinf*40)+xder)->status == ENFERMO) {
				if(((a+yinf*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 80;
				}
				else if(((a+yinf*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 25;
				}
				else if(((a+yinf*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 7;
				}
				if(rand() %101 < prob){
				enfermo++;
				}
			}

      if (((a+ysup*40)+xizq)->status == RECUPERADO) { //Para recuperados
				if(((a+ysup*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40; //Ambos sin cubrebocas, probabilidad del 40%
				}
				else if(((a+ysup*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12; //uno sin cubrebocas, probabilidad del 12%
				}
				else if(((a+ysup*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3; //ambos con cubrebocas, probabilidad del 3%
				}
				if(rand() %101 < prob){
				reinfectado++;
				}
			}
			if (((a+y*40)+xizq)->status == RECUPERADO) {
				if(((a+y*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+y*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+y*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
				reinfectado++;
				}
			}
			if (((a+yinf*40)+xizq)->status == RECUPERADO) {
				if(((a+yinf*40)+xizq)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+yinf*40)+xizq)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+yinf*40)+xizq)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
				reinfectado++;
				}
			}
			if (((a+ysup*40)+x)->status == RECUPERADO) {
				if(((a+ysup*40)+x)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+ysup*40)+x)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+ysup*40)+x)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
					reinfectado++;
				}
			}
			if (((a+yinf*40)+x)->status == RECUPERADO) {
				if(((a+yinf*40)+x)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+yinf*40)+x)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+yinf*40)+x)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
					reinfectado++;
				}
			}
			if (((a+ysup*40)+xder)->status == RECUPERADO) {
				if(((a+ysup*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+ysup*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+ysup*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
					reinfectado++;
				}
			}
			if (((a+y*40)+xder)->status == RECUPERADO) {
				if(((a+y*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+y*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+y*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
					reinfectado++;
				}
			}
			if (((a+yinf*40)+xder)->status == RECUPERADO) {
				if(((a+yinf*40)+xder)->cubrebocas == SIN && ((a+y*40)+x)->cubrebocas == SIN){
					prob = 40;
				}
				else if(((a+yinf*40)+xder)->cubrebocas == SIN || ((a+y*40)+x)->cubrebocas == SIN){
					prob = 12;
				}
				else if(((a+yinf*40)+xder)->cubrebocas == CON && ((a+y*40)+x)->cubrebocas == CON){
					prob = 3;
				}
				if(rand() %101 < prob){
					reinfectado++;
				}
			}

			if(((a+y*40)+x)->status == ENFERMO){ // si superan 10 dias, se vuelven recuperados
				((b+y*40)+x)->status = ENFERMO;
				if(((a+y*40)+x)->dias == 10){
					((b+y*40)+x)->status = RECUPERADO;
						}
				(((b+y*40)+x)->dias++); //se incrementan los dias
				}

			if(((a+y*40)+x)->status == SANO){ //si un sano entra en contacto se vuelve enfermo
				if(enfermo > 0){
					((b+y*40)+x)->status = ENFERMO;
				}
				else
					((b+y*40)+x)->status = SANO; //de lo contrario se mantiene igual
			}
			if(((a+y*40)+x)->status == RECUPERADO){ //si un recuperado entra en contacto
				((b+y*40)+x)->status = RECUPERADO;// con enfermos se infecta
				(((b+y*40)+x)->dias = 0);
				if(reinfectado > 0){
				((b+y*40)+x)->status = ENFERMO;
				if(((a+y*40)+x)->status == ENFERMO){ //si un enfermo pasa 10 dias se recupera
					((b+y*40)+x)->status = ENFERMO;
					if(((a+y*40)+x)->dias == 10){
						((b+y*40)+x)->status = RECUPERADO;
					}
					((b+y*40)+x)->dias++;
					}
				}
			}
			if(((a+y*40)+x)->celstat == LIBRE){ //celdas libres se mantienen igual
				((b+y*40)+x)->celstat = LIBRE;
			}
		}
	}
	for(int y = 0; y < 40; y++){
		for(int x = 0; x < 40; x++){
			((a+y*40)+x)->status = ((b+y*40)+x)->status; //se comparan ambas matrices
			((a+y*40)+x)->dias = ((b+y*40)+x)->dias;
		}
	}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //se asignan colores igual que anterior
		for(int i = 0; i < 40; i++){
			for(int j = 0; j < 40; j++){
			if((a+(i*40)+j)->celstat == LIBRE){
			printf("  ");}
			else{
			if((a+(i*40)+j)->status == SANO){
			if((a+(i*40)+j)->cubrebocas == CON){
			SetConsoleTextAttribute(hConsole, 2);
			printf(" s");}
			else{
			SetConsoleTextAttribute(hConsole, 10);
			printf(" S");}}
			else if((a+(i*40)+j)->status == ENFERMO){
			if((a+(i*40)+j)->cubrebocas == CON){
			SetConsoleTextAttribute(hConsole, 6);
			printf(" e");}
			else{
			SetConsoleTextAttribute(hConsole, 4);
			printf(" E");}}
			else{
			if((a+(i*40)+j)->cubrebocas == CON) {
			SetConsoleTextAttribute(hConsole, 11);
			printf(" r");}
			else{
			SetConsoleTextAttribute(hConsole, 3);
			printf(" R");
						}
					}
				}
			}
		printf("\n");
	}
}

int main() {
	int n;
	CELDA MATRIZ[40][40]; //se genera la matriz
	setbuf(stdout, NULL);
	srand(time(NULL));  // se genera las semillas

	Inicio(*MATRIZ); //se invoca la funcion 1
	printf("\n\n\n1 Para continuar:\n ");
	scanf("%d", &n);
	while (n == 1) {
		Interaciones(*MATRIZ, *MATRIZ); //se invoca la funcion de cambios
		printf("\n\n\n1 Para continuar:\n ");
		scanf("%d", &n);
	}
}


