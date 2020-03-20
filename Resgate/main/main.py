import serial as little_board
import RPi.GPIO as GPIO
import time 
import ultrassonic as ult
import cv2
import circle_segmentation as cs

cam = cv2.VideoCapture(0)
cam.set(cv2.CAP_PROP_FPS, 180)

GPIO.setmode(GPIO.BCM)

ult_sen = [0,1] #trig[0], echo[0], trig[1], echo[1], ... , trig[n], echo[n]

#it's just an example. Change please the name mainly for job with SO Windown and Linux
name_board = '/dev/ttyUSB0'
value_of_baudRate= 9600

b = little_board.Board(name_board, value_of_baudRate)

b.begin()

# setup
for i in range(len(ult_sen)):
	if((i%2) == 0):
		GPIO.setup(ult_sen[i], GPIO.OUT)
	else:
		GPIO.setup(ult_sen[i], GPIO.IN)

# loop
while True:
	ret, frame = cam.read()	
	
	circles_gray = cs.circle(frame, 1, 20, 130, 30, 0, 0)
	circles_black = cs.circle(frame, 1, 260, 30, 65, 0, 0)
	
	coordinate_gray_ball_x, coordinate_gray_ball_y, coordinate_gray_ball_r = circles_gray[0]
	coordinate_black_ball_x, coordinate_black_ball_y, coordinate_black_ball_r = circles_black[0]
	movement = "S"
    #byte from send. It's a form to say 'you can send... '
    
	distance = [ult.read(ult_sen[0], ult_sen[1])]

	if distance[0] < 0:
		b.send("CASO SE TIVER PERTO DA PAREDE")
	elif distance[1] < 0:
		b.send("parede")
	elif cs.hasABall(frame, coordinate_black_ball_x, coordinate_black_ball_r) == 0 or cs.hasABall(frame, coordinate_gray_ball_x, coordinate_gray_ball_r) == 0:
		b.send("F")
	elif cs.hasABall(frame, coordinate_black_ball_x, coordinate_black_ball_r) == 1 or cs.hasABall(frame, coordinate_gray_ball_x, coordinate_gray_ball_r) == 1:
		b.send("SL")
	elif cs.hasABall(frame, coordinate_black_ball_x, coordinate_black_ball_r) == -1 or cs.hasABall(frame, coordinate_gray_ball_x, coordinate_gray_ball_r) == -1:
		b.send("SR")
b.finalize()
GPIO.cleanup()