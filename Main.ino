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
    motor.initialize();
    motor.stop();
}

void loop(){
    if(limitSwitch.isPressed())
        motor.stop();
}

void PressedLeft(){
    redLed.off();
    yellowLed.off();
    greenLed.on();
    motor.forward();
}

void PressedRight(){
    redLed.off();   
    greenLed.off(); 
    yellowLed.on();
    motor.stop();
    motor.backward();
    //motor.stop();
}

void PressedLimit(){
    yellowLed.off();
    greenLed.off();    
    motor.stop();
    redLed.on();
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