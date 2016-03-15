#include <avr/pgmspace.h>

//The analogIn ports for the relfectance sensors
int F_SENSOR[] = {8,9,10,11,12,13,14,15}; 
int B_SENSOR[] = {0,1,2,3,4,5,6,7};
int THRESHOLD = 200; //amount difference between two snsrs 

//motor outs are on PWM pins
int R_MotorOUTS[] = {2,3};//2 isForward
int L_MotorOUTS[] = {5,4}; //5 is Forward
const int numActions = 7;//7;
const int numStates = 8;//8;
int pwrList[] = {0,42,84,126,168,210,255};//To create associated power levels from 0-6 for the motors

int qTable[numStates][numStates][numActions][numActions];//stateFront,stateBack,LeftMotor,RightMotor

double alpha = 0.1;
double gamma = 0.8;

int goodReward = 2;
int badReward = -10;

int oldFront=0,oldBack=0;
int currFront=0,currBack=0;

int oldLeft=0;
int oldRight=0;
int currLeft=0;
int currRight=0;

void setup() {
  Serial.begin(9600);
  pinMode(33,OUTPUT);
  
  //Init QTable;
  for(int i=0;i<numStates;i++)
  for(int j=0;j<numStates;j++)
  for(int k=0;k<numActions;k++)
  for(int l=0;l<numActions;l++)
  {
    qTable[i][j][k][l] = 3;
  }
}

void loop() {
  
SetMotorPower(pwrList[currLeft],pwrList[currRight]);
GetSensorData(currFront,currBack);
UpdateQTable(); //Updates the currFront and currBack, and selects a new motor power;
SerialEvent();

digitalWrite(33,HIGH);
delay(150);
digitalWrite(33,LOW);
delay(150);
//SetMotorPower(10,15);



}





