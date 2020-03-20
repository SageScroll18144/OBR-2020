import cv2

name = "Hey dboa man?"

cam = cv2.VideoCapture(0)
cam.set(cv2.CAP_PROP_FPS, 180)

while(True):
    ret, frame = cam.read()
	 
    #Alterar os valores para detecção da bola prateada.
    circles = cs.circle(frame, 1, 260, 30, 65, 0, 0)
    if circles is not None:
        for x, y, r in circles[0]:
    	    cv2.circle(frame,(x,y),r,(0,255,0),2)

    cv2.imshow(name, frame)
    print(cam.get(cv2.CAP_PROP_FPS))
    #letra 'q'
    if cv2.waitKey(1) == ord('q'):
        break
cam.release()
cv2.destroyWindow(name) 
