#pragma once
#include <Windows.h>
#include <assert.h>

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <bitset>
#include <functional>
#include <filesystem>

#include "LogHMath.h"
#include "LogHEnum.h"

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace std;

#define SAFE_DELETE(p) { if(p) { delete (p); (p) = nullptr; } }