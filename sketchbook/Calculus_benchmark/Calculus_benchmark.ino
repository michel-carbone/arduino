/*******************************************************
This program will measure the CPU time usage for differents
calculation, e.g. integer addition, float addition, etc
Michel Carbone, September 2018
********************************************************/
// variables for timing calculation
long tStart = 0;    // time in us before calculation
long tStop = 0;     // time in us after calculation 
long tTime = 0;     // time between tStart and tStop

// function setup()
// is call automaticaly at startup and init all libraries and ports if needed 
void setup() {
  // put your setup code here, to run once:
  // init Serial Port in order to print results
  Serial.begin(115200);
}

// function loop()
// is call automaticaly after setup() and run forever after setup
void loop() {
  // put your main code here, to run repeatedly:
  
}
