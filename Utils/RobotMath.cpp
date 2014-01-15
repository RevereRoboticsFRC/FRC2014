#include "RobotMath.h"

//	Returns a value between 0.0 and 1.0 according to the normalization of val between min and max.
float Normalize(float min, float max, float val) {
	//	Make sure we're not stupid
	if (max < min) {
		float temp = max;
		max = min;
		min = temp;
	}
	float range = max - min;
	//	Clamp first
	val = Clamp(min, max, val);
	float valRange = val - min;
	return valRange / range;
}

//	Clamp a value between a min and a max.
float Clamp(float min, float max, float val) {
	//	Make sure we're not stupid
	if (max < min) {
		float temp = max;
		max = min;
		min = temp;
	}
	//	Clamp dat
	if (val < min)
		return min;
	if (val > max)
		return max;
	return val;
}
