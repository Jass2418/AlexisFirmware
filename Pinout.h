#include "L298N.h"
#include "Pushbutton.h"
#include "LED.h"

///Motor
#define EN 9
#define IN1 8
#define IN2 7

///PushButton
#define PB1 D2
#define PB2 D1

//Limit Switch
#define LIMITSWITCHPIN A1

///LEDS
#define GREENLEDPIN D0
#define YELLOWLEDPIN D3
#define REDLEDPIN D4

extern L298N motor;

extern Pushbutton pushLeft;
extern Pushbutton pushRight;
extern Pushbutton limitSwitch;

extern LED redLed;
extern LED yellowLed;
extern LED greenLed; 
