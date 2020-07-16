
#include <Arduino.h>
#include <led.h>
// // conexion wifi
#include <PubSubClient.h>
#include <WiFiUdp.h>
#include <NTPClientLib.h>
#include <Time.h>
#include <TimeLib.h>
#include <Timezone.h>
#include <TM1637Display.h>
#include "time.h"

#include <Buzzer.h>
#include "time.h"
#include "song.h"

//Buzzer buzzer(14);

#ifndef STASSID
#define STASSID "Silence"
#define STAPSK "Totemirokoa2020!"

#define CLK 0
#define DIO 4

#endif

const char *ssid = STASSID;
const char *password = STAPSK;
bool wifiFirstConnected = false;

void onSTAConnected(WiFiEventStationModeConnected ipInfo)
{
  Serial.printf("Connected to %s\r\n", ipInfo.ssid.c_str());
}
// Start NTP only after IP network is connected
void onSTAGotIP(WiFiEventStationModeGotIP ipInfo)
{
  Serial.printf("Got IP: %s\r\n", ipInfo.ip.toString().c_str());
  Serial.printf("Connected: %s\r\n", WiFi.status() == WL_CONNECTED ? "yes" : "no");
  digitalWrite(LED_BUILTIN, LOW); // Turn on LED
  wifiFirstConnected = true;
}
// Manage network disconnection
void onSTADisconnected(WiFiEventStationModeDisconnected event_info)
{
  Serial.printf("Disconnected from SSID: %s\n", event_info.ssid.c_str());
  Serial.printf("Reason: %d\n", event_info.reason);
  digitalWrite(LED_BUILTIN, HIGH); // Turn off LED
  //NTP.stop(); // NTP sync can be disabled to avoid sync errors
  WiFi.reconnect();
}
void connecting_wifi_network(void)
{
  static WiFiEventHandler e1, e2, e3;
  e1 = WiFi.onStationModeGotIP(onSTAGotIP); // As soon WiFi is connected, start NTP Client
  e2 = WiFi.onStationModeDisconnected(onSTADisconnected);
  e3 = WiFi.onStationModeConnected(onSTAConnected);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// reveil
boolean reveil = false;
const int buttonInput = 5; // D1
uint16_t heure_save = 0;

// Checks if motion was detected, sets LED HIGH and starts a timer
ICACHE_RAM_ATTR void buttonPressed()
{
  reveil = false;
  Serial.println("arrêt reveil !");
}

void setup_ntp();
void processSyncEvent(NTPSyncEvent_t ntpEvent);
uint16_t get_time();
void display_time(uint16_t);
// reveil
void setup()
{
  // Mettre GPIO (General Purpose Input Output) en INPUT (Entrée) : Bouton
  pinMode(buttonInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonInput), buttonPressed, RISING);

  pinMode(5, INPUT);               // Mettre GPIO (General Purpose Input Output) D1 en INPUT (Entrée) : Bouton
  pinMode(16, OUTPUT);             // Mettre GPIO (General Purpose Input Output) D0 en OUTPUT (Sortie) : LED
  pinMode(LED_BUILTIN, OUTPUT);    // Onboard LED
  digitalWrite(LED_BUILTIN, HIGH); // Switch off LED

  Serial.begin(115200);

  connecting_wifi_network();
  setup_ntp();

  // connexion
}
void loop()
{
  // reveil
  uint16_t heure = get_time();
  display_time(heure);

  if (heure != heure_save)
  {
    heure_save = heure;

    if (heure % 2 == 0)
    {
      reveil = true;
      Serial.println("reveil declanché !");
    }
  }

  if (reveil)
  {
    clignoter_led();
    //starwars_song();
    gotSong();
  }
  // buzzeer
  // buzzer.begin(100);

  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_C7, 80);
  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_G7, 80);
  // buzzer.sound(0, 240);
  // buzzer.sound(NOTE_G6, 80);
  // buzzer.sound(0, 240);
  // buzzer.sound(NOTE_C7, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_G6, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_E6, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_A6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_B6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_AS6, 80);
  // buzzer.sound(NOTE_A6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_G6, 100);
  // buzzer.sound(NOTE_E7, 100);
  // buzzer.sound(NOTE_G7, 100);
  // buzzer.sound(NOTE_A7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_F7, 80);
  // buzzer.sound(NOTE_G7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_C7, 80);
  // buzzer.sound(NOTE_D7, 80);
  // buzzer.sound(NOTE_B6, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_C7, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_G6, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_E6, 80);
  // buzzer.sound(0, 160);
  // buzzer.sound(NOTE_A6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_B6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_AS6, 80);
  // buzzer.sound(NOTE_A6, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_G6, 100);
  // buzzer.sound(NOTE_E7, 100);
  // buzzer.sound(NOTE_G7, 100);
  // buzzer.sound(NOTE_A7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_F7, 80);
  // buzzer.sound(NOTE_G7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_E7, 80);
  // buzzer.sound(0, 80);
  // buzzer.sound(NOTE_C7, 80);
  // buzzer.sound(NOTE_D7, 80);
  // buzzer.sound(NOTE_B6, 80);
  // buzzer.sound(0, 160);
}