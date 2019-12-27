import RPi.GPIO as GPIO
import time 

def read(trig, echo):
	GPIO.output(trig, True)
	time.sleep(0.0001)
	GPIO.output(echo, False)

	while GPIO.input(echo) == False:
		start = time.time()
	while GPIO.input(echo) == True:
		end = time.time()

	delta_time = end - start

	#cm.:

	return delta_time/0.000058