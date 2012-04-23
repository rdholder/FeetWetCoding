#ifndef FWCSETTINGS_H
#define FWCSETTINGS_H

#include <QString>

//FWC file I/O and configuration settings
class FWCSettings
{
public:
    FWCSettings();
    ~FWCSettings();

    //The "fwcsandbox" is the safe area for writing files. It's a sub-directory of the main
    //project directory and it's the only place that fwc files can be written to from code.
    //Throws std::runtime_error if dir path cannot be determined
    QString getProjectSandboxPath();

    //Throws std::runtime_error if dir path cannot be determined
    QString getProjectDirPath();

    //Throws std::runtime_error if dir path cannot be determined
    QString getBuildDirPath();

    //Throws std::runtime_error if dir path cannot be determined
    QString getDefaultConfigDirPath();

    //Throws std::runtime_error if dir path cannot be determined
    QString getImgDirPath();

    //Throws std::runtime_error if dir path cannot be determined
    QString getUserConfigDirPath();

    QString getDefaultConfigFilePath();
    QString getUserConfigFilePath();
    QString getCurrentConfigFilePath();
    QString getLastExerciseFilePath();

    void initSettingsFile();
    void getSetting( const QString & settingKey, QString & settingVal );
    void getPreviousExerciseFromFile( QString pathToFile, QString & chapter, QString & section, QString & exercise );
    void saveCurrentExerciseToFile( QString pathToFile, QString chapter, QString section, QString exercise );

private:

};

#endif // FWCSETTINGS_H
