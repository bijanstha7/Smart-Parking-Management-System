// NODEMCU 8266 PROGRAMMING (ARDUINO_IDE)
#define BLYNK_PRINT Serial #include<ESP8266WiFi.h> #include<BlynkSimpleEsp8266.h> #include<SoftwareSerial.h>
char auth[] = "h7N5_B-fz7K_51qODgI9pgWBx2zE8IG4";
// Your WiFi credentials.
// Set password to "" for open networks. char ssid[] = "Basanta_Gajurel";
char pass[] = "password123";
BlynkTimer timer;
String myString;                   // complete message from arduino, which consistors of snesors data char rdata; // received charactors
int firstVal, secondVal, thirdVal; // sensors int led1,led2,led3,led4,led5,led6;
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App. void myTimerEvent()
{
    // You can send any value at any time. Blynk.virtualWrite(V1, millis() / 1000);
}
void setup()
{
    BlynkTimer timer;
    // Debug console Serial.begin(9600); Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, sensorvalue1);
    timer.setInterval(1000L, sensorvalue2);
    timer.setInterval(1000L, sensorvalue3);
    timer.setInterval(1000L, sensorvalue4);
    timer.setInterval(1000L, sensorvalue5);
    timer.setInterval(1000L, sensorvalue6);
}
void loop()
{
    if (Serial.available() == 0)
    {
        Blynk.run();
        timer.run(); // Initiates BlynkTimer
    }
    if (Serial.available() > 0)
    {
        rdata = Serial.read();
        myString = myString + rdata;
        Serial.print(rdata);
        if (rdata == '\n')
        {
            Serial.println(myString);
            Serial.println("hello"); // this shows in serial monitor means the code is working
            // new code
            String l = getValue(myString, ',', 0);
            String m = getValue(myString, ',', 1);
            String n = getValue(myString, ',', 2);
            String o = getValue(myString, ',', 3);
            String p = getValue(myString, ',', 4);
            String q = getValue(myString, ',', 5);
            // these leds represents the leds used in Blynk application led1 = l.toInt();
            led2 = m.toInt();
            led3 = n.toInt();
            led4 = o.toInt();
            led5 = p.toInt();
            led6 = q.toInt();
            myString = "";
            // end new code
        }
    }
}
void sensorvalue1()
{
    int sdata = led1;
    // You can send any value at any time. Blynk.virtualWrite(V10, sdata);
}
void sensorvalue2()
{
    int sdata = led2;
    // You can send any value at any time. Blynk.virtualWrite(V11, sdata);
}
void sensorvalue3()
{
    int sdata = led3;
    // You can send any value at any time. Blynk.virtualWrite(V12, sdata);}
    void sensorvalue4()
    {
        int sdata = led4;
        // You can send any value at any time. Blynk.virtualWrite(V13, sdata);
    }
    void sensorvalue5()
    {
        int sdata = led5;
        // You can send any value at any time. Blynk.virtualWrite(V14, sdata);
    }
    void sensorvalue6()
    {
        int sdata = led6;
        // You can send any value at any time. Blynk.virtualWrite(V15, sdata);
    }
    String getValue(String data, char separator, int index)
    {
        int found = 0;
        int strIndex[] = {0, -1};
        int maxIndex = data.length() - 1;
        for (int i = 0; i <= maxIndex && found <= index; i++)
        {
            if (data.charAt(i) == separator || i == maxIndex)
            {
                found++;
                strIndex[0] = strIndex[1] + 1;
                strIndex[1] = (i == maxIndex) ? i + 1 : i;
            }
        }
        return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
    }
