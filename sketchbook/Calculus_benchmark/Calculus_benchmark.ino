/*******************************************************
This program will measure the CPU time usage for differents
calculation, e.g. integer addition, float addition, etc
Michel Carbone, September 2018
********************************************************/
// pre-processor directive for debugging
#define DEBUG 0 // 1 = debug by serial print values

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
  
  // say hello world to check connection to console
  Serial.println("Running Calculus_benchmark...");
  
  // test additions_uint()
  tStart = micros();
  int ret_val = additions_uint();
  tStop = micros();
  print_output(ret_val, "additions_uint");
  
  // test additions_int()
  tStart = micros();
  ret_val = additions_int();
  tStop = micros(); // measure stop time before call of function...
  print_output(ret_val, "additions_int");

  // test additions_float()
  tStart = micros();
  ret_val = additions_float();
  tStop = micros(); // measure stop time before call of function...
  print_output(ret_val, "additions_float");
}

// function loop()
// is call automaticaly after setup() and run forever after setup
void loop() {
  // put your main code here, to run repeatedly:
  /******
   * nothing to do...
   */
}

// function print_output(int , String)
// calc stop time and duration and print results to console
void print_output(int fct_ret_val, String fct_name){
  //tStop = micros(); // removed here because call to function seems to introduce a delay of 20us TBC
  tTime = tStop-tStart;
  Serial.print("Time for ");
  Serial.print(fct_name);
  Serial.print("() in (us): ");
  Serial.print(tTime);
  Serial.print("; number of loop:");
  Serial.println(fct_ret_val);
}
// function additions_uint() add two unsigned integers 32766 times
int additions_uint(){
  unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i<32766; i++)
  {
    sum = i+i;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}

// function additions_int() add two signed integers 32766 times
int additions_int(){
  int sum = 0;
  int i = 0;
  for (i=0; i<32766; i++)
  {
    sum = i+i;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}

// function additions_int() add two float 32766 times
int additions_float(){
  float sum = 0;
  int i = 0;
  float j = 0;
  for (i=0; i<32766; i++)
  {
    j=i;
    sum = j+j;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}

