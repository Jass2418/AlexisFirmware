#include "Pinout.h"


void PressedLeft();
void PressedRight();
void PressedLimit();

int CloudFunction(String string);


L298N motor(EN, IN1, IN2);

Pushbutton pushLeft(PB1,FALLING,PressedLeft);
Pushbutton pushRight(PB2,FALLING,PressedRight);
Pushbutton limitSwitch(LIMITSWITCHPIN,FALLING,PressedLimit);

LED redLed(REDLEDPIN);
LED yellowLed(YELLOWLEDPIN);
LED greenLed(GREENLEDPIN); 

void setup() {
    Particle.function("Move", CloudFunction);
}

void loop(){
    if(limitSwitch.isPressed())
        motor.stop();
}

void PressedLeft(){
    greenLed.on();
    motor.forward();
}

void PressedRight(){
    yellowLed.on();
    motor.backwardFor(2000);
    motor.stop();
}

void PressedLimit(){
    redLed.off();
    motor.stop();
    redLed.on();
    greenLed.off();
}

int CloudFunction(String string){
    if(string=="IZQ")
        PressedLeft();
    else if(string=="DER")
        PressedRight();
    else if(string=="OFF")
        PressedLimit();
    else
        return 0;

    return 1; 
}