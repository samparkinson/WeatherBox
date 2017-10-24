import constants
import re
import time
import json
import os
import urllib2
from playsound import playsound
import psutil
import serial
import threading
import pygame
from slackclient import SlackClient

# class PlayThatFunkyMusic:


class FetchWeather:
    url = "http://api.openweathermap.org/data/2.5/weather?q="

    def city(self, city):
        requesturl = "http://api.openweathermap.org/data/2.5/weather?q=" + city
        req = urllib2.Request(requesturl)
        req.add_header('x-api-key', constants.OPENWEATHER)
        response = urllib2.urlopen(req)
        return json.load(response)


class slackky:

    def __init__(self):
        self.slack_client1 = SlackClient(constants.SLACK)

    def playFromPath(self, path):
        pygame.init()
        pygame.mixer.music.load(path)
        pygame.mixer.music.play()

    def routeMusicFromWeather(self, weatherCode):
        folder = "/Volumes/Data/ProtoAudio/"

        if weatherCode in (200, 210, 230):
            self.playFromPath(folder + "thunder_light_rain.wav")
        elif weatherCode in (201, 211, 231):
            self.playFromPath(folder + "thunderstorm.wav")
        elif weatherCode in (202, 212, 221, 232):
            self.playFromPath(folder + "heavy_thunderstorm.wav")
        elif weatherCode in (300, 301, 310, 500, 520):
            self.playFromPath(folder + "light_rain.wav")
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

    def play(self, slack_client, message):
        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Trying to play some music",
            as_user=True)

        path = "/Users/sam/DrizzleRain.wav"

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Song path: {0}.".format(path),
            as_user=True)

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Playing that funky music",
            as_user=True)

        self.playFromPath(path)

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Music Played",
            as_user=True)

    def cityWeather(self, city, slack_client, message, message_text):
        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Trying to get wind for city",
            as_user=True)

        api = FetchWeather()
        weatherdata = api.city(city)
        print json.dumps(weatherdata, indent=2)
        if 'wind' in weatherdata and 'speed' in weatherdata['wind']:
            wind = weatherdata['wind']
            windspeed = wind['speed']
        else:
            pass

        if 'weather' in weatherdata and 'id' in weatherdata['weather'][0]:
            weather = weatherdata['weather'][0]
            weatherId = weather['id']
            self.routeMusicFromWeather(weatherId)

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Wind for {0}: {1}.".format(
                city, windspeed,),
            as_user=True)

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Passing to serial..",
            as_user=True)

        speed = windspeed * 25
        speedrounded = int(round(speed))

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Multiplied speed is: {0}".format(
                speedrounded),
            as_user=True)

        try:
            ser = serial.Serial("/dev/tty.usbmodem1421", 9600)
            ser.baudrate = 9600
            ser.write(bytes(speedrounded))
        except serial.SerialException:
            print "Usb Not found"

        slack_client.api_call(
            "chat.postMessage",
            channel=message['channel'],
            text="Passed: %s%%." % message_text,
            as_user=True)

    def main(self):

            # Fetch your Bot's User ID
        slack_client = self.slack_client1
        user_list = slack_client.api_call("users.list")
        for user in user_list.get('members'):
            if user.get('name') == "pibot":
                slack_user_id = user.get('id')
                break

        # Start connection
        if slack_client.rtm_connect():
            print "Connected!"

            slack_client.api_call(
                "chat.postMessage",
                channel="general",
                text="I am here!!!",
                as_user=True)

            slack_client.api_call(
                "chat.postMessage",
                channel="general",
                text="My networking details are: %s%%" % psutil.net_if_addrs(),
                as_user=True)

            while True:
                for message in slack_client.rtm_read():
                    if 'text' in message and message['text'].startswith("<@%s>" % slack_user_id):

                        print "Message received: %s" % json.dumps(message, indent=2)

                        message_text = message['text'].split(
                            "<@%s>" % slack_user_id)[1].strip()

                        if re.match(r'.*(help).*', message_text, re.IGNORECASE):

                            slack_client.api_call(
                                "chat.postMessage",
                                channel=message['channel'],
                                text="The commands I understand are: music, rebootme and city[city name with no spaces]",
                                as_user=True)

                        elif re.match(r'.*(music).*', message_text, re.IGNORECASE):

                            self.play(slack_client, message)

                        elif re.match(r'.*(rebootme).*', message_text, re.IGNORECASE):

                            slack_client.api_call(
                                "chat.postMessage",
                                channel=message['channel'],
                                text="See you soon!",
                                as_user=True)

                            os.system('reboot')

                        elif re.match(r'.*(city).*', message_text, re.IGNORECASE):

                            mes = message_text
                            city = mes.split(' ', 1)[1]

                            self.cityWeather(
                                city, slack_client, message, message_text)

                        else:

                            slack_client.api_call(
                                "chat.postMessage",
                                channel=message['channel'],
                                text="Passing to serial..",
                                as_user=True)

                            ser = serial.Serial("/dev/tty.usbmodem1421", 9600)
                            ser.baudrate = 9600
                            ser.write(message_text.encode())

                            slack_client.api_call(
                                "chat.postMessage",
                                channel=message['channel'],
                                text="Passed: %s%%." % message_text,
                                as_user=True)

                    if 'ok' in message and 'false' in message['ok']:

                        print "Connection error..."
                        print "trying to connect:"

                        if slack_client.rtm_connect():
                            print "Connected!"

                time.sleep(1)


if __name__ == '__main__':
    client = slackky()
    client.main()
