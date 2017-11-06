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
  /* Simple loop to ramp up brightness */

  // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                weatherCode = Serial.read();

                if (weatherCode == 200 || weatherCode == 210 || weatherCode == 230)
                {
                  // thunder light rain
                }
                else if (weatherCode == 201 || weatherCode == 211 || weatherCode == 231)
                {
                  // thunderstorm
                }
                else if (weatherCode == 202 || weatherCode == 212 || weatherCode == 221 || weatherCode == 232)
                {
                  // heavy thunderstorm
                }
                else if (weatherCode == 300 || weatherCode == 301 || weatherCode == 310 || weatherCode == 500 || weatherCode == 520)
                {
                  // light rain
                }

        elif weatherCode in (302, 311, 313, 321, 501, 521):
            self.playFromPath(folder + "rain.wav")
        elif weatherCode in (312, 314, 502, 503, 504, 522, 531):
            self.playFromPath(folder + "heavy_rain.wav")
        elif weatherCode in (600, 601, 620, 621):
            self.playFromPath(folder + "snow.wav")
        elif weatherCode in (602, 622):
            self.playFromPath(folder + "heavy_snow.wav")
        elif weatherCode in (611, 612, 615, 906, 616):
            self.playFromPath(folder + "hail.wav")
        elif weatherCode in (800, 951, 801, 802, 904):
            self.playFromPath(folder + "sunny_day.wav")
        elif weatherCode in (952, 953, 803, 804):
            self.playFromPath(folder + "light_wind.wav")
        elif weatherCode in (701, 711, 721, 905, 954, 955, 903):
            self.playFromPath(folder + "wind.wav")
        elif weatherCode in (771, 956, 957, 958, 959):
            self.playFromPath(folder + "heavy_wind.wav")
        elif weatherCode in (731, 751, 761, 762):
            self.playFromPath(folder + "sandy_wind.wav")
        elif weatherCode == 781:
            self.playFromPath(folder + "tornado.wav")
        elif weatherCode in (901, 902, 962, 960, 961):
            self.playFromPath(folder + "tropical_cyclone.wav")
        else:
            pass
              
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
  
  if weatherCode in (200, 210, 230):
      self.playFromPath(folder + "thunder_light_rain.wav")
  else if weatherCode in (201, 211, 231):
      self.playFromPath(folder + "thunderstorm.wav")
  else if weatherCode in (202, 212, 221, 232):
      self.playFromPath(folder + "heavy_thunderstorm.wav")
  else if weatherCode in (300, 301, 310, 500, 520):
      self.playFromPath(folder + "light_rain.wav")
  else if weatherCode in (302, 311, 313, 321, 501, 521):
      self.playFromPath(folder + "rain.wav")
  else if weatherCode in (312, 314, 502, 503, 504, 522, 531):
      self.playFromPath(folder + "heavy_rain.wav")
  else if weatherCode in (600, 601, 620, 621):
      self.playFromPath(folder + "snow.wav")
  else if weatherCode in (602, 622):
      self.playFromPath(folder + "heavy_snow.wav")
  else if weatherCode in (611, 612, 615, 906, 616):
      self.playFromPath(folder + "hail.wav")
  else if weatherCode in (800, 951, 801, 802, 904):
      self.playFromPath(folder + "sunny_day.wav")
  else if weatherCode in (952, 953, 803, 804):
      self.playFromPath(folder + "light_wind.wav")
  else if weatherCode in (701, 711, 721, 905, 954, 955, 903):
      self.playFromPath(folder + "wind.wav")
  else if weatherCode in (771, 956, 957, 958, 959):
      self.playFromPath(folder + "heavy_wind.wav")
  else if weatherCode in (731, 751, 761, 762):
      self.playFromPath(folder + "sandy_wind.wav")
  else if weatherCode == 781:
      self.playFromPath(folder + "tornado.wav")
  else if weatherCode in (901, 902, 962, 960, 961):
      self.playFromPath(folder + "tropical_cyclone.wav")
  else:
      pass

  rando = random(1,100);

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
    /* Update DMX channel 1 to new brightness */
    
    /* Small delay to slow down the ramping */
    delay(150*rando);

    DmxMaster.write(1, 255);
    DmxMaster.write(2, 255);
    DmxMaster.write(3, 255);

    delay(10);
    
    DmxMaster.write(1, 0);
    DmxMaster.write(2, 0);
    DmxMaster.write(3, 0);
    /* Update DMX channel 1 to new brightness */
    
    /* Small delay to slow down the ramping */
    delay(1000);

}


