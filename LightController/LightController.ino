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
  DmxMaster.maxChannel(4);
  DmxMaster.write(4, 255);
}

void loop() {
  int brightness;
  int rando;
  unsigned long startTime
  
  if (Serial.available() > 0) {

    weatherCode = Serial.read();

    startTime = millis();

    if (weatherCode == 200 || weatherCode == 210 || weatherCode == 230)
    {
      while ((startTime + 30000) >= millis())
      {                
        rando = random(50,100);

        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);
        
        delay(10*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);
        
        delay(150*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);

        delay(1000);
      }
    }
    else if (weatherCode == 201 || weatherCode == 211 || weatherCode == 231)
    {
      while ((startTime + 30000) >= millis())
      {
        rando = random(30,80);

        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);
        /* Update DMX channel 1 to new brightness */
        
        /* Small delay to slow down the ramping */
        delay(10*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);
        
        delay(150*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);

        delay(1000);
      }
    }
    else if (weatherCode == 202 || weatherCode == 212 || weatherCode == 221 || weatherCode == 232)
    {
      while ((startTime + 30000) >= millis())
      {
        rando = random(1,60);

        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);

        delay(10*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);

        delay(150*rando);
    
        DmxMaster.write(1, 255);
        DmxMaster.write(2, 255);
        DmxMaster.write(3, 255);
    
        delay(10);
        
        DmxMaster.write(1, 0);
        DmxMaster.write(2, 0);
        DmxMaster.write(3, 0);

        delay(1000);
      }
    }
    else if (weatherCode == 300 || weatherCode == 301 || weatherCode == 310 || weatherCode == 500 || weatherCode == 520)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // light rain - Slight blue
    }
      
    else if (weatherCode == 302 || weatherCode == 311 || weatherCode == 313 || weatherCode == 321 || weatherCode == 501 || weatherCode == 521)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // rain - Slight grey / dark / dim
    }
    else if (weatherCode == 312 || weatherCode == 314 || weatherCode == 502 || weatherCode == 503 || weatherCode == 504 || weatherCode == 522 || weatherCode == 531)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // heavy rain / more grey / darker / dimmer
    }
    else if (weatherCode == 600 || weatherCode == 601 || weatherCode == 620 || weatherCode == 621)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // snow / white light
    }
    else if (weatherCode == 602 || weatherCode == 622)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // heavy snow / dim white
    }
   else if (weatherCode == 611 || weatherCode == 612 || weatherCode == 615 || weatherCode == 906 || weatherCode == 616)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // hail / dark grey
    }
    else if (weatherCode == 800 || weatherCode == 951 || weatherCode == 801 || weatherCode == 802 || weatherCode == 904)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // Sunny day / Warm yellow
    }
    else if (weatherCode == 952 || weatherCode == 953 || weatherCode == 803 || weatherCode == 804)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // light wind / less warm yellow
    }
    else if (weatherCode == 701 || weatherCode == 711 || weatherCode == 721 || weatherCode == 905 || weatherCode == 954 || weatherCode == 955 || weatherCode == 903)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // wind / less warm yellow
    }
    else if (weatherCode == 771 || weatherCode == 956 || weatherCode == 957 || weatherCode == 958 || weatherCode == 959)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // heavy wind / less warm yellow
    }
    else if (weatherCode == 731 || weatherCode == 751 || weatherCode == 761 || weatherCode == 762)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // sandy wind / yellow
    }
    else if (weatherCode == 781)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // Tornado / grey
    }
    else if (weatherCode == 901 || weatherCode == 902 || weatherCode == 962 || weatherCode == 960 || weatherCode == 961)
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // Tropical cyclone / very grey
    }
    else
    {
      while ((startTime + 30000) >= millis())
      {
        
      }
      // Party Mode
    }
  }
}


