
// puente H
int IN1 = 24;
int IN2 = 26;

// sensor de color
//  int S0 = 37;
//  int S1 = 38;
//  int S2 = 39;
//  int S3 = 40;
//  int SALIDA_TCS = 41;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // pinMode(S0,OUTPUT);
  // pinMode(S1,OUTPUT);
  // pinMode(S2, OUTPUT);
  // pinMode(S3, OUTPUT);
  // pinMode(SALIDA_TCS, INPUT);

  // digitalWrite(S0, HIGH);
  // digitalWrite(S1, LOW);

  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  motorReductorIzquierdaADerecha();
  
  delay(5000);

  apagarMotorReductor();

  delay(4000);

  motorReductorDerechaAIzquierda();

  delay(5000);

  apagarMotorReductor();

  delay(4000);
  
  // Serial.print(IN1);
  // Serial.print(IN1);

}
/*
void tomaDeColor(){
  // rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int rojo = pulseIn(SALIDA_TCS, LOW);
  delay(200);

  // verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  int verde = pulseIn(SALIDA_TCS, LOW);
  delay(200);

  // azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  int rojo = pulseIn(SALIDA_TCS, LOW);
  delay(200);

  Serial.print("R:");
  Serial.print(rojo);

  Serial.print("\t");
  
  Serial.print("V:");
  Serial.print(verde);

  Serial.print("\t");

  Serial.print("A:");
  Serial.println(azul);
}*/


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
