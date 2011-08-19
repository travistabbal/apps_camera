#pragma once
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <semaphore.h>

// The Preview FBO dimensions are determined from the low-res
// frame dimensions (gPreviewImageWidth, gPreviewImageHeight)
// using the scale factors below.
const int PREVIEW_FBO_WIDTH_SCALE = 8;
const int PREVIEW_FBO_HEIGHT_SCALE = 2;

// The factor below determines the (horizontal) speed at which the viewfinder
// will pan across the UI during capture. A value of 0.0 will keep the viewfinder
// static in the center of the screen and 1.0f will make it pan at the
// same speed as the device.
const float VIEWFINDER_PAN_FACTOR_HORZ = 0.2f;

const int LR = 0; // Low-resolution mode
const int HR = 1; // High-resolution mode
const int NR = 2; // Number of resolution modes

extern "C" void AllocateTextureMemory(int widthHR, int heightHR,
        int widthLR, int heightLR);
extern "C" void FreeTextureMemory();
extern "C" void UpdateWarpTransformation(float *trs);

extern unsigned char* gPreviewImage[NR];
extern int gPreviewImageWidth[NR];
extern int gPreviewImageHeight[NR];

extern sem_t gPreviewImage_semaphore;

extern double g_dAffinetrans[16];
extern double g_dAffinetransInv[16];
extern double g_dTranslation[16];