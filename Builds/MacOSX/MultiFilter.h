/*
  ==============================================================================

    MultiFilter.h
    Created: 13 Feb 2015 5:14:23pm
    Author:  Brian Uosseph

  ==============================================================================
*/

#ifndef MULTIFILTER_H_INCLUDED
#define MULTIFILTER_H_INCLUDED

#include <math.h>
#include "BiQuad.h"
#include "FilterType.h"

class MultiFilter
{
public:
    MultiFilter(FilterType type, float sampleRate);
    ~MultiFilter();
    
    void updateCoefficients();
    void updateSampleRate(float newSampleRate);
    float tick(float sample);
    // void changeFilterType(FilterType type);
    
    // Controllable Parameters
    float frequency, q, dbGain;
    
private:
    float fs;
    FilterType fType;
    stk::BiQuad filter;

    float A, w0, alpha, cos_w0, sin_w0;
    float tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    float inter1, inter2, inter3, inter4, inter5, inter6;
    
    // coefficients
    float b0, b1, b2, a1, a2;
};

#endif  // MULTIFILTER_H_INCLUDED
