/*
   ################
   #   Lab15125   #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor ultrasonico ping (parallax)

   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746' Inches ; TO_CM = 29_034' Centimeters ]

   El circuito:
     * +V conectado a sensor PING))) en +5V
     * GND conectado a sensor PING))) en GND (ground)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)
   
   Funcion
   readUltrasonicDistance(int triggerPin, int echoPin): Referencia obtenida de sensor ultrasonico tinkercad.com
*/

/*
   Esta version del codigo cumple con los requerimientos del circuito electrico presentados en la experiencia
   N°3 del laboratorio de robotica realizada el dia 21/08/2020, en donde se valida el rango operacional del 
   circuito y se intercambia el accionamiento del LED rojo con el LED verde.
*/

/*
Inicio declaracion funcion readUltrasonicDistance
Se define la funcion de lectura del sensor ultrasonico ping entregada por el fabricante parallax
*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);
}
/*
Fin declaracion funcion readUltrasonicDistance
*/

/*
Inicio funcion setup
*/

void setup()
{
  Serial.begin(9600);   //comunicación serial 9600 caracteres por segundo
  pinMode(8, OUTPUT);   //Se definen las señales de salida (LED's)
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}
/*
Fin funcion setup
*/

/*
Inicio funcion loop
*/
void loop()
{
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);   //Se define la variable flotante distancia que indica la lectura en [cm] del sensor (Se aplica el factor de conversion)
  if((distancia <= 336) && (distancia >= 200)) {	           //Se define la condicion (intervalo de distancia) para prender el LED rojo. Todas las condiciones consideran el rango operacional del sensor
    digitalWrite(4, HIGH);                                    //Intervalo LED rojo [200:336] centimetros
  }                                                           //Si se cumple la condicion, se prende el LED rojo. De lo contrario, se mantiene apagado
  else {						    
    digitalWrite(4, LOW);
  }
  if((distancia < 200) && (distancia >= 100)) {		     //Se define la condicion (intervalo de distancia) para prender el LED amarillo
    digitalWrite(7, HIGH);                              //Intervalo LED amarillo [100:200[ centimetros
  }                                                     //Si se cumple la condicion, se prende el LED amarillo. De lo contrario, se mantiene apagado.
  else {						     
    digitalWrite(7, LOW); 
  }
  if(distancia < 100) {					 //Se define la condicion (intervalo de distancia) para prender el LED verde.
    digitalWrite(8, HIGH);           //Intervalo LED verde, distancia menor que 100 centimetros (considerando rango operacional)
  } 							             //Si se cumple la condicion, se prende el LED verde. De lo contrario, se mantiene apagado.
  else {
    digitalWrite(8, LOW); 
  }
  delay(10); 					          //Pequeño retraso para mejorar el rendimiento de la simulacion

}
/*
Las lineas de codigo definidas a continuacion se utilizaron para obtener referencias sobre las lecturas del sensor
durante la calibracion del mismo. Las referencias se visualizan en el "Monitor en serie" del simulador.
 *SE COMPARA MONITOR SERIE CON VALOR VISUAL DEL SENSOR SUS RANGO Y SE CALIBRA*
  //Serial.print("distancia: "); //IMPRIMIR EN MONITOR SERIE EL STRING DISTANCIA
  //Serial.println(distancia+1.8); // IMPRIME VALOR NUMERICO LA VARIABLE DISTANCIA 
*/

/*
 #######################
 #   Fin de programa   #
 #######################
*/
