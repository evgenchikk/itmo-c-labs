#define H 600
#define W 1000
typedef unsigned char byte;

void PutPixel( byte Frame[H][W][3], int x, int y, byte red, byte green, byte blue );
void CalcNextStep( byte A[H][W][3], byte B[H][W][3] );

