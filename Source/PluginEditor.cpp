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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (f1Group = new GroupComponent ("Filter1 Group",
                                                     TRANS("Filter1")));
    f1Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f1Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f1FreqSlider = new Slider ("Filter1 Frequency"));
    f1FreqSlider->setRange (20, 20000, 0);
    f1FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f1FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1FreqSlider->addListener (this);

    addAndMakeVisible (f1GainDbSlider = new Slider ("Filter1 Gain"));
    f1GainDbSlider->setRange (-24, 24, 0.1);
    f1GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f1GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1GainDbSlider->addListener (this);

    addAndMakeVisible (f1QSlider = new Slider ("Filter1 Q"));
    f1QSlider->setRange (0.1, 10, 0.01);
    f1QSlider->setSliderStyle (Slider::LinearHorizontal);
    f1QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1QSlider->addListener (this);

    addAndMakeVisible (outputGainDbSlider = new Slider ("Output Gain"));
    outputGainDbSlider->setRange (-24, 24, 0.1);
    outputGainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    outputGainDbSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    outputGainDbSlider->addListener (this);

    addAndMakeVisible (f2Group = new GroupComponent ("Filter2 Group",
                                                     TRANS("Filter2")));
    f2Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f2Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f2FreqSlider = new Slider ("Filter2 Frequency"));
    f2FreqSlider->setRange (20, 20000, 0);
    f2FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f2FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2FreqSlider->addListener (this);

    addAndMakeVisible (f2GainDbSlider = new Slider ("Filter2 Gain"));
    f2GainDbSlider->setRange (-24, 24, 0.1);
    f2GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f2GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2GainDbSlider->addListener (this);

    addAndMakeVisible (f2QSlider = new Slider ("Filter2 Q"));
    f2QSlider->setRange (0.1, 10, 0.01);
    f2QSlider->setSliderStyle (Slider::LinearHorizontal);
    f2QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2QSlider->addListener (this);

    addAndMakeVisible (f3Group = new GroupComponent ("Filter3 Group",
                                                     TRANS("Filter3")));
    f3Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f3Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f3FreqSlider = new Slider ("Filter3 Frequency"));
    f3FreqSlider->setRange (20, 20000, 0);
    f3FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f3FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3FreqSlider->addListener (this);

    addAndMakeVisible (f3GainDbSlider = new Slider ("Filter3 Gain"));
    f3GainDbSlider->setRange (-24, 24, 0.1);
    f3GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f3GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3GainDbSlider->addListener (this);

    addAndMakeVisible (f3QSlider = new Slider ("Filter3 Q"));
    f3QSlider->setRange (0.1, 10, 0.01);
    f3QSlider->setSliderStyle (Slider::LinearHorizontal);
    f3QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3QSlider->addListener (this);

    addAndMakeVisible (f1TypeComboBox = new ComboBox ("Filter1 Type"));
    f1TypeComboBox->setEditableText (false);
    f1TypeComboBox->setJustificationType (Justification::centred);
    f1TypeComboBox->setTextWhenNothingSelected (TRANS("Filter Type"));
    f1TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f1TypeComboBox->addItem (TRANS("Low Shelf"), 1);
    f1TypeComboBox->addItem (TRANS("Peak"), 2);
    f1TypeComboBox->addItem (TRANS("High Shelf"), 3);
    f1TypeComboBox->addItem (TRANS("LowPass"), 4);
    f1TypeComboBox->addItem (TRANS("HighPass"), 5);
    f1TypeComboBox->addListener (this);

    addAndMakeVisible (f2TypeComboBox = new ComboBox ("Filter2 Type"));
    f2TypeComboBox->setEditableText (false);
    f2TypeComboBox->setJustificationType (Justification::centred);
    f2TypeComboBox->setTextWhenNothingSelected (TRANS("Filter Type"));
    f2TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f2TypeComboBox->addItem (TRANS("Low Shelf"), 1);
    f2TypeComboBox->addItem (TRANS("Peak"), 2);
    f2TypeComboBox->addItem (TRANS("High Shelf"), 3);
    f2TypeComboBox->addItem (TRANS("LowPass"), 4);
    f2TypeComboBox->addItem (TRANS("HighPass"), 5);
    f2TypeComboBox->addListener (this);

    addAndMakeVisible (f3TypeComboBox = new ComboBox ("Filter3 Type"));
    f3TypeComboBox->setEditableText (false);
    f3TypeComboBox->setJustificationType (Justification::centred);
    f3TypeComboBox->setTextWhenNothingSelected (TRANS("Filter Type"));
    f3TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f3TypeComboBox->addItem (TRANS("Low Shelf"), 1);
    f3TypeComboBox->addItem (TRANS("Peak"), 2);
    f3TypeComboBox->addItem (TRANS("High Shelf"), 3);
    f3TypeComboBox->addItem (TRANS("LowPass"), 4);
    f3TypeComboBox->addItem (TRANS("HighPass"), 5);
    f3TypeComboBox->addListener (this);


    //[UserPreSize]
    // Add any other settings not offered by GUI editor here, else they'll be deleted
    f1FreqSlider->setTextValueSuffix("Hz");
    f2FreqSlider->setTextValueSuffix("Hz");
    f3FreqSlider->setTextValueSuffix("Hz");
    f1GainDbSlider->setTextValueSuffix("db");
    f2GainDbSlider->setTextValueSuffix("db");
    f3GainDbSlider->setTextValueSuffix("db");
    outputGainDbSlider->setTextValueSuffix("db");

    f1TypeComboBox->setSelectedId(1);
    f2TypeComboBox->setSelectedId(2);
    f3TypeComboBox->setSelectedId(3);

    f1FreqSlider->setDoubleClickReturnValue(true, 800.f);
    f2FreqSlider->setDoubleClickReturnValue(true, 2000.f);
    f3FreqSlider->setDoubleClickReturnValue(true, 8000.f);

    f1QSlider->setDoubleClickReturnValue(true, 0.71f);
    f2QSlider->setDoubleClickReturnValue(true, 0.71f);
    f3QSlider->setDoubleClickReturnValue(true, 0.71f);

    f1GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f2GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f3GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    outputGainDbSlider->setDoubleClickReturnValue(true, 0.f);
    //[/UserPreSize]

    setSize (480, 232);


    //[Constructor] You can add your own custom stuff here..

    // Uncomment to apply custom styling from PluginLookAndFeel
    LookAndFeel::setDefaultLookAndFeel(&pluginLookAndFeel);

    startTimer (50);
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    f1Group = nullptr;
    f1FreqSlider = nullptr;
    f1GainDbSlider = nullptr;
    f1QSlider = nullptr;
    outputGainDbSlider = nullptr;
    f2Group = nullptr;
    f2FreqSlider = nullptr;
    f2GainDbSlider = nullptr;
    f2QSlider = nullptr;
    f3Group = nullptr;
    f3FreqSlider = nullptr;
    f3GainDbSlider = nullptr;
    f3QSlider = nullptr;
    f1TypeComboBox = nullptr;
    f2TypeComboBox = nullptr;
    f3TypeComboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    deleteAllChildren();    // Just in case you miss something (maybe unneeded)
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    f1Group->setBounds (0, 0, 160, 200);
    f1FreqSlider->setBounds (8, 104, 142, 40);
    f1GainDbSlider->setBounds (8, 56, 144, 40);
    f1QSlider->setBounds (8, 152, 144, 40);
    outputGainDbSlider->setBounds (240 - (448 / 2), 200, 448, 32);
    f2Group->setBounds (160, 0, 160, 200);
    f2FreqSlider->setBounds (168, 104, 142, 40);
    f2GainDbSlider->setBounds (168, 56, 144, 40);
    f2QSlider->setBounds (168, 152, 144, 40);
    f3Group->setBounds (320, 0, 160, 200);
    f3FreqSlider->setBounds (328, 104, 144, 40);
    f3GainDbSlider->setBounds (328, 56, 144, 40);
    f3QSlider->setBounds (328, 152, 144, 40);
    f1TypeComboBox->setBounds (16, 24, 128, 24);
    f2TypeComboBox->setBounds (176, 24, 128, 24);
    f3TypeComboBox->setBounds (336, 24, 128, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == f1FreqSlider)
    {
        //[UserSliderCode_f1FreqSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f1FreqSlider]
    }
    else if (sliderThatWasMoved == f1GainDbSlider)
    {
        //[UserSliderCode_f1GainDbSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f1GainDbSlider]
    }
    else if (sliderThatWasMoved == f1QSlider)
    {
        //[UserSliderCode_f1QSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f1QSlider]
    }
    else if (sliderThatWasMoved == outputGainDbSlider)
    {
        //[UserSliderCode_outputGainDbSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::outputGainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_outputGainDbSlider]
    }
    else if (sliderThatWasMoved == f2FreqSlider)
    {
        //[UserSliderCode_f2FreqSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f2FreqSlider]
    }
    else if (sliderThatWasMoved == f2GainDbSlider)
    {
        //[UserSliderCode_f2GainDbSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f2GainDbSlider]
    }
    else if (sliderThatWasMoved == f2QSlider)
    {
        //[UserSliderCode_f2QSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f2QSlider]
    }
    else if (sliderThatWasMoved == f3FreqSlider)
    {
        //[UserSliderCode_f3FreqSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f3FreqSlider]
    }
    else if (sliderThatWasMoved == f3GainDbSlider)
    {
        //[UserSliderCode_f3GainDbSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f3GainDbSlider]
    }
    else if (sliderThatWasMoved == f3QSlider)
    {
        //[UserSliderCode_f3QSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f3QSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == f1TypeComboBox)
    {
        //[UserComboBoxCode_f1TypeComboBox] -- add your combo box handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1TypeParam,
            (float)comboBoxThatHasChanged->getSelectedItemIndex() / (float) comboBoxThatHasChanged->getNumItems()
        );

        if (comboBoxThatHasChanged->getSelectedItemIndex() > 2) {
            f1GainDbSlider->setEnabled(false);
        }
        else {
            f1GainDbSlider->setEnabled(true);
        }
        //[/UserComboBoxCode_f1TypeComboBox]
    }
    else if (comboBoxThatHasChanged == f2TypeComboBox)
    {
        //[UserComboBoxCode_f2TypeComboBox] -- add your combo box handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2TypeParam,
            (float)comboBoxThatHasChanged->getSelectedItemIndex() / (float) comboBoxThatHasChanged->getNumItems()
        );

        if (comboBoxThatHasChanged->getSelectedItemIndex() > 2) {
            f2GainDbSlider->setEnabled(false);
        }
        else {
            f2GainDbSlider->setEnabled(true);
        }
        //[/UserComboBoxCode_f2TypeComboBox]
    }
    else if (comboBoxThatHasChanged == f3TypeComboBox)
    {
        //[UserComboBoxCode_f3TypeComboBox] -- add your combo box handling code here..
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3TypeParam,
            (float)comboBoxThatHasChanged->getSelectedItemIndex() / (float) comboBoxThatHasChanged->getNumItems()
        );

        if (comboBoxThatHasChanged->getSelectedItemIndex() > 2) {
            f3GainDbSlider->setEnabled(false);
        }
        else {
            f3GainDbSlider->setEnabled(true);
        }
        //[/UserComboBoxCode_f3TypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginAudioProcessorEditor::timerCallback()
{
    // Set UI values to match any changes made by host automation
    // Timer conflicts cause UI stuttering, this is due to the values not being mapped back
    PluginAudioProcessor& ourProcessor = getProcessor();

    f1FreqSlider->setValue(
        20 + (ourProcessor.uf1Freq * 19980),
        dontSendNotification
    );
    f1QSlider->setValue(
        0.1f + (ourProcessor.uf1Q * 9.9f),
        dontSendNotification
    );
    f1GainDbSlider->setValue(
        -24 + (ourProcessor.uf1GainDb * 48),
        dontSendNotification
    );
    f1TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf1Type * (float) f1TypeComboBox->getNumItems()),
        dontSendNotification
    );

    f2FreqSlider->setValue(
        20 + (ourProcessor.uf2Freq * 19980),
        dontSendNotification
    );
    f2QSlider->setValue(
        0.1f + (ourProcessor.uf2Q * 9.9f),
        dontSendNotification
    );
    f2GainDbSlider->setValue(
        -24 + (ourProcessor.uf2GainDb * 48),
        dontSendNotification
    );
    f2TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf2Type * (float) f2TypeComboBox->getNumItems()),
        dontSendNotification
    );

    f3FreqSlider->setValue(
        20 + (ourProcessor.uf3Freq * 19980),
        dontSendNotification
    );
    f3QSlider->setValue(
        0.1f + (ourProcessor.uf3Q * 9.9f),
        dontSendNotification
    );
    f3GainDbSlider->setValue(
        -24 + (ourProcessor.uf3GainDb * 48),
        dontSendNotification
    );
    f3TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf3Type * (float) f3TypeComboBox->getNumItems()),
        dontSendNotification
    );

    outputGainDbSlider->setValue(
         -24 + (ourProcessor.uOutputGainDb * 48),
        dontSendNotification
    );
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PluginAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="480" initialHeight="232">
  <BACKGROUND backgroundColour="ff222222"/>
  <GROUPCOMPONENT name="Filter1 Group" id="3e3623464cd19898" memberName="f1Group"
                  virtualName="" explicitFocusOrder="0" pos="0 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter1"/>
  <SLIDER name="Filter1 Frequency" id="9c1b5f965c3496b1" memberName="f1FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="8 104 142 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter1 Gain" id="ca46285293b766fb" memberName="f1GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="8 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter1 Q" id="6b3feafb481c407c" memberName="f1QSlider"
          virtualName="" explicitFocusOrder="0" pos="8 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Output Gain" id="c1a935f737dd219f" memberName="outputGainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="240c 200 448 32" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="Filter2 Group" id="7cd375bda4a5ec1a" memberName="f2Group"
                  virtualName="" explicitFocusOrder="0" pos="160 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter2"/>
  <SLIDER name="Filter2 Frequency" id="1c2a04d934cb6c9c" memberName="f2FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="168 104 142 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter2 Gain" id="b8f88db88714ea6b" memberName="f2GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="168 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter2 Q" id="51264063d9828a77" memberName="f2QSlider"
          virtualName="" explicitFocusOrder="0" pos="168 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="Filter3 Group" id="ef8795c31b8e473f" memberName="f3Group"
                  virtualName="" explicitFocusOrder="0" pos="320 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter3"/>
  <SLIDER name="Filter3 Frequency" id="833854691aa41e24" memberName="f3FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="328 104 144 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter3 Gain" id="709ddea6d5c7b347" memberName="f3GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="328 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter3 Q" id="70ef231f74f55ac0" memberName="f3QSlider"
          virtualName="" explicitFocusOrder="0" pos="328 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Filter1 Type" id="adb4886bc59b10c3" memberName="f1TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="16 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter2 Type" id="7fb9885b1b601bb1" memberName="f2TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="176 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter3 Type" id="2396ee60b755337b" memberName="f3TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="336 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
