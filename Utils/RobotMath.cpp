#include "RobotMath.h"

void Swap(float& f1, float& f2) {
	float tmp = f1;
	f1 = f2;
	f2 = tmp;
}

/**
 * Returns a value between 0.0 and 1.0 according to the normalization of val within the range.
 * Returns INVALID_ARGUMENT (-1) if the minimum and maximum values are the same.
 */
float Normalize(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	float range = b - a;
	if(range == 0.0) {
		return INVALID_ARGUMENT;
	}
	//	Clamp first
	val = Clamp(a, b, val);
	float valRange = val - a;
	return valRange / range;
}

/**
 * Clamp a value into a range.
 */
float Clamp(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	//	Clamp dat
	if (val < a)
		return a;
	if (val > b)
		return b;
	return val;
}

/**
 * Returns whether or not a value is within the provided bounds, inclusive
 */
bool IsInRange(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	return val >= a && val <= b;
}
