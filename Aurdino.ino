// ARDUINO PROGRAMMING CODE
#include <SoftwareSerial.h> SoftwareSerial nodemcu(2,3);

int parking1_slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino int parking1_slot2_ir_s = 5;
int parking1_slot3_ir_s = 6;
int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;
int parking2_slot3_ir_s = 9;

String sensor1;
String sensor2;
String sensor3;
String sensor4;
String sensor5;
String sensor6;

String sensorA;
String sensorB;
String sensorC;
String sensorD;
String sensorE;
String sensorF;

void p1slot1();
void p1slot2();
void p1slot3();
void p2slot1();
void p2slot2();
void p2slot3();
String cdata = ""; // complete data, consisting of sensor values for the desktop String ddata=""; // complete data, consisting of sensors values for the mobile

void setup()
{
    Serial.begin(9600);
    pinMode(parking1_slot1_ir_s, INPUT);
    pinMode(parking1_slot2_ir_s, INPUT);
    pinMode(parking1_slot3_ir_s, INPUT);
    pinMode(parking2_slot1_ir_s, INPUT);
    pinMode(parking2_slot2_ir_s, INPUT);
    pinMode(parking2_slot3_ir_s, INPUT);
}
void loop()
{

    p1slot1();
    p1slot2();
    p1slot3();

    p2slot1();
    p2slot2();
    p2slot3();

    cdata = cdata + sensor1 + "," + sensor2 + "," + sensor3 + "," + sensor4 + "," + sensor5 + "," + sensor6 + ","; // comma will be used a delimeter
    ddata = ddata + sensorA + "," + sensorB + "," + sensorC + "," + sensorD + "," + sensorE + "," + sensorF + ","; // comma will be used a delimeter
    Serial.println(cdata);
    Serial.println(ddata);
    nodemcu.println(ddata);

    delay(2000); // 2 seconds cdata = "";
    ddata = "";
    digitalWrite(parking1_slot1_ir_s, HIGH);
    digitalWrite(parking1_slot2_ir_s, HIGH);
    digitalWrite(parking1_slot3_ir_s, HIGH);

    digitalWrite(parking2_slot1_ir_s, HIGH);
    digitalWrite(parking2_slot2_ir_s, HIGH);
    digitalWrite(parking2_slot3_ir_s, HIGH);
}

// P1slot1 is a user defined function, it has no return type and it doesn not take any argument as the input. if there is a car infront of the sensor it gives digital logic 0, and if no car then it give digital logic 1, depending on this, then we store p1s1on or p1s1off. The same mechanism is used for all the other infrared sensors.

void p1slot1() // parkng 1 slot1
{
    if (digitalRead(parking1_slot1_ir_s) == LOW)
    {
        sensor1 = "p1s1on"; // parking1 slot1 (desktop app) sensorA = "255"; // parking1 slot1 (mobile app) delay(200);
    }
    if (digitalRead(parking1_slot1_ir_s) == HIGH)
    {
        sensor1 = "p1s1off";
        sensorA = "0";
        delay(200);
    }
}
void p1slot2() // parkng 1 slot1
{
    if (digitalRead(parking1_slot2_ir_s) == LOW)
    {
        sensor2 = "p1s2on"; // parking1 slot1 (desktop app) sensorB = "255"; // parking1 slot1 (mobile app) delay(200);
    }
    if (digitalRead(parking1_slot2_ir_s) == HIGH)
    {
        sensor2 = "p1s2off";
        sensorB = "0";
        delay(200);
    }
}
void p1slot3() // parkng 1 slot1
{
    if (digitalRead(parking1_slot3_ir_s) == LOW)
    {
        sensor3 = "p1s3on"; // parking1 slot1 (desktop app) sensorC = "255"; // parking1 slot1 (mobile app) delay(200);
    }
    if (digitalRead(parking1_slot3_ir_s) == HIGH)
    {
        sensor3 = "p1s3off";
        sensorC = "0";
        delay(200);
    }
}
void p2slot1() // parkng 1 slot1
{
    if (digitalRead(parking2_slot1_ir_s) == LOW)
    {
        sensor4 = "p2s1on"; // parking1 slot1 (desktop app) sensorD = "255"; // parking1 slot1 (mobile app)
    }
    if (digitalRead(parking2_slot1_ir_s) == HIGH)
    {
        sensor4 = "p2s1off";
        sensorD = "0";
        delay(200);
    }
}
void p2slot2() // parkng 1 slot1
{
    if (digitalRead(parking2_slot2_ir_s) == LOW)
    {
        sensor5 = "p2s2on"; // parking1 slot1 (desktop app) sensorE = "255"; // parking1 slot1 (mobile app) delay(200);
    }
    if (digitalRead(parking2_slot2_ir_s) == HIGH)
    {
        sensor5 = "p2s2off";
        sensorE = "0";
        delay(200);
    }
}
void p2slot3() // parkng 1 slot1
{
    if (digitalRead(parking2_slot3_ir_s) == LOW)
    {
        sensor6 = "p2s3on"; // parking1 slot1 (desktop app) sensorF = "255"; // parking1 slot1 (mobile app) delay(200);
    }
    if (digitalRead(parking2_slot3_ir_s) == HIGH)
    {
        sensor6 = "p2s3off";
        sensorF = "0";
        delay(200);
    }
}
