//Need to get the readings from the sensors, and determine the middle of the line on both
// the front array and rear array of Sensors

//Add plus one when found an 'i', so that we dont try adding 0 for a position

void GetSensorDataRaw(int& frontLine, int& backLine)
{
  ReadSensors();
  double numFront=0, numBack = 0;
  frontLine = backLine = 0;
  
  for(int i=0;i<8;i++)
  {
    if(F_SENSOR[i] >= THRESHOLD)
        {
          frontLine += i+1;//To not try adding position Zero
          numFront++;
        }       
      if(B_SENSOR[i] >= THRESHOLD)
        {
          backLine += i+1;
          numBack++;
        }
  }
  if(numFront > 0)
  {
  frontLine = (frontLine / numFront) + 0.5;
  frontLine -= 1;
  }
  else
  frontLine = 8;

  if(numBack > 0)
  {
  backLine = (backLine/numBack) + 0.5;//To Round Up
  backLine -= 1;
  }
  else
  backLine = 8;

  switch(frontLine)
  {
    case 0: frontLine=7; break;
    case 1: frontLine=6; break;
    case 2: frontLine=5; break;
    case 3: frontLine=4; break;
    case 4: frontLine=3; break;
    case 5: frontLine=2; break;
    case 6: frontLine=1; break;
    case 7: frontLine=0; break;
    default: frontLine=8; 
  }
//  switch(backLine)
//  {
//  case 0:{ backLine = 7; break;}
//  case 1: backLine = 6; break;
//  case 2: backLine = 5; break;
//  case 3: backLine = 4; break;
//  case 4: backLine = 3; break;
//  case 5: backLine = 2; break;
//  case 6: backLine = 1; break;  
//  case 7: backLine = 0; break;
//  default: backLine =8;
//  }
}

