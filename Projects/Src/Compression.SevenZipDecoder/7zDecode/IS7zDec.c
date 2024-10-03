/*
  IS7zDec.c, by Martijn Laan for Inno Setup
  This file is public domain (like the LZMA SDK)
*/

#ifdef _MSC_VER

/* Stop 7-Zip from using stdcall functions which will get unavoidable decorated names from
   MSVC's cl.exe which Delphi can't handle: first include windows.h and then hide the
   functions 7-Zip wants to use with macros pointing to cdecl prototypes. This will enable
   is us to call the stdcall function from a cdecl implementation in Delphi and keeps the
   rest of windows.h available to 7-Zip. */

#include "../../../../Components/Lzma2/Util/7z/Precomp.h" /* Says it must be included first */
#include "../../../../Components/Lzma2/7zWindows.h"

BOOL _CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#define CreateDirectoryW _CreateDirectoryW

HANDLE _CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
#define CreateFileA _CreateFileA

HANDLE _CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
#define CreateFileW _CreateFileW

BOOL _FileTimeToLocalFileTime(FILETIME* lpFileTime, LPFILETIME lpLocalFileTime);
#define FileTimeToLocalFileTime _FileTimeToLocalFileTime

DWORD _GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
#define GetFileSize _GetFileSize

BOOL _ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
#define ReadFile _ReadFile

BOOL _SetFileAttributesW(LPCWSTR lpFileName, DWORD dwFileAttributes);
#define SetFileAttributesW _SetFileAttributesW

DWORD _SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
#define SetFilePointer _SetFilePointer

BOOL _SetFileTime(HANDLE hFile, FILETIME* lpCreationTime, FILETIME* lpLastAccessTime, FILETIME* lpLastWriteTime);
#define SetFileTime _SetFileTime

BOOL _WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
#define WriteFile _WriteFile

BOOL _CloseHandle(HANDLE hObject);
#define CloseHandle _CloseHandle

DWORD _GetLastError(VOID);
#define GetLastError _GetLastError

HLOCAL _LocalFree(HLOCAL hMem);
#define LocalFree _LocalFree

DWORD _FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, va_list *Arguments);
#define FormatMessageA _FormatMessageA

int _WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);
#define WideCharToMultiByte _WideCharToMultiByte

#endif

#include "../../../../Components/Lzma2/Util/7z/7zMain.c"

#include "../../../../Components/Lzma2/7zAlloc.c"
#include "../../../../Components/Lzma2/7zArcIn.c"
#include "../../../../Components/Lzma2/7zBuf.c"
#include "../../../../Components/Lzma2/7zCrc.c"
#include "../../../../Components/Lzma2/7zCrcOpt.c"
#include "../../../../Components/Lzma2/7zDec.c"
#include "../../../../Components/Lzma2/7zFile.c"
#include "../../../../Components/Lzma2/7zStream.c"
#include "../../../../Components/Lzma2/Bcj2.c"
#include "../../../../Components/Lzma2/Bra.c"
#include "../../../../Components/Lzma2/Bra86.c"
#include "../../../../Components/Lzma2/Delta.c"
#include "../../../../Components/Lzma2/LzmaDec.c"
#include "../../../../Components/Lzma2/Lzma2Dec.c"

int IS_7zDec(WCHAR *fileName, BOOL fullPaths)
{
  WCHAR* args[3];
  args[0] = L"";
  args[1] = fullPaths?L"x":L"e";
  args[2] = fileName;
  return mainW(3, args);
}