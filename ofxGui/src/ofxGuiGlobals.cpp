/*
 *  ofxGuiGlobals.cpp
 *  openFrameworks
 *
 *  Copyright 2008 alphakanal/Stefan Kirch.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//	----------------------------------------------------------------------------------------------------

#include "ofxGuiGlobals.h"

//	----------------------------------------------------------------------------------------------------

ofxGuiGlobals* ofxGuiGlobals::Instance()
{
	static ofxGuiGlobals globals;
	return &globals;
}

//	----------------------------------------------------------------------------------------------------

ofxGuiGlobals::ofxGuiGlobals()
{
	mXmlfile			= "";
	
	// TODO: make this work with sandbox
	mHeadFontName		= "fonts/Questrial-Regular.ttf";
	mHeadFontSize		= 12;
	mHeadFontXOffset	= -1;
	mHeadFontYOffset	= 10;
	mHeadFontHeight		= 12;
	
	// TODO: make this work with sandbox
	mParamFontName		= "fonts/Questrial-Regular.ttf";
	mParamFontSize		= 9;
	mParamFontXOffset	= 1;
	mParamFontYOffset	= 10;
	mParamFontHeight	= 15;

	mButtonXText		= 5;
	mButtonYText		= -1;

	mFilesXText			= 3;
	mFilesYText			= 3;

	mPointSize			= 6;

	mKnobSize			= 10;

	mCoverColor			= ofRGBA(0x00000080);//(0x00000088);
	mTextColor			= ofRGBA(0xFFFFFFFF);
	mBorderColor		= ofRGBA(0xFFFFFF80);//(0xFFFFFFFF);
	mFrameColor			= ofRGBA(0xFFFFFFFF);
	mSliderColor		= ofRGBA(0x6699CCFF);
	mAxisColor			= ofRGBA(0x00FF00FF);
	mHandleColor		= ofRGBA(0xFFFFFFFF);
	mButtonColor		= ofRGBA(0x6699CCFF);
	mCurveColor			= ofRGBA(0x6699CCFF);
	mScopeColor			= ofRGBA(0x6699CCFF);
	mMatrixColor		= ofRGBA(0xFF0000FF);

	loadFonts();
}

//	----------------------------------------------------------------------------------------------------

void ofxGuiGlobals::buildFromXml()
{
	int numberOfTags = mXml.getNumTags("STYLE");

	if(numberOfTags != 1)
		return;

	mXml.pushTag("STYLE", 0);

	mHeadFontName		= mXml.getValue("HEADFONT", "Questrial-Regular.ttf");
	mHeadFontSize		= mXml.getValue("HEADSIZE", 14);
	mHeadFontXOffset	= mXml.getValue("HEADXOFF", -2);
	mHeadFontYOffset	= mXml.getValue("HEADYOFF", 10);
	mHeadFontHeight		= mXml.getValue("HEADHEIGHT", 12);

	mParamFontName		= mXml.getValue("PARAMFONT", "Questrial-Regular.ttf");
	mParamFontSize		= mXml.getValue("PARAMSIZE", 10);
	mParamFontXOffset	= mXml.getValue("PARAMXOFF", -2);
	mParamFontYOffset	= mXml.getValue("PARAMYOFF", 10);
	mParamFontHeight	= mXml.getValue("PARAMHEIGHT", 12);

	mButtonXText		= mXml.getValue("BUTTONXTEXT", 4);
	mButtonYText		= mXml.getValue("BUTTONYTEXT", 0);

	mFilesXText			= mXml.getValue("FILESXTEXT", 3);
	mFilesYText			= mXml.getValue("FILESYTEXT", 3);

	mPointSize			= mXml.getValue("POINTSIZE", 6);

	mKnobSize			= mXml.getValue("KNOBSIZE", 10);

	mCoverColor			= ofRGBA(mXml.getValue("COVERCOLOR",	"00000088"));
	mTextColor			= ofRGBA(mXml.getValue("TEXTCOLOR",		"FFFFFFFF"));
	mBorderColor		= ofRGBA(mXml.getValue("BORDERCOLOR",	"FFFFFFFF"));
	mFrameColor			= ofRGBA(mXml.getValue("FRAMECOLOR",	"FFFFFFFF"));
	mSliderColor		= ofRGBA(mXml.getValue("SLIDERCOLOR",	"0099FFFF"));
	mAxisColor			= ofRGBA(mXml.getValue("AXISCOLOR",		"00FF00FF"));
	mHandleColor		= ofRGBA(mXml.getValue("HANDLECOLOR",	"FFFFFFFF"));
	mButtonColor		= ofRGBA(mXml.getValue("BUTTONCOLOR",	"FFDD00FF"));
	mCurveColor			= ofRGBA(mXml.getValue("CURVECOLOR",	"FF9900FF"));
	mScopeColor			= ofRGBA(mXml.getValue("SCOPECOLOR",	"FF9900FF"));
	mMatrixColor		= ofRGBA(mXml.getValue("ACTIVECOLOR",	"FF0000FF"));

	mXml.popTag();

	loadFonts();
}

//	----------------------------------------------------------------------------------------------------

void ofxGuiGlobals::saveToXml()
{
	int id = mXml.addTag("STYLE");

	mXml.setValue("STYLE:HEADFONT",		mHeadFontName, id);
	mXml.setValue("STYLE:HEADSIZE",		mHeadFontSize, id);
	mXml.setValue("STYLE:HEADXOFF",		mHeadFontXOffset, id);
	mXml.setValue("STYLE:HEADYOFF",		mHeadFontYOffset, id);
	mXml.setValue("STYLE:HEADHEIGHT",	mHeadFontHeight, id);

	mXml.setValue("STYLE:PARAMFONT",	mParamFontName, id);
	mXml.setValue("STYLE:PARAMSIZE",	mParamFontSize, id);
	mXml.setValue("STYLE:PARAMXOFF",	mParamFontXOffset, id);
	mXml.setValue("STYLE:PARAMYOFF",	mParamFontYOffset, id);
	mXml.setValue("STYLE:PARAMHEIGHT",	mParamFontHeight, id);

	mXml.setValue("STYLE:BUTTONXTEXT",	mButtonXText, id);
	mXml.setValue("STYLE:BUTTONYTEXT",	mButtonYText, id);

	mXml.setValue("STYLE:FILESXTEXT",	mFilesXText, id);
	mXml.setValue("STYLE:FILESYTEXT",	mFilesYText, id);

	mXml.setValue("STYLE:POINTSIZE",	mPointSize, id);

	mXml.setValue("STYLE:KNOBSIZE",		mKnobSize, id);

	mXml.setValue("STYLE:COVERCOLOR",	mCoverColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:TEXTCOLOR",	mTextColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:BORDERCOLOR",	mBorderColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:FRAMECOLOR",	mFrameColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:SLIDERCOLOR",	mSliderColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:AXISCOLOR",	mAxisColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:HANDLECOLOR",	mHandleColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:BUTTONCOLOR",	mButtonColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:CURVECOLOR",	mCurveColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:SCOPECOLOR",	mScopeColor.toString(kofxGui_Color_RGBA), id);
	mXml.setValue("STYLE:ACTIVECOLOR",	mMatrixColor.toString(kofxGui_Color_RGBA), id);
}

//	----------------------------------------------------------------------------------------------------

void ofxGuiGlobals::loadFonts()
{
	mHeadFont.loadFont(mHeadFontName, mHeadFontSize, true, true);
	mParamFont.loadFont(mParamFontName, mParamFontSize, true, true);
}

//	----------------------------------------------------------------------------------------------------
