import cv2
import numpy as np

PATH = '/home/felipe/Imagens/ball.png'  

frame = cv2.imread(PATH)
img = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
circles = cv2.HoughCircles(img, cv2.HOUGH_GRADIENT, 1, 20, param1=130, param2=30, minRadius=0, maxRadius=0)

if circles is not None:
    for x, y, r in circles[0]:
        cv2.circle(frame,(x,y),r,(0,255,0),2)

cv2.imshow('Xamaa',frame)
cv2.waitKey(0)
cv2.destroyAllWindows()
