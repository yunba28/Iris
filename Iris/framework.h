// header.h : 標準のシステム インクルード ファイルのインクルード ファイル、
// またはプロジェクト専用のインクルード ファイル
//

#pragma once

#define _USE_MATH_DEFINES

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
// Windows ヘッダー ファイル
#include <windows.h>
// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 世界一害悪でゴミにも劣るカスマクロを消す
#ifdef min
	#undef min
#endif

// 世界一害悪でゴミにも劣るカスマクロを消す
#ifdef max
	#undef max
#endif