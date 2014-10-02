
#include "ZBRPrinter.h"


HMODULE hModuleZbrPrinter = NULL;

//SDK specific functions
PTR_ZBRPRNGetSDKVer ZBRPRNGetSDKVer;
PTR_ZBRPRNGetSDKVsn ZBRPRNGetSDKVsn;
PTR_ZBRPRNGetSDKProductVer ZBRPRNGetSDKProductVer;

//Printer driver handle functions
PTR_ZBRGetHandle ZBRGetHandle;
PTR_ZBRCloseHandle ZBRCloseHandle;

//Printer driver functions
PTR_ZBRPRNGetMsgSuppressionState ZBRPRNGetMsgSuppressionState;
PTR_ZBRPRNSuppressStatusMsgs ZBRPRNSuppressStatusMsgs;
PTR_ZBRPRNSetOverlayMode ZBRPRNSetOverlayMode;

//Printer driver functions
PTR_ZBRPRNPrintPrnFile ZBRPRNPrintPrnFile;

//Status functions
PTR_ZBRPRNCheckForErrors ZBRPRNCheckForErrors;
PTR_ZBRPRNClrErrStatusLn ZBRPRNClrErrStatusLn;
PTR_ZBRPRNGetPrintCount ZBRPRNGetPrintCount;
PTR_ZBRPRNGetPrintStatus ZBRPRNGetPrintStatus;
PTR_ZBRPRNGetPanelsRemaining ZBRPRNGetPanelsRemaining;
PTR_ZBRPRNGetPanelsPrinted ZBRPRNGetPanelsPrinted;
PTR_ZBRPRNGetPrinterSerialNumber ZBRPRNGetPrinterSerialNumber;
PTR_ZBRPRNGetPrinterSerialNumb ZBRPRNGetPrinterSerialNumb;
PTR_ZBRPRNGetPrinterOptions ZBRPRNGetPrinterOptions;
PTR_ZBRPRNGetPrintHeadSerialNumber ZBRPRNGetPrintHeadSerialNumber;
PTR_ZBRPRNGetPrintHeadSerialNumb ZBRPRNGetPrintHeadSerialNumb;
PTR_ZBRPRNGetOpParam ZBRPRNGetOpParam;
PTR_ZBRPRNGetPrinterStatus ZBRPRNGetPrinterStatus;
PTR_ZBRPRNGetSensorStatus ZBRPRNGetSensorStatus;
PTR_ZBRPRNIsPrinterReady ZBRPRNIsPrinterReady;

//Cleaning functions
PTR_ZBRPRNChkDueForCleaning ZBRPRNChkDueForCleaning;
PTR_ZBRPRNStartCleaningSeq ZBRPRNStartCleaningSeq;
PTR_ZBRPRNStartCleaningCardSeq ZBRPRNStartCleaningCardSeq;
PTR_ZBRPRNGetCleaningParam ZBRPRNGetCleaningParam;
PTR_ZBRPRNSetCleaningParam ZBRPRNSetCleaningParam;

//Printer setup functions
PTR_ZBRPRNResetPrinter ZBRPRNResetPrinter;
PTR_ZBRPRNSelfAdj ZBRPRNSelfAdj;
PTR_ZBRPRNGetChecksum ZBRPRNGetChecksum;
PTR_ZBRPRNSetCardFeedingMode ZBRPRNSetCardFeedingMode;
PTR_ZBRPRNSetPrintHeadResistance ZBRPRNSetPrintHeadResistance;
PTR_ZBRPRNClrMediaPath ZBRPRNClrMediaPath;
PTR_ZBRPRNImmediateParamSave ZBRPRNImmediateParamSave;
PTR_ZBRPRNSetRelativeXOffset ZBRPRNSetRelativeXOffset;
PTR_ZBRPRNSetRelativeYOffset ZBRPRNSetRelativeYOffset;
PTR_ZBRPRNSetStartPrintXOffset ZBRPRNSetStartPrintXOffset;
PTR_ZBRPRNSetStartPrintYOffset ZBRPRNSetStartPrintYOffset;
PTR_ZBRPRNGetIPAddress ZBRPRNGetIPAddress;

//Image buffer functions
PTR_ZBRPRNSetColorContrast ZBRPRNSetColorContrast;
PTR_ZBRPRNSetContrastIntensityLvl ZBRPRNSetContrastIntensityLvl;
PTR_ZBRPRNSetHologramIntensity ZBRPRNSetHologramIntensity;
PTR_ZBRPRNSetMonoContrast ZBRPRNSetMonoContrast;
PTR_ZBRPRNSetMonoIntensity ZBRPRNSetMonoIntensity;
PTR_ZBRPRNClrSpecifiedBmp ZBRPRNClrSpecifiedBmp;
PTR_ZBRPRNClrMonoImgBuf ZBRPRNClrMonoImgBuf;
PTR_ZBRPRNClrMonoImgBufs ZBRPRNClrMonoImgBufs;
PTR_ZBRPRNClrColorImgBufs ZBRPRNClrColorImgBufs;
PTR_ZBRPRNClrColorImgBuf ZBRPRNClrColorImgBuf;
PTR_ZBRPRNPrintMonoImgBuf ZBRPRNPrintMonoImgBuf;
PTR_ZBRPRNPrintMonoImgBufEx ZBRPRNPrintMonoImgBufEx;
PTR_ZBRPRNPrintColorImgBuf ZBRPRNPrintColorImgBuf;
PTR_ZBRPRNPrintClearVarnish ZBRPRNPrintClearVarnish;
PTR_ZBRPRNPrintVarnish ZBRPRNPrintVarnish;
PTR_ZBRPRNPrintVarnishEx ZBRPRNPrintVarnishEx;
PTR_ZBRPRNPrintHologramOverlay ZBRPRNPrintHologramOverlay;
PTR_ZBRPRNPrintCardPanel ZBRPRNPrintCardPanel;
PTR_ZBRPRNPrintMonoPanel ZBRPRNPrintMonoPanel;
PTR_ZBRPRNWriteBox ZBRPRNWriteBox;
PTR_ZBRPRNWriteBoxEx ZBRPRNWriteBoxEx;
PTR_ZBRPRNWriteText ZBRPRNWriteText;
PTR_ZBRPRNWriteTextEx ZBRPRNWriteTextEx;
PTR_ZBRPRNSetEndOfPrint ZBRPRNSetEndOfPrint;

//Position card functions
PTR_ZBRPRNMovePrintReady ZBRPRNMovePrintReady;
PTR_ZBRPRNReversePrintReady ZBRPRNReversePrintReady;
PTR_ZBRPRNEjectCard ZBRPRNEjectCard;
PTR_ZBRPRNFlipCard ZBRPRNFlipCard;
PTR_ZBRPRNMoveCard ZBRPRNMoveCard;
PTR_ZBRPRNMoveCardBkwd ZBRPRNMoveCardBkwd;
PTR_ZBRPRNMoveCardFwd ZBRPRNMoveCardFwd;
PTR_ZBRPRNResync ZBRPRNResync;
PTR_ZBRPRNStartSmartCard ZBRPRNStartSmartCard;
PTR_ZBRPRNEndSmartCard ZBRPRNEndSmartCard;

//Test card functions
PTR_ZBRPRNPrintTestCard ZBRPRNPrintTestCard;

//Barcode functions
PTR_ZBRPRNWriteBarCode ZBRPRNWriteBarCode;

//Update functions
PTR_ZBRPRNUpgradeFirmware ZBRPRNUpgradeFirmware;

// Magnetic encoder functions
PTR_ZBRPRNSetEncodingDir ZBRPRNSetEncodingDir;
PTR_ZBRPRNSetTrkDensity ZBRPRNSetTrkDensity;
PTR_ZBRPRNResetMagEncoder ZBRPRNResetMagEncoder;
PTR_ZBRPRNSetEncoderCoercivity ZBRPRNSetEncoderCoercivity;
PTR_ZBRPRNSetMagEncodingStd ZBRPRNSetMagEncodingStd;
PTR_ZBRPRNEnableMagReadDataEncryption ZBRPRNEnableMagReadDataEncryption;
PTR_ZBRPRNReadMag ZBRPRNReadMag;
PTR_ZBRPRNReadMagByTrk ZBRPRNReadMagByTrk;
PTR_ZBRPRNWriteMag ZBRPRNWriteMag;
PTR_ZBRPRNWriteMagByTrk ZBRPRNWriteMagByTrk;
PTR_ZBRPRNWriteMagPassThru ZBRPRNWriteMagPassThru;

//Old functions not in SDK document (to send command see "Programmer's Guide 980415-001")
PTR_ZBRPRNSendCmd ZBRPRNSendCmd;
PTR_ZBRPRNSendCommand ZBRPRNSendCommand;
PTR_ZBRPRNSendCmdEx ZBRPRNSendCmdEx;
PTR_ZBRPRNMultipleCmd ZBRPRNMultipleCmd;

int ZbrPrinter_LoadFunctionDLL(_In_ HMODULE *hModuleDLL, _In_ LPSTR functionName, _In_ FARPROC *funtionPtr)
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


int ZbrPrinter_LoadDLL(_In_ LPSTR filename)
{
	int ret;
	TCHAR filenameFinal[5096];

	if(filename == NULL)
	{
		wsprintf(filenameFinal, L"%hs", ZBR_PRINTER_DEFAULT_NAME);
	}
	else
	{
		wsprintf(filenameFinal, L"%hs", filename);
	}

	hModuleZbrPrinter = LoadLibrary(filenameFinal);
	if(hModuleZbrPrinter == NULL)
	{
		return 10;
	}

	//SDK specific functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetSDKVer", (FARPROC *)&ZBRPRNGetSDKVer);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetSDKVsn", (FARPROC *)&ZBRPRNGetSDKVsn);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetSDKProductVer", (FARPROC *)&ZBRPRNGetSDKProductVer);
	if (ret != 0)
		return ret;

	//Printer driver handle functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRGetHandle", (FARPROC *)&ZBRGetHandle);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRCloseHandle", (FARPROC *)&ZBRCloseHandle);
	if (ret != 0)
		return ret;

	//Printer driver functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetMsgSuppressionState", (FARPROC *)&ZBRPRNGetMsgSuppressionState);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSuppressStatusMsgs", (FARPROC *)&ZBRPRNSuppressStatusMsgs);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetOverlayMode", (FARPROC *)&ZBRPRNSetOverlayMode);
	if (ret != 0)
		return ret;

	//Printer driver functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintPrnFile", (FARPROC *)&ZBRPRNPrintPrnFile);
	if (ret != 0)
		return ret;

	//Status functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNCheckForErrors", (FARPROC *)&ZBRPRNCheckForErrors);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrErrStatusLn", (FARPROC *)&ZBRPRNClrErrStatusLn);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrintCount", (FARPROC *)&ZBRPRNGetPrintCount);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrintStatus", (FARPROC *)&ZBRPRNGetPrintStatus);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPanelsRemaining", (FARPROC *)&ZBRPRNGetPanelsRemaining);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPanelsPrinted", (FARPROC *)&ZBRPRNGetPanelsPrinted);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrinterSerialNumber", (FARPROC *)&ZBRPRNGetPrinterSerialNumber);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrinterSerialNumb", (FARPROC *)&ZBRPRNGetPrinterSerialNumb);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrinterOptions", (FARPROC *)&ZBRPRNGetPrinterOptions);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrintHeadSerialNumber", (FARPROC *)&ZBRPRNGetPrintHeadSerialNumber);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrintHeadSerialNumb", (FARPROC *)&ZBRPRNGetPrintHeadSerialNumb);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetOpParam", (FARPROC *)&ZBRPRNGetOpParam);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetPrinterStatus", (FARPROC *)&ZBRPRNGetPrinterStatus);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetSensorStatus", (FARPROC *)&ZBRPRNGetSensorStatus);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNIsPrinterReady", (FARPROC *)&ZBRPRNIsPrinterReady);
	if (ret != 0)
		return ret;

	//Cleaning functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNChkDueForCleaning", (FARPROC *)&ZBRPRNChkDueForCleaning);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNStartCleaningSeq", (FARPROC *)&ZBRPRNStartCleaningSeq);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNStartCleaningCardSeq", (FARPROC *)&ZBRPRNStartCleaningCardSeq);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetCleaningParam", (FARPROC *)&ZBRPRNGetCleaningParam);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetCleaningParam", (FARPROC *)&ZBRPRNSetCleaningParam);
	if (ret != 0)
		return ret;

	//Printer setup functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNResetPrinter", (FARPROC *)&ZBRPRNResetPrinter);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSelfAdj", (FARPROC *)&ZBRPRNSelfAdj);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetChecksum", (FARPROC *)&ZBRPRNGetChecksum);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetCardFeedingMode", (FARPROC *)&ZBRPRNSetCardFeedingMode);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetPrintHeadResistance", (FARPROC *)&ZBRPRNSetPrintHeadResistance);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrMediaPath", (FARPROC *)&ZBRPRNClrMediaPath);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNImmediateParamSave", (FARPROC *)&ZBRPRNImmediateParamSave);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetRelativeXOffset", (FARPROC *)&ZBRPRNSetRelativeXOffset);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetRelativeYOffset", (FARPROC *)&ZBRPRNSetRelativeYOffset);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetStartPrintXOffset", (FARPROC *)&ZBRPRNSetStartPrintXOffset);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetStartPrintYOffset", (FARPROC *)&ZBRPRNSetStartPrintYOffset);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNGetIPAddress", (FARPROC *)&ZBRPRNGetIPAddress);
	if (ret != 0)
		return ret;

	//Image buffer functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetColorContrast", (FARPROC *)&ZBRPRNSetColorContrast);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetContrastIntensityLvl", (FARPROC *)&ZBRPRNSetContrastIntensityLvl);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetHologramIntensity", (FARPROC *)&ZBRPRNSetHologramIntensity);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetMonoContrast", (FARPROC *)&ZBRPRNSetMonoContrast);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetMonoIntensity", (FARPROC *)&ZBRPRNSetMonoIntensity);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrSpecifiedBmp", (FARPROC *)&ZBRPRNClrSpecifiedBmp);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrMonoImgBuf", (FARPROC *)&ZBRPRNClrMonoImgBuf);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrMonoImgBufs", (FARPROC *)&ZBRPRNClrMonoImgBufs);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrColorImgBufs", (FARPROC *)&ZBRPRNClrColorImgBufs);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNClrColorImgBuf", (FARPROC *)&ZBRPRNClrColorImgBuf);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintMonoImgBuf", (FARPROC *)&ZBRPRNPrintMonoImgBuf);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintMonoImgBufEx", (FARPROC *)&ZBRPRNPrintMonoImgBufEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintColorImgBuf", (FARPROC *)&ZBRPRNPrintColorImgBuf);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintClearVarnish", (FARPROC *)&ZBRPRNPrintClearVarnish);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintVarnish", (FARPROC *)&ZBRPRNPrintVarnish);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintVarnishEx", (FARPROC *)&ZBRPRNPrintVarnishEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintHologramOverlay", (FARPROC *)&ZBRPRNPrintHologramOverlay);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintCardPanel", (FARPROC *)&ZBRPRNPrintCardPanel);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintMonoPanel", (FARPROC *)&ZBRPRNPrintMonoPanel);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteBox", (FARPROC *)&ZBRPRNWriteBox);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteBoxEx", (FARPROC *)&ZBRPRNWriteBoxEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteText", (FARPROC *)&ZBRPRNWriteText);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteTextEx", (FARPROC *)&ZBRPRNWriteTextEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetEndOfPrint", (FARPROC *)&ZBRPRNSetEndOfPrint);
	if (ret != 0)
		return ret;

	//Position card functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNMovePrintReady", (FARPROC *)&ZBRPRNMovePrintReady);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNReversePrintReady", (FARPROC *)&ZBRPRNReversePrintReady);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNEjectCard", (FARPROC *)&ZBRPRNEjectCard);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNFlipCard", (FARPROC *)&ZBRPRNFlipCard);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNMoveCard", (FARPROC *)&ZBRPRNMoveCard);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNMoveCardBkwd", (FARPROC *)&ZBRPRNMoveCardBkwd);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNMoveCardFwd", (FARPROC *)&ZBRPRNMoveCardFwd);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNResync", (FARPROC *)&ZBRPRNResync);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNStartSmartCard", (FARPROC *)&ZBRPRNStartSmartCard);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNEndSmartCard", (FARPROC *)&ZBRPRNEndSmartCard);
	if (ret != 0)
		return ret;

	//Test card functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNPrintTestCard", (FARPROC *)&ZBRPRNPrintTestCard);
	if (ret != 0)
		return ret;

	//Barcode functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteBarCode", (FARPROC *)&ZBRPRNWriteBarCode);
	if (ret != 0)
		return ret;

	//Update functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNUpgradeFirmware", (FARPROC *)&ZBRPRNUpgradeFirmware);
	if (ret != 0)
		return ret;

	// Magnetic encoder functions
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetEncodingDir", (FARPROC *)&ZBRPRNSetEncodingDir);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetTrkDensity", (FARPROC *)&ZBRPRNSetTrkDensity);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNResetMagEncoder", (FARPROC *)&ZBRPRNResetMagEncoder);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetEncoderCoercivity", (FARPROC *)&ZBRPRNSetEncoderCoercivity);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSetMagEncodingStd", (FARPROC *)&ZBRPRNSetMagEncodingStd);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNEnableMagReadDataEncryption", (FARPROC *)&ZBRPRNEnableMagReadDataEncryption);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNReadMag", (FARPROC *)&ZBRPRNReadMag);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNReadMagByTrk", (FARPROC *)&ZBRPRNReadMagByTrk);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteMag", (FARPROC *)&ZBRPRNWriteMag);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteMagByTrk", (FARPROC *)&ZBRPRNWriteMagByTrk);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNWriteMagPassThru", (FARPROC *)&ZBRPRNWriteMagPassThru);
	if (ret != 0)
		return ret;

	//Old functions not in SDK document (to send command see "Programmer's Guide 980415-001")
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSendCmd", (FARPROC *)&ZBRPRNSendCmd);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSendCommand", (FARPROC *)&ZBRPRNSendCommand);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNSendCmdEx", (FARPROC *)&ZBRPRNSendCmdEx);
	if (ret != 0)
		return ret;
	
	ret = ZbrPrinter_LoadFunctionDLL(&hModuleZbrPrinter, "ZBRPRNMultipleCmd", (FARPROC *)&ZBRPRNMultipleCmd);
	if (ret != 0)
		return ret;

	return 0;
}

void ZbrPrinter_UnloadDLL()	
{
	if(hModuleZbrPrinter != NULL)
	{
		FreeLibrary(hModuleZbrPrinter);
		hModuleZbrPrinter = NULL;

		//SDK specific functions
		ZBRPRNGetSDKVer = NULL;
		ZBRPRNGetSDKVsn = NULL;
		ZBRPRNGetSDKProductVer = NULL;

		//Printer driver handle functions
		ZBRGetHandle = NULL;
		ZBRCloseHandle = NULL;

		//Printer driver functions
		ZBRPRNGetMsgSuppressionState = NULL;
		ZBRPRNSuppressStatusMsgs = NULL;
		ZBRPRNSetOverlayMode = NULL;

		//Printer driver functions
		ZBRPRNPrintPrnFile = NULL;

		//Status functions
		ZBRPRNCheckForErrors = NULL;
		ZBRPRNClrErrStatusLn = NULL;
		ZBRPRNGetPrintCount = NULL;
		ZBRPRNGetPrintStatus = NULL;
		ZBRPRNGetPanelsRemaining = NULL;
		ZBRPRNGetPanelsPrinted = NULL;
		ZBRPRNGetPrinterSerialNumber = NULL;
		ZBRPRNGetPrinterSerialNumb = NULL;
		ZBRPRNGetPrinterOptions = NULL;
		ZBRPRNGetPrintHeadSerialNumber = NULL;
		ZBRPRNGetPrintHeadSerialNumb = NULL;
		ZBRPRNGetOpParam = NULL;
		ZBRPRNGetPrinterStatus = NULL;
		ZBRPRNGetSensorStatus = NULL;
		ZBRPRNIsPrinterReady = NULL;

		//Cleaning functions
		ZBRPRNChkDueForCleaning = NULL;
		ZBRPRNStartCleaningSeq = NULL;
		ZBRPRNStartCleaningCardSeq = NULL;
		ZBRPRNGetCleaningParam = NULL;
		ZBRPRNSetCleaningParam = NULL;

		//Printer setup functions
		ZBRPRNResetPrinter = NULL;
		ZBRPRNSelfAdj = NULL;
		ZBRPRNGetChecksum = NULL;
		ZBRPRNSetCardFeedingMode = NULL;
		ZBRPRNSetPrintHeadResistance = NULL;
		ZBRPRNClrMediaPath = NULL;
		ZBRPRNImmediateParamSave = NULL;
		ZBRPRNSetRelativeXOffset = NULL;
		ZBRPRNSetRelativeYOffset = NULL;
		ZBRPRNSetStartPrintXOffset = NULL;
		ZBRPRNSetStartPrintYOffset = NULL;
		ZBRPRNGetIPAddress = NULL;

		//Image buffer functions
		ZBRPRNSetColorContrast = NULL;
		ZBRPRNSetContrastIntensityLvl = NULL;
		ZBRPRNSetHologramIntensity = NULL;
		ZBRPRNSetMonoContrast = NULL;
		ZBRPRNSetMonoIntensity = NULL;
		ZBRPRNClrSpecifiedBmp = NULL;
		ZBRPRNClrMonoImgBuf = NULL;
		ZBRPRNClrMonoImgBufs = NULL;
		ZBRPRNClrColorImgBufs = NULL;
		ZBRPRNClrColorImgBuf = NULL;
		ZBRPRNPrintMonoImgBuf = NULL;
		ZBRPRNPrintMonoImgBufEx = NULL;
		ZBRPRNPrintColorImgBuf = NULL;
		ZBRPRNPrintClearVarnish = NULL;
		ZBRPRNPrintVarnish = NULL;
		ZBRPRNPrintVarnishEx = NULL;
		ZBRPRNPrintHologramOverlay = NULL;
		ZBRPRNPrintCardPanel = NULL;
		ZBRPRNPrintMonoPanel = NULL;
		ZBRPRNWriteBox = NULL;
		ZBRPRNWriteBoxEx = NULL;
		ZBRPRNWriteText = NULL;
		ZBRPRNWriteTextEx = NULL;
		ZBRPRNSetEndOfPrint = NULL;

		//Position card functions
		ZBRPRNMovePrintReady = NULL;
		ZBRPRNReversePrintReady = NULL;
		ZBRPRNEjectCard = NULL;
		ZBRPRNFlipCard = NULL;
		ZBRPRNMoveCard = NULL;
		ZBRPRNMoveCardBkwd = NULL;
		ZBRPRNMoveCardFwd = NULL;
		ZBRPRNResync = NULL;
		ZBRPRNStartSmartCard = NULL;
		ZBRPRNEndSmartCard = NULL;

		//Test card functions
		ZBRPRNPrintTestCard = NULL;

		//Barcode functions
		ZBRPRNWriteBarCode = NULL;

		//Update functions
		ZBRPRNUpgradeFirmware = NULL;

		// Magnetic encoder functions
		ZBRPRNSetEncodingDir = NULL;
		ZBRPRNSetTrkDensity = NULL;
		ZBRPRNResetMagEncoder = NULL;
		ZBRPRNSetEncoderCoercivity = NULL;
		ZBRPRNSetMagEncodingStd = NULL;
		ZBRPRNEnableMagReadDataEncryption = NULL;
		ZBRPRNReadMag = NULL;
		ZBRPRNReadMagByTrk = NULL;
		ZBRPRNWriteMag = NULL;
		ZBRPRNWriteMagByTrk = NULL;
		ZBRPRNWriteMagPassThru = NULL;

		//Old functions not in SDK document (to send command see "Programmer's Guide 980415-001")
		ZBRPRNSendCmd = NULL;
		ZBRPRNSendCommand = NULL;
		ZBRPRNSendCmdEx = NULL;
		ZBRPRNMultipleCmd = NULL;
	}
}

