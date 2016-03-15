
//Will get an action for both the left and right motors
//by updating each motor paramter
void GetMove(int l_MotorPwr, int r_MotorPwr)
{
  l_MotorPwr = 0;
  r_MotorPwr = 0;
  int maxQ = qTable[currFront][currBack][0][0];
  for (int i =0;i<numActions;i++) 
   for (int j =1;j<numActions;j++)
    if(maxQ < qTable[currFront][currBack][i][j])
     {
      l_MotorPwr = i;
      r_MotorPwr = j;
      maxQ = qTable[currFront][currBack][i][j];
     }
}




