/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class BasicOscillatorAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    BasicOscillatorAudioProcessor();
    ~BasicOscillatorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //    declare an oscillator in the dsp namespace
//    declare a gain controller with a gain value to adjust the overall signal volume
    
//    standard sin wave equation
//    juce::dsp::Oscillator<float> osc { [](float x) {return std::sin(x);}};
    
//    saw wave equation
//    juce::dsp::Oscillator<float> osc { [](float x) {return x / juce::MathConstants<float>::pi;}};
    
//    square wave equation
    
    juce::dsp::Oscillator<float> osc { [](float x) {return x < 0.0f ? -1.0f : 1.0f;}};
    
    juce::dsp::Gain<float> gain;
    //==============================================================================

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicOscillatorAudioProcessor)
};
