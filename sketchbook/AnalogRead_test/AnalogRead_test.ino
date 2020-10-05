//Read the six 10-bit analog values from each potentiometer
//and display them in an organized table on the Serial Monitor

//variable declarations
int A0value = 0;
int A1value = 0;
int A2value = 0;
int A3value = 0;
int A4value = 0;
int A5value = 0;
int A6value = 0;
int A7value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  Serial.print("Readings from analog channels 0-7");
  Serial.print("\n");
  Serial.print("micros\tA0\tA1\tA2\tA3\tA4\tA5\tA6\tA7\n");

}

void loop() {
  // put your main code here, to run repeatedly:
  A0value = analogRead(A0);
  A1value = analogRead(A1);
  A2value = analogRead(A2);
  A3value = analogRead(A3);
  A4value = analogRead(A4);
  A5value = analogRead(A5);
  A6value = analogRead(A6);
  A7value = analogRead(A7);
  
  Serial.print(micros());
  Serial.print('\t');
  Serial.print(A0value);
  Serial.print('\t');
  Serial.print(A1value);
  Serial.print('\t');
  Serial.print(A2value);
  Serial.print('\t');
  Serial.print(A3value);
  Serial.print('\t');
  Serial.print(A4value);
  Serial.print('\t');
  Serial.print(A5value);
  Serial.print('\t');
  Serial.print(A6value);
  Serial.print('\t');
  Serial.print(A7value);
  Serial.print('\n');
  delay(10);
  
}
