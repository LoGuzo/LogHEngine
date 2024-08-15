#pragma once
#include <Windows.h>

#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define SAFE_DELETE(p) { if(p) { delete (p); (p) = NULL; } }