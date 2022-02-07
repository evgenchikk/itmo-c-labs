#include <stdio.h>

int main( void )
{
  enum week {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
  } day = monday;
  
  printf("Number of monday: %i\n", day); //Task 1
  
  
  struct {
    float a, b, x, y, per;
  } rect;
  
  rect.a = 10;
  rect.b = 20;
  rect.per = rect.a * 2 + rect.b * 2;
  printf("Perimeter of rectangle: %f\n", rect.per); //Task 2
  
  
  struct PlayerState {
    unsigned play: 1;
    unsigned pause: 1;
    unsigned rec: 1;
  } CurrentState;
  
  union hex_state {
    unsigned int num;
    struct PlayerState state;
  } h_s;
  
  int x;
  
  printf("Input player state (0x..): ");
  scanf("%x", &x);
  
  h_s.num = x;
  CurrentState = h_s.state;
  //Task 3
  printf("Current state: Play: %d, Pause: %d, Rec: %d\n", CurrentState.play, CurrentState.pause, CurrentState.rec);
  
  return 0;
}
