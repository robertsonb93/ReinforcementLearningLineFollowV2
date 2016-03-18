//Reads input values from the front and rear Sensors
void ReadSensors()
{
  for(int i=0;i<numSensors;i++)
  {
    F_SENSOR[i] = analogRead(i+numStates);
    B_SENSOR[i] = analogRead(i); 
  }
}

