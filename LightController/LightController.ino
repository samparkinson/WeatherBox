/* Welcome to DmxMaster. This library allows you to control DMX stage and
** architectural lighting and visual effects easily from Arduino. DmxMaster
** is compatible with the Tinker.it! DMX shield and all known DIY Arduino
** DMX control circuits.
**
** DmxMaster is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/DmxMaster */

/* To use DmxMaster, you will need the following line. Arduino will
** auto-insert it if you select Sketch > Import Library > DmxMaster. */

#include <DmxMaster.h>
  int one;
  int two;
  int three;
  int four;

void setup() {
  /* The most common pin for DMX output is pin 3, which DmxMaster
** uses by default. If you need to change that, do it here. */
  Serial.begin(9600);
  DmxMaster.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
** even if you only need to adjust the first channel. You can
** easily change the number of channels sent here. If you don't
** do this, DmxMaster will set the maximum channel number to the
** highest channel you DmxMaster.write() to. */
  DmxMaster.maxChannel(334);
  
}
void loop() {
  int brightness;
  int rando;
  unsigned long startTime;
  int weatherCode;
  int randoChange;

  int one = 332;
  int two = 333;
  int three = 334;
  int four = 331;
  DmxMaster.write(four, 255);


  
  if (Serial.available() >= 3) {

    String inString = Serial.readString();
    weatherCode = inString.toInt();

    Serial.println("WeatherCode" + weatherCode);

    //if (inChar == '\r') {
      
      startTime = millis();
      
      if (weatherCode == 200 || weatherCode == 210 || weatherCode == 230)
      {
        while ((startTime + 29000) >= millis())
        {                
          rando = random(50,100);
  
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
          
          delay(10*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
          
          delay(150*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
  
          delay(1000);
        }
      }
      else if (weatherCode == 201 || weatherCode == 211 || weatherCode == 231)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(30,80);
  
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
          /* Update DMX channel 1 to new brightness */
          
          /* Small delay to slow down the ramping */
          delay(10*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
          
          delay(150*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
  
          delay(1000);
        }
      }
      else if (weatherCode == 202 || weatherCode == 212 || weatherCode == 221 || weatherCode == 232)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(1,60);
  
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
  
          delay(10*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
  
          delay(150*rando);
      
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
      
          delay(10);
          
          DmxMaster.write(one, 0);
          DmxMaster.write(two, 0);
          DmxMaster.write(three, 0);
  
          delay(1000);
        }
      }
      else if (weatherCode == 300 || weatherCode == 301 || weatherCode == 310 || weatherCode == 500 || weatherCode == 520)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 14);
          DmxMaster.write(two, 171);
          DmxMaster.write(three, 245);
        }
        // light rain - Slight blue
      }
        
      else if (weatherCode == 302 || weatherCode == 311 || weatherCode == 313 || weatherCode == 321 || weatherCode == 501 || weatherCode == 521)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 163);
          DmxMaster.write(two, 163);
          DmxMaster.write(three, 163);
          DmxMaster.write(four, 100);
        }
        // rain - Slight grey / dark / dim
      }
      else if (weatherCode == 312 || weatherCode == 314 || weatherCode == 502 || weatherCode == 503 || weatherCode == 504 || weatherCode == 522 || weatherCode == 531)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 100);
          DmxMaster.write(two, 100);
          DmxMaster.write(three, 100);
          DmxMaster.write(four, 60);
        }
        // heavy rain / more grey / darker / dimmer
      }
      else if (weatherCode == 600 || weatherCode == 601 || weatherCode == 620 || weatherCode == 621)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
          DmxMaster.write(four, 120);
        }
        // snow / white light
      }
      else if (weatherCode == 602 || weatherCode == 622)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(70, 85);
          randoChange = random (300, 2000);
          
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 255);
          DmxMaster.write(four, rando);
  
          delay(randoChange);
        }
        // heavy snow / dim white
      }
     else if (weatherCode == 611 || weatherCode == 612 || weatherCode == 615 || weatherCode == 906 || weatherCode == 616)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(58, 65);
          randoChange = random (300, 1000);
          
          DmxMaster.write(one, 200);
          DmxMaster.write(two, 200);
          DmxMaster.write(three, 200);
          DmxMaster.write(four, rando);
  
          delay(randoChange);     
        }
        // hail / dark grey
      }
      else if (weatherCode == 800 || weatherCode == 951 || weatherCode == 801 || weatherCode == 802 || weatherCode == 904)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 151);
          DmxMaster.write(four, 180);
        }
        // Sunny day / Warm yellow
      }
      else if (weatherCode == 952 || weatherCode == 953 || weatherCode == 803 || weatherCode == 804)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 151);
          DmxMaster.write(four, 140);
        }
        // light wind / less warm yellow
      }
      else if (weatherCode == 701 || weatherCode == 711 || weatherCode == 721 || weatherCode == 905 || weatherCode == 954 || weatherCode == 955 || weatherCode == 903)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 151);
          DmxMaster.write(four, 140);
        }
        // wind / less warm yellow
      }
      else if (weatherCode == 771 || weatherCode == 956 || weatherCode == 957 || weatherCode == 958 || weatherCode == 959)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 151);
          DmxMaster.write(four, 140);
        }
        // heavy wind / less warm yellow
      }
      else if (weatherCode == 731 || weatherCode == 751 || weatherCode == 761 || weatherCode == 762)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(135, 145);
          randoChange = random (300, 1000);
          
          DmxMaster.write(one, 255);
          DmxMaster.write(two, 255);
          DmxMaster.write(three, 151);
          DmxMaster.write(four, rando);
  
          delay(randoChange);
        }
        // sandy wind / yellow
      }
      else if (weatherCode == 781)
      {
        while ((startTime + 29000) >= millis())
        {
    
          rando = random(90, 109);
          randoChange = random (1, 300);
          
          DmxMaster.write(one, 100);
          DmxMaster.write(two, 100);
          DmxMaster.write(three, 100);
          DmxMaster.write(four, rando);
  
          delay(randoChange);
        }
        // Tornado / grey
      }
      else if (weatherCode == 901 || weatherCode == 902 || weatherCode == 962 || weatherCode == 960 || weatherCode == 961)
      {
        while ((startTime + 29000) >= millis())
        {
          rando = random(100, 130);
          randoChange = random (900, 2000);
          
          DmxMaster.write(one, 100);
          DmxMaster.write(two, 100);
          DmxMaster.write(three, 100);
          DmxMaster.write(four, rando);
  
          delay(randoChange);
        }
        // Tropical cyclone / very grey
      }
      else if (weatherCode == 666)
      {
        while ((startTime + 29000) >= millis())
        {
          DmxMaster.write(one, 100);
          DmxMaster.write(two, 100);
          DmxMaster.write(three, 100);
          DmxMaster.write(four, 70);
        }
        // Night
      }
      else if (weatherCode != -1)
      {
        while ((startTime + 29000) >= millis())
        {
          int rando2;
          int rando3;
          
          rando = random(0, 255);
          rando2 = random(0, 255);
          rando3 = random(0, 255);
          randoChange = random (0, 400);
          
          DmxMaster.write(332, rando);
          DmxMaster.write(333, rando2);
          DmxMaster.write(334, rando3);
          DmxMaster.write(331, 255);
  
          delay(randoChange);
        }
        // Party Mode
      }
    weatherCode = 0;
    //}

    DmxMaster.write(one, 0);
    DmxMaster.write(two, 0);
    DmxMaster.write(three, 0);
        
  }

  //DmxMaster.write(four, 100);
  
  //DmxMaster.write(one, 255);
  //DmxMaster.write(two, 0);
  //DmxMaster.write(three, 0);

  //delay(2000);
  
  //DmxMaster.write(one, 0);
  //DmxMaster.write(two, 255);
  //DmxMaster.write(three, 0);

  //delay(2000);

  //DmxMaster.write(one, 0);
  //DmxMaster.write(two, 0);
  //DmxMaster.write(three, 255);

  //delay(2000);

  //DmxMaster.write(one, 0);
  //DmxMaster.write(two, 0);
  //DmxMaster.write(three, 0);
  //DmxMaster.write(four, 255);
  
}


