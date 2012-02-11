#ifndef FWCEXERCISECHOOSER_H
#define FWCEXERCISECHOOSER_H

#include <QObject>
#include <QString>
#include <QComboBox>
#include <QHBoxLayout>
#include <map>
#include <vector>

//Forward declarations
class FeetWetCodingExercise;

class FWCExerciseChooser : public QObject
{
    Q_OBJECT
public:
    FWCExerciseChooser(QObject *parent= NULL);
    ~FWCExerciseChooser();

    void selectChapter( const QString & selection );
    void selectSection( const QString & selection );
    void selectExercise( const QString & selection );
    void setOkToRun(bool ok) { mOkToRun = ok; }

    QComboBox * getChapterChooser() { return mChapterChooser; }
    QComboBox * getSectionChooser() { return mSectionChooser; }
    QComboBox * getExerciseChooser() { return mExerciseChooser; }
    QHBoxLayout * getChooserLayout() { return mHlayout; }

public slots:
    void chapterSelected( const QString & selection );
    void sectionSelected( const QString & selection );
    void exerciseSelected( const QString & selection );
    void runCurrentExercise();
    void saveCurrentExercise();

private:
    void createExercisesMap();
    FeetWetCodingExercise * getExerciseFromName( const QString & name );
    void stopExercise();
    void runExercise( const QString & selection );
    bool getSettingLoadPreviousExerciseEnabled( const QString & filename );
    bool loadPreviousExerciseEnabled();
    void loadPreviousExercise();

    FeetWetCodingExercise *mSelectedExercise;
    std::map<QString, std::map<QString, std::vector<QString> > > mExerciseMap;
    std::map<QString, std::map<QString, std::vector<QString> > >::iterator mChptIter;
    std::map<QString, std::vector<QString> >::iterator mSectIter;
    std::vector<QString>::iterator mExIter;

    QString mCurrentChapter;
    QString mCurrentSection;
    QString mCurrentExercise;

    QComboBox *mChapterChooser;
    QComboBox *mSectionChooser;
    QComboBox *mExerciseChooser;
    QHBoxLayout *mHlayout;
    bool mOkToRun;
};


#endif // FWCEXERCISECHOOSER_H
