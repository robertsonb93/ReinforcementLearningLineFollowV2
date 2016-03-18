//Will update the motor powers with the best levels as well
void UpdateQTable()
{
 oldLeft = currLeft;//The currents will get overwrite in getmove below
 oldRight = currRight;
 
 int rwrd =  GetReward(currFront, currBack);
 
 //Find best Q(s',a')
 GetMove(currLeft,currRight); //This is going to update the left and Rights
 int bestPrime = qTable[currBack][currFront][currLeft][currRight];
 
 //Update Q Value
// qTable[oldBack][oldFront][oldLeft][oldRight] += alpha*(rwrd + gamma*bestPrime-qTable[oldBack][oldFront][oldLeft][oldRight]);
  //Update teh oldFront and Back for next iteration
 oldFront = currFront;
 oldBack  = currBack;

 
}
