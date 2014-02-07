#include <string>
#include <cstdarg>

#ifndef ROBOMATH
#define ROBOMATH

static const float INVALID_ARGUMENT = -1.0;

float Normalize(float a, float b, float val);

float Clamp(float a, float b, float val);

bool IsInRange(float a, float b, float val);

std::string StrFormat(const char*, ...);

#endif
