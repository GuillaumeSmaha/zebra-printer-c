
#ifndef _ZBR_PRINTER_HEADER_
#define _ZBR_PRINTER_HEADER_

#include <Windows.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif


#define ZBR_PRINTER_DEFAULT_NAME "ZBRPrinter.dll"


// For printer types
enum ZbrPrinterType {
	zbrPrinterType_100 = 100,
	zbrPrinterType_110 = 110,
	zbrPrinterType_120 = 120,
	zbrPrinterType_330 = 330,
	zbrPrinterType_360 = 360,
	zbrPrinterType_420 = 420,
	zbrPrinterType_430 = 430,
	zbrPrinterType_640 = 640
};

// For card type
enum ZbrCardType {
	zbrCardType_Contact = 1,
	zbrCardType_ContacLess = 2,
	zbrCardType_UHF = 3
};

// For overlay type
enum ZbrOverlayType {
	zbrOverlayType_Front = 0,
	zbrOverlayType_Back = 1
};

// For magnetic encoding
enum ZbrMagneticEncodingTricks {
	zbrMagneticEncoding_Trick1 = 1,
	zbrMagneticEncoding_Trick2 = 2,
	zbrMagneticEncoding_Trick3 = 3
};

#ifndef _ZBR_GRAPHICS_HEADER_
// For code bar
enum ZbrCodebarRotation {
	zbrCodebarRotation_OriginLeft_NoRotation = 0,
	zbrCodebarRotation_OriginLeft_Rotation90 = 1,
	zbrCodebarRotation_OriginLeft_Rotation180 = 2,
	zbrCodebarRotation_OriginLeft_Rotation270 = 3,
	zbrCodebarRotation_OriginCenter_NoRotation = 4,
	zbrCodebarRotation_OriginCenter_Rotation90 = 5,
	zbrCodebarRotation_OriginCenter_Rotation180 = 6,
	zbrCodebarRotation_OriginCenter_Rotation270 = 7
};

enum ZbrCodebarType {
	zbrCodebarType_Code39 = 0,
	zbrCodebarType_2_5Interleave = 1, //no count
	zbrCodebarType_2_5Industrial = 2, //no check digits
	zbrCodebarType_EAN8 = 3,
	zbrCodebarType_EAN13 = 4,
	zbrCodebarType_UPC = 5,
	zbrCodebarType_Code128C = 7,
	zbrCodebarType_Code128B = 8,
	zbrCodebarType_Code128C_CheckDigits = 107,
	zbrCodebarType_Code128B_CheckDigits = 108
};

enum ZbrCodebarWidthRatio{
	zbrCodebarWidthRatio_NarrowBar0 = 0, //0 = narrow bar = 1 dot, wide bar = 2 dots
	zbrCodebarWidthRatio_NarrowBar1 = 1, //1 = narrow bar = 1 dot, wide bar = 3 dots
	zbrCodebarWidthRatio_NarrowBar2 = 2 //2 = narrow bar = 2 dots, wide bar = 5 dots
};

enum ZbrCodebarTextUnder {
	zbrCodebarTextUnder_True = 1,
	zbrCodebarTextUnder_Yes = 1,
	zbrCodebarTextUnder_False = 0,
	zbrCodebarTextUnder_No = 0
};
#endif

// Errors returned by the driver
#define ZBR_ERROR_PRINTER_MECHANICAL_ERROR              -1
#define ZBR_ERROR_BROKEN_RIBBON                          1
#define ZBR_ERROR_TEMPERATURE                            2
#define ZBR_ERROR_MECHANICAL_ERROR                       3
#define ZBR_ERROR_OUT_OF_CARD                            4
#define ZBR_ERROR_CARD_IN_ENCODER                        5
#define ZBR_ERROR_CARD_NOT_IN_ENCODER                    6
#define ZBR_ERROR_PRINT_HEAD_OPEN                        7
#define ZBR_ERROR_OUT_OF_RIBBON                          8
#define ZBR_ERROR_REMOVE_RIBBON                          9
#define ZBR_ERROR_PARAMETERS_ERROR                      10
#define ZBR_ERROR_INVALID_COORDINATES                   11
#define ZBR_ERROR_UNKNOWN_BARCODE                       12
#define ZBR_ERROR_UNKNOWN_TEXT                          13
#define ZBR_ERROR_COMMAND_ERROR                         14
#define ZBR_ERROR_BARCODE_DATA_SYNTAX                   20
#define ZBR_ERROR_TEXT_DATA_SYNTAX                      21
#define ZBR_ERROR_GRAPHIC_DATA_SYNTAX                   22
#define ZBR_ERROR_GRAPHIC_IMAGE_INITIALIZATION          30
#define ZBR_ERROR_GRAPHIC_IMAGE_MAXIMUM_WIDTH_EXCEEDED  31
#define ZBR_ERROR_GRAPHIC_IMAGE_MAXIMUM_HEIGHT_EXCEEDED 32
#define ZBR_ERROR_GRAPHIC_IMAGE_DATA_CHECKSUM_ERROR     33
#define ZBR_ERROR_DATA_TRANSFER_TIME_OUT                34
#define ZBR_ERROR_CHECK_RIBBON                          35
#define ZBR_ERROR_INVALID_MAGNETIC_DATA                 40
#define ZBR_ERROR_MAG_ENCODER_WRITE                     41
#define ZBR_ERROR_READING_ERROR                         42
#define ZBR_ERROR_MAG_ENCODER_MECHANICAL                43
#define ZBR_ERROR_MAG_ENCODER_NOT_RESPONDING            44
#define ZBR_ERROR_MAG_ENCODER_MISSING_OR_CARD_JAM       45
#define ZBR_ERROR_ROTATION_ERROR                        47
#define ZBR_ERROR_COVER_OPEN							48
#define ZBR_ERROR_ENCODING_ERROR                        49
#define ZBR_ERROR_MAGNETIC_ERROR                        50
#define ZBR_ERROR_BLANK_TRACK                           51
#define ZBR_ERROR_FLASH_ERROR                           52
#define ZBR_ERROR_NO_ACCESS                             53
#define ZBR_ERROR_SEQUENCE_ERROR                        54
#define ZBR_ERROR_PROX_ERROR							55
#define ZBR_ERROR_CONTACT_DATA_ERROR					56
#define ZBR_ERROR_PROX_DATA_ERROR						57

// Errors returned by the SDK
#define ZBR_SDK_ERROR_PRINTER_NOT_SUPPORTED				60
#define ZBR_SDK_ERROR_CANNOT_GET_PRINTER_HANDLE			61
#define ZBR_SDK_ERROR_CANNOT_GET_PRINTER_DRIVER			62
#define ZBR_SDK_ERROR_INVALID_PARAMETER  				63
#define ZBR_SDK_ERROR_PRINTER_BUSY				       	64
#define ZBR_SDK_ERROR_INVALID_PRINTER_HANDLE			65
#define ZBR_SDK_ERROR_CLOSE_HANDLE_ERROR				66
#define ZBR_SDK_ERROR_COMMUNICATION_ERROR				67
#define ZBR_SDK_ERROR_BUFFER_OVERFLOW			    	68
#define ZBR_SDK_ERROR_READ_DATA_ERROR				    69
#define ZBR_SDK_ERROR_WRITE_DATA_ERROR				    70
#define ZBR_SDK_ERROR_LOAD_LIBRARY_ERROR				71
#define ZBR_SDK_ERROR_INVALID_STRUCT_ALIGNMENT			72
#define ZBR_SDK_ERROR_GETTING_DEVICE_CONTEXT			73
#define ZBR_SDK_ERROR_SPOOLER_ERROR				        74
#define ZBR_SDK_ERROR_OUT_OF_MEMORY			        	75
#define ZBR_SDK_ERROR_OUT_OF_DISK_SPACE		    		76
#define ZBR_SDK_ERROR_USER_ABORT			        	77
#define ZBR_SDK_ERROR_APPLICATION_ABORT		    		78
#define ZBR_SDK_ERROR_CREATE_FILE_ERROR		    		79
#define ZBR_SDK_ERROR_WRITE_FILE_ERROR		    		80
#define ZBR_SDK_ERROR_READ_FILE_ERROR		    		81
#define ZBR_SDK_ERROR_INVALID_MEDIA			        	82
#define ZBR_SDK_ERROR_MEMORY_ALLOCATION			        83
#define ZBR_SDK_ERROR_UNKNOWN_ERROR		                255



//SDK specific functions
typedef void (CALLBACK *PTR_ZBRPRNGetSDKVer)(_Out_ LPINT major, _Out_ LPINT minor, _Out_ LPINT engLevel);
typedef void (CALLBACK *PTR_ZBRPRNGetSDKVsn)(_Out_ LPINT major, _Out_ LPINT minor, _Out_ LPINT engLevel);
typedef INT (CALLBACK *PTR_ZBRPRNGetSDKProductVer)(_Out_ LPSTR productVersion, _Out_ LPINT buffSize);

//Printer driver handle functions
typedef INT (CALLBACK *PTR_ZBRGetHandle)(_Out_ LPHANDLE hPrinter, LPSTR pName, _Out_ INT* printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRCloseHandle)(HANDLE hPrinter, _Out_ LPINT err);

//Printer driver functions
typedef INT (CALLBACK *PTR_ZBRPRNGetMsgSuppressionState)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT state, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSuppressStatusMsgs)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT suppressMsgs, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetOverlayMode)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ ZbrOverlayType overlay, _Out_ LPSTR filename, _Out_ LPINT err);

//Printer driver functions
typedef INT (CALLBACK *PTR_ZBRPRNPrintPrnFile)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ LPSTR filename, _Out_ LPINT err);

//Status functions
typedef INT (CALLBACK *PTR_ZBRPRNCheckForErrors)(_In_ HANDLE hPrinter, _In_ INT printerType);
typedef INT (CALLBACK *PTR_ZBRPRNClrErrStatusLn)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrintCount)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT printCount, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrintStatus)(_In_ HANDLE hPrinter, _In_ INT printerType);
typedef INT (CALLBACK *PTR_ZBRPRNGetPanelsRemaining)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT panels, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPanelsPrinted)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT panels, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrinterSerialNumber)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPSTR serialNum, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrinterSerialNumb)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPSTR serialNum, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrinterOptions)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPSTR options, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrintHeadSerialNumber)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPSTR serialNum, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrintHeadSerialNumb)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPSTR serialNum, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetOpParam)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT paramIDx, _Out_ LPSTR opParam, _Out_ LPINT respSize, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetPrinterStatus)(_Out_ LPINT statusCode);
typedef INT (CALLBACK *PTR_ZBRPRNGetSensorStatus)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPBYTE status, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNIsPrinterReady)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);

//Cleaning functions
typedef INT (CALLBACK *PTR_ZBRPRNChkDueForCleaning)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT imgCounter, _Out_ LPINT cleanCounter, _Out_ LPINT cleanCardCounter, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNStartCleaningSeq)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNStartCleaningCardSeq)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetCleaningParam)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT imgCounter, _Out_ LPINT cleanCounter, _Out_ LPINT cleanCardCounter, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetCleaningParam)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT ribbonPanelCounter, _In_ INT cleanCardPass, _Out_ LPINT err);

//Printer setup functions
typedef INT (CALLBACK *PTR_ZBRPRNResetPrinter)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSelfAdj)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetChecksum)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT checksum, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetCardFeedingMode)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT mode, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetPrintHeadResistance)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT resistance, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrMediaPath)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNImmediateParamSave)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetRelativeXOffset)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT offset, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetRelativeYOffset)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT offset, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetStartPrintXOffset)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT offset, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetStartPrintYOffset)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT offset, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNGetIPAddress)(_In_ LPSTR printerName, _Out_ LPSTR ipAddress);

//Image buffer functions
typedef INT (CALLBACK *PTR_ZBRPRNSetColorContrast)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT imgBufIdx, _In_ INT contrast, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetContrastIntensityLvl)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT imgBufIdx, _In_ INT intensity, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetHologramIntensity)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT intensity, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetMonoContrast)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT contrast, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetMonoIntensity)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT intensity, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrSpecifiedBmp)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT colorBufIdx, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrMonoImgBuf)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT clrVarnish, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrMonoImgBufs)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT clrBuffer, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrColorImgBufs)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNClrColorImgBuf)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT imgBufIdx, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintMonoImgBuf)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintMonoImgBufEx)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT printParameter, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintColorImgBuf)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT imgBufIdx, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintClearVarnish)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintVarnish)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintVarnishEx)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT printParameter, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintHologramOverlay)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT printParam, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintCardPanel)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT imgBufIdx, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNPrintMonoPanel)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteBox)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT startX, _In_ INT startY, _In_ INT width,
									_In_ INT height, _In_ INT thickness, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteBoxEx)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT startX, _In_ INT startY, _In_ INT width,
									_In_ INT height, _In_ INT thickness, _In_ INT gMode, _In_ INT isVarnish, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteText)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT startX, _In_ INT startY, _In_ INT rotation, _In_ INT isBold, _In_ INT height, _In_ LPSTR text, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteTextEx)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT startX, _In_ INT startY, _In_ INT rotation, _In_ INT isBold, _In_ INT width, _In_ INT height, _In_ INT gMode,
									_In_ LPSTR text, _In_ INT isVarnish, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetEndOfPrint)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT xWidth, _Out_ LPINT err);

//Position card functions
typedef INT (CALLBACK *PTR_ZBRPRNMovePrintReady)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNReversePrintReady)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNEjectCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNFlipCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNMoveCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT steps, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNMoveCardBkwd)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT steps, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNMoveCardFwd)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT steps, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNResync)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNStartSmartCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT cardType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNEndSmartCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT cardType, _In_ INT moveType, _Out_ LPINT err);

//Test card functions
typedef INT (CALLBACK *PTR_ZBRPRNPrintTestCard)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT cardType, _Out_ LPINT err);

//Barcode functions
typedef INT (CALLBACK *PTR_ZBRPRNWriteBarCode)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT startX, _In_ INT startY,
	_In_ ZbrCodebarRotation rotation, _In_ ZbrCodebarType barcodeType, _In_ ZbrCodebarWidthRatio barWidthRatio,
	_In_ INT barcodeMultiplier, _In_ INT barcodeHeight,
	_In_ ZbrCodebarTextUnder textUnder, _In_ LPSTR barcodeData, _Out_ LPINT err);

//Update functions
typedef INT (CALLBACK *PTR_ZBRPRNUpgradeFirmware)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ LPSTR filename, _Out_ LPINT err);

// Magnetic encoder functions
typedef INT (CALLBACK *PTR_ZBRPRNSetEncodingDir)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT dir, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetTrkDensity)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ ZbrMagneticEncodingTricks trkNumb, _In_ INT density, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNResetMagEncoder)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetEncoderCoercivity)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT coercivity, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSetMagEncodingStd)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT std, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNEnableMagReadDataEncryption)(_In_ HANDLE hPrinter, _In_ INT printerType, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNReadMag)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT trksToRead, LPSTR trk1Buf, _Out_ LPINT trk1BytesNeeded, LPSTR trk2Buf, _Out_ LPINT trk2BytesNeeded, LPSTR trk3Buf, _Out_ LPINT trk3BytesNeeded, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNReadMagByTrk)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT trkNumb, LPSTR trkBuf, _Out_ LPINT trkBytesNeeded, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteMag)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT trksToWrite, LPSTR trk1Data, LPSTR trk2Data, LPSTR trk3Data, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteMagByTrk)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT trkNumb, LPSTR trkData, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNWriteMagPassThru)(HDC hDC, _In_ INT printerType, _In_ INT trksToWrite, LPSTR trk1Data, LPSTR trk2Data, LPSTR trk3Data, _Out_ LPINT err);

//Old functions not in SDK document (to send command see "Programmer's Guide 980415-001")
typedef INT (CALLBACK *PTR_ZBRPRNSendCmd)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ LPSTR cmd, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSendCommand)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ LPSTR cmd, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNSendCmdEx)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ LPSTR cmd, LPSTR response, _Out_ LPINT respBytesNeeded, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRPRNMultipleCmd)(_In_ HANDLE hPrinter, _In_ INT printerType, _In_ INT numb, _In_ LPSTR cmd, _Out_ LPINT err);



//SDK specific functions
extern PTR_ZBRPRNGetSDKVer ZBRPRNGetSDKVer;
extern PTR_ZBRPRNGetSDKVsn ZBRPRNGetSDKVsn;
extern PTR_ZBRPRNGetSDKProductVer ZBRPRNGetSDKProductVer;

//Printer driver handle functions
extern PTR_ZBRGetHandle ZBRGetHandle;
extern PTR_ZBRCloseHandle ZBRCloseHandle;

//Printer driver functions
extern PTR_ZBRPRNGetMsgSuppressionState ZBRPRNGetMsgSuppressionState;
extern PTR_ZBRPRNSuppressStatusMsgs ZBRPRNSuppressStatusMsgs;
extern PTR_ZBRPRNSetOverlayMode ZBRPRNSetOverlayMode;

//Printer driver functions
extern PTR_ZBRPRNPrintPrnFile ZBRPRNPrintPrnFile;

//Status functions
extern PTR_ZBRPRNCheckForErrors ZBRPRNCheckForErrors;
extern PTR_ZBRPRNClrErrStatusLn ZBRPRNClrErrStatusLn;
extern PTR_ZBRPRNGetPrintCount ZBRPRNGetPrintCount;
extern PTR_ZBRPRNGetPrintStatus ZBRPRNGetPrintStatus;
extern PTR_ZBRPRNGetPanelsRemaining ZBRPRNGetPanelsRemaining;
extern PTR_ZBRPRNGetPanelsPrinted ZBRPRNGetPanelsPrinted;
extern PTR_ZBRPRNGetPrinterSerialNumber ZBRPRNGetPrinterSerialNumber;
extern PTR_ZBRPRNGetPrinterSerialNumb ZBRPRNGetPrinterSerialNumb;
extern PTR_ZBRPRNGetPrinterOptions ZBRPRNGetPrinterOptions;
extern PTR_ZBRPRNGetPrintHeadSerialNumber ZBRPRNGetPrintHeadSerialNumber;
extern PTR_ZBRPRNGetPrintHeadSerialNumb ZBRPRNGetPrintHeadSerialNumb;
extern PTR_ZBRPRNGetOpParam ZBRPRNGetOpParam;
extern PTR_ZBRPRNGetPrinterStatus ZBRPRNGetPrinterStatus;
extern PTR_ZBRPRNGetSensorStatus ZBRPRNGetSensorStatus;
extern PTR_ZBRPRNIsPrinterReady ZBRPRNIsPrinterReady;

//Cleaning functions
extern PTR_ZBRPRNChkDueForCleaning ZBRPRNChkDueForCleaning;
extern PTR_ZBRPRNStartCleaningSeq ZBRPRNStartCleaningSeq;
extern PTR_ZBRPRNStartCleaningCardSeq ZBRPRNStartCleaningCardSeq;
extern PTR_ZBRPRNGetCleaningParam ZBRPRNGetCleaningParam;
extern PTR_ZBRPRNSetCleaningParam ZBRPRNSetCleaningParam;

//Printer setup functions
extern PTR_ZBRPRNResetPrinter ZBRPRNResetPrinter;
extern PTR_ZBRPRNSelfAdj ZBRPRNSelfAdj;
extern PTR_ZBRPRNGetChecksum ZBRPRNGetChecksum;
extern PTR_ZBRPRNSetCardFeedingMode ZBRPRNSetCardFeedingMode;
extern PTR_ZBRPRNSetPrintHeadResistance ZBRPRNSetPrintHeadResistance;
extern PTR_ZBRPRNClrMediaPath ZBRPRNClrMediaPath;
extern PTR_ZBRPRNImmediateParamSave ZBRPRNImmediateParamSave;
extern PTR_ZBRPRNSetRelativeXOffset ZBRPRNSetRelativeXOffset;
extern PTR_ZBRPRNSetRelativeYOffset ZBRPRNSetRelativeYOffset;
extern PTR_ZBRPRNSetStartPrintXOffset ZBRPRNSetStartPrintXOffset;
extern PTR_ZBRPRNSetStartPrintYOffset ZBRPRNSetStartPrintYOffset;
extern PTR_ZBRPRNGetIPAddress ZBRPRNGetIPAddress;

//Image buffer functions
extern PTR_ZBRPRNSetColorContrast ZBRPRNSetColorContrast;
extern PTR_ZBRPRNSetContrastIntensityLvl ZBRPRNSetContrastIntensityLvl;
extern PTR_ZBRPRNSetHologramIntensity ZBRPRNSetHologramIntensity;
extern PTR_ZBRPRNSetMonoContrast ZBRPRNSetMonoContrast;
extern PTR_ZBRPRNSetMonoIntensity ZBRPRNSetMonoIntensity;
extern PTR_ZBRPRNClrSpecifiedBmp ZBRPRNClrSpecifiedBmp;
extern PTR_ZBRPRNClrMonoImgBuf ZBRPRNClrMonoImgBuf;
extern PTR_ZBRPRNClrMonoImgBufs ZBRPRNClrMonoImgBufs;
extern PTR_ZBRPRNClrColorImgBufs ZBRPRNClrColorImgBufs;
extern PTR_ZBRPRNClrColorImgBuf ZBRPRNClrColorImgBuf;
extern PTR_ZBRPRNPrintMonoImgBuf ZBRPRNPrintMonoImgBuf;
extern PTR_ZBRPRNPrintMonoImgBufEx ZBRPRNPrintMonoImgBufEx;
extern PTR_ZBRPRNPrintColorImgBuf ZBRPRNPrintColorImgBuf;
extern PTR_ZBRPRNPrintClearVarnish ZBRPRNPrintClearVarnish;
extern PTR_ZBRPRNPrintVarnish ZBRPRNPrintVarnish;
extern PTR_ZBRPRNPrintVarnishEx ZBRPRNPrintVarnishEx;
extern PTR_ZBRPRNPrintHologramOverlay ZBRPRNPrintHologramOverlay;
extern PTR_ZBRPRNPrintCardPanel ZBRPRNPrintCardPanel;
extern PTR_ZBRPRNPrintMonoPanel ZBRPRNPrintMonoPanel;
extern PTR_ZBRPRNWriteBox ZBRPRNWriteBox;
extern PTR_ZBRPRNWriteBoxEx ZBRPRNWriteBoxEx;
extern PTR_ZBRPRNWriteText ZBRPRNWriteText;
extern PTR_ZBRPRNWriteTextEx ZBRPRNWriteTextEx;
extern PTR_ZBRPRNSetEndOfPrint ZBRPRNSetEndOfPrint;

//Position card functions
extern PTR_ZBRPRNMovePrintReady ZBRPRNMovePrintReady;
extern PTR_ZBRPRNReversePrintReady ZBRPRNReversePrintReady;
extern PTR_ZBRPRNEjectCard ZBRPRNEjectCard;
extern PTR_ZBRPRNFlipCard ZBRPRNFlipCard;
extern PTR_ZBRPRNMoveCard ZBRPRNMoveCard;
extern PTR_ZBRPRNMoveCardBkwd ZBRPRNMoveCardBkwd;
extern PTR_ZBRPRNMoveCardFwd ZBRPRNMoveCardFwd;
extern PTR_ZBRPRNResync ZBRPRNResync;
extern PTR_ZBRPRNStartSmartCard ZBRPRNStartSmartCard;
extern PTR_ZBRPRNEndSmartCard ZBRPRNEndSmartCard;

//Test card functions
extern PTR_ZBRPRNPrintTestCard ZBRPRNPrintTestCard;

//Barcode functions
extern PTR_ZBRPRNWriteBarCode ZBRPRNWriteBarCode;

//Update functions
extern PTR_ZBRPRNUpgradeFirmware ZBRPRNUpgradeFirmware;

// Magnetic encoder functions
extern PTR_ZBRPRNSetEncodingDir ZBRPRNSetEncodingDir;
extern PTR_ZBRPRNSetTrkDensity ZBRPRNSetTrkDensity;
extern PTR_ZBRPRNResetMagEncoder ZBRPRNResetMagEncoder;
extern PTR_ZBRPRNSetEncoderCoercivity ZBRPRNSetEncoderCoercivity;
extern PTR_ZBRPRNSetMagEncodingStd ZBRPRNSetMagEncodingStd;
extern PTR_ZBRPRNEnableMagReadDataEncryption ZBRPRNEnableMagReadDataEncryption;
extern PTR_ZBRPRNReadMag ZBRPRNReadMag;
extern PTR_ZBRPRNReadMagByTrk ZBRPRNReadMagByTrk;
extern PTR_ZBRPRNWriteMag ZBRPRNWriteMag;
extern PTR_ZBRPRNWriteMagByTrk ZBRPRNWriteMagByTrk;
extern PTR_ZBRPRNWriteMagPassThru ZBRPRNWriteMagPassThru;

//Old functions not in SDK document (to send command see "Programmer's Guide 980415-001")
extern PTR_ZBRPRNSendCmd ZBRPRNSendCmd;
extern PTR_ZBRPRNSendCommand ZBRPRNSendCommand;
extern PTR_ZBRPRNSendCmdEx ZBRPRNSendCmdEx;
extern PTR_ZBRPRNMultipleCmd ZBRPRNMultipleCmd;


int ZbrPrinter_LoadFunctionDLL(_In_ HMODULE *hModuleDLL, _In_ LPSTR functionName, _In_ FARPROC *funtionPtr);
int ZbrPrinter_LoadDLL(_In_ LPSTR filename);
void ZbrPrinter_UnloadDLL();


#ifdef __cplusplus
}
#endif


#endif


