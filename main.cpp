#include "mbed.h"

class Joystick{
    private:
        DigitalIn up, down, left, right, fire;
    public:
        Joystick(PinName u, PinName d, PinName l, PinName r, PinName f):up(u), down(d), left(l), right(r), fire(f){
        };
        bool upPressed(void){
            if (up){
                return true;
            }
            else {
                return false;
            }
        };

        bool downPressed(void){
            if (down){
                return true;
            }
            else {
                return false;
            }
        };
        bool leftPressed(void){
            if (left){
                return true;
            }
            else {
                return false;
            }
        };
        bool rightPressed(void){
            if (right){
                return true;
            }
            else {
                return false;
            }
        };
        bool firePressed(void){
            if (fire){
                return true;
            }
            else {
                return false;
            }
        };
};

class RGBLed{
    private:
        PwmOut red, green, blue;
    public:
        RGBLed(PinName r, PinName g, PinName b):red(r),green(g),blue(b){

        };

        void setOff(){
            red = 1.0;
            blue = 1.0;
            green = 1.0;
        };

        void setRed(){
            red = 0.0;
            blue = 1.0;
            green = 1.0;
        };
        
        void setGreen(){
            red = 1.0;
            blue = 1.0;
            green = 0.0;
        };

        void setBlue(){
            red = 1.0;
            blue = 0.0;
            green = 1.0;
        };

        void setYellow(){
            red = 0.0;
            blue = 1.0;
            green = 0.0;
        };

        void setWhite(){
            red = 0.0;
            blue = 0.0;
            green = 0.0;
        };
};


int main() {
    Joystick joystick(A2,A3,A4,A5,D4);
    RGBLed led(D5,D9,D8);
    while(1) {
        if (joystick.upPressed()) {
            led.setRed();
        }
        else if (joystick.downPressed()) {
            led.setGreen();
        }
        else if (joystick.leftPressed()) {
            led.setBlue();
        }
        else if (joystick.rightPressed()) {
            led.setYellow();
        }
        else{
            led.setOff();
        };
        while(joystick.firePressed()){
            led.setWhite();
            wait(0.5);
            led.setOff();
            wait(0.5);
        }
        

    }
}
