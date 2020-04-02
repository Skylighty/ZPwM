#include <Windows.h>
#include <cstdio>
#include "res.h"
using namespace std;

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
  case WM_CREATE:
    break;
  case WM_PAINT:
    HDC hDC;
    hDC = GetDC(hwndDlg);
    BitBlt(hDC, 0, 0, 800, 600, GetDC(0), 0, 0, SRCCOPY);
    SelectObject(hDC, GetStockObject(ANSI_VAR_FONT));
    SetTextColor(hDC, RGB(255, 0, 0));
    TextOut(hDC, 0, 0, "Text output to client area.", 27);
    ReleaseDC(hwndDlg, hDC);
    break;
  case WM_COMMAND:
    {
      switch(HIWORD(wParam))
      {
      case BN_CLICKED:
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON1:
          MessageBox(hwndDlg, "DZIALA", "WOW", MB_ICONINFORMATION | MB_OK);
          break;
        }
      }
    }
    return 0;
  case WM_CLOSE:
    {
    DestroyWindow(hwndDlg);
    PostQuitMessage(0);
    break;
    }
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  }
  return 0;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR nCmdLine, int iCmdShow)
{
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}