#include <fwclib/FWCSettings.h>
#include <stdexcept>
#include <QFile>
#include <QDir>
#include <QDebug>

FWCSettings::FWCSettings()
{

}

FWCSettings::~FWCSettings()
{

}

QString FWCSettings::getProjectSandboxPath()
{
    QString sandboxDir;
    try
    {
        sandboxDir = getProjectDirPath() + "/fwcsandbox";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( sandboxDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getProjectSandboxPath(), unable to find fwcsandbox path");
        throw std::runtime_error(errorMsg);
    }

    return ( sandboxDir );
}

QString FWCSettings::getProjectDirPath()
{
    //Only figure this out once per run
    static QString projectPath;

    if ( false == projectPath.isEmpty() )
    {
        return projectPath;
    }

    //By default the project dir lives in the same parent directory as
    //the build dir. Assume this is the case, then test the assumption.
    QString buildDirPath;
    try
    {
        buildDirPath = getBuildDirPath();
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to determine build directory path");
        throw std::runtime_error(errorMsg);
    }

    //Initialize parentDir to the build dir, then pop up one level
    QDir parentDir(buildDirPath);
    if ( false == parentDir.cdUp() )
    {
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to determine parent directory path");
        throw std::runtime_error(errorMsg);
    }

    //Find the project directory by looking for the FeetWetCoding.pro file.
    //Limit the search to directories which have "FeetWetCoding" in their name.
    //Sort list in chronological order so we can grab the first (latest)
    //directory that meets our criteria.
    QString proFileName("FeetWetCoding.pro");
    QStringList filters;
    filters << "FeetWetCoding*";
    parentDir.setNameFilters(filters);
    parentDir.setFilter(QDir::Dirs);
    parentDir.setSorting(QDir::Time);
    QStringList dirnames(parentDir.entryList());

    for ( int i=0; i < dirnames.length(); ++i )
    {
        if ( QFile::exists( parentDir.canonicalPath() + QDir::separator() + dirnames.at(i) + QDir::separator() + proFileName ) )
        {
            //If this is the second valid project, notify user that
            //he has more than one project path and that we're using
            //the one with the latest timestamp.
            if (false == projectPath.isEmpty())
            {
                //Notify user
                break;
            }
            projectPath = parentDir.canonicalPath() + QDir::separator() + dirnames.at(i);
        }
    }


    //See if we have something to return. If not, throw.
    if ( projectPath.isEmpty() )
    {
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to find project path");
        throw std::runtime_error(errorMsg);
    }

    //Convert separators to the native characters for current platform
    projectPath = QDir::toNativeSeparators(projectPath);

#ifdef DEBUG
    qDebug() << "getProjectDirPath() returning projectPath: " << projectPath;
#endif
    return projectPath;
}

QString FWCSettings::getBuildDirPath()
{
    //Only figure this out once per run
    static QString buildDirPath;

    if ( false == buildDirPath.isEmpty() )
    {
        return buildDirPath;
    }

    //The main build directory's name starts with "FeetWetCoding-build" but
    //the rest of the name varies depending on the build configuration, plus,
    //we don't know where in the system it is. Fortunately, the running program's
    //current working directory, which we can query for, is somewhere in that
    //main build directory, either at its top level or in some sub-directory.
    //We just need to find where the string "FeetWetCoding-build" occurs in
    //the current working directory string and then find the next "/" that
    //occurs after that. This will mark the end of the main build directory
    //path, and if anything else follows that "/" then it's sub-directories
    //that we can discard from the string.

    //Get the current working directory and check that it's valid.
    const QString cwd = QDir::currentPath();
    if ( false == QDir(cwd).isReadable() )
    {
        std::string errorMsg("ERROR: In getBuildDirPath(), QDir::currentPath() invalid");
        throw std::runtime_error(errorMsg);
    }

    //Assume main build dir is the same until we learn otherwise.
    buildDirPath = cwd;

    //To find the first "/" (aka "separator() to get native character)
    //after the start of the build directory name, first find the
    //location of the partial main build directory name.
    const QString buildDirPartialName("FeetWetCoding-build");
    const int buildDirStartIndex(cwd.lastIndexOf(buildDirPartialName));

    //Next, starting from that index, find the next "/" character in the path.
    const int buildDirEndIndex(cwd.indexOf(QDir::separator(), buildDirStartIndex));

    //If we didn't find a "/" following the build dir name then that
    //means our current working directory *is* the main build dir and
    //we're done looking for the main build dir. Else if we did find
    //it that means the current working directory is a subdirectory of
    //the main build directory. We only want the main build directory,
    //so remove the any build dir subdirectories from the path.
    if ( -1 != buildDirEndIndex )
    {
        //If index is valid (i.e. not -1), then we found sub-dirs
        //and need to remove them
        buildDirPath.chop(buildDirPath.length()-buildDirEndIndex);
    }

    //Convert separators to the native characters for current platform
    buildDirPath = QDir::toNativeSeparators(buildDirPath);

    //Print out some debugging and we're done
#ifdef DEBUG
    qDebug() << "-------------------------------------";
    qDebug() << "In getBuildDirPath()...";
    qDebug() << "cwd:                        " << cwd;
    qDebug() << "buildDirPartialName:        " << buildDirPartialName;
    qDebug() << "Idx of buildDirPartialName: " << buildDirStartIndex;
    qDebug() << "Idx of following / :        " << buildDirEndIndex;
    qDebug() << "buildDirPath:               " << buildDirPath;
    qDebug() << "returning buildDirPath:     " << buildDirPath;
    qDebug() << "-------------------------------------";
#endif

    return buildDirPath;
}

QString FWCSettings::getImgDirPath()
{
    QString imgDir;
    try
    {
        imgDir = getProjectSandboxPath() + "/img";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( imgDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getImgDirPath(), unable to find img path");
        throw std::runtime_error(errorMsg);
    }

    //Convert separators to the native characters for current platform
    imgDir = QDir::toNativeSeparators(imgDir);

#ifdef DEBUG
    qDebug() << "getImgDirPath() returning imgDir: " << imgDir;
#endif
    return imgDir;
}

QString FWCSettings::getUserConfigDirPath()
{
    QString configDir;
    try
    {
        configDir = getProjectSandboxPath() + "/config_user";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( configDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getUserConfigDirPath(), unable to find user config path");
        throw std::runtime_error(errorMsg);
    }

    //Convert separators to the native characters for current platform
    configDir = QDir::toNativeSeparators(configDir);

#ifdef DEBUG
    qDebug() << "getUserConfigDirPath() returning configDir: " << configDir;
#endif

    return configDir;
}

QString FWCSettings::getDefaultConfigDirPath()
{
    QString configDir;
    try
    {
        configDir = getProjectSandboxPath() + "/config_default";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( configDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getDefaultConfigDirPath(), unable to find default config path");
        throw std::runtime_error(errorMsg);
    }

    //Convert separators to the native characters for current platform
    configDir = QDir::toNativeSeparators(configDir);

#ifdef DEBUG
    qDebug() << "getDefaultConfigDirPath() returning configDir: " << configDir;
#endif

    return configDir;
}

QString FWCSettings::getDefaultConfigFilePath()
{
    QString configFilePath;
    try
    {
        configFilePath = getDefaultConfigDirPath() + "/defaultconfig.txt";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //Convert separators to the native characters for current platform
    configFilePath = QDir::toNativeSeparators(configFilePath);

#ifdef DEBUG
    qDebug() << "getDefaultConfigFilePath() returning configFilePath: " << configFilePath;
#endif

    return configFilePath;
}

QString FWCSettings::getUserConfigFilePath()
{
    QString configFilePath;
    try
    {
        configFilePath = getUserConfigDirPath() + "/userconfig.txt";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //Convert separators to the native characters for current platform
    configFilePath = QDir::toNativeSeparators(configFilePath);

#ifdef DEBUG
    qDebug() << "getUserConfigFilePath() returning configFilePath: " << configFilePath;
#endif

    return ( configFilePath );
}

QString FWCSettings::getCurrentConfigFilePath()
{
    //Try user config first
    QString configFilePath;

    if (QFile(getUserConfigFilePath()).exists())
    {
        configFilePath = getUserConfigFilePath();
    }
    else if (QFile(getDefaultConfigFilePath()).exists())
    {
        configFilePath = getDefaultConfigFilePath();
    }

    //Convert separators to the native characters for current platform
    configFilePath = QDir::toNativeSeparators(configFilePath);

#ifdef DEBUG
    qDebug() << "getCurrentConfigFilePath() returning configFilePath: " << configFilePath;
#endif

    return configFilePath;
}

QString FWCSettings::getLastExerciseFilePath()
{
    QString configFilePath;
    try
    {
        configFilePath = getUserConfigDirPath() + "/lastexercise.txt";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //Convert separators to the native characters for current platform
    configFilePath = QDir::toNativeSeparators(configFilePath);

#ifdef DEBUG
    qDebug() << "getLastExerciseFilePath() returning configFilePath: " << configFilePath;
#endif

    return configFilePath;
}

void FWCSettings::initSettingsFile()
{
    //If there's already a user config file then we're done.
    QString userConfigFile(getUserConfigFilePath());

    if ( QFile(userConfigFile).exists() )
    {
        return;
    }

    try
    {
        //Copy the default config file to the user config dir.
        //If the user config directory doesn't exist create it.
        //It lives in the project's build directory (see getUserConfigDirPath())
        //so it's ok for us to write there. getUserConfigDirPath() throws if dir
        //can't be found
        QDir dir(getUserConfigDirPath());
        if ( !dir.exists() && !dir.mkdir(getUserConfigDirPath()) )
        {
             //program can still proceed, so no need to throw
             //but can't continue to init, so return
             return;
        }

        QFile srcFile(getDefaultConfigFilePath());
        if ( srcFile.exists() )
        {
            srcFile.copy(getUserConfigFilePath());
        }
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();

        //program can still proceed, so no need to throw
    }
}

void FWCSettings::getSetting( const QString & settingKey, QString & settingVal )
{
    QString configFilePath(getCurrentConfigFilePath());

    QFile configFile(configFilePath);
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "WARNING: In getSetting(), unable to open file " << configFilePath << " for reading";
        return;
    }

    QTextStream in(&configFile);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(":", QString::SkipEmptyParts);
        if ( 2 != list.count() )
            continue;

        if ( list.at(0).contains(settingKey, Qt::CaseInsensitive) )
        {
            settingVal = list.at(1);
        }
    }

    configFile.close();
}

void FWCSettings::getPreviousExerciseFromFile( QString pathToFile, QString & chapter, QString & section, QString & exercise )
{
    QFile file(pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
#ifdef DEBUG
        qDebug() << "INFO: File \"" << pathToFile << "\" not found.\n";
#endif
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(":", QString::SkipEmptyParts);
        if ( 2 != list.count() )
            continue;

        if ( list.at(0).contains("chapter", Qt::CaseInsensitive) )
        {
            chapter = ( list.at(1) );
        }
        else if ( list.at(0).contains("section", Qt::CaseInsensitive) )
        {
            section = ( list.at(1) );
        }
        else if ( list.at(0).contains("exercise", Qt::CaseInsensitive) )
        {
            exercise = ( list.at(1) );
        }
    }

    file.close();
}

void FWCSettings::saveCurrentExerciseToFile( QString pathToFile, QString chapter, QString section, QString exercise )
{
    QFile file(pathToFile);
    if ( file.exists() )
    {
        file.remove();
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "WARNING: Unable to write to file \"" << pathToFile << "\". Cannot save which exercise was viewed last.\n";
        return;
    }

    QTextStream out(&file);
    out << "chapter:" << chapter << "\n";
    out << "section:" << section << "\n";
    out << "exercise:" << exercise << "\n";

    file.close();
}

