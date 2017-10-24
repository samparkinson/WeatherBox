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
        red = json.load(response)
        # return red
        # return red.type()
        print json.dumps(red, indent=2)
        if 'wind' in red and 'speed' in red['wind']:
            wind = red['wind']
            return wind['speed']


class slackky:

    def __init__(self):
        self.slack_client1 = SlackClient(constants.SLACK)

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

        pygame.init()
        pygame.mixer.music.load(path)
        pygame.mixer.music.play()

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
        windspeed = api.city(city)

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

        ser = serial.Serial("/dev/tty.usbmodem1421", 9600)
        ser.baudrate = 9600
        ser.write(bytes(speedrounded))

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

                        message_text = message['text'].\
                            split("<@%s>" % slack_user_id)[1].\
                            strip()

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
