#include <EEPROM.h>

//The analogIn ports for the relfectance sensors
int F_SENSOR[] = {8,9,10,11,12,13,14,15}; 
int B_SENSOR[] = {0,1,2,3,4,5,6,7};
int THRESHOLD = 200; //amount difference between two snsrs 

//motor outs are on PWM pins
int R_MotorOUTS[] = {6,7};//2 isForward
int L_MotorOUTS[] = {9,8}; //5 is Forward
const int numActions = 3;//7;
const int numStates = 9;//8;
const int numSensors = 8;
//int pwrList[] = {0,42,84,126,168,210,255};//To create associated power levels from 0-6 for the motors
int pwrList[] = {0,30,60};

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
  int address = 0;
  //Init QTable;
  for(int i=0;i<numStates;i++)
  for(int j=0;j<numStates;j++)
  for(int k=0;k<numActions;k++)
  for(int l=0;l<numActions;l++)
  {
    EEPROM.get(address,qTable[i][j][k][l]);
    address +=sizeof(int);
  }
}

void loop() 
{  
SetMotorPower(pwrList[currLeft],pwrList[currRight]);
GetSensorDataRaw(currFront,currBack);
UpdateQTable(); //Updates the currFront and currBack, and selects a new motor power;
//delay(500);
//SerialEvent();
}





