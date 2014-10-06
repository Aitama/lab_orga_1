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


double Taylor(double y){//Entra el valor del logaritmo a lcalcular
	double x = (y-1)/(y+1);//Se simplifica en algo el codigo y el calculo
	return 2 * (c0 * x +  //Se retorna la operacion matematica del logaritmo natural
			c1 * x * x * x +
			c2 * x * x * x * x * x  +
			c3 * x * x * x * x * x * x * x +
			c4 * x * x * x * x * x * x * x * x * x +
			c5 * x * x * x * x * x * x * x * x * x * x * x +
			c6 * x * x * x * x * x * x * x * x * x * x * x * x * x +
			c7 * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x);
}


int main(int argc,char *argv[]){//Entran los argumentos con getopt
	int sgte_opcion;//Valor en ascii de la opcion -i o -n segun corresponda
	char *tipo = "i:n:";//"i" y "n" corresponden a los caracteres que anteceden a los argumentos
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
						ultimo = Taylor(x);//Se calcula el valor del logaritmo
					}
					printf("%f\n",ultimo);//Imprime por pantalla el ultimo calculo del logaritmo natural
					break;
			
		}
	}
	return 0;
}
