#define FALSE 0
#define TRUE 1

// Indention flag
int flag[2] = {FALSE, FALSE};
// Turn
int turn = 0;

void p0()
{
  // Set my indention flag
  flag[0] = TRUE;
  // Check the other one's indention flag 
  while (flag[1] == TRUE) {
    if (turn != 0) {
      // Clear my flag if not my turn
      flag[0] = FALSE;
      // Wait for the other one to give me a turn
      while (turn != 0) {
      }
      // Set my indention flag
      flag[0] = TRUE;
    }
  }

  ///////////////////
  // critical section
  ///////////////////

  // Give the turn to the other one
  turn = 1;
  // Clear my indention flag
  flag[0] = FALSE;
} 

void p1() 
{
  flag[1] = TRUE;
  while (flag[0] == TRUE) {
    if (turn != 1) {
      flag[1] = FALSE;
      while (turn != 1) {
      }
      flag[1] = TRUE;
    }
  }
  ///////////////////
  // critical section
  ///////////////////
  turn = 0;
  flag[1] = FALSE;
}

int main()
{
}
