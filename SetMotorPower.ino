//Give a MotorOutPut power for both the left and the right
void SetMotorPower(const int L_MtrPwr,const int R_MtrPwr)
{
  int l_out = 0;
  int r_out = 0;
  int left = L_MtrPwr;
  int right = R_MtrPwr;
  
  if(L_MtrPwr < 0)
   {
    l_out = 1;
    left *= -1;
   }

    if(R_MtrPwr < 0)
   {
    r_out = 1;
    right *= -1;  
   }  
   analogWrite(L_MotorOUTS[l_out],left);
   analogWrite(R_MotorOUTS[r_out],right);
}

