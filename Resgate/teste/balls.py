import cv2
import numpy as np
import circle_segmentation as cs

PATH = '/home/felipe/Imagens/ballb.png'  

frame = cv2.imread(PATH)

#Alterar os valores para detecção da bola prateada.
circles = cs.circle(frame, 1, 260, 30, 65, 0, 0)
if circles is not None:
    for x, y, r in circles[0]:
        cv2.circle(frame,(x,y),r,(0,255,0),2)

cv2.imshow('Xamaa',frame)
cv2.waitKey(0)
cv2.destroyAllWindows()

