#include "WorkingDirectory.hpp"

WorkingDirectory::WorkingDirectory()
{
    /**
     * TODO: Have assets moved to the bin folder when
     * you build to prevent having to use `../../` ...
     */

    path = "../../res/";

    /**
     * Tutorial includes code that manages assets correctly
     * for Mac OS, I doubt I'll end up needing it but for
     * the sake of consistency I'll keep it in ...
     */

    #ifdef MACOS

    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL =
		CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (CFURLGetFileSystemRepresentation(
		resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        CFRelease(resourcesURL);
        chdir(path);
    }

    #endif
}