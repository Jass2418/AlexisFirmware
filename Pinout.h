#include "L298N.h"
#include "Pushbutton.h"
#include "LED.h"

///Motor
#define EN 9
#define IN1 D6
#define IN2 D7

///PushButton
#define PB1 D5
#define PB2 D4

//Limit Switch
#define LIMITSWITCHPIN D3

///LEDS
#define GREENLEDPIN D2
#define YELLOWLEDPIN D1
#define REDLEDPIN D0

extern L298N motor;
extern Pushbutton pushLeft;
extern Pushbutton pushRight;
extern Pushbutton limitSwitch;

extern LED redLed;
extern LED yellowLed;
extern LED greenLed; 
