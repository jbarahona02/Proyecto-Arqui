#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);


// puente H
int IN1 = 24;
int IN2 = 26;

// sensor de color
 int S0 = 37;
 int S1 = 38;
 int S2 = 39;
 int S3 = 40;
 int salidaTCS = 41;

 int numeroProcesos; 
 String rojoBinario,verdeBinario,azulBinario;

void setup(void) {
  // put your setup code here, to run once:

    
 

  //pinMode(IN1, OUTPUT);
  //pinMode(IN2, OUTPUT);

  numeroProcesos = 0;

  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Buscando sensor");
  } else {
    Serial.println("No se encontró el sensor");
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // motorReductorIzquierdaADerecha();
  
  // delay(5000);

  // apagarMotorReductor();

  // delay(4000);

  // motorReductorDerechaAIzquierda();

  // delay(5000);

  // apagarMotorReductor();

  // delay(4000);
  
  tomaDeColor();
}

void tomaDeColor(){
 
  float rojo, verde, azul;

  tcs.getRGB(&rojo,&verde,&azul);

  Serial.print("Rojo: "); Serial.print(int(rojo));
  Serial.print("Verde: "); Serial.print(int(verde));
  Serial.print("Azul: "); Serial.print(int(azul));
  Serial.println(" ");
 //delay(2000);
  // Serial.println("\n\nRojo" + String(rojo));
  // Serial.println(obtenerBinario(rojo));

  rojoBinario = obtenerBinario(rojo);
  verdeBinario = obtenerBinario(verde);
  azulBinario = obtenerBinario(azul);
  
  /*
    Rango verde R: 60 a 110, V: 90 a 132, A: 40 a 90
    Rango naranja R: 165 a 192, V: 30 a 60, A: 20 a 60
    Rango rojo: R: 90 a 180, V: 40 a 105, A: 35 a 105
  */
  if(rojoBinario <= "0000000001101110" && rojoBinario >= "0000000000101000" && 
     verdeBinario >= "0000000001011010" && verdeBinario <= "0000000010000100" && 
     azulBinario >= "0000000000110010" && azulBinario <= "0000000001011010"){
      Serial.println("Detecto color verde " + rojoBinario + " " + verdeBinario + " " + azulBinario);
  } else if (rojoBinario <= "0000000011000000" && rojoBinario >= "0000000010100101" && 
    verdeBinario >= "0000000000011110" && verdeBinario <= "0000000000111100" && 
    azulBinario >= "0000000000010100" && azulBinario <= "0000000000111100") {
    Serial.println("Detecto color naranja " + rojoBinario + " " + verdeBinario + " " + azulBinario);
  } else if (rojoBinario <= "0000000010110100" && rojoBinario >= "0000000001011010" && 
    verdeBinario >= "0000000000101000" && verdeBinario <= "0000000001101001" && 
    azulBinario >= "0000000000100011" && azulBinario <= "0000000001101001") {
    Serial.println("Detecto color rojo " + rojoBinario + " " + verdeBinario + " " + azulBinario);
  } else {
    Serial.println("Detecto color no valido: " + rojoBinario + " " + verdeBinario + " " + azulBinario);
  }

  delay(500);
  
}


void motorReductorIzquierdaADerecha(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}


void motorReductorDerechaAIzquierda(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void apagarMotorReductor(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

String obtenerBinario(int numero) {
  String binario = "";
  for (int i = 15; i >= 0; i--) {
    binario += String((numero >> i) & 1);
  }
  return binario;
}
