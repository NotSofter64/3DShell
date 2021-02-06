#ifndef _3D_SHELL_GUI_H
#define _3D_SHELL_GUI_H

#include <3ds.h>
#include <citro2d.h>
#include <vector>

enum MENU_STATES {
    MENU_STATE_FILEBROWSER,
    MENU_STATE_OPTIONS,
    MENU_STATE_DELETE,
    MENU_STATE_PROPERTIES,
    MENU_STATE_SETTINGS,
    MENU_STATE_IMAGEVIEWER,
    MENU_STATE_ARCHIVEEXTRACT,
    MENU_STATE_TEXTREADER,
    MENU_STATE_UPDATE
};

typedef struct {
    MENU_STATES state = MENU_STATE_FILEBROWSER;
    int selected = 0;
    std::vector<FS_DirectoryEntry> entries;
    std::vector<bool> checked;
    std::vector<bool> checked_copy;
    std::string checked_cwd;
    int checked_count = 0;
    s64 used_storage = 0;
    s64 total_storage = 0;
    std::vector<C2D_Image> textures;
} MenuItem;

namespace GUI {
    void ResetCheckbox(MenuItem *item);
    void RecalcStorageSize(MenuItem *item);
    void ProgressBar(const std::string &title, const std::string &message, u64 offset, u64 size);
    Result Loop(void);

    // Windows
    void DisplayFileBrowser(MenuItem *item);
    void ControlFileBrowser(MenuItem *item, u32 *kDown);
    void DisplayFileOptions(MenuItem *item);
    void ControlFileOptions(MenuItem *item, u32 *kDown);
    void DisplaySettings(MenuItem *item);
    void ControlSettings(MenuItem *item, u32 *kDown);
    void DisplayImageViewer(MenuItem *item);
    void ControlImageViewer(MenuItem *item, u32 *kDown);
    void DisplayDeleteOptions(MenuItem *item);
    void ControlDeleteOptions(MenuItem *item, u32 *kDown);
    void DisplayUpdateOptions(bool *connection_status, bool *available, const std::string &tag);
    void ControlUpdateOptions(MenuItem *item, u32 *kDown, bool *state, bool *connection_status, bool *available, const std::string &tag);
}

#endif
