#-------------------------------------------------
#
# Project created by QtCreator 2011-11-30T00:37:08
#
#-------------------------------------------------

QT       += core gui

TARGET = FeetWetCoding
TEMPLATE = app

SOURCES += \
    source/main.cpp \
    source/lib/feetwetcodinglib.cpp \
    source/lib/ExerciseLauncher.cpp \
    source/lib/ColorViewer.cpp \
    exercises/feetwetcodingexercise.cpp \
    source/lib/FWCExerciseChooser.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/001_Welcome.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/010_ChangeText.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/020_ChangeX.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/030_ChangeY.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/040_ChangeXY.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/050_ChangeColor.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/060_ChangeFont.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/200_DrawingText.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/070_DrawLines.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/080_DrawCircles.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/100_DrawDots.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/090_DrawRectangles.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/110_DrawEllipses.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/250_DrawingImages.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/310_SeeoutFormatting.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/400_OnYourOwn.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/550_FontProportions.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/300_SeeoutIntro.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/520_ColorNames.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/001_WelcomeSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/010_ChangeTextSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/020_ChangeXSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/030_ChangeYSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/040_ChangeXYSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/050_ChangeColorSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/060_ChangeFontSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/070_DrawLinesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/080_DrawCirclesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/100_DrawDotsSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/090_DrawRectanglesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/110_DrawEllipsesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/200_DrawingTextSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/250_DrawingImagesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/300_SeeoutIntroSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/310_SeeoutFormattingSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/400_OnYourOwnSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/520_ColorNamesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S02-Getting_Started/Solutions/550_FontProportionsSOLN.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/020_NumericTypes.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/040_DrawingVersusSeeout.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/080_CONSTANTS.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/100_Chars.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/110_Booleans.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/200_StandardStrings.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/300_Arrays.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/Solutions/020_NumericTypesSOLN.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/Solutions/040_DrawingVersusSeeoutSOLN.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/Solutions/200_StandardStringsSOLN.cpp \
    exercises/C01-Beginner_Exercises/S03-Types_Variables/Solutions/300_ArraysSOLN.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/040_OrderOfOperations.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/520_Misdirection.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/020_AssignmentArithmetic.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/060_PreAndPostIncAndDec.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/100_ModulusOperator.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/120_BlocksAndScope.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/140_MathFunctions.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/200_randomAndrandomRange.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/210_DistanceEquation.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/Solutions/060_PreAndPostIncAndDecSOLN.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/Solutions/210_DistanceEquationSOLN.cpp \
    exercises/C01-Beginner_Exercises/S04-Expressions_Syntax/Solutions/520_MisdirectionSOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/002_WhileLoopIntro.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/004_ForLoopIntro.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/010_WhileLoop1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/015_InfiniteLooping1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/020_C01S05_OYO1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/025_C01S05_OYO2.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/030_WhileLoop2.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/035_WhileLoop3.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/040_C01S05_OYO3.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/045_C01S05_OYO4.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/050_WhileLoop4.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/055_WhileLoop5.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/110_ForLoops1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/115_ForLoops2.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/120_ForLoops3.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/210_IfThen1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/215_IfThen2.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/220_IfThen3.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/250_Switch1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/260_OYO_IfThen4.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/310_DivideByZero.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/315_Primes1.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/320_OYO_Primes2.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/480_C01S05_OYO5.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/002_WhileLoopIntroSOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/004_ForLoopIntroSOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/480_C01S05_OYO5SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/010_WhileLoop1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/015_InfiniteLooping1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/020_C01S05_OYO1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/025_C01S05_OYO2SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/030_WhileLoop2SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/035_WhileLoop3SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/040_C01S05_OYO3SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/045_C01S05_OYO4SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/050_WhileLoop4SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/055_WhileLoop5SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/110_ForLoops1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/115_ForLoops2SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/120_ForLoops3SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/210_IfThen1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/215_IfThen2SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/220_IfThen3SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/250_Switch1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/260_OYO_IfThen4SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/315_Primes1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S05-Loops_Logic/Solutions/320_OYO_Primes2SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/010_Sleep1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/020_SingleKeyInput1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/030_StringInput1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/040_ShiftItem1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/050_MoveItem1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/060_ScaleItem1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/070_RotateItem1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/080_ChangeZ1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/090_ChangeLineEnd1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/100_ChangeWidthAndHeight1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/110_ChangeRadius1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/120_ChangeColor1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/130_ChangeLineWidth1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/140_ChangeFontSize1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/150_ChangeText1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/160_ChangeInt1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/170_ChangeFloat1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/180_EraseItem1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/190_ClearItems1.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/010_Sleep1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/020_SingleKeyInput1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/030_StringInput1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/040_ShiftItem1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/050_MoveItem1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/060_ScaleItem1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/070_RotateItem1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/080_ChangeZ1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/090_ChangeLineEnd1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/100_ChangeWidthAndHeight1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/110_ChangeRadius1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/120_ChangeColor1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/130_ChangeLineWidth1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/140_ChangeFontSize1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/150_ChangeText1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/160_ChangeInt1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/170_ChangeFloat1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/180_EraseItem1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S06-More_Drawing_Tools/Solutions/190_ClearItems1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S07-Storing_Data/050_Arrays1.cpp \
    exercises/C01-Beginner_Exercises/S09-Classes_Intro/Solutions/010_Classes1SOLN.cpp \
    exercises/C01-Beginner_Exercises/S09-Classes_Intro/010_Classes1.cpp \
    exercises/C08-Game_Programming/S03-TopDown2D/TopDown2D.cpp \
    exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.cpp \
    exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DSOLN.cpp \
    exercises/C08-Game_Programming/GameWidget.cpp \
    mycode/lib/MyLib.cpp \
    mycode/src/MyCode0.cpp \
    mycode/src/MyCode1.cpp \
    mycode/src/MyCode2.cpp \
    mycode/src/MyCode3.cpp \
    mycode/src/MyCode4.cpp \
    mycode/src/MyCode5.cpp \
    mycode/src/MyCode6.cpp \
    mycode/src/MyCode7.cpp \
    mycode/src/MyCode8.cpp \
    mycode/src/MyCode9.cpp

HEADERS += \
    include/lib/setup.h \
    include/lib/feetwetcodinglib.h \
    include/lib/constants.h \
    include/exercises/exercises.h \
    include/exercises/C01_S02.h \
    include/exercises/C01_S03.h \
    include/exercises/C01_S05.h \
    include/exercises/C01_S04.h \
    include/exercises/FeetWetCodingExercise.h \
    include/exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.h \
    include/exercises/C08-Game_Programming/S03-TopDown2D/TopDown2D.h \
    include/exercises/C08-Game_Programming/GameWidget.h \
    include/lib/FWCExerciseChooser.h \
    include/lib/colors.h \
    include/lib/ColorViewer.h \
    include/lib/ExerciseLauncher.h \
    include/lib/SeeOut.h \
    include/lib/MyCode.h \
    include/exercises/C01_S09.h \
    include/exercises/C01_S07.h \
    include/exercises/C01_S06.h

FORMS +=

INCLUDEPATH += include include/lib
DEPENDPATH += . src include
OUTPUT += Console

OTHER_FILES +=

RESOURCES += \
    feetwetresources.qrc
