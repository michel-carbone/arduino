/*******************************************************
This program will measure the CPU time usage for differents
calculation, e.g. integer addition, float addition, etc
Michel Carbone, September 2018, Namur, Belgium
********************************************************/
// pre-processor directive for debugging
#define DEBUG 0 // 1 = debug by serial print values

// loop count in each test
const int LOOP_COUNT = 10000;

// variable for function return
int ret_val = 0;

// variables for timing calculation
unsigned long tStart = 0;    // time in us before calculation
unsigned long tStop = 0;     // time in us after calculation 
unsigned long tTime = 0;     // time between tStart and tStop

// variables for sum result
byte bsum = 0;
unsigned int usum = 0;
int sum = 0;
float fsum = 0;
double dsum = 0;

// function setup()
// is call automaticaly at startup and init all libraries and ports if needed 
void setup() {
  // put your setup code here, to run once:
  // init Serial Port in order to print results
  Serial.begin(115200);
  
  // say hello world to check connection to console
  Serial.println("Running Calculus_benchmark...");
  
  // BYTE SECTION
  // ============
  Serial.println("Tests with bytes");
  
  // test additions_byte()
  tStart = micros();
  ret_val = additions_byte();
  tStop = micros();
  print_output(ret_val, "additions_byte", tStart, tStop);
  
  // test substract_byte()
  tStart = micros();
  ret_val = substract_byte();
  tStop = micros();
  print_output(ret_val, "substract_byte", tStart, tStop);
  
  // test multiply_byte()
  tStart = micros();
  ret_val = multiply_byte();
  tStop = micros();
  print_output(ret_val, "multiply_byte", tStart, tStop);
  
  // test divide_byte()
  tStart = micros();
  ret_val = divide_byte();
  tStop = micros();
  print_output(ret_val, "divide_byte", tStart, tStop);
  
  // UINT SECTION
  // ============
  Serial.println("Tests with unsigned integer");
  
  // test additions_uint()
  tStart = micros();
  ret_val = additions_uint();
  tStop = micros();
  print_output(ret_val, "additions_uint", tStart, tStop);

  // test substract_uint()
  tStart = micros();
  ret_val = substract_uint();
  tStop = micros();
  print_output(ret_val, "substract_uint", tStart, tStop);
  
  // test multiply_uint()
  tStart = micros();
  ret_val = multiply_uint();
  tStop = micros();
  print_output(ret_val, "multiply_uint", tStart, tStop);
  
  // test divide_uint()
  tStart = micros();
  ret_val = divide_uint();
  tStop = micros();
  print_output(ret_val, "divide_uint", tStart, tStop);

  
  // INT SECTION
  // ===========
  Serial.println("Tests with signed integer");
  
  // test additions_int()
  tStart = micros();
  ret_val = additions_int();
  tStop = micros(); // measure stop time before call of function...
  print_output(ret_val, "additions_int", tStart, tStop);
  
  // test substract_int()
  tStart = micros();
  ret_val = substract_int();
  tStop = micros();
  print_output(ret_val, "substract_int", tStart, tStop);
  
  // test multiply_int()
  tStart = micros();
  ret_val = multiply_int();
  tStop = micros();
  print_output(ret_val, "multiply_int", tStart, tStop);
  
  // test divide_int()
  tStart = micros();
  ret_val = divide_int();
  tStop = micros();
  print_output(ret_val, "divide_int", tStart, tStop);

  
  // FLOAT SECTION
  // =============
  Serial.println("Tests with floats");
  
  // test additions_float()
  tStart = micros();
  ret_val = additions_float();
  tStop = micros(); // measure stop time before call of function...
  print_output(ret_val, "additions_float", tStart, tStop);

  // test substract_float()
  tStart = micros();
  ret_val = substract_float();
  tStop = micros();
  print_output(ret_val, "substract_float", tStart, tStop);
  
  // test multiply_float()
  tStart = micros();
  ret_val = multiply_float();
  tStop = micros();
  print_output(ret_val, "multiply_float", tStart, tStop);
  
  // test divide_float()
  tStart = micros();
  ret_val = divide_float();
  tStop = micros();
  print_output(ret_val, "divide_float", tStart, tStop);

  // DOUBLE SECTION
  // ==============
  Serial.println("Tests with doubles");
  
  // test additions_double()
  // NOTE: double is an alias for float on 8-bits processors and give the same result!
  tStart = micros();
  ret_val = additions_double();
  tStop = micros(); // measure stop time before call of function...
  print_output(ret_val, "additions_double", tStart, tStop);

  
  // test substract_double()
  tStart = micros();
  ret_val = substract_double();
  tStop = micros();
  print_output(ret_val, "substract_double", tStart, tStop);
  
  // test multiply_double()
  tStart = micros();
  ret_val = multiply_double();
  tStop = micros();
  print_output(ret_val, "multiply_double", tStart, tStop);
  
  // test divide_double()
  tStart = micros();
  ret_val = divide_double();
  tStop = micros();
  print_output(ret_val, "divide_double", tStart, tStop);

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
// display start, stop time and duration and print results to console
void print_output(int fct_ret_val, String fct_name, unsigned long tStart, unsigned long tStop){
  unsigned long tTime = 0;
  //tStop = micros(); // removed here because call to function seems to introduce a delay of 20us TBC
  tTime = tStop-tStart; // calc duration
  Serial.print("Time for ");
  Serial.print(fct_name);
  Serial.print("() in (us): ");
  Serial.print(tTime);
  Serial.print("; number of loop:");
  Serial.println(fct_ret_val);
  Serial.print("tStart: ");
  Serial.print(tStart);
  Serial.print(" us, tStop: ");
  Serial.print(tStop);
  Serial.println(" us");
}

// function additions_byte() add two bytes LOOP_COUNT times
int additions_byte(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    bsum = bsum + i;
    #if DEBUG == 1
    Serial.println(bsum);
    #endif
  }
  return i;
}

// function substract_byte() add two bytes LOOP_COUNT times
int substract_byte(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    bsum = bsum - i;
    #if DEBUG == 1
    Serial.println(bsum);
    #endif
  }
  return i;
}

// function multiply_byte() multiply two bytes LOOP_COUNT times
int multiply_byte(){
  //unsigned int sum = 0;
  int i = 0;  // loop pointer
  bsum = 1;
  for (i = 1; i < LOOP_COUNT + 1; i++) // start at 1 for avoiding result to ZERO and add one cycle in loop
  {
    bsum = i * bsum;
    #if DEBUG == 1
    Serial.println(bsum);
    #endif
  }
  return i-1;
}

// function divide_byte() divide two bytes LOOP_COUNT times
int divide_byte(){
  //unsigned int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    bsum = i;
    bsum = bsum/i;
    #if DEBUG == 1
    Serial.println(bsum);
    #endif
  }
  return i;
}

// function additions_uint() add two unsigned integers LOOP_COUNT times
int additions_uint(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    usum = usum + i;
    #if DEBUG == 1
    Serial.println(usum);
    #endif
  }
  return i;
}

// function substract_uint() add two unsigned integers LOOP_COUNT times
int substract_uint(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    usum = usum - i;
    #if DEBUG == 1
    Serial.println(usum);
    #endif
  }
  return i;
}

// function multiply_uint() multiply two unsigned integers LOOP_COUNT times
int multiply_uint(){
  //unsigned int sum = 0;
  int i = 0;  // loop pointer
  usum = 1;
  for (i = 1; i < LOOP_COUNT + 1; i++) // start at 1 for avoiding result to ZERO and add one cycle in loop
  {
    usum = i * usum;
    #if DEBUG == 1
    Serial.println(usum);
    #endif
  }
  return i-1;
}

// function divide_uint() divide two unsigned integers LOOP_COUNT times
int divide_uint(){
  //unsigned int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    usum = i;
    usum = usum/i;
    #if DEBUG == 1
    Serial.println(usum);
    #endif
  }
  return i;
}


// function additions_int() add two signed integers LOOP_COUNT times
int additions_int(){
  //int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    sum = sum + i;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}

// function substract_int() add two signed integers LOOP_COUNT times
int substract_int(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    sum = sum - i;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}

// function multiply_int() multiply two signed integers LOOP_COUNT times
int multiply_int(){
  //unsigned int sum = 0;
  int i = 0;  // loop pointer
  sum = 1;
  for (i = 1; i < LOOP_COUNT + 1; i++)// start at 1 for avoiding result to ZERO and add one cycle in loop
  {
    sum = i * sum;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i-1;
}

// function divide_int() divide two signed integers LOOP_COUNT times
int divide_int(){
  //unsigned int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    sum = i;
    sum = sum/i;
    #if DEBUG == 1
    Serial.println(sum);
    #endif
  }
  return i;
}


// function additions_float() add two float LOOP_COUNT times
int additions_float(){
  //float sum = 0;
  int i = 0;
  float j = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    j=i;
    fsum = fsum + j;
    #if DEBUG == 1
    Serial.println(fsum);
    #endif
  }
  return i;
}

// function substract_float() add two floats LOOP_COUNT times
int substract_float(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    fsum = fsum - i;
    #if DEBUG == 1
    Serial.println(fsum);
    #endif
  }
  return i;
}

// function multiply_float() multiply two floats LOOP_COUNT times
int multiply_float(){
  //unsigned int sum = 0;
  int i = 0;  // loop pointer
  fsum = 1;
  for (i = 1; i < LOOP_COUNT + 1; i++) // start at 1 for avoiding result to ZERO and add one cycle in loop
  {
    fsum = i * fsum;
    #if DEBUG == 1
    Serial.println(fsum);
    #endif
  }
  return i-1;
}

// function divide_float() divide two floats LOOP_COUNT times
int divide_float(){
  //unsigned int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    fsum = i;
    fsum = fsum/i;
    #if DEBUG == 1
    Serial.println(fsum);
    #endif
  }
  return i;
}


// function additions_double() add two double LOOP_COUNT times
int additions_double(){
  //float sum = 0;
  int i = 0;
  double j = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    j=i;
    dsum = dsum + j;
    #if DEBUG == 1
    Serial.println(dsum);
    #endif
  }
  return i;
}

// function substract_double() add two doubles LOOP_COUNT times
int substract_double(){
  //unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    dsum = dsum - i;
    #if DEBUG == 1
    Serial.println(dsum);
    #endif
  }
  return i;
}

// function multiply_float() multiply two floats LOOP_COUNT times
int multiply_double(){
  //unsigned int sum = 0;
  int i = 0;  // loop pointer
  dsum = 1;
  for (i = 1; i < LOOP_COUNT + 1; i++) // start at 1 for avoiding result to ZERO and add one cycle in loop
  {
    dsum = i * dsum;
    #if DEBUG == 1
    Serial.println(dsum);
    #endif
  }
  return i-1;
}

// function divide_double() divide two doubles LOOP_COUNT times
int divide_double(){
  //unsigned int sum = 0;
  int i = 0;
  for (i=0; i < LOOP_COUNT; i++)
  {
    dsum = i;
    dsum = dsum/i;
    #if DEBUG == 1
    Serial.println(dsum);
    #endif
  }
  return i;
}

