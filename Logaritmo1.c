#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

//Se definen las primeras 8 constantes utilizadas por la serie de taylor
static double c0 = 1.0;
static double c1 = 1.0/3;
static double c2 = 1.0/5;
static double c3 = 1.0/7;
static double c4 = 1.0/9;
static double c5 = 1.0/11;
static double c6 = 1.0/13;
static double c7 = 1.0/15;


double Taylor4(double y){//Entra el valor del logaritmo al calcular
	//Se simplifica en algo el codigo y el calculo
	double x = (y-1)/(y+1);
	double y2 = x * x;
	double y4 = y2 * y2;
	double R = y2 * (c2 + y2 * (c3 + y2 * c4));
	double L = y4 * ( y2 * (c5 + y2 * (c6 + y2 * c7)));
	return 2 * y * (c0 + y2 * (c1 + R + L));//Se retorna la operacion matematica del logaritmo natural
}


int main(int argc,char *argv[]){//Entran los argumentos con getopt
	int sgte_opcion;//Valor en ascii de la opcion -i o -n segun corresponda
	char *tipo = "i:n:";//"i" y "n" son las opciones cortas correspondientes que reciben un argumento obligatorio cada una.
	int x,iteracion;//x = logaritmo a calcular. iteracion = numero de iteraciones de la funcion logaritmo
	double ultimo;// ultimo = ultimo valor del logaritmo calculado
	while(1){//entra si o si al while
		sgte_opcion = getopt_long(argc,argv,tipo,NULL,NULL);//Obtiene el tipo de argumento que se esta ingresando
		if (sgte_opcion == -1) break;//Si no hay argumentos, se sale.
		switch(sgte_opcion){
			case 'i':	iteracion = atoi(optarg);//Si el argumento que viene es del tipo i
					break;                         //este correspondera al numero de iteraciones
			case 'n':	x = atoi(optarg);//Si el argumento que vienes es del tipo n
					int i;                 //este correspondera al numero de logartimo a calcular
					for (i = 0; i<iteracion;i++){//se realizan el numero de iteraciones ingresadas
						ultimo = Taylor4(x);//Se calcula el valor del logaritmo
					}
					printf("%f\n",ultimo);//Imprime por pantalla el ultimo calculo del logaritmo natural
					break;
			
		}
	}
	return 0;
}
