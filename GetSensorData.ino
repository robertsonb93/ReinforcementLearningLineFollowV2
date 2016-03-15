


//Function needs to take the data from the sensors
//and interpret valid integers from it to determine the line
//position
 //-1 implies that no line is found


void GetSensorData(int frontLine, int backLine)
{
  ReadSensors();
  
  frontLine = 0;
  backLine = 0;
  int numFront = 0;
  int numBack = 0;
  //Establish if two lines vary by the threshold amount
  //If there is a difference, mark it. 
  for(int i= 0;i<7;i++)
    {
      if(abs(F_SENSOR[i] - F_SENSOR[i+1])>= THRESHOLD)
        {
          frontLine += i+1;//To not try adding position Zero
          numFront++;
        }
        
      if(abs(B_SENSOR[i] - B_SENSOR[i+1]) >= THRESHOLD)
        {
          backLine += i+1;
          numBack++;
        }
    }
    frontLine /= numFront; //Midline of the Line
    backLine /= numBack;
    
    frontLine -=1; //Set the position back to count from 0
    backLine -= 1;
}
