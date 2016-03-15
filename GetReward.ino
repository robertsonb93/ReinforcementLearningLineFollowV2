int GetReward(int front, int back)
{
  if(front < 0 || back < 0)
  {
    int tFront = -1;
    int tBack = -1;
    while(tFront < 0 || tBack < 0)
      {
        GetSensorData(tFront,tBack);
        
        delay(3000);
      }    
    return badReward;
  }
  else
    return goodReward;
}
