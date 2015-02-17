/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_419FC5D7D3F5212A__
#define __JUCE_HEADER_419FC5D7D3F5212A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "PluginLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Timer,
                                    public SliderListener,
                                    public ComboBoxListener
{
public:
    //==============================================================================
    PluginAudioProcessorEditor (PluginAudioProcessor& p);
    ~PluginAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginAudioProcessor& processor;

    PluginAudioProcessor& getProcessor() const
    {
        return static_cast<PluginAudioProcessor&> (processor);
    }

    PluginLookAndFeel pluginLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> f1Group;
    ScopedPointer<Slider> f1FreqSlider;
    ScopedPointer<Slider> f1GainDbSlider;
    ScopedPointer<Slider> f1QSlider;
    ScopedPointer<Slider> outputGainDbSlider;
    ScopedPointer<GroupComponent> f2Group;
    ScopedPointer<Slider> f2FreqSlider;
    ScopedPointer<Slider> f2GainDbSlider;
    ScopedPointer<Slider> f2QSlider;
    ScopedPointer<GroupComponent> f3Group;
    ScopedPointer<Slider> f3FreqSlider;
    ScopedPointer<Slider> f3GainDbSlider;
    ScopedPointer<Slider> f3QSlider;
    ScopedPointer<ComboBox> f1TypeComboBox;
    ScopedPointer<ComboBox> f2TypeComboBox;
    ScopedPointer<ComboBox> f3TypeComboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_419FC5D7D3F5212A__
