import RPi.GPIO as GPIO
import time    
import numpy as np

'''
 M0  ####  M3.
    ######       -> chassi do robô
    ######       -> M(motor)[número do motor]
 M1  ####  M2
'''

class Control:
    def __init__(self, motors, directions):
        self.motors = motors
        self.directions = directions
    def print_motors(self):
        for i in motors:
            print(i)
    def forward(self):
        for i in motors:
            GPIO.output(directions[i*2], 1)
            GPIO.output(directions[i*2+1], 0)
    def backward(self):
        for i in motors:
            GPIO.output(directions[i*2], 0)
            GPIO.output(directions[i*2+1], 1)
    def left(self):
        for i in range(len(motors)):
            if(i%2) == 0:
                GPIO.output(directions[motors[i]*2], 0)
                GPIO.output(directions[motors[i]*2+1], 1)
            else:
                GPIO.output(directions[motors[i]*2], 1)
                GPIO.output(directions[motors[i]*2+1], 0)
    def right(self):
        for i in range(len(motors)):
            if(i%2) == 0:
                GPIO.output(directions[motors[i]*2], 1)
                GPIO.output(directions[motors[i]*2+1], 0)
            else:
                GPIO.output(directions[motors[i]*2], 0)
                GPIO.output(directions[motors[i]*2+1], 1)
    def spin_l(self):
        GPIO.output(directions[motors[0]*2], 0)
        GPIO.output(directions[motors[0]*2+1], 1)
        GPIO.output(directions[motors[1]*2], 0)
        GPIO.output(directions[motors[1]*2+1], 1)
        GPIO.output(directions[motors[2]*2], 1)
        GPIO.output(directions[motors[2]*2+1], 0)
        GPIO.output(directions[motors[3]*2], 1)
        GPIO.output(directions[motors[3]*2+1], 0)

'''
#TESTE
if __name__ == "main":
    motors = np.array([1,1,1])
    directions = np.array([1,1,1])
    control = Control(motors, directions)
    control.print_motors()
'''
