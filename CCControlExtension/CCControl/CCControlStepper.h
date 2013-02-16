/*
 * CCControlStepper.h
 *
 * Copyright 2012 Yannick Loriot. All rights reserved.
 * http://yannickloriot.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#import "CCControl.h"

typedef enum
{
    kCCControlStepperPartMinus,
    kCCControlStepperPartPlus,
    kCCControlStepperPartNone,
} CCControlStepperPart;

/**
 * CCControlStepper is a stepper control which provides a user
 * interface for incrementing or decrementing a value.
 */
@interface CCControlStepper : CCControl
{
@public
    double                  value_;
    BOOL                    continuous_;
    BOOL                    autorepeat_;
    BOOL                    wraps_;
    double                  minimumValue_;
    double                  maximumValue_;
    double                  stepValue_;
        
@protected
    // Weak links to children
	CCSprite                *minusSprite_;
    CCSprite                *plusSprite_;
    CCLabelTTF              *minusLabel_;
    CCLabelTTF              *plusLabel_;
    
    BOOL                    touchInsideFlag_;
    CCControlStepperPart    touchedPart_;
    NSInteger               autorepeatCount_;
}
/** @name Accessing the Stepper’s Value */
/**
 * @abstract The numeric value of the stepper.
 * @discussion When the value changes, the stepper sends
 * the CCControlEventValueChanged flag to its target (see
 * addTarget:action:forControlEvents:). Refer to the
 * description of the continuous property for information
 * about whether value change events are sent continuously
 * or when user interaction ends.
 *
 * The default value for this property is 0. This property
 * is clamped at its lower extreme to minimumValue and is
 * clamped at its upper extreme to maximumValue.
 */
@property (nonatomic) double value;
/** @name Configuring the Stepper */
/**
 * @abstract The continuous vs. noncontinuous state of the
 * stepper.
 * @discussion If YES, value change events are sent
 * immediately when the value changes during user interaction.
 * If NO, a value change event is sent when user interaction
 * ends.
 *
 * The default value for this property is YES.
 */
@property (nonatomic, getter=isContinuous) BOOL continuous;
/**
 * @abstract The automatic vs. nonautomatic repeat state of the
 * stepper.
 * @discussion If YES, the user pressing and holding on the
 * stepper repeatedly alters value.
 *
 * The default value for this property is YES.
 */
@property (nonatomic) BOOL autorepeat;
/**
 * @abstract The wrap vs. no-wrap state of the stepper.
 * @discussion If YES, incrementing beyond maximumValue sets
 * value to minimumValue; likewise, decrementing below
 * minimumValue sets value to maximumValue. If NO, the stepper
 * does not increment beyond maximumValue nor does it decrement
 * below minimumValue but rather holds at those values.
 *
 * The default value for this property is NO.
 */
@property (nonatomic) BOOL wraps;
/**
 * @abstract The lowest possible numeric value for the stepper.
 * @discussion Must be numerically less than maximumValue. If
 * you attempt to set a value equal to or greater than
 * maximumValue, the system raises an NSInvalidArgumentException
 * exception.
 *
 *The default value for this property is 0.
 */
@property (nonatomic) double minimumValue;
/**
 * @abstract The highest possible numeric value for the stepper.
 * @discussion Must be numerically greater than minimumValue. If
 * you attempt to set a value equal to or lower than minimumValue,
 * the system raises an NSInvalidArgumentException exception.
 *
 * The default value of this property is 100.
 */
@property (nonatomic) double maximumValue;
/**
 * @abstract The step, or increment, value for the stepper.
 * @discussion Must be numerically greater than 0. If you attempt
 * to set this property’s value to 0 or to a negative number, the
 * system raises an NSInvalidArgumentException exception.
 *
 * The default value for this property is 1.
 */
@property (nonatomic) double stepValue;

#pragma mark Contructors - Initializers
/** @name Creating Steppers */

/** Initializes a stepper with a minus and plus sprites. */
- (id)initWithMinusSprite:(CCSprite *)minusSprite plusSprite:(CCSprite *)plusSprite;
/**
 * Creates a stepper with the given minus and plus sprites.
 *
 * @see initWithMinusSprite:plusSprite:
 */
+ (id)stepperWithMinusSprite:(CCSprite *)minusSprite plusSprite:(CCSprite *)plusSprite;

#pragma mark - Public Methods

@end
