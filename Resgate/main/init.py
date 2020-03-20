import RPi.GPIO as GPIO
import time 
import ultrassonic as ult

GPIO.setmode(GPIO.BCM)

ult_sen = [0,1] #trig[0], echo[0], trig[1], echo[1], ... , trig[n], echo[n]

for i in range(len(ult_sen)):
	if((i%2) == 0):
		GPIO.setup(ult_sen[i], GPIO.OUT)
	else:
		GPIO.setup(ult_sen[i], GPIO.IN)

#ex.:
distance = ult.read(ult_sen[0], ult_sen[1])

GPIO.cleanup()