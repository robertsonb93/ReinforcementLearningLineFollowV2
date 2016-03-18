int GetReward(int front, int back)
{
  if(front > 7 && back > 7)
  {
    int tFront = -1;
    int tBack = -1;
    while(tFront < 0 && tBack < 0)
      {
        GetSensorData(tFront,tBack);
        SetMotorPower(0,0);     
        delay(3000);       
      }    
    return badReward;
  }

  
  else
    return goodReward;
}
