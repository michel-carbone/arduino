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
// variables in loop() for precise timing
long tStart = 0;    // time in us before first Serial Print
long tStop = 0;     // time in us after last Serial Print 
long tTime = 0;     // time between tStart and tStop

// function loop()
// is call automaticaly after setup() and run forever after setup
void loop() {
  // put your main code here, to run repeatedly:
  tStart = micros();
  Serial.print("Step number ");
  Serial.print(i); // display loop count
  Serial.print("; time elapsed (ms): ");
  Serial.print(millis()); // display current time from startup
  Serial.print("; duration (us): "); // 62 char takes around 1052 us to print to COM port
  Serial.println(tTime); // display duration of previous loop cycle
  i=i+1;
  tStop = micros();
  tTime = tStop - tStart; // calc diff  of current loop cycle
  delay(99); // 99 in order to remove the approx. 1ms for serial print
}
