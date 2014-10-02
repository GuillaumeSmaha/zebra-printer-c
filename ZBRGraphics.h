
#ifndef _ZBR_GRAPHICS_HEADER_
#define _ZBR_GRAPHICS_HEADER_

#include <Windows.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif


#define ZBR_GRAPHICS_DEFAULT_NAME "ZbrGraphics.dll"

// Number of graphical pixels on card, width and height
#define ZBR_MAX_WIDTH 1044
#define ZBR_MAX_HEIGHT 660
	
// For positioning text and images
enum ZbrGraphicsPosition {
	zbrGraphicsPosition_UpperLeft = 0,
	zbrGraphicsPosition_LowerLeft = 1,
	zbrGraphicsPosition_UpperRight = 2,
	zbrGraphicsPosition_LowerRight = 3,
	zbrGraphicsPosition_Center = 4,
	zbrGraphicsPosition_Left = 5,
	zbrGraphicsPosition_Right = 6
};

// For alignement text
enum ZbrGraphicsAlign {
	zbrGraphicsAlign_Center = 4,
	zbrGraphicsAlign_Left = 5,
	zbrGraphicsAlign_Right = 6
};

// For font styles
enum ZbrGraphicsFontstyle {
	zbrGraphicsFontstyle_Regular = 0,
	zbrGraphicsFontstyle_Bold = 1,
	zbrGraphicsFontstyle_Italic = 2,
	zbrGraphicsFontstyle_BoldItalic = 3,
	zbrGraphicsFontstyle_Underline = 4,
	zbrGraphicsFontstyle_Strikeout = 8
};


#ifndef _ZBR_PRINTER_HEADER_
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

// Errors returned by the SDK graphics engine
#define ZBR_GDI_ERROR_GENERIC_ERROR                8001	//GenericError      = 1,
#define ZBR_GDI_ERROR_INVALID_PARAMETER            8002	//InvalidParameter  = 2,
#define ZBR_GDI_ERROR_OUT_OF_MEMORY                8003	//OutOfMemory       = 3,
#define ZBR_GDI_ERROR_OBJECT_BUSY                  8004	//ObjectBusy        = 4,
#define ZBR_GDI_ERROR_INSUFFICIENT_BUFFER          8005	//InsufficientBuffer = 5,
#define ZBR_GDI_ERROR_NOT_IMPLEMENTED              8006	//NotImplemented     = 6,
#define ZBR_GDI_ERROR_WIN32_ERROR                  8007	//Win32Error         = 7,
#define ZBR_GDI_ERROR_WRONG_STATE                  8008	//WrongState         = 8,
#define ZBR_GDI_ERROR_ABORTED                      8009	//Aborted            = 9,
#define ZBR_GDI_ERROR_FILE_NOT_FOUND               8010	//FileNotFound       = 10,
#define ZBR_GDI_ERROR_VALUE_OVERFLOW               8011	//ValueOverflow      = 11,
#define ZBR_GDI_ERROR_ACCESS_DENIED                8012	//AccessDenied       = 12,
#define ZBR_GDI_ERROR_UNKNOWN_IMAGE_FORMAT         8013	//UnknownImageFormat = 13,
#define ZBR_GDI_ERROR_FONT_FAMILY_NOT_FOUND        8014	//FontFamilyNotFound = 14,
#define ZBR_GDI_ERROR_FONT_STYLE_NOT_FOUND         8015	//FontStyleNotFound  = 15,
#define ZBR_GDI_ERROR_NOT_TRUE_TYPE_FONT           8016	//NotTrueTypeFont    = 16,
#define ZBR_GDI_ERROR_UNSUPPORTED_GDIPLUS_VERSION  8017	//UnsupportedGdiplusVersion = 17,
#define ZBR_GDI_ERROR_GDIPLUS_NOT_INITIALIZED      8018	//GdiplusNotInitialized     = 18,
#define ZBR_GDI_ERROR_PROPERTY_NOT_FOUND           8019	//PropertyNotFound     = 19,
#define ZBR_GDI_ERROR_PROPERTY_NOT_SUPPORTED       8020	//PropertyNotSupported = 20

#define ZBR_GDI_ERROR_GRAPHICS_ALREADY_INITIALIZED 8021
#define ZBR_GDI_ERROR_NO_GRAPHIC_DATA              8022
#define ZBR_GDI_ERROR_GRAPHICS_NOT_INITIALIZED     8023
#define ZBR_GDI_ERROR_GETTING_DEVICE_CONTEXT       8024

// Print Dialog Error Codes
#define ZBR_PD_ERROR_DLG_CANCELED			8025	//User closed or canceled the dlg window
#define ZBR_PD_ERROR_SETUP_FAILURE			8026	//PrintDlg function failed to load the required resources.
#define ZBR_PD_ERROR_PARSE_FAILURE			8027	//PrintDlg function failed to parse the strings in the 
														//[devices] section of the WIN.INI file.
#define ZBR_PD_ERROR_RET_DEFAULT_FAILURE    8028	//PD_RETURNDEFAULT flag was specified in the Flags member of 
														//the PRINTDLG structure, but the hDevMode or hDevNames member was not NULL
#define ZBR_PD_ERROR_LOAD_DRV_FAILURE		8029	//PrintDlg function failed to load the device driver for the specified printer.
#define ZBR_PD_ERROR_GET_DEVMODE_FAIL		8030	//printer driver failed to initialize a DEVMODE structure.
#define ZBR_PD_ERROR_INIT_FAILURE			8031	//PrintDlg function failed during initialization, and there is no more specific 
														//extended error code to describe the failure.
#define ZBR_PD_ERROR_NO_DEVICES				8032	//No printer drivers were found.
#define ZBR_PD_ERROR_NO_DEFAULT_PRINTER     8033	//A default printer does not exist.
#define ZBR_PD_ERROR_DN_DM_MISMATCH			8034	//data in the DEVMODE and DEVNAMES structures describes two different printers.
#define ZBR_PD_ERROR_CREATE_IC_FAILURE		8035	//PrintDlg function failed when it attempted to create an information context.
#define ZBR_PD_ERROR_PRINTER_NOT_FOUND		8036	//The [devices] section of the WIN.INI file did not contain an entry for the requested printer.
#define ZBR_PD_ERROR_DEFAULT_DIFFERENT		8037	//error occurs when you store the DEVNAMES structure and the user changes the default printer by using the Control Panel.

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
typedef void (CALLBACK *PTR_ZBRGDIGetSDKVer)(_Out_ LPINT major, _Out_ LPINT minor, _Out_ LPINT engLevel);
typedef void (CALLBACK *PTR_ZBRGDIGetSDKVsn)(_Out_ LPINT major, _Out_ LPINT minor, _Out_ LPINT engLevel);
typedef INT (CALLBACK *PTR_ZBRGDIGetSDKProductVer)(_Out_ LPSTR productVersion, _Out_ LPINT buffSize);

//Initialization functions
typedef INT (CALLBACK *PTR_ZBRGDIInitGraphics)(_In_ LPSTR printerName, _Out_ HDC *hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIInitGraphicsEx)(_In_ LPSTR printerName, _Out_ HDC *hDC, _In_ LPSTR jobName, _Out_ LPINT jobID, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIInitGraphicsFromPrintDlg)(_Out_ HDC *hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDICloseGraphics)(_In_ HDC hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIClearGraphics)(_Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIStartPage)(_In_ HDC hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIEndPage)(_In_ HDC hDC, _Out_ LPINT err);

//Print functions
typedef INT (CALLBACK *PTR_ZBRGDIPreviewGraphics)(_In_ HWND hwnd, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintGraphics)(_In_ HDC hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintGraphicsEx)(_In_ HDC hDC, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintFilePos)(_In_ HDC hDC, _In_ LPSTR fileName, _In_ ZbrGraphicsPosition position, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintFileRect)(_In_ HDC hDC, _In_ LPSTR fileName, _In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD sizeY, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIIsPrinterReady)(_In_ LPSTR printerName, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintImagePos)(_In_ HDC hDC, _In_ LPSTR imageData, _In_ INT imageSize, _In_ ZbrGraphicsPosition position, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIPrintImageRect)(_In_ HDC hDC, _In_ LPSTR imageData, _In_ INT imageSize, _In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD sizeY, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDICancelJob)(_In_ HDC hDC, _In_ INT jobID, _Out_ LPINT err);

//Draw functions
typedef INT (CALLBACK *PTR_ZBRGDIDrawText)(_In_ DWORD x, _In_ DWORD y, LPSTR text, LPSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawTextEx)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD angle, _In_ ZbrGraphicsAlign alignment, LPSTR text, LPSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawTextUnicode)(_In_ DWORD x, _In_ DWORD y, LPWSTR text, LPWSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawTextUnicodeEx)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD angle, _In_ ZbrGraphicsAlign alignment, LPWSTR text, LPWSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawTextRect)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _In_ ZbrGraphicsAlign alignment, LPSTR text, LPSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawTextRectEx)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _In_ DWORD angle, _In_ ZbrGraphicsAlign alignment, LPSTR text, LPSTR font, _In_ DWORD fontSize, _In_ ZbrGraphicsFontstyle fontStyle, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawLine)(_In_ DWORD x1, _In_ DWORD y1, _In_ DWORD x2, _In_ DWORD y2, _In_ DWORD color, _In_ float thickness, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImage)(_In_ LPSTR fileName, _In_ DWORD x, _In_ DWORD y, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImageEx)(_In_ LPSTR fileName, _In_ INT imageSize, _In_ DWORD x, _In_ DWORD y, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImagePos)(_In_ LPSTR fileName, _In_ ZbrGraphicsPosition position, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImagePosEx)(_In_ LPSTR fileName, _In_ INT imageSize, _In_ ZbrGraphicsPosition position, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImageRect)(_In_ LPSTR fileName, _In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawImageRectEx)(_In_ LPSTR fileName, _In_ INT imageSize, _In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawRectangle)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _In_ float thickness, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawEllipse)(_In_ DWORD x, _In_ DWORD y, _In_ DWORD width, _In_ DWORD height, _In_ float thickness, _In_ DWORD color, _Out_ LPINT err);
typedef INT (CALLBACK *PTR_ZBRGDIDrawBarCode)(_In_ DWORD x, _In_ DWORD y, _In_ ZbrCodebarRotation rotation, _In_ ZbrCodebarType barCodeType, _In_ ZbrCodebarWidthRatio barWidthRatio, _In_ DWORD barCodeMultiplier, _In_ DWORD barCodeHeight, _In_ ZbrCodebarTextUnder textUnder, _In_ LPSTR barCodeData, _Out_ LPINT err);



//SDK specific functions
extern PTR_ZBRGDIGetSDKVer ZBRGDIGetSDKVer;
extern PTR_ZBRGDIGetSDKVsn ZBRGDIGetSDKVsn;
extern PTR_ZBRGDIGetSDKProductVer ZBRGDIGetSDKProductVer;

//Initialization functions
extern PTR_ZBRGDIInitGraphics ZBRGDIInitGraphics;
extern PTR_ZBRGDIInitGraphicsEx ZBRGDIInitGraphicsEx;
extern PTR_ZBRGDIInitGraphicsFromPrintDlg ZBRGDIInitGraphicsFromPrintDlg;
extern PTR_ZBRGDICloseGraphics ZBRGDICloseGraphics;
extern PTR_ZBRGDIClearGraphics ZBRGDIClearGraphics;
extern PTR_ZBRGDIStartPage ZBRGDIStartPage;
extern PTR_ZBRGDIEndPage ZBRGDIEndPage;

//Print functions
extern PTR_ZBRGDIPreviewGraphics ZBRGDIPreviewGraphics;
extern PTR_ZBRGDIPrintGraphics ZBRGDIPrintGraphics;
extern PTR_ZBRGDIPrintGraphicsEx ZBRGDIPrintGraphicsEx;
extern PTR_ZBRGDIPrintFilePos ZBRGDIPrintFilePos;
extern PTR_ZBRGDIPrintFileRect ZBRGDIPrintFileRect;
extern PTR_ZBRGDIIsPrinterReady ZBRGDIIsPrinterReady;
extern PTR_ZBRGDIPrintImagePos ZBRGDIPrintImagePos;
extern PTR_ZBRGDIPrintImageRect ZBRGDIPrintImageRect;
extern PTR_ZBRGDICancelJob ZBRGDICancelJob;

//Draw functions
extern PTR_ZBRGDIDrawText ZBRGDIDrawText;
extern PTR_ZBRGDIDrawTextEx ZBRGDIDrawTextEx;
extern PTR_ZBRGDIDrawTextUnicode ZBRGDIDrawTextUnicode;
extern PTR_ZBRGDIDrawTextUnicodeEx ZBRGDIDrawTextUnicodeEx;
extern PTR_ZBRGDIDrawTextRect ZBRGDIDrawTextRect;
extern PTR_ZBRGDIDrawTextRectEx ZBRGDIDrawTextRectEx;
extern PTR_ZBRGDIDrawLine ZBRGDIDrawLine;
extern PTR_ZBRGDIDrawImage ZBRGDIDrawImage;
extern PTR_ZBRGDIDrawImageEx ZBRGDIDrawImageEx;
extern PTR_ZBRGDIDrawImagePos ZBRGDIDrawImagePos;
extern PTR_ZBRGDIDrawImagePosEx ZBRGDIDrawImagePosEx;
extern PTR_ZBRGDIDrawImageRect ZBRGDIDrawImageRect;
extern PTR_ZBRGDIDrawImageRectEx ZBRGDIDrawImageRectEx;
extern PTR_ZBRGDIDrawRectangle ZBRGDIDrawRectangle;
extern PTR_ZBRGDIDrawEllipse ZBRGDIDrawEllipse;
extern PTR_ZBRGDIDrawBarCode ZBRGDIDrawBarCode;


int ZbrGraphics_LoadFunctionDLL(_In_ HMODULE *hModuleDLL, _In_ LPSTR functionName, _In_ FARPROC *funtionPtr);
int ZbrGraphics_LoadDLL(_In_ LPSTR filename);
void ZbrGraphics_UnloadDLL();

#ifdef __cplusplus
}
#endif


#endif


