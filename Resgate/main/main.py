import RPi.GPIO as GPIO
import time 

GPIO.setmode(GPIO.BCM)

trig = 1
echo = 0

GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)

distance = ult.read(trig, echo)

GPIO.cleanup()