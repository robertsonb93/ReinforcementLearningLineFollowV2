void SerialEvent()
{
  if(Serial.available())//Needs a ping from the computer, this will be the msg for either the send or receive
  {
    String msg = "";
     while(Serial.available())
      {
        char temp =  (Serial.read());
        msg += temp;
      }
    
   snd: if(msg == "send")//C# is asking arduino to send the table
    {
             digitalWrite(33,LOW);
             delay(50);
             digitalWrite(33,HIGH);
              delay(150);
             
        String serialSize = String(numStates * numStates * numActions * numActions);      
          ss:Serial.print(serialSize);
            Serial.write("\n");
          msg = "";
          while(!(Serial.available())) //Wait for the reply from c#
              delay(10);
       
          while(Serial.available())
          {
                char temp =Serial.read();
                 msg += temp;
                 if(msg == "send") goto snd;//This may not be necessary, merely for robustness
                 else if(msg == "receive") goto rcv;
          }       
          if(msg == serialSize)//confirm the appropriate size was received, can send the table info
          {
            for(int i=0;i<numStates;i++)
               for(int j=0;j<numStates;j++)
                   for(int k=0;k<numActions;k++)
                      for(int l=0;l<numActions;l++)
                            {
                              Serial.print((qTable[i][j][k][l]));       
                              Serial.write("\n");                
                            }
          }
        else goto ss;//Try and send again untill the two are lined up appropriately
      }


      
     else rcv:if(msg == "receive")//C# is telling arduino to receive the table
     {  

      digitalWrite(33,LOW);delay(10);    
      digitalWrite(33,HIGH);delay(10);
      digitalWrite(33,LOW);delay(10);
      digitalWrite(33,HIGH);delay(10);
      digitalWrite(33,LOW);
      
        Serial.print(msg);
        Serial.write("\n");
        
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
                             
                             //Serial.print(temp); 
                             //Serial.write("\n");     
                           
                          }     
                          qTable[i][j][k][l] = msg.toInt(); 
                         // Serial.flush();   
                          Serial.print(msg.toInt()); 
                             Serial.write("\n");                                                           
                      }
                    }
                  }
                }
               Serial.flush();
     }
     
     else//There was an error in the message
     Serial.flush();
  }


}

