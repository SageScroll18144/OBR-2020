import cv2

def circle(img, dp, minDist, param_1, param_2, minR, maxR):
	img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	circles = cv2.HoughCircles(img, cv2.HOUGH_GRADIENT, dp, minDist, param1=param_1, param2=param_2, minRadius=minR, maxRadius=maxR)
	
	return circles

def hasABall(img, x, r, limite):
	center = int(img.shape[0]/2)
	euclidian_distance = 0
	if x >= center:
		euclidian_distance = (x - r) - center 
	elif x < center:
		euclidian_distance = center - (x + r)

	return (euclidian_distance <= limite)

