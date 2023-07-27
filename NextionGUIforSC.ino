/* James Kane - some code by Korban O'Malley
 * Code for GUI for Star Citizen
 * Arduino Leonardo / Micro
 * Nextion Enhanced Display NX4832K035
 *
 * This code will translate touches on
 * the nextion device to keystrokes
 */

#include <Keyboard.h>
#include <Nextion.h>
#include <SoftwareSerial.h>

SoftwareSerial HMISerial(0,1);


// Declare buttons      (page, ID, name)

NexButton flightReady = NexButton(1, 1, "flightReady");
NexButton cruiseControl = NexButton(1, 2, "NexButton");
NexButton gear = NexButton(1, 3, "gear");
NexButton exitShip = NexButton(1, 4, "exitShip");
NexButton lights = NexButton(1, 5, "lights");
NexButton spool = NexButton(1, 6, "spool");
NexButton power = NexButton(1, 7, "power");
NexButton engine = NexButton(1, 8, "engine");
NexDSButton micLeft = NexDSButton(1, 9, "micLeft");
NexDSButton micRight = NexDSButton(1, 10, "micRight");
NexButton unassigned_b8 = NexButton(1, 11, "unassigned_b8");
NexButton unassigned_b9 = NexButton(1, 12, "unassigned_b9");
NexButton unassigned_b10 = NexButton(1, 13, "unassigned_b10");
NexButton unassigned_b11 = NexButton(1, 14, "unassigned_b11");


//NexDualStateButton micLeft = NexDualStateButton(0, 12, "bt0");
//NexDualStateButton micRight = NexDualStateButton(0, 12, "bt1");

// add buttons to list of events
NexTouch *nex_listen_list[] = 
{
  &flightReady,
  &cruiseControl,
  &gear,
  &exitShip,
  &lights,
  &spool,
  &power,
  &engine,
  &unassigned_b8,
  &unassigned_b9,
  &unassigned_b10,
  &unassigned_b11,
  &micLeft,
  &micRight,
  NULL 
};

void flightReadyPopCallback(void *ptr){
  Keyboard.write('r');
}
void cruiseControlPopCallback(void *ptr){
  Keyboard.write('c');
}
void gearPopCallback(void *ptr){
  Keyboard.write('n');
}
void exitShipPopCallback(void *ptr){
  Keyboard.write('Y');
}
void lightsPopCallback(void *ptr){
  Keyboard.write('L');
}
void spoolPopCallback(void *ptr){
  Keyboard.write('B');
}
void powerPopCallback(void *ptr){
  Keyboard.write('U');
}
void enginePopCallback(void *ptr){
  Keyboard.write('I');
}
void unassigned_b8PopCallback(void *ptr){
  Keyboard.write(NULL);
}
void unassigned_b9PopCallback(void *ptr){
  Keyboard.write(NULL);
}
void unassigned_b10PopCallback(void *ptr){
  Keyboard.write(NULL);
}
void unassigned_b11PopCallback(void *ptr){
  Keyboard.write(NULL);
}
void micLeftPopCallback(void *ptr){
  Keyboard.write(KEY_KP_DOT); // mute with discord open - custom keybind
}
void micRightPopCallback(void *ptr){
  Keyboard.write(KEY_KP_MINUS); // deafen with discord open - custom keybind
}
 int led = 13;

void setup() {
  
  // Start the software serial
  HMISerial.begin(9600);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  HMISerial.write(0xff);

  flightReady.attachPop(flightReadyPopCallback);
  cruiseControl.attachPop(cruiseControlPopCallback);
  gear.attachPop(gearPopCallback);
  exitShip.attachPop(exitShipPopCallback);
  lights.attachPop(lightsPopCallback);
  spool.attachPop(spoolPopCallback);
  power.attachPop(powerPopCallback);
  engine.attachPop(enginePopCallback);
  unassigned_b8.attachPop(unassigned_b8PopCallback);
  unassigned_b9.attachPop(unassigned_b9PopCallback);
  unassigned_b10.attachPop(unassigned_b10PopCallback);
  unassigned_b11.attachPop(unassigned_b11PopCallback);
  micLeft.attachPop(micLeftPopCallback); // mute
  micRight.attachPop(micRightPopCallback); // deafen 
}

void loop() {
  nexLoop(nex_listen_list);  // Check for any touch event
  delay(5); // for stability
}
