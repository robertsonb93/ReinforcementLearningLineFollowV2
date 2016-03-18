void SerialEvent()
{
  if(Serial.available())//Needs a ping from the computer, this will be the msg for either the send or receive
  {
    delay(10);
    String msg = "";
     while(Serial.available())
      {
        char temp =  Serial.read();
        delay(10);
        msg += temp;
      }
  
    if(msg == "send"){
    //  Serial.print("snd");
    // if(msg[0] == 's' && msg[1] == 'e' && msg[2] == 'n' && msg[3] == 'd')//C# is asking arduino to send the table
        String serialSize = String(numStates * numStates * numActions * numActions);      
    
          ss:Serial.print(serialSize);
            Serial.write('\n');
          msg = "";
          while(!(Serial.available())) //Wait for the reply from c#
              delay(10);
       
          while(Serial.available())
          {
            delay(10);
                char temp =Serial.read();
                 msg += temp;
          }       
          if(msg == serialSize)//confirm the appropriate size was received, can send the table info
          {
            for(int i=0;i<numStates;i++)
               for(int j=0;j<numStates;j++)
                   for(int k=0;k<numActions;k++)
                      for(int l=0;l<numActions;l++)
                            {
                              Serial.print((qTable[i][j][k][l]));       
                              Serial.write('\n');                
                            }
          }
          else goto ss;//Try and send again untill the two are lined up appropriately
      }

     else if(msg == "receive")//C# is telling arduino to receive the table
     {  
        Serial.print(msg);
        Serial.write("\n");
        int address = 0;
        while(!(Serial.available())) //Wait for the reply from c#
              delay(10);
        
          //Start receiving the values from C#
              for(int i =0;i<numStates;i++)
                { for(int j=0;j<numStates;j++)
                  {for(int k=0;k<numActions;k++)
                   { for(int l=0;l<numActions;l++)
                      {
                        while(!(Serial.available())) //Wait for the reply from c#
                            delay(10);
                            
                        msg ="";
                        char temp = Serial.read();                       
                        while((temp - '0' >= 0 && '9' - temp <= 9) || temp == '-')
                          { 
                            delay(5);
                            msg += temp;
                            temp = Serial.read();
                          }     
                          qTable[i][j][k][l] = msg.toInt();
                            //Double increment address since the int use 2 bytes, each byte is one address pos.
                            
                           EEPROM.put(address,qTable[i][j][k][l]);
                           address += sizeof(int);
                          Serial.print(msg.toInt()); 
                             Serial.write('\n');                                                           
                      }
                    }
                  }
                }
               Serial.flush();
     }
     
     
    //There was an error in the message/or complete
     {Serial.flush();}
  }


}

