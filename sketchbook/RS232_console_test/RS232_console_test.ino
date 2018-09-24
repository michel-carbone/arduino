/*******************************************************
This program will test the CPU usage with RS232
Michel Carbone, September 2018
********************************************************/

// function setup()
// is call automaticaly at startup and init all libraries and ports if needed 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

// variable for loop() pointer
long i = 0; // pointer

// function loop()
// is call automaticaly after setup() and run forever after setup
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Step number ");
  Serial.print(i);
  Serial.print("; time elapsed: ");
  Serial.println(millis());
  i=i+1;
  delay(10);
}
