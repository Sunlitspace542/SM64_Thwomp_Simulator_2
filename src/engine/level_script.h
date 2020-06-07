#ifndef _LEVEL_SCRIPT_H
#define _LEVEL_SCRIPT_H

struct LevelCommand *level_script_execute(struct LevelCommand *cmd);

extern u8 level_script_entry[];
extern u8 level_script_entry_error_screen[];

#endif /* _LEVEL_SCRIPT_H */
