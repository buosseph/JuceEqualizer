/*
 ==============================================================================
 
 MultiFilter.cpp
 Created: 13 Feb 2015 5:14:23pm
 Author:  Brian Uosseph
 
 ==============================================================================
 */

#include "MultiFilter.h"

MultiFilter::MultiFilter(FilterType type, float sampleRate) {
    updateSampleRate(sampleRate);
    fType = type;
    frequency = 2000.f;     // inital frequency should change based on FilterType
    dbGain = 0.f;
    q = 0.71f;
    filter = *new stk::BiQuad();
    updateCoefficients();
}

MultiFilter::~MultiFilter(){}

void MultiFilter::updateCoefficients() {
    switch (fType) {
        case FilterType::LowShelf:
            // Low Shelf Filter
            // Frequency occurs left of slope
            // Isn't balanced when attenuating...
            A = powf(10.f, dbGain/40.f);
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            tmp1 =      A * ( (A+1.f) - (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha );
            tmp2 =  2.f*A * ( (A-1.f) - (A+1.f)*cos_w0                      );
            tmp3 =      A * ( (A+1.f) - (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha );
            
            tmp4 =            (A+1.f) + (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha;
            tmp5 =  -2.f  * ( (A-1.f) + (A+1.f)*cos_w0                      );
            tmp6 =            (A+1.f) + (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha;
            
            b0 = tmp1/tmp4; b1 = tmp2/tmp4; b2 = tmp3/tmp4;
            a1 = tmp5/tmp4; a2 = tmp6/tmp4;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
        
        case FilterType::HighShelf:
            // High Shelf Filter
            // Frequency occurs left of slope
            // Isn't balanced when amplifying...
            A = powf(10.f, dbGain/40.f);
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            tmp1 =      A * ( (A+1.f) + (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha );
            tmp2 = -2.f*A * ( (A-1.f) + (A+1.f)*cos_w0                      );
            tmp3 =      A * ( (A+1.f) + (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha );
            
            tmp4 =            (A+1.f) - (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha;
            tmp5 =    2.f * ( (A-1.f) - (A+1.f)*cos_w0                      );
            tmp6 =            (A+1.f) - (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha;
            
            b0 = tmp1/tmp4; b1 = tmp2/tmp4; b2 = tmp3/tmp4;
            a1 = tmp5/tmp4; a2 = tmp6/tmp4;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
        
        case FilterType::Peak:
            // Peaking Filter
            // Frequecy is skewed in this equation!!! (Peak isn't provided freq)
            A = powf(10.f, dbGain/40.f);
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            tmp1 =  1.f + alpha * A;
            tmp2 =  -2.f * cos_w0;
            tmp3 =  1.f - alpha * A;
            
            tmp4 =  1.f + alpha / A;
            tmp5 =  tmp2;
            tmp6 =  1.f - alpha / A;
            
            b0 = tmp1/tmp4; b1 = tmp2/tmp4; b2 = tmp3/tmp4;
            a1 = tmp5/tmp4; a2 = tmp6/tmp4;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
            
        default:
            break;
    }
}

void MultiFilter::updateSampleRate(float newSampleRate) {
    fs = newSampleRate;
    updateCoefficients();
}

float MultiFilter::tick(float sample) {
    return filter.tick(sample);
}