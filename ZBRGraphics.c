
#include "ZBRGraphics.h"


HMODULE hModuleZbrGraphics = NULL;

//SDK specific functions
PTR_ZBRGDIGetSDKVer ZBRGDIGetSDKVer;
PTR_ZBRGDIGetSDKVsn ZBRGDIGetSDKVsn;
PTR_ZBRGDIGetSDKProductVer ZBRGDIGetSDKProductVer;

//Initialization functions
PTR_ZBRGDIInitGraphics ZBRGDIInitGraphics;
PTR_ZBRGDIInitGraphicsEx ZBRGDIInitGraphicsEx;
PTR_ZBRGDIInitGraphicsFromPrintDlg ZBRGDIInitGraphicsFromPrintDlg;
PTR_ZBRGDICloseGraphics ZBRGDICloseGraphics;
PTR_ZBRGDIClearGraphics ZBRGDIClearGraphics;
PTR_ZBRGDIStartPage ZBRGDIStartPage;
PTR_ZBRGDIEndPage ZBRGDIEndPage;

//Print functions
PTR_ZBRGDIPreviewGraphics ZBRGDIPreviewGraphics;
PTR_ZBRGDIPrintGraphics ZBRGDIPrintGraphics;
PTR_ZBRGDIPrintGraphicsEx ZBRGDIPrintGraphicsEx;
PTR_ZBRGDIPrintFilePos ZBRGDIPrintFilePos;
PTR_ZBRGDIPrintFileRect ZBRGDIPrintFileRect;
PTR_ZBRGDIIsPrinterReady ZBRGDIIsPrinterReady;
PTR_ZBRGDIPrintImagePos ZBRGDIPrintImagePos;
PTR_ZBRGDIPrintImageRect ZBRGDIPrintImageRect;
PTR_ZBRGDICancelJob ZBRGDICancelJob;

//Draw functions
PTR_ZBRGDIDrawText ZBRGDIDrawText;
PTR_ZBRGDIDrawTextEx ZBRGDIDrawTextEx;
PTR_ZBRGDIDrawTextUnicode ZBRGDIDrawTextUnicode;
PTR_ZBRGDIDrawTextUnicodeEx ZBRGDIDrawTextUnicodeEx;
PTR_ZBRGDIDrawTextRect ZBRGDIDrawTextRect;
PTR_ZBRGDIDrawTextRectEx ZBRGDIDrawTextRectEx;
PTR_ZBRGDIDrawLine ZBRGDIDrawLine;
PTR_ZBRGDIDrawImage ZBRGDIDrawImage;
PTR_ZBRGDIDrawImageEx ZBRGDIDrawImageEx;
PTR_ZBRGDIDrawImagePos ZBRGDIDrawImagePos;
PTR_ZBRGDIDrawImagePosEx ZBRGDIDrawImagePosEx;
PTR_ZBRGDIDrawImageRect ZBRGDIDrawImageRect;
PTR_ZBRGDIDrawImageRectEx ZBRGDIDrawImageRectEx;
PTR_ZBRGDIDrawRectangle ZBRGDIDrawRectangle;
PTR_ZBRGDIDrawEllipse ZBRGDIDrawEllipse;
PTR_ZBRGDIDrawBarCode ZBRGDIDrawBarCode;


int ZbrGraphics_LoadFunctionDLL(_In_ HMODULE *hModuleDLL, _In_ LPSTR functionName, _In_ FARPROC *funtionPtr)
{
    if(*funtionPtr == NULL)
    {
        if (hModuleDLL == NULL)
		{
            return 1;
		}

        if ((*funtionPtr = GetProcAddress(*hModuleDLL, functionName)) == NULL)
		{
            return 2;
		}
        else
		{
            return 0;
		}
    }
    else
	{
        return 0;
	}
}


int ZbrGraphics_LoadDLL(_In_ LPSTR filename)
{
	int ret;
	TCHAR filenameFinal[5096];

	if(filename == NULL)
	{
		wsprintf(filenameFinal, L"%hs", ZBR_GRAPHICS_DEFAULT_NAME);
	}
	else
	{
		wsprintf(filenameFinal, L"%hs", filename);
	}

	hModuleZbrGraphics = LoadLibrary(filenameFinal);
	if(hModuleZbrGraphics == NULL)
	{
		return 10;
	}


	//SDK specific functions
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIGetSDKVer", (FARPROC *)&ZBRGDIGetSDKVer);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIGetSDKVsn", (FARPROC *)&ZBRGDIGetSDKVsn);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIGetSDKProductVer", (FARPROC *)&ZBRGDIGetSDKProductVer);
	if (ret != 0)
		return ret;

	//Initialization functions
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIInitGraphics", (FARPROC *)&ZBRGDIInitGraphics);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIInitGraphicsEx", (FARPROC *)&ZBRGDIInitGraphicsEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIInitGraphicsFromPrintDlg", (FARPROC *)&ZBRGDIInitGraphicsFromPrintDlg);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDICloseGraphics", (FARPROC *)&ZBRGDICloseGraphics);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIClearGraphics", (FARPROC *)&ZBRGDIClearGraphics);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIStartPage", (FARPROC *)&ZBRGDIStartPage);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIEndPage", (FARPROC *)&ZBRGDIEndPage);
	if (ret != 0)
		return ret;

	//Print functions
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPreviewGraphics", (FARPROC *)&ZBRGDIPreviewGraphics);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintGraphics", (FARPROC *)&ZBRGDIPrintGraphics);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintGraphicsEx", (FARPROC *)&ZBRGDIPrintGraphicsEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintFilePos", (FARPROC *)&ZBRGDIPrintFilePos);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintFileRect", (FARPROC *)&ZBRGDIPrintFileRect);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIIsPrinterReady", (FARPROC *)&ZBRGDIIsPrinterReady);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintImagePos", (FARPROC *)&ZBRGDIPrintImagePos);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIPrintImageRect", (FARPROC *)&ZBRGDIPrintImageRect);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDICancelJob", (FARPROC *)&ZBRGDICancelJob);
	if (ret != 0)
		return ret;

	//Draw functions
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawText", (FARPROC *)&ZBRGDIDrawText);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawTextEx", (FARPROC *)&ZBRGDIDrawTextEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawTextUnicode", (FARPROC *)&ZBRGDIDrawTextUnicode);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawTextUnicodeEx", (FARPROC *)&ZBRGDIDrawTextUnicodeEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawTextRect", (FARPROC *)&ZBRGDIDrawTextRect);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawTextRectEx", (FARPROC *)&ZBRGDIDrawTextRectEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawLine", (FARPROC *)&ZBRGDIDrawLine);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImage", (FARPROC *)&ZBRGDIDrawImage);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImageEx", (FARPROC *)&ZBRGDIDrawImageEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImagePos", (FARPROC *)&ZBRGDIDrawImagePos);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImagePosEx", (FARPROC *)&ZBRGDIDrawImagePosEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImageRect", (FARPROC *)&ZBRGDIDrawImageRect);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawImageRectEx", (FARPROC *)&ZBRGDIDrawImageRectEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawRectangle", (FARPROC *)&ZBRGDIDrawRectangle);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawEllipse", (FARPROC *)&ZBRGDIDrawEllipse);
	if (ret != 0)
		return ret;
	
	ret = ZbrGraphics_LoadFunctionDLL(&hModuleZbrGraphics, "ZBRGDIDrawBarCode", (FARPROC *)&ZBRGDIDrawBarCode);
	if (ret != 0)
		return ret;

	return 0;
}

void ZbrGraphics_UnloadDLL()	
{
	if(hModuleZbrGraphics != NULL)
	{
		FreeLibrary(hModuleZbrGraphics);
		hModuleZbrGraphics = NULL;

		//SDK specific functions
		ZBRGDIGetSDKVer = NULL;
		ZBRGDIGetSDKVsn = NULL;
		ZBRGDIGetSDKProductVer = NULL;

		//Initialization functions
		ZBRGDIInitGraphics = NULL;
		ZBRGDIInitGraphicsEx = NULL;
		ZBRGDIInitGraphicsFromPrintDlg = NULL;
		ZBRGDICloseGraphics = NULL;
		ZBRGDIClearGraphics = NULL;
		ZBRGDIStartPage = NULL;
		ZBRGDIEndPage = NULL;

		//Print functions
		ZBRGDIPreviewGraphics = NULL;
		ZBRGDIPrintGraphics = NULL;
		ZBRGDIPrintGraphicsEx = NULL;
		ZBRGDIPrintFilePos = NULL;
		ZBRGDIPrintFileRect = NULL;
		ZBRGDIIsPrinterReady = NULL;
		ZBRGDIPrintImagePos = NULL;
		ZBRGDIPrintImageRect = NULL;
		ZBRGDICancelJob = NULL;

		//Draw functions
		ZBRGDIDrawText = NULL;
		ZBRGDIDrawTextEx = NULL;
		ZBRGDIDrawTextUnicode = NULL;
		ZBRGDIDrawTextUnicodeEx = NULL;
		ZBRGDIDrawTextRect = NULL;
		ZBRGDIDrawTextRectEx = NULL;
		ZBRGDIDrawLine = NULL;
		ZBRGDIDrawImage = NULL;
		ZBRGDIDrawImageEx = NULL;
		ZBRGDIDrawImagePos = NULL;
		ZBRGDIDrawImagePosEx = NULL;
		ZBRGDIDrawImageRect = NULL;
		ZBRGDIDrawImageRectEx = NULL;
		ZBRGDIDrawRectangle = NULL;
		ZBRGDIDrawEllipse = NULL;
		ZBRGDIDrawBarCode = NULL;
	}
}
